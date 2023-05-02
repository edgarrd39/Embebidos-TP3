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

#ifndef ALUMNO_H
#define ALUMNO_H

/** \brief Declaraciones publicas del modulo de alumno

 **
 ** \addtogroup alumno Alumnos
 ** \brief Modulo para gestion de alumnos
 ** @{ */

/* === Headers files inclusions ================================================================ */

#include <stdint.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */
/**
 * @brief Define el tamaño de los campos de texto
 *
 * ESte parametro define el tamaño de los campos de texto de
 * la estructura alumno_t
 */

#define FIELD_SIZE 50

/**
 * @brief Define si la memoria será dinamica o estatica
 * Si DINAMICO = 1, entonces la memoria seleccionada es dinamica
 * Si DINAMICO = 0, entonces la memoria seleccionada es estatica
 *
 */
#define DINAMICO 0

/* === Public data type declarations =========================================================== */

//! Estructura para almacenar los datos de un alumno
typedef struct alumno_s * alumno_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */
/**
 * @brief Función Para crear Alumno
 *
 * @param apellido
 * @param nombre
 * @param documento
 * @return alumno_t
 */

alumno_t CrearAlumno(char * apellido, char * nombre, uint32_t documento);

/**
 * @brief Función para serializar los datos de un alumno
 *
 * @param alumno Puntero a la estructura con los datos del alumno
 * @param cadena Puntero a la cadena de resultado
 * @param espacio Espacio disponible en la cadena de resultado
 * @return int, La longitud de la cadena generada, o -1 si el espacio no es suficiente
 */
int Serializar(const struct alumno_s * alumno, char cadena[], int espacio);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* TEMPLATE_H */
