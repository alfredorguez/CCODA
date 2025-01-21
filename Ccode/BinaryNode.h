#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include <vector>
using namespace std;

/**
 * Clase que representa un nodo binario de un árbol de decisión
 */
class BinaryNode {
public:
    /**
     * Constructor de la clase BinaryNode
     *
     * :param feature_index: Índice de la característica a comparar en el nodo
     * :type feature_index: int
     *
     * :param threshold: Umbral para la comparación en el nodo
     * :type threshold: float
     *
     * :param values: Lista de valores que representan el número de muestras
     *                de cada clase en el nodo
     * :type values: vector<int>
     *
     * :param left: Puntero al nodo hijo izquierdo
     * :type left: BinaryNode*
     *
     * :param right: Puntero al nodo hijo derecho
     * :type right: BinaryNode*
     */
    BinaryNode(int feature_index, float threshold, vector<int> values, 
               BinaryNode* left = nullptr, BinaryNode* right = nullptr);

    /**
     * Método para predecir la clase de un conjunto de características
     *
     * :param features: Puntero a un array de características a evaluar
     * :type features: const float*
     *
     * :return: Clase predicha por el árbol
     * :rtype: int
     */
    int predict(const float* features);

private:
    int feature_index;           // Índice de la característica a comparar
    float threshold;             // Umbral de comparación
    vector<int> values;          // Lista de valores de muestras por clase
    BinaryNode* left;            // Puntero al nodo izquierdo
    BinaryNode* right;           // Puntero al nodo derecho
};

#endif // BINARY_NODE_H