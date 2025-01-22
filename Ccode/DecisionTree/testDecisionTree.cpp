#include "third_party/json/json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "decisiontree.h"
#include "rapidcsv.h"

using namespace std;
using json = nlohmann::json;

// Función para cargar el CSV y generar una matriz de características y predicciones
vector<pair<vector<float>, int>> loadCSV(const string& filename) {
    vector<pair<vector<float>, int>> dataset;

    try {
        rapidcsv::Document doc(filename, rapidcsv::LabelParams(-1, -1));

        size_t numRows = doc.GetRowCount();
        size_t numCols = doc.GetColumnCount();

        for (size_t i = 1; i < numRows; ++i) {
            vector<float> features;
            for (size_t j = 0; j < numCols - 1; ++j) { // Todas las columnas menos la última
                features.push_back(doc.GetCell<float>(j, i));
            }
            float prediction = doc.GetCell<float>(numCols - 1, i); // Última columna es la predicción
            dataset.emplace_back(features, static_cast<int>(prediction));
        }
    } catch (const exception& e) {
        cerr << "Error al cargar el archivo CSV: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    return dataset;
}

int main() {
    try{
        // Leer el archivo JSON usando ifstream
        ifstream file("decision_tree_DS2.json");
        if (!file.is_open()) {
            cerr << "Error: No se pudo abrir el archivo JSON" << endl;
            return -1;
        }

        // Parsear el archivo JSON
        json tree_json;
        // Parsear el JSON
        file >> tree_json;
        file.close();

        // Crear el árbol de decisión
        DecisionTree tree(tree_json);

        // Cargar los datos desde el CSV
        string csv_file = "muestras_predicciones.csv";
        auto dataset = loadCSV(csv_file);
        cout << "Datos cargados exitosamente desde " << csv_file << ".\n";

        // Comparar predicciones
        size_t correct_predictions = 0;
        size_t total_samples = dataset.size();

        for (const auto& pair : dataset) {
            const vector<float>& features = pair.first; // Accede al vector de características
            int python_prediction = pair.second;       // Accede a la predicción de Python

            // Convertir vector<float> a puntero float* para usar con el método predict
            int model_prediction = tree.predict(features.data());

            cout << "Python: " << python_prediction
                 << " | Modelo C++: " << model_prediction << endl;

            // Verifica si la predicción es correcta
            if (model_prediction == python_prediction) {
                correct_predictions++;
            }
        }
        // Mostrar estadísticas
        cout << fixed << setprecision(2);
        cout << "\nPrecisión: " << (100.0 * correct_predictions / total_samples) << "% ("
             << correct_predictions << "/" << total_samples << ")\n";

    }

    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }


    // Realizar la predicción
    //int prediction = tree.predict(features);
    //cout << "Predicción: Clase " << prediction << endl;

    return 0;
}
