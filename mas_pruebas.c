/*
void prueba_random_1(){

	int un_numero = 10;

	lista_t* una_lista = lista_crear(); 
	pa2m_afirmar(lista_insertar(una_lista, &un_numero) == EXITO, "Primer elemento insertado correctamente");
	pa2m_afirmar(lista_elementos(una_lista) == 1, "La cantidad de elementos es 1");
	pa2m_afirmar(una_lista->nodo_inicio->siguiente == NULL, "La lista se enlazo correctamente");
	pa2m_afirmar(una_lista->nodo_fin->siguiente == NULL, "La lista se enlazo correctamente");
	pa2m_afirmar(una_lista->nodo_inicio->elemento == &un_numero && una_lista->nodo_fin->elemento == &un_numero, "El inicio y el fin de la lista apuntan al mismo elemento");

	pa2m_afirmar(lista_borrar(una_lista) == EXITO, "El unico elemento se pudo borrar");
	pa2m_afirmar(lista_elementos(una_lista) == 0, "La cantidad de elementos es 0");
	pa2m_afirmar(lista_vacia(una_lista), "La lista se encuentra vacia"); //aca compruebo que inicio y fin apunten a NULL
	pa2m_afirmar(lista_borrar(una_lista) == ERROR, "No se pudo borrar porque la lista esta vacia");

	pa2m_afirmar(lista_insertar(una_lista, &un_numero) == EXITO, "Primer elemento insertado correctamente");
	pa2m_afirmar(lista_elementos(una_lista) == 1, "La cantidad de elementos es 1");
	pa2m_afirmar(una_lista->nodo_inicio->siguiente == NULL, "La lista se enlazo correctamente");
	pa2m_afirmar(una_lista->nodo_fin->siguiente == NULL, "La lista se enlazo correctamente");
	pa2m_afirmar(una_lista->nodo_inicio->elemento == &un_numero && una_lista->nodo_fin->elemento == &un_numero, "El inicio y el fin de la lista apuntan al mismo elemento");
	pa2m_afirmar(lista_borrar(una_lista) == EXITO, "El unico elemento se pudo borrar");
	pa2m_afirmar(lista_elementos(una_lista) == 0, "La cantidad de elementos es 0");
	pa2m_afirmar(lista_vacia(una_lista), "La lista se encuentra vacia"); //aca compruebo que inicio y fin apunten a NUL

	lista_destruir(una_lista);
}

void prueba_random_2(){

	bool todos_insertados_correctamente = true;
	bool todos_enlazados_correctamente = true;

	int numeros[50]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
	int i = 0;
	lista_t* una_lista = lista_crear();

	while(todos_insertados_correctamente && i < 50){

		if (lista_insertar(una_lista, &numeros[i]) != EXITO || lista_elementos(una_lista) != i + 1){
        	todos_insertados_correctamente = false;
		}
		i++;
	}

    i = 0;
    nodo_t* nodo_actual = una_lista->nodo_inicio;

    while(todos_enlazados_correctamente && i < (49)){
    	if(nodo_actual->siguiente->elemento != &numeros[i + 1]){
    		todos_enlazados_correctamente = false;
    	}
    	nodo_actual = nodo_actual->siguiente;
    	i++;
    }
	
	if(una_lista->nodo_fin->siguiente != NULL) todos_enlazados_correctamente = false;


	pa2m_afirmar(todos_enlazados_correctamente && todos_insertados_correctamente ,"Los 50 elementos fueron insertados y enlazados correctamente");

	i = 0;
	while (i < 10){
		lista_borrar(una_lista);
		i++;
	}

	pa2m_afirmar(lista_elementos(una_lista) == 40, "Pude borrar los 10 elementos al final");

	i = 0;
	while (i < 10){
		lista_borrar_de_posicion(una_lista, 4);
		i++;
	}

	pa2m_afirmar(lista_elementos(una_lista) == 30, "Pude borrar otros 10 elementos al medio de la lista");

	lista_destruir(una_lista);
}

void prueba_random_5(){

	int un_numero = 10;

	lista_t* una_lista = lista_crear(); 
	pa2m_afirmar(lista_insertar(una_lista, &un_numero) == EXITO, "Primer elemento insertado correctamente");
	pa2m_afirmar(lista_elementos(una_lista) == 1, "La cantidad de elementos es 1");
	pa2m_afirmar(una_lista->nodo_inicio->siguiente == NULL, "La lista se enlazo correctamente");
	pa2m_afirmar(una_lista->nodo_fin->siguiente == NULL, "La lista se enlazo correctamente");
	pa2m_afirmar(una_lista->nodo_inicio->elemento == &un_numero && una_lista->nodo_fin->elemento == &un_numero, "El inicio y el fin de la lista apuntan al mismo elemento");

	pa2m_afirmar(lista_insertar_en_posicion(una_lista, &un_numero, 0) == EXITO, "Segundo elemento insertado correctamente al inicio");
	pa2m_afirmar(lista_elementos(una_lista) == 2, "La cantidad de elementos es 2");

	pa2m_afirmar(lista_insertar_en_posicion(una_lista, &un_numero, 100) == EXITO, "Tercer elemento insertado correctamente al final");
	pa2m_afirmar(lista_elementos(una_lista) == 3, "La cantidad de elementos es 3");

	lista_destruir(una_lista);
}


void prueba_random_3(){


	bool todos_insertados_correctamente = true;
	bool todos_enlazados_correctamente = true;


	int numeros[MAX_1]={1,2,3,4,5,6};
	int i = 0;
	lista_t* una_lista = lista_crear();

	while(todos_insertados_correctamente && i < MAX_1){

		if (lista_insertar(una_lista, &numeros[i]) != EXITO || lista_elementos(una_lista) != i + 1){
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

    pa2m_afirmar(todos_enlazados_correctamente && todos_insertados_correctamente ,"Los 6 elementos fueron insertados y enlazados correctamente");

    i = 0;
	while (i < MAX_1){
		lista_borrar(una_lista);
		i++;
	}

	pa2m_afirmar(lista_elementos(una_lista) == 0, "La cantidad de elementos es 0");
	pa2m_afirmar(lista_vacia(una_lista), "La lista se encuentra vacia"); //aca compruebo que inicio y fin apunten a NULL
	pa2m_afirmar(lista_borrar(una_lista) == ERROR, "No se pudo borrar porque la lista esta vacia");
}*/


void probar_lista_nula_cant_elementos(){
	pa2m_afirmar(lista_elementos(NULL) == 0, "La cantidad de elementos de una lista nula es 0");
}

void probar_lista_nula_elementos_nulos(){
	pa2m_afirmar(lista_primero(NULL) == NULL, "El primer elemento de una lista nula es NULL");
	pa2m_afirmar(lista_ultimo(NULL) == NULL, "El ultimo elemento de una lista nula es NULL");
	pa2m_afirmar(lista_elemento_en_posicion(NULL, 9) == NULL, "Cualquier elemento de una lista nula es NULL");
}
void probar_lista_nula_insertar(){

	int un_numero = 10;
	pa2m_afirmar(lista_insertar(NULL, &un_numero) == ERROR, "No es posible insertar al final en una lista nula");
	pa2m_afirmar(lista_insertar_en_posicion(NULL, &un_numero, 0) == ERROR, "No es posible insertar al inicio en una lista nula");
	pa2m_afirmar(lista_insertar_en_posicion(NULL, &un_numero, 3) == ERROR, "No es posible insertar en una posicion en una lista nula");
}

void probar_lista_nula_borrar(){

	pa2m_afirmar(lista_borrar(NULL) == ERROR, "No es posible borrar al final en una lista nula");
	pa2m_afirmar(lista_borrar_de_posicion(NULL, 0) == ERROR, "No es posible borrar al inicio en una lista nula");
	pa2m_afirmar(lista_borrar_de_posicion(NULL, 2) == ERROR, "No es posible borrar una posicion de una lista nula");
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


void probar_lista_vacia_creacion(){ //NO ES REDUCIBLE

	lista_t* una_lista = lista_crear(); 
	pa2m_afirmar(lista_vacia(una_lista) == true, "La lista se creo vacia");
	lista_destruir(una_lista);
}

void probar_primer_elemento_lista_vacia(){

}
void probar_ultimo_elemento_lista_vacia(){
	pa2m_afirmar(funcion_general_ultimo_tope_vacia(&lista_ultimo), "EL ultimo elemento en una lista vacia es NULL");
}

void probar_elemento_pos_lista_vacia(){ //NO ES REDUCIBLE, ES UNICA

	lista_t* una_lista = lista_crear(); 
	pa2m_afirmar(lista_elemento_en_posicion(una_lista, 4) == NULL, "Un elemento cualquiera de una lista vacia es NULL");
	lista_destruir(una_lista);
}

void probar_lista_elementos_vacia(){ //NO ES REDUCIBLE, ES UNICA

	lista_t* una_lista = lista_crear();
	pa2m_afirmar(lista_elementos(una_lista) == 0, "La cantidad de elementos de una lista vacia es 0");
	lista_destruir(una_lista);
}

void probar_eliminacion_final_lista_vacia(){ //REDUCIBLE PERO POCO CODIGO
	lista_t* una_lista = lista_crear(); 
	pa2m_afirmar(lista_borrar(una_lista) == ERROR, "No es posible borrar al final en una lista vacia");
	lista_destruir(una_lista);
}

void probar_eliminacion_pos_lista_vacia(){ // NO ES REDUCIBLE, ES UNICA
	lista_t* una_lista = lista_crear(); 
	pa2m_afirmar(lista_borrar_de_posicion(una_lista, 2) == ERROR, "No es posible borrar una posicion de una lista vacia");
	lista_destruir(una_lista);
}

void probar_pila_vacia_tope(){
	pa2m_afirmar(funcion_general_ultimo_tope_vacia(&lista_tope), "EL ultimo elemento en una pila vacia es NULL");
}

void probar_desapilar_lista_vacia(){
	lista_t* una_lista = lista_crear(); 
	pa2m_afirmar(lista_desapilar(una_lista) == ERROR, "No es posible desapilar en una pila vacia");
	lista_destruir(una_lista);
}

void probar_desencolar_lista_vacia(){

	lista_t* una_lista = lista_crear(); 
	pa2m_afirmar(lista_desencolar(una_lista) == ERROR, "No es posible desencolar en una pila vacia");
	lista_destruir(una_lista);
}

void probar_cola_vacia_primero(){

	lista_t* una_lista = lista_crear(); 
	pa2m_afirmar(lista_primero(una_lista) == NULL, "EL primer elemento en una cola vacia es NULL");
	lista_destruir(una_lista);
}




size_t contador = 0;
		nodo_insertar_posicion(lista, lista->nodo_inicio, nodo_a_insertar, posicion, contador);

		nodo_t* nodo_auxiliar = lista->nodo_fin; 

	else {
		lista->nodo_fin = nodo_ante_ultimo(lista, lista->nodo_inicio);
		lista->nodo_fin->siguiente = NULL;
	}

	free(nodo_auxiliar);
	lista->cantidad--;
	return EXITO;



	void probar_ultimo_elemento_lista(){

	bool retorno = false;
	int numeros[MAX_1]={1,2,3,4,5,6};
	lista_t* una_lista = lista_crear();

	for (int i = 0; i < MAX_1; i++){
		lista_insertar(una_lista, &numeros[i]);
	}

	if (lista_ultimo<s(una_lista) == &numeros[MAX_1-1]) retorno = true;

	lista_destruir(una_lista);
	return retorno;
}
	pa2m_afirmar(funcion_general_ultimo_tope(&lista_insertar, &lista_ultimo), "Devuelve correctamente el ultimo elemento de una lista no vacia");
}

void probar_elemento_pos(){ //NO ES REDUCIBLE, ES UNICA

	int numeros[MAX_1]={1,2,3,4,5,6};
	lista_t* una_lista = lista_crear();

	for (int i = 0; i < MAX_1; i++){
		lista_insertar(una_lista, &numeros[i]);
	}

	pa2m_afirmar(lista_elemento_en_posicion(una_lista, MAX_1-2)== &numeros[MAX_1-2], "Devuelve correctamente el elemento pedido");
	lista_destruir(una_lista);
}

void probar_lista_elementos(){ //NO ES REDUCIBLE, ES UNICA

	int numeros[MAX_1]={1,2,3,4,5,6};
	lista_t* una_lista = lista_crear();

	for (int i = 0; i < MAX_1; i++){
		lista_insertar(una_lista, &numeros[i]);
	}

	pa2m_afirmar(lista_elementos(una_lista) == MAX_1 , "La cantidad de elementos de una lista no vacia es correcta");
	lista_destruir(una_lista);
}

void probar_pila_tope(){
	pa2m_afirmar(funcion_general_ultimo_tope(&lista_apilar, &lista_tope), "Devuelve correctamente el ultimo elemento de una lista no vacia");
}

void probar_cola_primero(){

	int numeros[MAX_1]={1,2,3,4,5,6};
	lista_t* una_lista = lista_crear();

	for (int i = 0; i < MAX_1; i++){
		lista_encolar(una_lista, &numeros[i]);
	}

	pa2m_afirmar(lista_primero(una_lista) == &numeros[0], "Devuelve correctamente el primer elemento de una cola no vacia");
	lista_destruir(una_lista);
}