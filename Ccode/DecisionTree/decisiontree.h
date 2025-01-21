#ifndef DECISION_TREE_H
#define DECISION_TREE_H

#include "BinaryNode.h"
//#include <nlohmann/json.hpp>
#include "third_party/json/json.hpp"
#include <vector>
#include <memory>  // Para std::unique_ptr

using namespace std;
using json = nlohmann::json;

/**
 * Clase que representa un árbol de decisión.
 */
class DecisionTree {
public:
    /**
     * Constructor de la clase DecisionTree
     *
     * :param tree_json: Objeto JSON que contiene la estructura del árbol
     * :type tree_json: const json&
     */
    DecisionTree(const json& tree_json);

    /**
     * Destructor de la clase DecisionTree
     * Limpia la memoria asignada dinámicamente para los nodos.
     */
    ~DecisionTree();

    /**
     * Método para predecir la clase de un conjunto de características.
     *
     * :param features: Puntero a un array con las características a evaluar
     * :type features: const float*
     *
     * :return: Clase predicha por el árbol
     * :rtype: int
     */
    int predict(const float* features);

private:
    vector<unique_ptr<BinaryNode>> nodes;  // Almacena los nodos del árbol
    BinaryNode* root;                      // Nodo raíz del árbol

    /**
     * Método auxiliar para construir el árbol recursivamente.
     *
     * :param tree_json: Objeto JSON con la estructura del árbol
     * :param node_index: Índice del nodo actual
     * :return: Puntero al nodo binario creado
     */
    BinaryNode* buildTree(const json& tree_json, int node_index);
};

#endif // DECISION_TREE_H
