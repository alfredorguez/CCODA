#include "third_party/json/json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "decisiontree.h"

using json = nlohmann::json;

using namespace std;
using json = nlohmann::json;

int main() {
    // Leer el archivo JSON usando ifstream
    ifstream file("treePrueba.json");
    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo JSON" << endl;
        return -1;
    }

    // Parsear el archivo JSON
    json tree_json;
    try {
        file >> tree_json;
    } catch (const json::parse_error& e) {
        cerr << "Error de parseo del JSON: " << e.what() << endl;
        return -1;
    }

    // Crear el árbol de decisión
    DecisionTree tree(tree_json);

    // Características de entrada para la predicción
    float features[] = {1.0, 4.0};

    // Realizar la predicción
    int prediction = tree.predict(features);
    cout << "Predicción: Clase " << prediction << endl;

    return 0;
}
