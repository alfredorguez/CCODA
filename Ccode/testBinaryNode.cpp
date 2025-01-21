#include "BinaryNode.h"
#include <iostream>

int main() {
    // Crear nodos hoja
    BinaryNode* leaf1 = new BinaryNode(-1, 0.0, {3, 0, 0});  // Clase 0
    BinaryNode* leaf2 = new BinaryNode(-1, 0.0, {0, 5, 0});  // Clase 1

    // Nodo intermedio
    BinaryNode* root = new BinaryNode(0, 1.5, {8, 5, 0}, leaf1, leaf2);

    // Características de entrada
    float features[] = {2.0};

    // Predicción
    int prediction = root->predict(features);
    std::cout << "Predicción: Clase " << prediction << std::endl;

    // Liberar memoria
    delete leaf1;
    delete leaf2;
    delete root;

    return 0;
}