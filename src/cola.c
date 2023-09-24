#include "cola.h"
#include "lista.h"


typedef struct nodo {
	void *elemento;
	struct nodo *siguiente;
} nodo_t;

struct lista {
	nodo_t *nodo_inicio;
	nodo_t *nodo_final;
	size_t cantidad;
};

cola_t *cola_crear()
{	
	lista_t* lista= calloc(1,sizeof(lista));
	cola_t* cola = (cola_t*)lista;

	return cola;
}

cola_t *cola_encolar(cola_t *cola, void *elemento)
{
	if(!cola)
		return NULL;
	lista_t* lista = lista_insertar((lista_t*)cola,elemento);
	cola = (cola_t*)lista;
	return cola;
}

void *cola_desencolar(cola_t *cola)
{
	if(!cola || cola_vacia(cola))
		return NULL;

	nodo_t* nodo_a_desencolar = ((lista_t*)cola)->nodo_inicio;
	void* elemento_buscado = cola_frente(cola);
	if(cola_tamanio(cola) == 1){
		free(nodo_a_desencolar);
		((lista_t*)cola)->nodo_final= NULL;
		((lista_t*)cola)->nodo_inicio= NULL;
		((lista_t*)cola)->cantidad--;
		return nodo_a_desencolar;
	}
	((lista_t*)cola)->nodo_inicio= nodo_a_desencolar->siguiente;
	free(nodo_a_desencolar);
	((lista_t*)cola)->cantidad--;

	return elemento_buscado;
}

void *cola_frente(cola_t *cola)
{
	
	return lista_primero((lista_t*)cola);
}

size_t cola_tamanio(cola_t *cola)
{
	return lista_tamanio((lista_t*)cola);
}

bool cola_vacia(cola_t *cola)
{
	return lista_vacia((lista_t*)cola);
}

void cola_destruir(cola_t *cola)
{
	lista_destruir((lista_t*)cola);
}
