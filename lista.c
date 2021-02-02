#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define ERROR -1
#define EXITO 0
#define INICIO 0
#define VACIA 0


lista_t* lista_crear(){

	lista_t* mi_lista = malloc(sizeof(lista_t));
	
	if(!mi_lista) return NULL;

	mi_lista->nodo_inicio = NULL;
	mi_lista->nodo_fin = NULL;
	mi_lista->cantidad = VACIA;

	return mi_lista;
}


size_t lista_elementos(lista_t* lista){

	if(!lista) return VACIA;
	return lista->cantidad;
}


bool lista_vacia(lista_t* lista){
	return (!lista || (lista_elementos(lista) == VACIA && lista->nodo_inicio == NULL && lista->nodo_fin == NULL));
}


int lista_insertar(lista_t* lista, void* elemento){

	if (!lista) return ERROR;

	nodo_t* nodo_actual = malloc(sizeof(nodo_t));
	if(!nodo_actual) return ERROR;

	nodo_actual->elemento = elemento;
	nodo_actual->siguiente = NULL;

	if(lista_elementos(lista) == 0){
		lista->nodo_inicio = nodo_actual;	
	}
	
	else{
		lista->nodo_fin->siguiente = nodo_actual;
	} 

	lista->nodo_fin = nodo_actual; //este lo asigno aca porque en cualquier caso lo debo hacer
	lista->cantidad++;

	return EXITO;
}


/*
 * Recibe una lista valida no vacia, un puntero a un nodo valido de la lista, otro puntero al nodo que contiene el
 * elemento que debemos insertar, la posicion en la que se debe insertar a ese nodo y un entero correspondiente
 * a un contador.
 ! Estos dos ultimos determinan la condicion de corte de la funcion recursiva.
 * En el primer llamado nodo_actual apunta al nodo que contiene el primer elemento de la lista.
 *
 *
 * Se encargara de modificar la lista insertando el nodo en la posicion pedida.
 */
void nodo_insertar_posicion(lista_t* lista, nodo_t* nodo_actual, nodo_t* nodo_a_insertar, size_t posicion, size_t contador){

	/*El contador se inicializa en 0.
	nodo_acutal = lista->nodo_inicio
	nodo_a_insertar contiene al elemento que queremos insertar
	
	Ejemplo: tengo una lista con 6 elementos [A B C D E F]
			 la posicion que me pasan es la 3, con el elemento 6, es decir quiero que quede como [A-> B-> C-> 6-> D-> E-> F-> NULL], nodo_acutal->elemento = A
			 1ª: posicion - 1 = contador? (2 = 0) no, aumento el contador, hago la llamada recursiva donde nodo_acutal->elemento = B
			 2ª: posicion - 1 = contador? (2 = 1) no, aumento el contador, hago la llamada recursiva donde nodo_acutal->elemento = C
			 3ª: posicion - 1 = contador? (2 = 2) si, entro
			 	 nodo_a_insertar->siguiente = nodo_actual->siguiente (aca estoy haciendo apuntar al nodo_insertar al nodo que ahora va a ser su siguinete
			 	 													  hago apuntar al nodo que contiene al 6 al nodo que contiene a la letra D)

			 	 nodo_actual->siguiente = nodo_a_insertar            (aca estoy haciendo apuntar al nodo_actual al nodo que insertamos
			 	 													  hago apuntar al nodo que contiene a la letra C al nodo que contiene al 6)  
	*/

	if((posicion-1) == contador){ 
		nodo_a_insertar->siguiente = nodo_actual->siguiente;
		nodo_actual->siguiente = nodo_a_insertar;
		return;
	}

	contador++;
	nodo_insertar_posicion(lista, nodo_actual->siguiente, nodo_a_insertar, posicion, contador);
}


int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion){

	if(!lista) return ERROR;

	/*Si la lista tiene 0 elementos, es decir esta vacia, no importa la posicion que me pasen, el elemento va a ir al inicio (que en este caso tb es el final), llamamos a lista_insertar() para que lo haga.*/
	if(lista_elementos(lista) ==  0) return lista_insertar(lista, elemento);
	
	/*Si posicion recibida es mayor a la cantidad de elementos en la lista, signfica que la posicion no existe y el elemento va a ir al final, llamamos a lista_insertar() para que lo haga.*/
	if(posicion > (lista_elementos(lista) -1)) return lista_insertar(lista, elemento);
	
	/*En otro caso, el elemento va en una posicion existente*/

	nodo_t* nodo_a_insertar = malloc(sizeof(nodo_t));
	if(!nodo_a_insertar) return ERROR;

	nodo_a_insertar->elemento = elemento;
	nodo_a_insertar->siguiente = NULL;

	/*Caso en el que la posicion recibida sea 0 y el elemento deba ir al inicio de la lista*/
	if (posicion == INICIO){ 
		nodo_a_insertar->siguiente = lista->nodo_inicio;
		lista->nodo_inicio = nodo_a_insertar;
	}
	
	/*Caso en el que tenga que ir en cualquier otra posicion que no sea el inicio.*/
	else{
		size_t contador = 0;
		nodo_insertar_posicion(lista, lista->nodo_inicio, nodo_a_insertar, posicion, contador);
	}
	
	lista->cantidad++;
	return EXITO;
}


/*
 * Recibe una lista valida no vacia y un puntero a un nodo de esa lista. En el primer llamado
 * nodo_actual apunta al nodo que contiene el primer elemento de la lista.
 * 
 * Devuelve un puntero al anteultimo nodo de la lista, que sera el que tenga 
 * al nodo siguiente de su nodo sguiente apuntando a NULL (condicion de corte).
 */
nodo_t* nodo_ante_ultimo(lista_t* lista, nodo_t* nodo_actual){

	/*Aca estoy probando que si el siguiente del siguiente es NULL, significa que estoy parada en el anteultimo nodo
	Ejemplo: la lista tiene 4 nodos [0 1 2 3]
			 primero nodo_actual = primer_nodo,  pos 0 ----> el siguiente del siguiente, es el nodo 3. pos 2, diferente a NULL, 

			 entonces hago la llamada recursiva donde 
			 		 nodo_actual = segundo_nodo, pos 1 ----> el siguiente del siguiente, es el nodo 4. pos 3, diferente a NULL, 

			 entonces hago la llamada recursiva donde 
			 		 nodo_actual = tercer_nodo,  pos 2 ----> el siguiente del siguiente, es el nodo NULL. pos "5, no existente", IGUAL a NULL,
			 por lo tanto, no se hace otro llamado recursivo y el nodo que se devuelve es el nodo en la posicion 2 
	*/

	if(nodo_actual->siguiente->siguiente == NULL) return nodo_actual;
	return nodo_ante_ultimo(lista, nodo_actual->siguiente);
}


int lista_borrar(lista_t* lista){

	if(lista_vacia(lista)) return ERROR; 

	nodo_t* nodo_auxiliar = lista->nodo_fin; //si hay uno solo estaria apuntando a ese uico que hay porque si es uno solo nodo_fin y nodo_inicio 				                                                                                                              apuntan a lo mismo
	if(lista->cantidad == 1){
		lista->nodo_inicio = NULL;
		lista->nodo_fin = NULL;
	}

	else {
		lista->nodo_fin = nodo_ante_ultimo(lista, lista->nodo_inicio);
		lista->nodo_fin->siguiente = NULL;
	}

	free(nodo_auxiliar);
	lista->cantidad--;
	return EXITO;
}

/*
 * Recibe una lista valida no vacia, un puntero a un nodo valido de la lista, la posicion donde se encuenta el elemento
 * que se desea borrar y un entero que corresponde a un contador.
 ! Estos dos ultimos determinan la condicion de corte de la funcion recursiva.
 * En el primer llamado nodo_actual apunta al nodo que contiene el primer elemento de la lista.
 *
 *
 * Se encargara de modificar la lista borrando al nodo que contiene a ese elemento.
 */
void nodo_borrar_posicion(lista_t* lista, nodo_t* nodo_actual, size_t posicion, int contador){

	nodo_t* nodo_auxiliar = NULL;

	if((posicion-1) == contador){ 
		nodo_auxiliar = nodo_actual->siguiente;
		nodo_actual->siguiente = nodo_auxiliar->siguiente;
		free(nodo_auxiliar);
		return;
	}

	contador++;
	nodo_borrar_posicion(lista, nodo_actual->siguiente, posicion, contador);
}


int lista_borrar_de_posicion(lista_t* lista, size_t posicion){
	
	if(lista_vacia(lista)) return ERROR;

	if(lista_elementos(lista) == 0) return (lista_borrar(lista));

	if(posicion >= (lista_elementos(lista) - 1)) return (lista_borrar(lista));

	nodo_t* nodo_auxiliar = NULL;

	if(posicion == INICIO){ 
		nodo_auxiliar = lista->nodo_inicio->siguiente;
		free(lista->nodo_inicio);
		lista->nodo_inicio = nodo_auxiliar;
	}

	else{

		int contador = 0;
		nodo_borrar_posicion(lista, lista->nodo_inicio, posicion, contador);
	}

	lista->cantidad--;
	return EXITO;
}


void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){

	if(lista_vacia(lista)) return NULL;

	nodo_t* nodo_auxiliar = lista->nodo_inicio;
	void* elemento_retorno = NULL;
	int contador = 0;

	while(nodo_auxiliar != NULL && (posicion + 1) > contador){

		elemento_retorno = nodo_auxiliar->elemento;
		nodo_auxiliar = nodo_auxiliar->siguiente;
		contador++;
	}

	if(nodo_auxiliar == NULL && (posicion + 1) > contador) // si se da asi es porque la posicion pedida no existe
		elemento_retorno = NULL; 

	return elemento_retorno;
}


void* lista_ultimo(lista_t* lista){

	if(!lista) return NULL;
	return (lista_elemento_en_posicion(lista, lista->cantidad - 1));
}


int lista_apilar(lista_t* lista, void* elemento){
	return (lista_insertar(lista, elemento));
}


int lista_desapilar(lista_t* lista){
	return (lista_borrar(lista));
}


void* lista_tope(lista_t* lista){
	return (lista_ultimo(lista));
}


int lista_encolar(lista_t* lista, void* elemento){
	return(lista_insertar(lista, elemento));
}


int lista_desencolar(lista_t* lista){
	return (lista_borrar_de_posicion(lista, 0));
}


void* lista_primero(lista_t* lista){
	return (lista_elemento_en_posicion(lista, 0));
}


void lista_destruir(lista_t* lista){

	if(!lista_vacia(lista)){

		while(lista->cantidad > 0){
			lista_borrar(lista);
		}
	}

	free(lista);
}


void* lista_iterador_elemento_actual(lista_iterador_t* iterador){

	if(!lista_iterador_tiene_siguiente(iterador)) return NULL;

	return iterador->corriente->elemento;
}


lista_iterador_t* lista_iterador_crear(lista_t* lista){

	if(!lista) return NULL;

	lista_iterador_t* mi_iterador = malloc(sizeof(lista_iterador_t));
	if(!mi_iterador) return NULL;

	else {
		mi_iterador->lista = lista;
		mi_iterador->corriente = lista->nodo_inicio;
	}

	return mi_iterador;
}


bool lista_iterador_tiene_siguiente(lista_iterador_t* iterador){
	if(!iterador || !iterador->corriente) return false;
	if(iterador->corriente) return true;
	return false;
}


bool lista_iterador_avanzar(lista_iterador_t* iterador){

	if(!lista_iterador_tiene_siguiente(iterador)) return false;

	iterador->corriente = iterador->corriente->siguiente;
	return iterador->corriente;
}


size_t lista_con_cada_elemento(lista_t* lista, bool (*funcion)(void*, void*), void *contexto){

	if(!lista || !funcion) return 0; //hacer constante

	nodo_t* nodo_auxiliar = lista->nodo_inicio;
	size_t contador = 0;

	while(contador < lista->cantidad){
		if(funcion(nodo_auxiliar->elemento, contexto)){
			contador++;
		}
		nodo_auxiliar = nodo_auxiliar->siguiente;
	}
	return contador;
}


void lista_iterador_destruir(lista_iterador_t* iterador){
	free(iterador);
}
