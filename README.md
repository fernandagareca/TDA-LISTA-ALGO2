<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# NOMBRE TP/TDA

## Repositorio de marianela fernanda gareca janko - 109606 - fernanda.gareca321@gmail.com

- Para compilar:

```bash
make pruebas_chanutron
```

- Para ejecutar:

```bash
./pruebas_chanutron
```

- Para ejecutar con valgrind:
```bash
make valgrind-chanutron
```
---
##  Funcionamiento
El trabajo consiste en un TDA elaborado con nodos enlazados que pueden almacenar elementos de cualquier tipo y permiten aumentar la cantidad de elementos en la lista cada vez que se necesite sin la desventaja de tener que redimensionar todos los elementos como lo sería con un vector dinámico.
__________________________________________________________________________________________________________________________________


##  Estructuras:


En la estructura de lista agregué un punteo al último nodo para no tener que recorrer buscando la última posición ya sea para obtener o insertar al final de la lista y que la complejidad pase de o(n) a o(1), también agregue un campo para tener la cantidad de elementos en la lista.

```c
struct lista {
	nodo_t *nodo_inicio;
	nodo_t *nodo_final;
	size_t cantidad;
};

En la estructura del iterador agrege un campo para un puntero a la lista que es lo que se va a iterar y un puntero al nodo actual por ser una lista de nodos enlazados.


struct lista_iterador {
	nodo_t *nodo_actual;
	lista_t *lista;
};

```

En el archivo `lista.c` la función `lista_crear` utiliza `calloc` para inicializar un puntero a una lista en el heap,
la cual tiene un puntero al primer nodo y uno para el ultimo, más un campo para guardar la cantidad actual de elementos en la lista. En la función `lista_insertar` se reserva memoria para un nodo en el heap el cual contiene un campo para el elemento recibido y un puntero al siguiente nodo que será inicializado en `NULL` momentáneamente hasta que se inserte otro nodo actualizando el puntero al último nodo y aumentando la cantidad de elementos en la lista.

```c
/* EN LA FUNCION LISTA INSERTAR  */

    nodo_t *nodo_nuevo = calloc(1, sizeof(nodo_t));
	if (nodo_nuevo == NULL)
		return NULL;

	nodo_nuevo->elemento = elemento;

	if (lista_vacia(lista)) {
		lista->nodo_inicio = nodo_nuevo;
	} else {
		lista->nodo_final->siguiente = nodo_nuevo;
	}
	lista->nodo_final = nodo_nuevo;
    lista->cantidad++;
```
En la funcion `lista_iterador_crear` se reserva memoria en el heap para un iterador el cual tiene un puntero a la lista y un puntero al nodo actual de la lista que se inicializa con el primer nodo. 

```c
// EN LA FUNCION LISTA ITERADOR CREAR

lista_iterador_t *iterador = malloc(sizeof(lista_iterador_t));
	if (!iterador)
		return NULL;

	iterador->nodo_actual = lista->nodo_inicio;
	iterador->lista = lista;

```


<div align="center">
<img width="70%" src="img/diagrama de memoria de lista.jpeg">
</div>

En el archivo `pila.c` en  la funcion `pila_crear` se crea un puntero a una pila en el stack que apunta a una pila en el heap,la cual tiene un campo que apunta al primer elemento de la pila que es donde se van a apilar mas elementos  y posterioremente se desapilaran por el mismo lugar.

<div align="center">
<img width="70%" src="img/diagrama de memoria de pila.jpeg">
</div>

En el archivo `cola.c` en la función `cola_crear` se crea un puntero a una cola en el stack la cual apunta a una cola en el heap, la cual tiene un puntero al último nodo que es donde se irá encolando más nodos tambien tiene un puntero al primer nodo que es donde se ira desencolando los nodos.

<div align="center">
<img width="70%" src="img/diagrama de memoria de cola.jpeg">
</div>



---

## Respuestas a las preguntas teóricas
Incluír acá las respuestas a las preguntas del enunciado (si aplica).

## DIAGRAMA DE LISTA

<div align="center">
<img width="70%" src="img/diagrama de lista.jpeg">
</div>

## DIAGRAMA DE COLA

<div align="center">
<img width="70%" src="img/diagrama de cola.jpeg">
</div>

## DIAGRAMA DE PILA


<div align="center">
<img width="70%" src="img/diagrama de pila.jpeg">
</div>

## TABLA DE COMPLEJIDADES EN UNA LISTA

<div align="center">
<img width="70%" src="img/tabla de complejidades.jpeg">
</div>


## COMPLEJIDAD DE LAS OPERACIONES DE COLA

        CREAR COLA:  es O(1).
        COLA ENCOLAR: es O(1),ya que tenemos un puntero al ultimo elemento y podemos encolar en esa posicion sin tener que buscarla.
        COLA DESENCOLAR: es O(1) ya que tenemos que desencolar en la primera posicion y siempre sera una iteracion.
        COLA FRENTE:es O(1), ya que tenemos un puntero al primer elementos de la cola y a su informacion.
        COLA DETRUIR:es O(n), ya que tenemos que ir destruyendo cada elemento desde el comienzo de la cola.
        COLA VACIO:es O(1),ya que tenemos un campo en la cola que nos indica la cantidad de elementos o 0 es el caso de estar vacio.
        COLA TAMAÑO:es O(1),ya que hay un campo que indica la cantidad de elementos en la cola.


## COMPLEJIDAD DE LAS OPERACIONES DE PILA

        CREAR PILA: ES O(1),ya que hago un calloc.
        PILA APILAR: Es O(1) ya que apilamos siempre en la primera posicion.
        PILA DESAPILAR: Es O(1),ya que desapilamos siempre en la primera posicon donde se encuentra el ultimo elemento apilado.
        PILA TOPE : Es O(1),ya que hay un puntero al primer nodo de la cola.
        PILA DETRUIR: Es O(n) ya que avanzamos desde el ultimo elemento apilado, desapilando los demas.
        PILA VACIO: Es O(1),ya que tenemos un campo en la pila que nos indica la cantidad de elementos o 0 es el caso de estar vacio..
        PILA TAMAÑO: Es o(1), ya que tenemos un campo en pila que nos indica la cantidad de elementos en la pila.