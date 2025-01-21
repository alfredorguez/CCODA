#include "decisiontree.h"

// ---------------------------------------------------------------------
// Constructor de la clase DecisionTree
DecisionTree::DecisionTree(const json& tree_json) : root(nullptr) {
    // Construir el árbol a partir del JSON
    root = buildTree(tree_json, 0);
}

// ---------------------------------------------------------------------
// Destructor de la clase DecisionTree
DecisionTree::~DecisionTree() {
    // Los nodos se eliminan automáticamente gracias a std::unique_ptr
}

// ---------------------------------------------------------------------
// Método auxiliar para construir el árbol recursivamente
BinaryNode* DecisionTree::buildTree(const json& tree_json, int node_index) {
    if (node_index == -1) {
        return nullptr;  // Nodo inexistente
    }

    // Crear el nodo actual
    int feature = tree_json["feature"][node_index];
    float threshold = tree_json["threshold"][node_index];
    vector<int> values(tree_json["value"][node_index][0].begin(),
                       tree_json["value"][node_index][0].end());

    // Crear nodo y agregarlo al vector
    nodes.push_back(make_unique<BinaryNode>(feature, threshold, values));

    // Obtener puntero al nodo recién creado
    BinaryNode* current_node = nodes.back().get();

    // Construir los nodos hijos recursivamente
    current_node->left = buildTree(tree_json, tree_json["children_left"][node_index]);
    current_node->right = buildTree(tree_json, tree_json["children_right"][node_index]);

    return current_node;
}

// ---------------------------------------------------------------------
// Método para predecir la clase de un conjunto de características
int DecisionTree::predict(const float* features) {
    if (root) {
        return root->predict(features);
    }
    return -1;  // Si el árbol está vacío, retorna un valor por defecto
}
