#include "pila.h"
#include "lista.h"
#include <stdio.h>

pila_t *pila_crear()
{
	lista_t *lista = lista_crear();
	pila_t *pila = (pila_t *)lista;

	return pila;
}

pila_t *pila_apilar(pila_t *pila, void *elemento)
{
	lista_t *lista =
		lista_insertar_en_posicion((lista_t *)pila, elemento, 0);
	pila = (pila_t *)lista;
	return pila;
}

void *pila_desapilar(pila_t *pila)
{
	return lista_quitar_de_posicion((lista_t *)pila, 0);
}

void *pila_tope(pila_t *pila)
{
	return lista_primero((lista_t *)pila);
}

size_t pila_tamanio(pila_t *pila)
{
	return lista_tamanio((lista_t *)pila);
}

bool pila_vacia(pila_t *pila)
{
	return lista_vacia((lista_t *)pila);
}

void pila_destruir(pila_t *pila)
{
	lista_destruir((lista_t *)pila);
}
