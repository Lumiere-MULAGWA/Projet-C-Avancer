#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ACTIVATION_FUNCTION(x) (1 / (1 + exp(-(x)))) 

typedef struct {
    int num_inputs;
    int num_hidden_layers;
    int* hidden_layer_sizes;
    int num_outputs;
    double** weights;
    double* biases;
} NeuralNetwork;

NeuralNetwork* create_neural_network(int num_inputs, int num_hidden_layers, int* hidden_layer_sizes, int num_outputs) {
    NeuralNetwork* nn = (NeuralNetwork*)malloc(sizeof(NeuralNetwork));
    nn->num_inputs = num_inputs;
    nn->num_hidden_layers = num_hidden_layers;
    nn->hidden_layer_sizes = (int*)malloc(num_hidden_layers * sizeof(int));
    for (int i = 0; i < num_hidden_layers; i++) {
        nn->hidden_layer_sizes[i] = hidden_layer_sizes[i];
    }
    nn->num_outputs = num_outputs;

    // Allouer de l'espace pour les poids et les biais
    nn->weights = (double**)malloc((num_hidden_layers + 1) * sizeof(double*));
    nn->biases = (double*)malloc((num_hidden_layers + 1) * sizeof(double));

    // Initialiser les poids et les biais de manière aléatoire
    for (int i = 0; i < num_hidden_layers + 1; i++) {
        int layer_size = (i == 0) ? num_inputs : nn->hidden_layer_sizes[i - 1];
        nn->weights[i] = (double*)malloc(layer_size * ((i == num_hidden_layers) ? num_outputs : nn->hidden_layer_sizes[i]) * sizeof(double));
        for (int j = 0; j < layer_size * ((i == num_hidden_layers) ? num_outputs : nn->hidden_layer_sizes[i]); j++) {
            nn->weights[i][j] = ((double)rand() / RAND_MAX) * 2 - 1; // Valeurs aléatoires entre -1 et 1
        }
        nn->biases[i] = ((double)rand() / RAND_MAX) * 2 - 1; // Valeur aléatoire entre -1 et 1
    }

    return nn;
}

void destroy_neural_network(NeuralNetwork* nn) {
    for (int i = 0; i < nn->num_hidden_layers + 1; i++) {
        free(nn->weights[i]);
    }
    free(nn->weights);
    free(nn->biases);
    free(nn->hidden_layer_sizes);
    free(nn);
}

int main() {
    int num_inputs = 10;
    int num_hidden_layers = 2;
    int hidden_layer_sizes[] = {20, 10};
    int num_outputs = 5;

    NeuralNetwork* nn = create_neural_network(num_inputs, num_hidden_layers, hidden_layer_sizes, num_outputs);

    // Utiliser le réseau de neurones pour des prédictions, de l'entraînement, etc.

    destroy_neural_network(nn);
    return 0;
}
