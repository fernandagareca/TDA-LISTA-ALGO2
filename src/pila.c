#include "pila.h"
#include "lista.h"
#include <stdio.h>

typedef struct nodo {
	void *elemento;
	struct nodo *siguiente;
} nodo_t;

struct lista {
	nodo_t *nodo_inicio;
	nodo_t *nodo_final;
	size_t cantidad;
};
pila_t *pila_crear()
{
	lista_t* lista= lista_crear();
	pila_t* pila = (pila_t*)lista;

	return pila;

}

pila_t *pila_apilar(pila_t *pila, void *elemento)
{
	if(!pila)
		return NULL;


	nodo_t* nodo_nuevo = calloc(1,sizeof(nodo_t));
	if(!nodo_nuevo)
        return NULL;
	
	nodo_nuevo->elemento = elemento;
	if(pila_vacia(pila)){
		((lista_t*)pila)->nodo_final = nodo_nuevo;
		((lista_t*)pila)->nodo_inicio = nodo_nuevo;
		((lista_t*)pila)->cantidad++;
		return pila;
	}
	nodo_nuevo->siguiente = ((lista_t*)pila)->nodo_inicio;
	((lista_t*)pila)->nodo_inicio = nodo_nuevo;
	((lista_t*)pila)->cantidad++;
	
	return pila;
}

void *pila_desapilar(pila_t *pila)
{
	if(!pila || pila_vacia(pila))
		return NULL;


	nodo_t* nodo_nuevo = calloc(1,sizeof(nodo_t));
	if(!nodo_nuevo)
        return NULL;
	void* elemento_final;
	nodo_t* nodo_a_eliminar;
	elemento_final = ((lista_t*)pila)->nodo_inicio->elemento;

	if(pila_tamanio(pila) == 1){
		
		nodo_a_eliminar = ((lista_t*)pila)->nodo_final;
		free(nodo_a_eliminar);
		((lista_t*)pila)->nodo_inicio = NULL;
		((lista_t*)pila)->nodo_final = NULL;
		((lista_t*)pila)->cantidad--;
		return elemento_final;
	}
	nodo_a_eliminar = ((lista_t*)pila)->nodo_inicio;
	((lista_t*)pila)->nodo_inicio = nodo_a_eliminar->siguiente;
	free(nodo_a_eliminar);
	((lista_t*)pila)->cantidad--;

	return elemento_final;
}

void *pila_tope(pila_t *pila)
{
	return lista_primero((lista_t*)pila);
}

size_t pila_tamanio(pila_t *pila)
{

	return lista_tamanio((lista_t*)pila);
}

bool pila_vacia(pila_t *pila)
{
	return lista_vacia((lista_t*)pila);
}

void pila_destruir(pila_t *pila)
{
	lista_destruir((lista_t*)pila);
	
}
