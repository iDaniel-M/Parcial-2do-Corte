#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Estudiante.h"

using namespace std;

int main() {
    vector<Estudiante> estudiantes;

    estudiantes.emplace_back("Ana Pérez", 101, 85.0f, 20);
    estudiantes.emplace_back("Luis Gómez", 102, 90.0f, 25);
    estudiantes.emplace_back("María Torres", 103, 70.0f, 18);

    estudiantes[0].registrarNota(95.0f, 3);
    estudiantes[1].registrarNota(88.0f, 4);
    estudiantes[2].registrarNota(75.0f, 2);

    cout << fixed << setprecision(2);
    cout << "===== Resumen General =====" << endl;

    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return 0;
    }

    double sumaPromedios = 0.0;
    for (const auto& e : estudiantes) {
        cout << "ID: " << e.id
             << " | Nombre: " << e.nombre
             << " | Promedio: " << e.promedio
             << " | Créditos: " << e.creditosAprobados
             << endl;
        sumaPromedios += static_cast<double>(e.promedio);
    }

    double promedioGeneral = sumaPromedios / static_cast<double>(estudiantes.size());
    cout << "\nPromedio general de los estudiantes: " << promedioGeneral << endl;

    ofstream reporte("reporte_estudiantes.txt");
    if (reporte.is_open()) {
        reporte << "Nombre;Promedio;CreditosAprobados\n";
        for (const auto& e : estudiantes) {
            reporte << e.nombre << ";"
                    << e.promedio << ";"
                    << e.creditosAprobados << "\n";
        }
        reporte.close();
        cout << "\nReporte generado: reporte_estudiantes.txt" << endl;
    } else {
        cerr << "Error al generar el reporte." << endl;
    }

    return 0;
}
