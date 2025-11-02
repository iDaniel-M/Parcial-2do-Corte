#include "Estudiante.h"

void Estudiante::registrarNota(float nota, int creditos) {
    promedio = ((promedio * creditosAprobados) + (nota * creditos)) / (creditosAprobados + creditos);
    creditosAprobados += creditos;
}
