#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

/**
 * @brief Clase que representa a un estudiante con su información académica.
 */
class Estudiante {
private:
    std::string nombre;        ///< Nombre del estudiante
    int id;                    ///< Identificador del estudiante
    float promedio;            ///< Promedio ponderado del estudiante
    int creditosAprobados;     ///< Total de créditos aprobados

public:
    /**
     * @brief Constructor que inicializa todos los atributos.
     * @param nombre Nombre del estudiante.
     * @param id Identificador del estudiante.
     * @param promedio Promedio inicial del estudiante.
     * @param creditosAprobados Créditos aprobados iniciales.
     */
    Estudiante(std::string nombre, int id, float promedio, int creditosAprobados)
        : nombre(nombre), id(id), promedio(promedio), creditosAprobados(creditosAprobados) {}

    /**
     * @brief Registra una nueva nota y actualiza el promedio ponderado.
     * @param nota Nota obtenida.
     * @param creditos Créditos asociados a la materia.
     */
    void registrarNota(float nota, int creditos) {
        promedio = ((promedio * creditosAprobados) + (nota * creditos)) / (creditosAprobados + creditos);
        creditosAprobados += creditos;
    }
};

#endif
