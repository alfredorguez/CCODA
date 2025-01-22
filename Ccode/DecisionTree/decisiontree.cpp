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

    // Extraer la información del nodo actual desde la lista de nodos
    const auto& node_data = tree_json["nodes"][node_index];
    int left_index = node_data[0];  // Índice del hijo izquierdo
    int right_index = node_data[1]; // Índice del hijo derecho
    int feature = node_data[2];     // Característica usada para el umbral
    float threshold = node_data[3]; // Umbral de división
    vector<int> values(tree_json["values"][node_index][0].begin(),
                       tree_json["values"][node_index][0].end()); // Valores de las clases

    // Crear el nodo actual
    nodes.push_back(std::make_unique<BinaryNode>(feature, threshold, values));
    BinaryNode* current_node = nodes.back().get();  // Obtener puntero al nodo actual

    // Construir recursivamente los hijos izquierdo y derecho
    current_node->left = buildTree(tree_json, left_index);
    current_node->right = buildTree(tree_json, right_index);

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
