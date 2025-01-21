#include "BinaryNode.h"
#include <algorithm>
#include <numeric>

// ---------------------------------------------------------------------
// Constructor de la clase BinaryNode
BinaryNode::BinaryNode(int feature_index, float threshold, vector<int> values, 
                       BinaryNode* left, BinaryNode* right)
    : feature_index(feature_index), threshold(threshold), values(values),
      left(left), right(right) {}

// ---------------------------------------------------------------------
// Método para predecir la clase de un conjunto de características
int BinaryNode::predict(const float* features) {
    // Comprobar si el nodo es un nodo hoja
    bool is_leaf = all_of(values.begin(), values.end(), 
                          [](int val) { return val == 0; }) ||
                   count_if(values.begin(), values.end(), 
                            [](int val) { return val > 0; }) == 1;

    if (is_leaf) {
        // Devolver la clase con el único valor positivo en la lista
        return distance(values.begin(), max_element(values.begin(), values.end()));
    }

    // Comparar la característica con el umbral
    if (features[feature_index] <= threshold) {
        // Si el hijo izquierdo no es nulo, continuar por la izquierda
        if (left) {
            return left->predict(features);
        }
    } else {
        // Si el hijo derecho no es nulo, continuar por la derecha
        if (right) {
            return right->predict(features);
        }
    }

    // Valor por defecto si algo falla (esto no debería suceder)
    return -1;
}