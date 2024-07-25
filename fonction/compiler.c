#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX_SYMBOLS 100

typedef enum {
    TOKEN_NUMBER,
    TOKEN_IDENTIFIER,
    TOKEN_ASSIGN,
    TOKEN_SEMICOLON,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_END,
Token_LUM
} TokenType;

typedef struct {
    TokenType type;
    char value[100];
} Token;

typedef struct {
    char name[100];
    int value;
} Symbol;

typedef struct {
    Symbol symbols[MAX_SYMBOLS];
    int count;
} SymbolTable;


Token getNextToken(const char **input) {
    while (**input == ' ') (*input)++; // Skip spaces

    Token token;
    if (**input == '\0') {
        token.type = TOKEN_END;
        strcpy(token.value, "EOF");
    } else if (isdigit(**input)) {
        token.type = TOKEN_NUMBER;
        int i = 0;
        while (isdigit(**input)) {
            token.value[i++] = *(*input)++;
        }
        token.value[i] = '\0';
    } else if (isalpha(**input)) {
        token.type = TOKEN_IDENTIFIER;
        int i = 0;
        while (isalpha(**input) || isdigit(**input)) {
            token.value[i++] = *(*input)++;
        }
        token.value[i] = '\0';
    } else {
        token.type = TOKEN_END;
        switch (**input) {
            case '=': token.type = TOKEN_ASSIGN; break;
            case ';': token.type = TOKEN_SEMICOLON; break;
            case '+': token.type = TOKEN_PLUS; break;
            case '-': token.type = TOKEN_MINUS; break;
            case '*': token.type = TOKEN_MULTIPLY; break;
            case '/': token.type = TOKEN_DIVIDE; break;
            case '(': token.type = TOKEN_LPAREN; break;
            case ')': token.type = TOKEN_RPAREN; break;
            default: token.type = TOKEN_END; break;
        }
        token.value[0] = *(*input)++;
        token.value[1] = '\0';
    }

    return token;
}

typedef struct {
    Token token;
    const char *input;
    SymbolTable *symbolTable;
} Parser;

Parser createParser(const char *input, SymbolTable *symbolTable) {
    Parser parser;
    parser.input = input;
    parser.token = getNextToken(&parser.input);
    parser.symbolTable = symbolTable;
    return parser;
}

void expect(Parser *parser, TokenType type) {
    if (parser->token.type == type) {
        parser->token = getNextToken(&parser->input);
    } else {
        printf("Syntax error: expected token %d, got %d\n", type, parser->token.type);
        exit(EXIT_FAILURE);
    }
}

int parseExpression(Parser *parser);

int parseFactor(Parser *parser) {
    int result = 0;
    if (parser->token.type == TOKEN_NUMBER) {
        result = atoi(parser->token.value);
        expect(parser, TOKEN_NUMBER);
    } else if (parser->token.type == TOKEN_IDENTIFIER) {
        for (int i = 0; i < parser->symbolTable->count; i++) {
            if (strcmp(parser->token.value, parser->symbolTable->symbols[i].name) == 0) {
                result = parser->symbolTable->symbols[i].value;
                break;
            }
        }
        expect(parser, TOKEN_IDENTIFIER);
    } else if (parser->token.type == TOKEN_LPAREN) {
        expect(parser, TOKEN_LPAREN);
        result = parseExpression(parser);
        expect(parser, TOKEN_RPAREN);
    } else {
        printf("Syntax error: unexpected token %d\n", parser->token.type);
        exit(EXIT_FAILURE);
    }
    return result;
}

int parseTerm(Parser *parser) {
    int result = parseFactor(parser);
    while (parser->token.type == TOKEN_MULTIPLY || parser->token.type == TOKEN_DIVIDE) {
        TokenType op = parser->token.type;
        expect(parser, op);
        int rhs = parseFactor(parser);
        if (op == TOKEN_MULTIPLY) {
            result *= rhs;
        } else {
            result /= rhs;
        }
    }
    return result;
}

int parseExpression(Parser *parser) {
    int result = parseTerm(parser);
    while (parser->token.type == TOKEN_PLUS || parser->token.type == TOKEN_MINUS) {
        TokenType op = parser->token.type;
        expect(parser, op);
        int rhs = parseTerm(parser);
        if (op == TOKEN_PLUS) {
            result += rhs;
        } else {
            result -= rhs;
        }
    }
    return result;
}

void storeSymbol(SymbolTable *symbolTable, const char *name, int value) {
    for (int i = 0; i < symbolTable->count; i++) {
        if (strcmp(symbolTable->symbols[i].name, name) == 0) {
            symbolTable->symbols[i].value = value;
            return;
        }
    }
    strcpy(symbolTable->symbols[symbolTable->count].name, name);
    symbolTable->symbols[symbolTable->count].value = value;
    symbolTable->count++;
}

void parseAssignment(Parser *parser) {
    if (parser->token.type == TOKEN_IDENTIFIER) {
        char varName[100];
        strcpy(varName, parser->token.value);
        expect(parser, TOKEN_IDENTIFIER);
        expect(parser, TOKEN_ASSIGN);
        int value = parseExpression(parser);
        storeSymbol(parser->symbolTable, varName, value);
        printf("Assigned %d to %s\n", value, varName);
        expect(parser, TOKEN_SEMICOLON);
    } else {
        printf("Syntax error: expected identifier, got %d\n", parser->token.type);
        exit(EXIT_FAILURE);
    }
}

void parse(Parser *parser) {
    while (parser->token.type != TOKEN_END) {
        parseAssignment(parser);
    }
}

int main() {
    const char *input = "x = 3 + 4 * (2 - 1); y = x + 5;";
    SymbolTable symbolTable = {0};
    Parser parser = createParser(input, &symbolTable);
    parse(&parser);
    return 0;
}
