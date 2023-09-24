#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include "pa2m.h"


typedef struct nodo {
	void *elemento;
	struct nodo *siguiente;
} nodo_t;

struct lista {
	nodo_t *nodo_inicio;
	nodo_t *nodo_final;
	size_t cantidad;
	
	
};

struct lista_iterador {
	
	nodo_t* nodo_actual;
	lista_t* lista;
};

void pruebas_de_crear_lista_recien_creada(){
	lista_t* lista = lista_crear();
	void* elemento = (void*)82433;

	pa2m_afirmar(lista != NULL,"lista creada no es null");
	pa2m_afirmar(lista_tamanio(lista) == 0,"lista recien creada tiene tamaño cero");
	pa2m_afirmar(lista_vacia(lista)== true,"lista recien creada esta vacia");
	pa2m_afirmar(lista_quitar(lista) == NULL,"no se puede quitar el ultimo elemento de la lista sin elementos");
	pa2m_afirmar(lista_quitar_de_posicion(lista,6) == NULL, "no es posible quitar elemento en posicion en una lista vacia");
	pa2m_afirmar(lista_elemento_en_posicion(lista,6) == NULL, "no es posible listar elemento en posicion en una lista vacia");
	pa2m_afirmar(lista_primero(lista) == NULL, "no es posible listar primer elemento en una lista vacia");
	pa2m_afirmar(lista_ultimo(lista) == NULL, "no es posible listar ultimo elemento en una lista vacia");
	pa2m_afirmar(lista_insertar_en_posicion(lista,elemento,0)== lista,"se inserto en la posicion 0");
	pa2m_afirmar(lista_elemento_en_posicion(lista,0) == elemento,"busco el elemento en la posicion 0 y lo encuentro");
	pa2m_afirmar(lista_insertar_en_posicion(lista,elemento,8)== lista,"no se puede insertar en la posicion 8 ,inserto al final");
	lista_destruir(lista);

}
void pruebas_en_una_lista_inexistente(){
	lista_t* lista = NULL;
	int elemento = 8;
	
	pa2m_afirmar(lista == NULL,"la lista no existe");
	pa2m_afirmar(lista_insertar(lista,&elemento) == NULL,"no se puede insertar al final  en una lista inexistente");
	pa2m_afirmar(lista_insertar_en_posicion(lista,&elemento,8)== NULL,"no se puede insertar en la posicion de una lista inexistente");
	pa2m_afirmar(lista_tamanio(lista) == 0,"lista inexistente tiene 0 elementos");
	pa2m_afirmar(lista_vacia(lista)== true,"lista que no existe esta vacia");
	pa2m_afirmar(lista_quitar(lista) == NULL,"no se puede quitar el ultimo elemento de una lista inexistente");
	pa2m_afirmar(lista_quitar_de_posicion(lista,6) == NULL, "no es posible quitar elemento en posicion en una lista inexistente");
	pa2m_afirmar(lista_elemento_en_posicion(lista,6) == NULL, "no es posible listar elemento en posicion en una lista inexistente");
	pa2m_afirmar(lista_primero(lista) == NULL, "no es posible listar primer elemento en una lista inexistente");
	pa2m_afirmar(lista_ultimo(lista) == NULL, "no es posible listar ultimo elemento en una lista inerxistente");

}
void cargar_lista(){
	
}
void pruebas_de_eliminacion(){
	lista_t* lista = lista_crear();
	void* elemento1 = (void*)30,*elemento2 = (void*)64,*elemento3 = (void*)54,*elemento4 = (void*)61,*elemento5 = (void*)20,*elemento6 = (void*)10,*elemento7 = (void*)90;

	lista_insertar(lista,elemento1);
	lista_insertar(lista,elemento2);
	lista_insertar(lista,elemento3);
	lista_insertar(lista,elemento4);
	lista_insertar(lista,elemento5);
	lista_insertar(lista,elemento6);
	lista_insertar(lista,elemento7);
    pa2m_afirmar(lista_tamanio(lista) == 7,"la lista es tamaño 7");
	pa2m_afirmar(lista_quitar_de_posicion(lista,0) == elemento1, "el elemento quitado de la posicon 0 es correcto");
	pa2m_afirmar(lista_quitar_de_posicion(lista,3) == elemento5, "el elemento quitado de la posicon 3 es correcto");
	pa2m_afirmar(lista_quitar_de_posicion(lista,6) == elemento7, "el elemento quitado de la posicon 6 es correcto");
    pa2m_afirmar(lista_tamanio(lista) == 4,"la lista es tamaño 4");
	pa2m_afirmar(lista_elemento_en_posicion(lista,0)== elemento2,"el elemento del inicio es correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista,1)== elemento3,"el elemento de la posicion 1 es correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista,2)== elemento4,"el elemento de la posicion 2  es correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista,3)== elemento6,"el elemento del final es correcto");
	

	lista_destruir(lista);

}
void prueba_de_insercion_lista(){
	lista_t* lista = lista_crear();
	void* elemento1 = (void*)61,*elemento2 = NULL,*elemento3 = (void*)87,*elemento4 = (void*)40,*elemento5 = (void*)30,*elemento6 = (void*)10,*elemento7 = (void*)80;
    
	pa2m_afirmar(lista_insertar(lista,elemento1)== lista,"insertar al final devuelve la lista");
	pa2m_afirmar(lista_tamanio(lista)==1,"lista aumenta tamaño a 1");
	pa2m_afirmar(lista_vacia(lista) == false,"la lista no esta vacia");

	pa2m_afirmar(lista_insertar_en_posicion(lista,elemento2,0)== lista,"insertar en la posicion 0 devuelve la lista");
	pa2m_afirmar(lista_tamanio(lista)==2,"lista aumenta tamaño a 2");

	pa2m_afirmar(lista_insertar_en_posicion(lista,elemento3,1)== lista,"insertar en la posicion 1 devuelve la lista");
	pa2m_afirmar(lista_tamanio(lista)==3,"lista aumenta tamaño a 3");

	pa2m_afirmar(lista_insertar_en_posicion(lista,elemento4,100)== lista,"insertar en la posicion 100 devuelve la lista");
	pa2m_afirmar(lista_tamanio(lista)==4,"lista aumenta tamaño a 4");

	pa2m_afirmar(lista_insertar_en_posicion(lista,elemento5,2)== lista,"insertar en la posicion 2 devuelve la lista");
	pa2m_afirmar(lista_tamanio(lista)==5,"lista aumenta tamaño a 5");

	pa2m_afirmar(lista_insertar_en_posicion(lista,elemento6,4)== lista,"insertar en la posicion 4 devuelve la lista");
	pa2m_afirmar(lista_tamanio(lista)==6,"lista aumenta tamaño a 6");

	pa2m_afirmar(lista_insertar_en_posicion(lista,elemento7,6)== lista,"insertar en la posicion 6 devuelve la lista");
	pa2m_afirmar(lista_tamanio(lista)==7,"lista aumenta tamaño a 7");

	pa2m_afirmar(lista_elemento_en_posicion(lista,0) == lista_primero(lista),"el primer elemento de la lista es correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista,0)== elemento2,"elemento en la posicion 0 es correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista,1)== elemento3,"elemento en la posicion 1 es correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista,2)== elemento5,"elemento en la posicion 2 es correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista,3)== elemento1,"elemento en la posicion 3 es correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista,4)== elemento6,"elemento en la posicion 4 es correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista,5)== elemento4,"elemento en la posicion 4 es correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista,6)== elemento7,"elemento en la posicion 4 es correcto");
	pa2m_afirmar(lista_elemento_en_posicion(lista,6) == lista_ultimo(lista),"el ultimo elemento de la lista es correcto");

	lista_destruir(lista);

}

int comparador(void* valor1, void* valor2){

	char* v1 = valor1;
	char* v2 = valor2;
	if(v1 == v2){
        return 0;
	}
	return -1;
}
void pruebas_de_busqueda_de_lista(){
	lista_t* lista =lista_crear();
	
	void* valor3 = (void*)4;
	void* valor4 = (void*)3;
	void* valor5 = (void*)100;
	
    lista_insertar(lista,valor3);
    lista_insertar(lista,valor4);
	pa2m_afirmar(lista_buscar_elemento(lista,comparador,valor3) == valor3,"el elemento buscado se encuentra en la lista");
	pa2m_afirmar(lista_buscar_elemento(lista,comparador,valor5) == NULL,"el elemento buscado no se encuentra en la lista");

	lista_destruir(lista);
}

void pruebas_lista_vacia(){
	lista_t* lista =lista_crear();
	void* nombre1 = (void*)1;

	pa2m_afirmar(lista_vacia(lista) == true,"la lista esta vacia");
	pa2m_afirmar(lista_tamanio(lista) == 0,"el tamaño es 0");
	pa2m_afirmar(lista_insertar_en_posicion(lista,nombre1,0) == lista,"se inserto en la posicion 0 devuelve la lista");
	pa2m_afirmar(lista_elemento_en_posicion(lista,0) == nombre1,"elemento insertado es correcto");
	lista_destruir(lista);
}

bool funcion(void* elemento1,void* elemento2){

	char* nombre = elemento1;
	if(nombre){
		return true;
	}

	return true;
}

void pruebas_de_iterador_externo(){
	lista_t* lista = lista_crear();
	char* elemento1 = "yaco";
	char* elemento2 = "mia";
	char* elemento3 = "lili";
	char* elemento4 = "sol";
	

	lista_insertar(lista,elemento1);
	lista_insertar(lista,elemento2);
	lista_insertar(lista,elemento3);
	lista_insertar(lista,elemento4);
	
	lista_iterador_t* iterador = lista_iterador_crear(lista);
	pa2m_afirmar(iterador != NULL,"iterador creado distinto de NULL");
	pa2m_afirmar(lista_con_cada_elemento(lista,funcion,elemento1) == lista_tamanio(lista),"se iteraron todos los elementos de la lista");
	
	lista_destruir(lista);
	lista_iterador_destruir(iterador);

}
void pruebas_iterdor_lista_vacia(){
	lista_t* lista = lista_crear();
	lista_iterador_t* iterador = lista_iterador_crear(lista);
	pa2m_afirmar(lista_iterador_tiene_siguiente(iterador) == false,"cuando la lista esta vacia el iterador devuelve false");
	pa2m_afirmar(lista_iterador_avanzar(iterador) == false,"cuanod la lista esta vacia avanzar devuelve false");
	pa2m_afirmar(lista_iterador_elemento_actual(iterador) == NULL,"cuando la lista esta vacia el elemento actual es null");
	lista_destruir(lista);
	lista_iterador_destruir(iterador);

}


void prueba_crear_pila(){

	void* elemento1 = (void*)61,*elemento2 = NULL,*elemento3 = (void*)87;
	pila_t* pila = pila_crear();
	pa2m_afirmar(pila  != NULL,"crear la lista devuelve la lista");
	pa2m_afirmar(pila_vacia(pila),"la pila esta vacia");
	pa2m_afirmar(pila_tamanio(pila)==0,"!la pila tiene tamaño 0");
	pa2m_afirmar(pila_apilar(pila,elemento1)== pila,"se apilo un elemento devuelve la pila");
	pa2m_afirmar(pila_vacia(pila)== false,"la pila no esta vacia");
	pa2m_afirmar(pila_tamanio(pila) == 1,"la pila tiene tamaño 1");
	pa2m_afirmar(pila_tope(pila)== elemento1,"el tope es correcto");

	pa2m_afirmar(pila_apilar(pila,elemento2)== pila,"se apilo un elemento devuelve la pila");
	pa2m_afirmar(pila_tamanio(pila) == 2,"la pila tiene tamaño 2");

	pa2m_afirmar(pila_apilar(pila,elemento3)== pila,"se apilo un elemento devuelve la pila");
	pa2m_afirmar(pila_tamanio(pila) == 3,"la pila tiene tamaño 1");
	pa2m_afirmar(pila_tope(pila)== elemento3,"el tope es correcto");



	pila_destruir(pila);
}

void pruebas_null_de_pila(){
	pila_t* pila = NULL;
	void* elemento = (void*)23;

	pa2m_afirmar(pila_apilar(pila,elemento) == NULL,"no se puede apilar sin una pila");
	pa2m_afirmar(pila_desapilar(pila) == NULL,"no se puede desapilar con una pila null");
	pa2m_afirmar(pila_tope(pila) == NULL,"el tope de un pila inexistente es null");
	pa2m_afirmar(pila_tamanio(pila) == 0,"el tamaño de una pila inexistente es 0");
	pa2m_afirmar(pila_vacia(pila) == true,"una pila inexistente esta vacia");
}

void pruebas_de_cola(){
	cola_t* cola = cola_crear();


	void* elemento1 = (void*)61, *elemento2 = NULL,*elemento3 = (void*)87;
	pa2m_afirmar(cola_vacia(cola)== true,"la cola esta vacia");
	pa2m_afirmar(cola_tamanio(cola)==0,"el tamaño de la cola es 0");
	pa2m_afirmar(cola_encolar(cola,elemento1)== cola,"encolar devuelve la lista");
	pa2m_afirmar(cola_vacia(cola)== false,"la cola no esta vacia");
	pa2m_afirmar(cola_tamanio(cola)==1,"el tamaño de la cola es 1");
	pa2m_afirmar(cola_desencolar(cola)  == elemento1,"desencolar devuelve el elemento");
	pa2m_afirmar(cola_vacia(cola)== true,"la cola vuelve a estar vacia");
	pa2m_afirmar(cola_tamanio(cola)==0,"el tamaño de la cola es 0 otra vez");

	pa2m_afirmar(cola_encolar(cola,elemento2)== cola,"se encolo un nuevo elemento devuelve la cola");
	pa2m_afirmar(cola_tamanio(cola)==1,"el tamaño de la cola es 1");
	pa2m_afirmar(cola_frente(cola)== elemento2,"el primer elemento es correcto");
	pa2m_afirmar(cola_encolar(cola,elemento3)== cola,"se encolo un nuevo elemento devuelve la cola");
	pa2m_afirmar(cola_tamanio(cola)==2,"el tamaño de la cola es 2");

	pa2m_afirmar(cola_frente(cola)== elemento2,"el primer elemento es correcto");
	pa2m_afirmar(cola_desencolar(cola)== elemento2,"se desencolo el primer elemento es correcto");
	pa2m_afirmar(cola_frente(cola)== elemento3,"el primer elemento es correcto");


	cola_destruir(cola);
}
void pruebas_null_de_cola(){
	cola_t* cola = NULL;
	void* elemento = (void*)23;
	pa2m_afirmar(cola_desencolar(cola)== NULL,"no se puede desencolar de una cola inexistente");
	pa2m_afirmar(cola_encolar(cola,elemento)== NULL,"no se puede encolar en una cola inexistente");
	pa2m_afirmar(cola_frente(cola) == NULL,"el frente de una cola inexistente es null");
	pa2m_afirmar(cola_tamanio(cola)==0,"el tamaño de una cola inexistente es 0");
	pa2m_afirmar(cola_vacia(cola)== true,"una cola null no esta vacia");

}
int main()
{
	pa2m_nuevo_grupo("------------------PRUEBAS DE LISTA-------------------------");

	pa2m_nuevo_grupo("PRUEBAS EN UNA LISTA VACIA");
	pruebas_lista_vacia();

	pruebas_de_crear_lista_recien_creada();
	pa2m_nuevo_grupo("PRUEBAS EN UNA LISTA ENEXISTENTE");
	pruebas_en_una_lista_inexistente();
	pa2m_nuevo_grupo("PRUEBAS DE ELIMINACIO");
	pruebas_de_eliminacion();
	pa2m_nuevo_grupo("PRUEBAS DE INSERCION");
    prueba_de_insercion_lista();
	pa2m_nuevo_grupo("PRUEBAS DE BUSQUEDA");
	pruebas_de_busqueda_de_lista();
	pa2m_nuevo_grupo("PRUEBAS DE ITERADOR EXTERNO");
	pruebas_de_iterador_externo();
	pruebas_iterdor_lista_vacia();

	pa2m_nuevo_grupo("------------------PRUEBAS DE PILA-------------------------");
	prueba_crear_pila();
	pruebas_null_de_pila();


	pa2m_nuevo_grupo("------------------PRUEBAS DE COLA-------------------------");
	pruebas_null_de_cola();
	pruebas_de_cola();



	return pa2m_mostrar_reporte();
}
