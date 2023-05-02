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

/** \brief Segundo Trabajo Practico
 **
 **
 ** \addtogroup tp2 TPN2
 ** \brief El programa principal se encarga de mostrar los datos del alumno por pantalla en formato
 * JSON
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include <stdio.h>
#include "alumno.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

int main(void) {

    alumno_t yo = CrearAlumno("Diaz", "Edgardo", 12345321);
    char cadena[128];

    if (Serializar(yo, cadena, sizeof(cadena)) >= 0) {
        printf("%s\n", cadena);
    } else {
        printf("Error al serializar\n");
    }

    /*
        alumno_t otro = CrearAlumno("Perez", "Pepe", 35532112);
        if (Serializar(otro, cadena, sizeof(cadena)) >= 0) {
            printf("%s\n", cadena);
        } else {
            printf("Error al serializar\n");
        }
    */
    return 0;
}
/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
