# Laboratorio de Microprocesadores - Trabajo Práctico Nº3

Autor: Díaz, Edgardo Rodrigo

Trabajo Práctico Nº3: Compilación de proyectos en Lenguaje C -  Usando Patrón de programación ADT (Abstract Data Type).

**Descripción**: El programa principal se encarga de mostrar los datos del alumno por pantalla en formato **JSON**.Se podra elegir el tipo de memoria, ya sea dinamica o estatica. 

## Compilación

La compilación se puede realizar utilizando memoria dinámica como también memoria estatica

+ Para compilar de manera estatica usar simplemnte en linea de comando la sentencia `make`.

+ Para compilar de manera dinamica se utilizara la varaible `TIPO` escribiendo en linea de comando `make TIPO =-DDINAMICO`.

**NOTA**: Para asegurarse que se este utilizando la memoria deseada, usar primero
`make clean`.

Con `make clean` se elimina la carpeta build
## Ejecución

Para ejecutar el codigo se deebe escribir en linea de comandos la siguiente sentencia:
`./build/bin/app.elf `

## Documentación

Para generar la documentación del proyecto se utiliza `make doc`

Para abrir la documentación escribir en linea de comando `open ./build/doc/html/index.html`


## Más informacion

Para leer más sobre memoría dinámica en C ir a https://en.cppreference.com/w/c/memory

Más sobre memoria estatica: https://craftofcoding.wordpress.com/2015/12/07/memory-in-c-the-stack-the-heap-and-static/
- - - -

