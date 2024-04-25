# PUSH_SWAP

## Detalles del proyecto

El objetivo del proyecto es crear un algoritmo capaz de ordenar una lista de números aleatorios con el menor número de instrucciones.
El proyecto debe contener dos ejecutables:
*   `push_swap:`  toma la lista de números sin duplicados y devuelve instrucciones para ordenarlos en una segunda pila.
*   `checker:`    verifica que las instrucciones de push_swap sean correctas y ordenen los números.

### Estructura y funcionamiento

El proyecto se puede enfocar en varias partes: la lógica de ordenación, el manejo de las dos pilas y la interacción entre las pilas y las instrucciones. 
El algoritmo debe tener en cuenta el número de elementos a ordenar y la complejidad para minimizar el número de pasos para ordenar la lista.
Los movimientos permitidos:

```swap
`sa`    Intercambia 1º y 2º elemento        		pila `A`
`sb`    Intercambia 1º y 2º elemento       			pila `B`
`ss`    Intercambia 1º y 2º elemento       		 	pila `A` y `B` al mismo tiempo
```push
`pa`    Mueve       1º elemento         	  	  	pila `B` a la pila `A`
`pb`    Mueve       1º elemento         	    	pila `A` a la pila `B`
```rotate
`ra`    Rota        1º elemento al final    		pila `A`
`rb`    Rota        1º elemento al final    		pila `B`
`rr`    Rota        1º elemento al final    		pila `A` y `B` al mismo tiempo
```reverse rotate
`rra`    Rota        ultimo elemento al principio    pila `A`
`rrb`    Rota        ultimo elemento al principio 	pila `B`
`rrr`    Rota        ultimo elemento al principio 	pila `A` y `B` al mismo tiempo

La proyecto contiene:
*	`Pila A` 	Donde se ralizan la mayoria de las operaciones.
*	`Pila B`	Se usa como espacio temporal para almacenar los elementos mientras se realizan operaciones en la pila A. El objetivo es mover los elementos de la pila A a la pila B en orden ascendente.

### Archivos

* `1. push_swap.c`	Contendrá la lógica principal del programa. Aquí se implementa el algoritma de clasificación y se maneja la `entrada` y la `salida`.
* `2. push_swap.h`	Encabezado con las declaraciones de las funciones y estructuras.
* `3. stack.c`		Funciones relacionadas con la manipulación de la pila, inicialización, agregar elementos, quitar elementos y verificar si está vacía o llena.
* `4. operations.c`	Implementación de los movimientos permitidos en las pilas: swap, push, rotate y reverse rotate. 
* `5. sorting.c`	Implementación del algoritmo de clasificación. 
* `utils.c`			Funciones varias de utilidad: verificar si argumentos son válidos, generar números aleatorios para pruebas, imprimir pilas...
















