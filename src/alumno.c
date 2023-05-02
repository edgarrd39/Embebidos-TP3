/************************************************************************************************
Copyright (c) 2023, Edgardo Rodrigo Díaz <rodrigo.09tuc@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** \brief Implementación del modulo alumno
 **
 ** \addtogroup alumno Alumnos
 ** \brief Modulo para la gestión de alumnos
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "alumno.h"

/* === Macros definitions ====================================================================== */

#define FIELD_SIZE    50
#define MAX_INSTANCES 50

/* === Private data type declarations ========================================================== */
struct alumno_s {
    char apellido[FIELD_SIZE]; //!< Almacena el apellido del alumno
    char nombre[FIELD_SIZE];   //!< Almacena el nombre del alumno
    uint32_t documento;        //!< Almacena el documento del alumno
    bool ocupado;              //!< Indica si el descriptor está en uso
};
/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

static int SerializarCadena(const char * campo, const char * valor, char * cadena, int espacio);

static int SerializarNumero(const char * campo, int valor, char * cadena, int espacio);

alumno_t AlumnoOcupado(void);
/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

static int SerializarCadena(const char * campo, const char * valor, char * cadena, int espacio) {
    return snprintf(cadena, espacio, "\"%s\":\"%s\",", campo, valor);
}

static int SerializarNumero(const char * campo, int valor, char * cadena, int espacio) {
    return snprintf(cadena, espacio, "\"%s\":\"%d\",", campo, valor);
}

alumno_t AlumnoOcupado(void) {
    alumno_t alumno = NULL;

    static struct alumno_s instances[MAX_INSTANCES] = {};
    for (int index = 0; index < MAX_INSTANCES; index++) {
        if (!instances[index].ocupado) {
            instances[index].ocupado = true;
            alumno = &instances[index];
            break;
        }
    }
    return alumno;
}

/* === Public function implementation ========================================================== */

alumno_t CrearAlumno(char * apellido, char * nombre, uint32_t documento) {

    if (!DINAMICO) {
        alumno_t alumno = AlumnoOcupado();

        if (alumno) {
            printf("Se crea alumno de manera estatica\n");
            strcpy(alumno->apellido, apellido);
            strcpy(alumno->nombre, nombre);
            alumno->documento = documento;
        }
        return alumno;
    } else {
        printf("Se crea alumno de manera dinamica\n");
        alumno_t alumno = malloc(sizeof(struct alumno_s));
        strcpy(alumno->apellido, apellido);
        strcpy(alumno->nombre, nombre);
        alumno->documento = documento;
        return alumno;
    }
}

int Serializar(const struct alumno_s * alumno, char cadena[], int espacio) {
    int disponibles = espacio;
    int resultado;

    cadena[0] = '{';
    disponibles--;
    cadena++;

    resultado = SerializarCadena("apellido", alumno->apellido, cadena, espacio);

    if (resultado > 0) {
        disponibles -= resultado;
        cadena += resultado;
        resultado = SerializarCadena("nombre", alumno->nombre, cadena, espacio);
    }
    if (resultado > 0) {
        disponibles -= resultado;
        cadena += resultado;
        resultado = SerializarNumero("documento", alumno->documento, cadena, espacio);
    }
    if (resultado > 0) {
        cadena += resultado;
        *(cadena - 1) = '}';
        resultado = espacio - disponibles;
    }

    return resultado;
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
