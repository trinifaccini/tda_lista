#include <stdio.h>
#include "lista.h"
#include "pa2m.h"

#define VACIA 0
#define ERROR -1
#define EXITO 0
#define MAX_1 6
#define MAX_2 4
#define FALSO 0
#define VERDADERO 1

bool mostrar_elemento(void* elemento, void* contador){
    if(elemento && contador)
        printf("  Elemento %i: %i \n", (*(int*)contador)++, *(char*)elemento);
    return true;
}


/**************** LISTA/COLA/PILA VACIA ****************/

void probar_lista_vacia(){

	lista_t* una_lista = lista_crear(); 

	pa2m_afirmar(lista_vacia(una_lista), "La lista se crea vacia");
	pa2m_afirmar(!lista_ultimo(una_lista), "El ultimo elemento en una lista vacia es NULL");
	pa2m_afirmar(!lista_elemento_en_posicion(una_lista, 4), "Un elemento cualquiera de una lista vacia es NULL");
	pa2m_afirmar(lista_elementos(una_lista) == 0, "La cantidad de elementos de una lista vacia es 0");
	pa2m_afirmar(lista_borrar(una_lista) == ERROR, "No es posible borrar al final en una lista vacia");
	pa2m_afirmar(lista_borrar_de_posicion(una_lista, 2) == ERROR, "No es posible borrar una posicion de una lista vacia");
	pa2m_afirmar(!lista_tope(una_lista), "EL tope en una pila vacia es NULL");
	pa2m_afirmar(lista_desapilar(una_lista) == ERROR, "No es posible desapilar en una pila vacia");
	pa2m_afirmar(lista_desencolar(una_lista) == ERROR, "No es posible desencolar en una cola vacia");
	pa2m_afirmar(!lista_primero(una_lista), "El primer elemento en una cola vacia es NULL");

	lista_iterador_t* iterador = lista_iterador_crear(una_lista);
	size_t contador = 0;
	pa2m_afirmar(iterador != NULL, "Es posible crear un iterador");
	pa2m_afirmar(!lista_iterador_tiene_siguiente(iterador), "No es posible iterar");
	pa2m_afirmar(!lista_iterador_avanzar(iterador), "No es posible avanzar");
	pa2m_afirmar(lista_con_cada_elemento(una_lista, NULL, (void*)&contador) == 0, "No esposible recorrer los elementos con el iterador interno si no recibe la funcion");
	pa2m_afirmar(lista_con_cada_elemento(una_lista, mostrar_elemento, (void*)&contador) == 0, "La cantidad de elementos recorridos con el iterador interno es de 0");

	lista_destruir(una_lista);
	lista_iterador_destruir(iterador);
}


/**************** LISTA/COLA/PILA NULA ****************/

void probar_lista_nula(){

	int un_numero = 10;
	size_t contador = 0;

	pa2m_afirmar(lista_vacia(NULL), "Una lista nula es una lista vacia");
	pa2m_afirmar(lista_elementos(NULL) == 0, "La cantidad de elementos de una lista nula es 0");
	
	pa2m_afirmar(!lista_primero(NULL), "El primer elemento de una lista nula es NULL");
	pa2m_afirmar(!lista_ultimo(NULL), "El ultimo elemento de una lista nula es NULL");
	pa2m_afirmar(!lista_elemento_en_posicion(NULL, 9), "Cualquier elemento de una lista nula es NULL");

	pa2m_afirmar(lista_insertar(NULL, &un_numero) == ERROR, "No es posible insertar al final en una lista nula");
	pa2m_afirmar(lista_insertar_en_posicion(NULL, &un_numero, 0) == ERROR, "No es posible insertar al inicio en una lista nula");
	pa2m_afirmar(lista_insertar_en_posicion(NULL, &un_numero, 3) == ERROR, "No es posible insertar en una posicion en una lista nula");

	pa2m_afirmar(lista_borrar(NULL) == ERROR, "No es posible borrar al final en una lista nula");
	pa2m_afirmar(lista_borrar_de_posicion(NULL, 0) == ERROR, "No es posible borrar al inicio en una lista nula");
	pa2m_afirmar(lista_borrar_de_posicion(NULL, 2) == ERROR, "No es posible borrar una posicion de una lista nula");

	pa2m_afirmar(!lista_tope(NULL), "EL tope en una pila nula es NULL");
	pa2m_afirmar(lista_desapilar(NULL) == ERROR, "No es posible desapilar en una pila nula");
	pa2m_afirmar(lista_desencolar(NULL) == ERROR, "No es posible desencolar en una cola vula");
	pa2m_afirmar(!lista_primero(NULL), "El primer elemento en una cola nula es NULL");

	lista_iterador_t* iterador = lista_iterador_crear(NULL);
	pa2m_afirmar(!iterador, "No es posible crear un iterador");
	pa2m_afirmar(!lista_iterador_tiene_siguiente(iterador), "No es posible iterar");
	pa2m_afirmar(!lista_iterador_avanzar(iterador), "No es posible avanzar");
	pa2m_afirmar(!lista_con_cada_elemento(NULL, mostrar_elemento, (void*)&contador), "No es posible iterar con cada elemento");

}


/**************** CREACION LISTA ****************/

void probar_creacion_lista(){ //NO ES REDUCIBLE, ES UNICA

	lista_t* una_lista = lista_crear(); 
	pa2m_afirmar(una_lista != NULL, "Puedo crear una lista");
	pa2m_afirmar(una_lista->nodo_inicio == NULL, "Nodo final se inicicializa apuntando a NULL");
	pa2m_afirmar(una_lista->nodo_fin == NULL, "Nodo final se inicicializa apuntando a NULL");
	pa2m_afirmar(una_lista->cantidad == 0, "La lista se crea vacia");
	lista_destruir(una_lista);
}

/**************** INSERCION FINAL ****************/

void probar_insercion_final_primero(){ //YA REDUCI LA DE INSERTAR VARIOS ELEMENTOS, ESTA ES UNICA

	int un_numero = 10;
	lista_t* una_lista = lista_crear(); 
	pa2m_afirmar(lista_insertar(una_lista, &un_numero) == EXITO, "Primer elemento insertado correctamente");
	pa2m_afirmar(lista_elementos(una_lista) == 1, "La cantidad de elementos es 1");
	pa2m_afirmar(una_lista->nodo_inicio->siguiente == NULL, "La lista se enlazo correctamente");
	pa2m_afirmar(una_lista->nodo_fin->siguiente == NULL, "La lista se enlazo correctamente");
	pa2m_afirmar(lista_elemento_en_posicion(una_lista, 0) == &un_numero && lista_ultimo(una_lista) == &un_numero, "El inicio y el fin de la lista apuntan al mismo elemento");
	lista_destruir(una_lista);

	//pa2m_afirmar(lista_elementos(una_lista) == 1 && lista_elementos(una_lista) == una_lista->cantidad, "La cantidad de elementos es 1");

}

void probar_insercion_final_dos(){ 

	int un_numero = 10;
	int otro_numero = 20;

	lista_t* una_lista = lista_crear();
	pa2m_afirmar(lista_insertar(una_lista, &un_numero) == EXITO, "Primer elemento insertado correctamente");
	pa2m_afirmar(lista_elementos(una_lista) == 1, "La cantidad de elementos es 1");
	pa2m_afirmar(lista_elemento_en_posicion(una_lista, 0) == &un_numero, "El primer elemento es correcto");
	pa2m_afirmar(lista_insertar(una_lista, &otro_numero) == EXITO, "Segundo y ultimo elemento insertado correctamente");
	pa2m_afirmar(lista_elementos(una_lista) == 2, "La cantidad de elementos es 2");
	pa2m_afirmar((lista_ultimo(una_lista) == &otro_numero) && lista_elemento_en_posicion(una_lista, 1) == &otro_numero, "El ultimo y segundo elemento coinciden");
	pa2m_afirmar(una_lista->nodo_inicio->siguiente->elemento == &otro_numero, "La lista se enlazo correctamente");
	pa2m_afirmar(una_lista->nodo_fin->siguiente == NULL, "La lista se enlazo correctamente");

	//pa2m_afirmar(lista_elemento_en_posicion(una_lista, 0) == &un_numero && lista_elemento_en_posicion(una_lista, 0) == lista->nodo_inicio , "El primer elemento es correcto");
	//pa2m_afirmar(lista_elementos(una_lista) == 2 && lista_elementos(una_lista) == una_lista->cantidad , "La cantidad de elementos es 2");


	lista_destruir(una_lista);
}


void probar_insercion_final_varios(){

	bool todos_insertados_correctamente = true;
	bool todos_enlazados_correctamente = true;

	int numeros[MAX_1]={1,2,3,4,5,6};
	int i = 0;
	lista_t* una_lista = lista_crear();

	while(todos_insertados_correctamente && i < MAX_1){

		if (lista_insertar(una_lista, &numeros[i]) != EXITO || una_lista->cantidad != i + 1){
        	todos_insertados_correctamente = false;
		}
		i++;
	}

    i = 0;
    nodo_t* nodo_actual = una_lista->nodo_inicio;

    while(todos_enlazados_correctamente && i < (MAX_1 - 1)){
    	if(nodo_actual->siguiente->elemento != &numeros[i + 1]){
    		todos_enlazados_correctamente = false;
    	}
    	nodo_actual = nodo_actual->siguiente;
    	i++;
    }
	
	if(una_lista->nodo_fin->siguiente != NULL) todos_enlazados_correctamente = false;

	pa2m_afirmar(todos_insertados_correctamente && todos_enlazados_correctamente, "Todos los elementos fueron insertados y enlazados correctamente");
	pa2m_afirmar(lista_elementos(una_lista) == 6, "La cantidad de elementos es 6");

	lista_destruir(una_lista);
}


/**************** INSERCION EN POSICION ****************/

void probar_insercion_en_pos_inicio(){ // NO ES REDUCIBLE, ES UNICA

	bool todos_insertados_correctamente = true;
	int primer_numero = 0;
	int numeros[MAX_1]={1,2,3,4,5,6};
	lista_t* una_lista = lista_crear();

	pa2m_afirmar(lista_vacia(una_lista), "Al inicio, la lista se encuentra vacia");

	for (int i = 0; i < MAX_1; i++){
		if(lista_insertar_en_posicion(una_lista, &numeros[i], 0) == ERROR) todos_insertados_correctamente = false;
	}

	pa2m_afirmar(lista_elementos(una_lista) == MAX_1 && todos_insertados_correctamente, "La cantidad de elementos insertados es de 6");
	pa2m_afirmar(lista_insertar_en_posicion(una_lista, &primer_numero, 0) == EXITO, "Pude insertar un elemento al inicio de la lista");
	pa2m_afirmar(lista_elemento_en_posicion(una_lista, 0) == &primer_numero, "El elemento se inserto correctamente");
	pa2m_afirmar(una_lista->nodo_inicio->siguiente->elemento == &numeros[MAX_1-1], "Se enlazo correctamente a la lista");
	pa2m_afirmar(lista_elementos(una_lista) == 7, "La cantidad de elementos es 7");

	lista_destruir(una_lista);

	//pa2m_afirmar(lista_elemento_en_posicion(una_lista, 0) == &primer_numero && lista_elemento_en_posicion(una_lista) == lista->nodo_inicio->elemento, "El elemento se inserto correctamente");
	//pa2m_afirmar(lista_elementos(una_lista) == 7 && lista_elementos(una_lista) == una_lista->cantidad, "La cantidad de elementos es 7");
}


void probar_insercion_en_pos_media(){ // NO ES REDUCIBLE, ES UNICA

	bool todos_enlazados_correctamente = true;
	bool todos_insertados_correctamente = true;
	int primer_numero = 0;
	int numeros[MAX_2]={1,2,3,4};
	lista_t* una_lista = lista_crear();

	pa2m_afirmar(lista_vacia(una_lista), "Al inicio, la lista se encuentra vacia");

	for (int i = 0; i < MAX_2; i++){
		if(lista_insertar(una_lista, &numeros[i]) == ERROR) todos_insertados_correctamente = false;
	}

	pa2m_afirmar(lista_elementos(una_lista) == MAX_2 && todos_insertados_correctamente, "La cantidad de elementos insertados es de 4");
	pa2m_afirmar(lista_insertar_en_posicion(una_lista, &primer_numero, 3) == EXITO, "Pude insertar un elemento en la cuarta posicion");
	pa2m_afirmar(lista_elementos(una_lista) == 5, "La cantidad de elementos es 5");
	if(lista_elemento_en_posicion(una_lista, 0) != &numeros[0])    todos_enlazados_correctamente = false;
	if(lista_elemento_en_posicion(una_lista, 1) != &numeros[1])    todos_enlazados_correctamente = false;
	if(lista_elemento_en_posicion(una_lista, 2) != &numeros[2])    todos_enlazados_correctamente = false;
	if(lista_elemento_en_posicion(una_lista, 3) != &primer_numero) todos_enlazados_correctamente = false;
	if(lista_elemento_en_posicion(una_lista, 4) != &numeros[3] || lista_ultimo(una_lista) != &numeros[3]) todos_enlazados_correctamente = false;
	if(una_lista->nodo_fin->siguiente != NULL) todos_enlazados_correctamente = false;

	pa2m_afirmar(todos_enlazados_correctamente, "Todos los elementos fueron enlazados correctamente");

	lista_destruir(una_lista);

	//pa2m_afirmar(lista_elementos(una_lista) == 5 && lista_elementos(una_lista) == una_lista->cantidad, "La cantidad de elementos es 5");
}


void probar_insercion_en_pos_final(){ // NO ES REDUCIBLE, ES UNICA

	int ultimo_numero = 0;
	int numeros[MAX_1]={1,2,3,4,5,6};
	lista_t* una_lista = lista_crear();

	for (int i = 0; i < MAX_1; i++){
		lista_insertar(una_lista, &numeros[i]);
	}

	pa2m_afirmar(lista_insertar_en_posicion(una_lista, &ultimo_numero, 40) == EXITO, "Pude insertar un elemento al final de la lista");
	pa2m_afirmar(lista_ultimo(una_lista) == &ultimo_numero, "El elemento se inserto correctamente");
	pa2m_afirmar(una_lista->nodo_fin->siguiente == NULL, "El elemento se enlazo correctamente");
	pa2m_afirmar(lista_elementos(una_lista) == 7, "La cantidad de elementos es 7");

	lista_destruir(una_lista);

	//pa2m_afirmar(lista_ultimo(una_lista) == &ultimo_numero && lista_ultimo(una_lista) == una_lista->nodo_fin->elemento, "El elemento se inserto correctamente");
	//pa2m_afirmar(lista_elementos(una_lista) == 7 && lista_elementos(una_lista) == una_lista->cantidad, "La cantidad de elementos es 7");
}

/**************** ELIMINACION FINAL ****************/

void probar_eliminacion_final(){ //REDUCIBLE CON DESAPILAR 

	int numeros[MAX_1]={1,2,3,4,5,6};
	lista_t* una_lista = lista_crear();

	for (int i = 0; i < MAX_1; i++){
		lista_insertar(una_lista, &numeros[i]);
	}

	pa2m_afirmar(lista_borrar(una_lista) == EXITO, "Pude borrar el ultimo elemento");
	pa2m_afirmar(lista_elementos(una_lista) ==  MAX_1-1, "La cantidad de elementos es 5");
	pa2m_afirmar(lista_ultimo(una_lista) == &numeros[MAX_1-2], "La re-asignacion se realizo correctamente");
	lista_destruir(una_lista);
}


void probar_eliminacion_final_unico_elemento(){ // NO ES REDUCIBLE, ES UNICA

	int un_numero = 10;
	lista_t* una_lista = lista_crear(); 
	lista_insertar(una_lista, &un_numero);
	pa2m_afirmar(lista_borrar(una_lista) == EXITO, "Puedo borrar al final el unico elemento de la lista");
	pa2m_afirmar(lista_vacia(una_lista), "La lista quedo vacia y el elemento se borro correctamente"); //en este mismo compruebo que tenga 0 elementos y que nodo fin y nodo inicio apunten a NULL
	lista_destruir(una_lista);
}

/**************** ELIMINACION DE POSICION ****************/

void probar_eliminacion_pos_inicio(){ //NO REDUCIBLE CON DESENCOLAR PORQUE ESTA RECIBE DOS PARAMETROS

	int numeros[MAX_1]={1,2,3,4,5,6};
	lista_t* una_lista = lista_crear();

	for (int i = 0; i < MAX_1; i++){
		lista_insertar(una_lista, &numeros[i]);
	}

	pa2m_afirmar(lista_borrar_de_posicion(una_lista, 0) == EXITO, "Pude eliminar el primer elemento de la lista");
	pa2m_afirmar(lista_elemento_en_posicion(una_lista, 0) == &numeros[1], "El inicio de la lista se re-asigno correctamente");
	pa2m_afirmar(lista_elementos(una_lista) == (MAX_1-1), "La cantidad de elementos es 5");
	lista_destruir(una_lista);

	//pa2m_afirmar(lista_elemento_en_posicion(una_lista, 0) == &numeros[1] && lista_elemento_en_posicion(una_lista, 0) == una_lista->nodo_inicio->elemento, "El inicio de la lista se re-asigno correctamente");

}


void probar_eliminacion_pos_media(){ // NO ES REDUCIBLE, ES UNICA

	bool todos_enlazados_correctamente = true;
	int numeros[MAX_2]={1,2,3,4};
	lista_t* una_lista = lista_crear();

	for (int i = 0; i < MAX_2; i++){
		lista_insertar(una_lista, &numeros[i]);
	}

	pa2m_afirmar(lista_borrar_de_posicion(una_lista, 2) == EXITO, "Pude eliminar el tercer elemento de la lista");

	if(lista_elemento_en_posicion(una_lista, 0) != &numeros[0]) todos_enlazados_correctamente = false;
	if(lista_elemento_en_posicion(una_lista, 1) != &numeros[1]) todos_enlazados_correctamente = false;
	if(lista_elemento_en_posicion(una_lista, 2) != &numeros[3]) todos_enlazados_correctamente = false;

	pa2m_afirmar(lista_elementos(una_lista) == (MAX_2-1), "La cantidad de elementos es 3");
	pa2m_afirmar(todos_enlazados_correctamente, "Todos los elementos fueron re-enlazados correctamente");
	lista_destruir(una_lista);

	//pa2m_afirmar(lista_elementos(una_lista) == (MAX_2-1) && lista_elementos(una_lista) == una_lista->cantidad , "La cantidad de elementos es 3");

}


void probar_eliminacion_pos_final(){ // NO ES REDUCIBLE, ES UNICA

	int numeros[MAX_1]={1,2,3,4,5,6};
	lista_t* una_lista = lista_crear();

	for (int i = 0; i < MAX_1; i++){
		lista_insertar(una_lista, &numeros[i]);
	}

	pa2m_afirmar(lista_borrar_de_posicion(una_lista, 40) == EXITO, "Pude eliminar el elemento al final de la lista");
	pa2m_afirmar(lista_ultimo(una_lista) == &numeros[MAX_1-2], "El final de la lista se re-asigno correctamente");
	pa2m_afirmar(lista_elementos(una_lista) == (MAX_1-1), "La cantidad de elementos es 5");
	lista_destruir(una_lista);

	//pa2m_afirmar(lista_ultimo(una_lista) == &numeros[MAX_1-2] && lista_ultimo(una_lista) == una_lista->nodo_fin->elemento  , "El final de la lista se re-asigno correctamente");
	//pa2m_afirmar(lista_elementos(una_lista) == (MAX_1-1) && lista_elementos(una_lista) == una_lista->cantidad , "La cantidad de elementos es 5");
}


void probar_eliminacion_en_pos_unico_elemento(){ // NO ES REDUCIBLE, ES UNICA

	int un_numero = 10;
	lista_t* una_lista = lista_crear(); 
	lista_insertar(una_lista, &un_numero);
	lista_borrar_de_posicion(una_lista, 9);
	pa2m_afirmar(lista_elemento_en_posicion(una_lista, 0) == NULL && lista_ultimo(una_lista) == NULL, "El unico elemento de la lista se borro correctamente");
	pa2m_afirmar(lista_vacia(una_lista), "La lista quedo vacia");
	lista_destruir(una_lista);
}

/**************** PRUEBAS PILA ****************/


void probar_funciones_pila(){
	
	bool todos_apilados_correctamente = true;

	int numeros[MAX_1]={1,2,3,4,5,6};
	int i = 0;
	lista_t* una_pila = lista_crear();

	pa2m_afirmar(lista_elementos(una_pila) == VACIA, "Luego de crearsee, la pila tiene 0 elementos");

	while(todos_apilados_correctamente && i < MAX_1){

		if (lista_apilar(una_pila, &numeros[i]) != EXITO || lista_elementos(una_pila) != i + 1){
        	todos_apilados_correctamente = false;
		}
		i++;
	}

	pa2m_afirmar(todos_apilados_correctamente, "Pude apilar todos los elementos");
	pa2m_afirmar(lista_elementos(una_pila) == MAX_1, "La pila tiene 6 elementos");
	pa2m_afirmar(lista_tope(una_pila) == &numeros[MAX_1-1], "El elemento en el tope de la pila es correcto");
	pa2m_afirmar(lista_desapilar(una_pila) == EXITO, "Pude desapilar");
	pa2m_afirmar(lista_elementos(una_pila) == MAX_1-1, "La pila tiene 5 elementos");
	pa2m_afirmar(lista_tope(una_pila) == &numeros[MAX_1-2], "El elemento en el tope de la pila es correcto");
	pa2m_afirmar(lista_desapilar(una_pila) == EXITO, "Pude desapilar");
	pa2m_afirmar(lista_elementos(una_pila) == MAX_1-2, "La pila tiene 4 elementos");
	pa2m_afirmar(lista_tope(una_pila) == &numeros[MAX_1-3], "El elemento en el tope de la pila es correcto");
	pa2m_afirmar(lista_desapilar(una_pila) == EXITO, "Pude desapilar");
	pa2m_afirmar(lista_elementos(una_pila) == MAX_1-3, "La pila tiene 3 elementos");
	pa2m_afirmar(lista_tope(una_pila) == &numeros[MAX_1-4], "El elemento en el tope de la pila es correcto");
	pa2m_afirmar(lista_desapilar(una_pila) == EXITO, "Pude desapilar");
	pa2m_afirmar(lista_elementos(una_pila) == MAX_1-4, "La pila tiene 2 elementos");
	pa2m_afirmar(lista_tope(una_pila) == &numeros[MAX_1-5], "El elemento en el tope de la pila es correcto");
	pa2m_afirmar(lista_desapilar(una_pila) == EXITO, "Pude desapilar");
	pa2m_afirmar(lista_elementos(una_pila) == MAX_1-5, "La pila tiene 1 elemento");
	pa2m_afirmar(lista_tope(una_pila) == &numeros[0], "El elemento en el tope de la pila es correcto");
	pa2m_afirmar(lista_desapilar(una_pila) == EXITO, "Pude desapilar");
	pa2m_afirmar(lista_elementos(una_pila) == VACIA, "La pila se encuentra vacia");
	pa2m_afirmar(lista_tope(una_pila) == NULL, "El elemento en el tope de la pila es NULL");

	lista_destruir(una_pila);
}


/**************** PRUEBAS COLA ****************/
void probar_funciones_cola(){
	
	bool todos_encolados_correctamente = true;

	int numeros[MAX_1]={1,2,3,4,5,6};
	int i = 0;
	lista_t* una_cola = lista_crear();

	pa2m_afirmar(lista_elementos(una_cola) == VACIA, "Luego de crearsee, la cola tiene 0 elementos");

	while(todos_encolados_correctamente && i < MAX_1){

		if (lista_encolar(una_cola, &numeros[i]) != EXITO || lista_elementos(una_cola) != i + 1){
        	todos_encolados_correctamente = false;
		}
		i++;
	}

	pa2m_afirmar(todos_encolados_correctamente, "Pude apilar todos los elementos");
	pa2m_afirmar(lista_elementos(una_cola) == MAX_1, "La cola tiene 6 elementos");
	pa2m_afirmar(lista_primero(una_cola) == &numeros[0], "El primer elemento de la cola es correcto");
	pa2m_afirmar(lista_desencolar(una_cola) == EXITO, "Pude desacolar");
	pa2m_afirmar(lista_elementos(una_cola) == MAX_1-1, "La cola tiene 5 elementos");
	pa2m_afirmar(lista_primero(una_cola) == &numeros[1], "El primer elemento de la cola es correcto");
	pa2m_afirmar(lista_desencolar(una_cola) == EXITO, "Pude desacolar");
	pa2m_afirmar(lista_elementos(una_cola) == MAX_1-2, "La cola tiene 4 elementos");
	pa2m_afirmar(lista_primero(una_cola) == &numeros[2], "El primer elemento de la cola es correcto");
	pa2m_afirmar(lista_desencolar(una_cola) == EXITO, "Pude desacolar");
	pa2m_afirmar(lista_elementos(una_cola) == MAX_1-3, "La cola tiene 3 elementos");
	pa2m_afirmar(lista_primero(una_cola) == &numeros[3], "El primer elemento de la cola es correcto");
	pa2m_afirmar(lista_desencolar(una_cola) == EXITO, "Pude desacolar");
	pa2m_afirmar(lista_elementos(una_cola) == MAX_1-4, "La cola tiene 2 elementos");
	pa2m_afirmar(lista_primero(una_cola) == &numeros[4], "El primer elemento de la cola es correcto");
	pa2m_afirmar(lista_desencolar(una_cola) == EXITO, "Pude desacolar");
	pa2m_afirmar(lista_elementos(una_cola) == MAX_1-5, "La cola tiene 1 elemento");
	pa2m_afirmar(lista_primero(una_cola) == &numeros[5], "El primer elemento de la cola es correcto");
	pa2m_afirmar(lista_desencolar(una_cola) == EXITO, "Pude desacolar");
	pa2m_afirmar(lista_elementos(una_cola) == VACIA, "La cola se encuentra vacia");
	pa2m_afirmar(lista_primero(una_cola) == NULL, "El primer elemento de la cola es NULL");

	lista_destruir(una_cola);
}

/**************** PRUEBAS ITERADORES ****************/

void probar_iteradores_lista_un_elemento(){

	int contador = 0;
	int un_numero = 10;
	lista_t* una_lista = lista_crear(); 

	pa2m_afirmar(lista_insertar(una_lista, &un_numero) == EXITO, "Primer elemento insertado correctamente");
	lista_iterador_t * iterador = lista_iterador_crear(una_lista);
	pa2m_afirmar(iterador != NULL, "Puedo crear un iterador cuando la lista contiene solo un elemento");
	pa2m_afirmar(lista_iterador_tiene_siguiente(iterador) == true, "Puedo iterar sobre el elemento");
	pa2m_afirmar(lista_iterador_elemento_actual(iterador) == &un_numero, "El elemento actual es correcto");
	pa2m_afirmar(lista_iterador_avanzar(iterador) == false, "EL iterador no tiene siguiente");
	pa2m_afirmar(lista_con_cada_elemento(una_lista, mostrar_elemento, (void*)&contador) == 1, "La cantidad de elementos recorridos con el iterador interno es de 1");

	lista_destruir(una_lista);
	lista_iterador_destruir(iterador);
}

void probar_iteradores_lista_varios_elementos(){

	int i = 0;
	int contador = 0;
	bool pudo_avanzar = true;
	int numeros[MAX_1]={1,2,3,4,5,6};
	lista_t* una_lista = lista_crear();

	for (int i = 0; i < MAX_1; i++){
		lista_insertar(una_lista, &numeros[i]);
	}

	lista_iterador_t * iterador = lista_iterador_crear(una_lista);
	pa2m_afirmar(iterador != NULL, "Puedo crear un iterador cuando la lista contiene varios elementos");
	pa2m_afirmar(lista_iterador_elemento_actual(iterador) == &numeros[0], "El elemento actual (que es el inicial) es correcto");

	while (i < una_lista->cantidad){
		if(lista_iterador_tiene_siguiente(iterador) == false) pudo_avanzar = false;
		i++;
	}

	pa2m_afirmar(pudo_avanzar, "Pudo iterar sobre todos los elementos");
	pa2m_afirmar(lista_con_cada_elemento(una_lista, mostrar_elemento, (void*)&contador) == MAX_1, "La cantidad de elementos recorridos es de 6");
	lista_destruir(una_lista);
	lista_iterador_destruir(iterador);
}

/*********************************************************************************************************/


int main(){

	pa2m_nuevo_grupo("PRUEBAS CREACION LISTA");
	probar_creacion_lista();

	pa2m_nuevo_grupo("PRUEBAS EN LISTA VACIA");
	probar_lista_vacia();

	pa2m_nuevo_grupo("PRUEBAS EN LISTA NULA");
	probar_lista_nula();

	pa2m_nuevo_grupo("PRUEBAS INSERCION FINAL");
	printf("UN ELEMENTO\n");
	probar_insercion_final_primero();
	printf("\nDOS ELEMENTOS\n");
	probar_insercion_final_dos();
	printf("\nVARIOS ELEMENTOS\n");
	probar_insercion_final_varios();

	pa2m_nuevo_grupo("PRUEBAS INSERCION EN POSICION");
	printf("AL INICIO\n");
	probar_insercion_en_pos_inicio();
	printf("\nEN POSICION MEDIA\n");
	probar_insercion_en_pos_media();
	printf("\nAL FINAL\n");
	probar_insercion_en_pos_final();

	pa2m_nuevo_grupo("PRUEBAS ELIMINACION FINAL");
	printf("Eliminar ultimo elemento de una lista que contiene varios elementos\n");
	probar_eliminacion_final();
	printf("\nEliminar el unico elemento de la lista\n");
	probar_eliminacion_final_unico_elemento();

	pa2m_nuevo_grupo("PRUEBAS ELIMINACION DE POSICION");
	printf("AL INICIO\n");
	probar_eliminacion_pos_inicio();
	printf("\nEN POSICION MEDIA\n");
	probar_eliminacion_pos_media();
	printf("\nAL FINAL\n");
	probar_eliminacion_pos_final();
	printf("\nEliminar el unico elemento de la lista\n");
	probar_eliminacion_en_pos_unico_elemento();

	pa2m_nuevo_grupo("PRUEBAS OPERACIONES PILA");
	probar_funciones_pila();

	pa2m_nuevo_grupo("PRUEBAS OPERACIONES COLA");
	probar_funciones_cola();

	pa2m_nuevo_grupo("PRUEBAS ITERADORES");
	printf("\nCon lista que contiene un solo elemento\n");
	probar_iteradores_lista_un_elemento();
	printf("\nCon lista que contiene varios elementos\n");
	probar_iteradores_lista_varios_elementos();

	return 0;
}
