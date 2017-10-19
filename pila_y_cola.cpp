/*
*   Programa: Pilas y Colas
*   Fecha: 18/10/2017
*   Autor:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define reservar_memoria (Nodo *)malloc(sizeof(Nodo))

//Estructura Nodo
struct Nodo{
	int dato;
	Nodo *siguiente;
};

//Variables
Nodo *pila;
int dato;
int op;
int valor;
FILE *archivo;
int cantDatos;

//Funciones pila
void insertarElemento();
void quitarElemento();
bool pilaVacia();
void mostrarElementos();
bool buscarElemento();
void quitarElementos();
void editarElemento();
void ordenarElemento();
void salvarElementos();

//Funciones Cola
void generarDatos(Nodo *&, Nodo *&);
void insertarDatosCola(int, Nodo *&, Nodo *&);
void ordenarDatosCola(Nodo *);
void imprimirDatos(Nodo *);
void menuGenerar(Nodo *&, Nodo *&);
void menuEliminarCola(Nodo *, Nodo *, int);
void quitarElementoCola( Nodo *&, Nodo *&, int );
void buscarElementoCola(Nodo *, Nodo *);
bool colaVacia(Nodo *);
void editarElementoCola(Nodo *&, Nodo *&);
void guardarElementosCola(Nodo *&);

//Funciones auxiliares
void estadoPila();
void Cargar();
void Generar();

//Metodos de ordenamiento
void Burbuja();
void metodoRapido();

//Prototipos Menus
void menuPilas();
void menuEliminar();
void menuColas();
void menu();
void menuGenerar();
void menuCargar();
void menuOrdenar();

//Funcion Principal
int main(){
	menu();
}

void menu(){

	do{
        printf("\t\t|-----------------------------------|\n");
		printf("\t\t|           MENU PRINCIPAL          |\n");
		printf("\t\t|-----------------------------------|\n");
		printf("\t\t|             1. Pila               |\n");
		printf("\t\t|             2. Cola               |\n");
		printf("\t\t|             0. Salir              |\n");
		printf("\t\t|-----------------------------------|\n\n");
		printf("\t\tIngrese una opcion: ");
		scanf("%d",&op);
		system("cls");

		switch(op){
			case 1:menuPilas();
				break;
			case 2:menuPilas();
				break;
            case 0:menu();
				break;
			default:printf("Numero Equivocado!\n");
				break;
		}
		system("pause");
		system("cls");
	}while(op != 0);
}
//Funcion Menu Pila
void menuPilas(){
	Nodo *inicio =NULL;
	Nodo *fin = NULL;
	int opcion,dato;

	do{
		printf("\t\t|----------------------------------------------------------|\n");
		printf("\t\t|                         MENU PILA                        |\n");
		printf("\t\t|----------------------------------------------------------|\n");
		printf("\t\t|                              |                           |\n");
		printf("\t\t| 1. Generar Elementos         |  6. Editar Elemento       |\n");
		printf("\t\t| 2. Cargar Elementos          |  7. Ordenar Elemento      |\n");
		printf("\t\t| 3. Listar Elementos          |  8. Salvar Elemento       |\n");
		printf("\t\t| 4. Eliminar Elementos        |  9. Estado Pila           |\n");
		printf("\t\t| 5. Buscar Elementos          |  0. Salir                 |\n");
		printf("\t\t|----------------------------------------------------------|\n\n");
		printf("\tIngrese una opcion: ");
		scanf("%d",&opcion);
		system("cls");

		if(op == 1){
			switch(opcion){
				case 1:menuGenerar();
					break;
				case 2:menuCargar();
					break;
				case 3:mostrarElementos();
					break;
				case 4:menuEliminar();
					break;
				case 5:buscarElemento();
					break;
				case 6:editarElemento();
					break;
				case 7:menuOrdenar();
					break;
				case 8:salvarElementos();
					break;
				case 9:estadoPila();
					break;
                case 0:menu();
					break;
				default:printf("No es una opcion valida\n");
					break;
			}
		}
		else{
			switch(opcion){
                case 1:menuGenerar(inicio,fin);
                    break;
                case 2:
                    break;
                case 3:imprimirDatos(inicio);
                    break;
                case 4:menuEliminarCola(inicio,fin,dato);
                    break;
                case 5:buscarElementoCola(inicio,fin);
                    break;
                case 6:editarElementoCola(inicio,fin);
                    break;
                case 7:ordenarDatosCola(inicio);
                    break;
                case 8:guardarElementosCola(inicio);
                    break;
                case 0:exit('0');
                    break;
                default:printf("Numero Equivocado\n");
            }
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
//Funcion Menu Pila
void menuGenerar(){
	int opcion;

	do{
		printf("\t\t|----------------------------------------------|\n");
		printf("\t\t|                  MENU GENERAR                |\n");
		printf("\t\t|----------------------------------------------|\n");
		printf("\t\t|                       |                      |\n");
		printf("\t\t| 1. 1.000.000          |   5. 20.000.000      |\n");
		printf("\t\t| 2. 2.000.000          |   0. Salir           |\n");
		printf("\t\t| 3. 5.000.000          |                      |\n");
		printf("\t\t| 4. 10.000.000         |                      |\n");
		printf("\t\t|----------------------------------------------|\n\n");
		printf("\tIngrese una opcion: ");
		scanf("%d",&opcion);
		system("cls");

		switch(opcion){
			case 1:valor = 1000000;
				Generar();
				break;
			case 2:valor = 2000000;
				Generar();
				break;
			case 3:valor = 5000000;
				Generar();
				break;
			case 4:valor = 10000000;
				Generar();
				break;
			case 5:valor = 20000000 ;
				Generar();
				break;
            case 0:menuPilas();
				break;
			default:printf("No es una opcion valida\n");
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
//Funcion Menu Cargar
void menuCargar(){
	int opcion;

	do{
		printf("\t\t|-----------------------------------|\n");
		printf("\t\t|           MENU CARGAR             |\n");
		printf("\t\t|-----------------------------------|\n");
		printf("\t\t|             1. 1.000.000          |\n");
		printf("\t\t|             2. 2.000.000          |\n");
		printf("\t\t|             3. 5.000.000          |\n");
		printf("\t\t|             4. 10.000.000         |\n");
		printf("\t\t|             5. 20.000.000         |\n");
		printf("\t\t|             0. Salir              |\n");
		printf("\t\t|-----------------------------------|\n\n");
		printf("\tIngrese una opcion: ");
		scanf("%d",&opcion);
		system("cls");

		switch(opcion){
			case 1:	archivo = fopen("Unmillon.txt", "r");
				Cargar();
				break;
			case 2:archivo = fopen("dosmillones.txt", "r");
				Cargar();
				break;
			case 3:archivo = fopen("cincomillones.txt", "r");
				Cargar();
				break;
			case 4:archivo = fopen("diezmillones.txt", "r");
				Cargar();
				break;
			case 5:archivo = fopen("veintemillones.txt", "r");
				Cargar();
				break;
            case 0:menu();
				break;
			default:printf("Opcion no valida\n");
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
//Menu Eliminar
void menuEliminar(){
	int opcion;

	do{
		printf("\t\t|-------------------------------------|\n");
		printf("\t\t|           MENU ELIMINAR             |\n");
		printf("\t\t|-------------------------------------|\n");
		printf("\t\t|           1. Eliminar Todo          |\n");
		printf("\t\t|           2. Eliminar un elemento   |\n");
		printf("\t\t|           0. Salir                  |\n");
		printf("\t\t|-------------------------------------|\n\n");
		printf("\nIngrese una opcion: ");
		scanf("%d",&opcion);

		switch(opcion){
			case 1:quitarElementos();
				break;
			case 2:quitarElemento();
				break;
			case 0:menu();
				break;
			default:printf("Numero Equivocado!\n");
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
//Funcion Menu Ordenar
void menuOrdenar(){
	int opcion;
	do{
		printf("\t\t|-------------------------------------|\n");
		printf("\t\t|           MENU ORDENAMIENTO         |\n");
		printf("\t\t|-------------------------------------|\n");
		printf("\t\t|             1. Burbuja              |\n");
		printf("\t\t|             2. Metodo Rapido        |\n");
		printf("\t\t|             0. Salir                |\n");
		printf("\t\t|-------------------------------------|\n\n");
		printf("\tIngrese una opcion: ");
		scanf("%d",&opcion);

		switch(opcion){
			case 1:Burbuja();
				break;
			case 2:metodoRapido();
				break;
			case 0:menu();
				break;
			default:printf("Numero Equivocado!\n");
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}

//Insertar elemento en la pila
void insertarElemento(){
	Nodo *elemento = reservar_memoria;
	elemento->dato = dato;
	elemento->siguiente = pila;
	pila = elemento;
	if(elemento != NULL){
		printf("\nElemento insertado de manera correcta\n\n");
	}else{
		printf("\nError\n");
	}
}
//Funcion quitar un elemento de la pila
void quitarElemento(){
	char rpt;
	if(pilaVacia()){
		printf("\nPila vacia!\n");
	}else{
		do{
			Nodo *aux = pila;
			dato = aux->dato;
			pila = aux->siguiente;
			free(aux);
			fflush(stdin);
			printf("\nElemento Borrado correctamente\n");
			printf("\nDesea ingresar otro dato (s/n): ");
			fflush(stdin);
			scanf("%c",&rpt);
			system("cls");
		}while((rpt == 'S') || (rpt == 's'));
	}
}
//Funcion quitar todos los elementos de la pila
void quitarElementos(){
	if(pilaVacia() == true){
		printf("\nPila vacia!\n");
	}else{
		while(pila != NULL){
			Nodo *aux = pila;
			dato = aux->dato;
			pila = aux->siguiente;
			printf("\nElemento %d Borrado Exitosamente!\n",aux->dato);
			free(aux);
		}
	}
}
//Funcion comprobar estado de pila
bool pilaVacia(){
	return (pila == NULL)?true:false;
}
//Funcion de mostrar los elementos de una pila
void mostrarElementos(){
	Nodo *Nueva_Pila = pila;
	if(pilaVacia()){
		printf("La pila esta vacia!\n");
	}else if(Nueva_Pila != NULL){
			while(Nueva_Pila != NULL){
				printf("%d,",Nueva_Pila->dato);
				Nueva_Pila = Nueva_Pila->siguiente;
			}
		}else{
			printf("%d.",Nueva_Pila->dato);
		}printf("\n");
}
//Funcion para buscar un elemento
bool buscarElemento(){
	fflush(stdin);
	Nodo *pilita = pila;
	int datos, contador = 0;
	bool encontrado = false;
	if(pilaVacia() == true){
		printf("\nPila Vacia!\n");
	}else{
		if(pilaVacia() == false){
			printf("\nIngrese dato a buscar: ");
			scanf("%d",&datos);
			system("cls");
		}
		while((pilita != NULL)){
			if(datos == pilita->dato){
				contador += 1;
				encontrado = true;
				printf("\nDato Encontrado: %d\n",pilita->dato);
			}
			pilita = pilita->siguiente;
		}
	}
	if(contador == 0){
		printf("\nDato no encontrado: %d\n",datos);
	}
}
//Funcion eliminar pila
void editarElemento(){
	fflush(stdin);
	Nodo *pilita = pila;
	int datos;
	char rpt;

	bool encontrado = false;
	if(pilaVacia() == true){
		printf("\nPila Vacia!\n");
	}else{
		do{
			printf("\nIngrese dato a Modificar: ");
			scanf("%d",&datos);
			system("cls");
			while((pilita != NULL)){
				if(datos == pilita->dato){
					encontrado = true;
					printf("\nDato Encontrado: %d\n",pilita->dato);
					printf("\nIngrese el nuevo dato: ");
					scanf("%d",&pilita->dato);
					printf("\nDato modificado!\n\n");
				}
				pilita = pilita->siguiente;
			}
			if(encontrado == false){
				printf("\nDato no encontrado: %d\n",datos);
			}
			printf("\nQuieres Modificar otro dato(s/n): ");
			fflush(stdin);
			scanf("%c",&rpt);
			system("cls");
		}while((rpt == 'S') || (rpt == 's'));
	}
}
//Funcion metodo de ordenamiento
void Burbuja(){
	Nodo *p = pila;
	Nodo *j;

	while(p != NULL){
		j = p->siguiente;
		while(j != NULL){
			if(p->dato > j->dato){
				int aux = j->dato;
				j->dato = p->dato;
				p->dato = aux;
			}
			j = j->siguiente;
		}
		p = p->siguiente;
	}
	printf("Ordenado Satisfactoriamente!\n\n");
}

//Funcion estado pila
void estadoPila(){
	if(pilaVacia()){
		printf("\nPila Vacia!\n\n");
	}else{
		printf("\nPila Llena!\n\n");
	}
}
//Funcion metodo de ordenamiento
void metodoRapido(){
}
//Funcion guardar datos
void salvarElementos(){
	Nodo *polo = pila;
	archivo = fopen("Elementos_Recuperados.txt", "w");
	while(polo != NULL){
		dato = polo->dato;
		fprintf(archivo, "%d\n", dato);
		polo = polo->siguiente;

	}
	fclose(archivo);
}
//Funcion Generar 
void Generar(){
	int i;
	Nodo *nueva_pila = pila;
	srand(time(NULL));
	while(i != valor){
		dato = (rand() % (1999999 + 1)- 1000000);
		insertarElemento();
		i += 1;
	}
}
//Funcion cargar elemento
void Cargar(){
	Nodo *polo = pila;
	archivo = fopen("Elementos_Recuperados.txt", "r");
	while(!feof(archivo)){
		fscanf(archivo,"%d\n",&dato);
		insertarElemento();
		printf("%d\n",dato);

	}printf("Cargado con exito\n");
	fclose(archivo);
}
//Cola
void menuGenerar(Nodo *&inicio, Nodo *&fin){
	int opcion;
		printf("\t\t|----------------------------------------------|\n");
		printf("\t\t|                  MENU GENERAR                |\n");
		printf("\t\t|----------------------------------------------|\n");
		printf("\t\t|                       |                      |\n");
		printf("\t\t| 1. 1.000.000          |   5. 20.000.000      |\n");
		printf("\t\t| 2. 2.000.000          |   0. Salir           |\n");
		printf("\t\t| 3. 5.000.000          |                      |\n");
		printf("\t\t| 4. 10.000.000         |                      |\n");
		printf("\t\t|----------------------------------------------|\n\n");
		printf("\tIngrese cantidad de datos a generar: ");
		scanf("%d",&cantDatos);
		system("cls");
		
		if(cantDatos == 0){
                menuPilas();
		}else{
			generarDatos(inicio,fin);
		}
		system("pause");
		system("cls");
}
void menuEliminarCola(Nodo *inicio, Nodo *fin, int n){
	int opcion;
	do{
		printf("\t\t|-------------------------------------|\n");
		printf("\t\t|           MENU ELIMINAR             |\n");
		printf("\t\t|-------------------------------------|\n");
		printf("\t\t|           1. Eliminar Todo          |\n");
		printf("\t\t|           2. Eliminar un elemento   |\n");
		printf("\t\t|           0. Salir                  |\n");
		printf("\t\t|-------------------------------------|\n\n");
		printf("\tIngrese una opcion: ");
		scanf("%d",&opcion);
		
		switch(opcion){
			case 1:
				break;
			case 2:quitarElementoCola(inicio,fin,n);
				break;
			case 0:menuPilas();
				break;
			default:printf("Numero Equivocado!\n");
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
void generarDatos(Nodo *&inicio, Nodo *&fin){
	fflush(stdin);
	int i, aleatorio;
	srand(time(NULL));
	for(i = 1; i <= cantDatos; i++){
		aleatorio = (rand() % (1999999 + 1)- 1000000);
		insertarDatosCola(aleatorio, inicio, fin);
	}
}

void insertarDatosCola(int n, Nodo *&inicio, Nodo *&fin){
	Nodo * nuevo_nodo = reservar_memoria;
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;
	if(inicio == NULL){
		inicio = nuevo_nodo;
	}else{
		fin -> siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
}

void ordenarDatosCola(Nodo *inicio){
	int aux;
	Nodo * x = inicio;
	Nodo * y = NULL;
	if(inicio == NULL){
		printf("Me la gane suave\n");
	}else{
		while(x != NULL){
			y = x -> siguiente;
			while(y != NULL){
				if(x -> dato > y -> dato){
					aux = x -> dato;
					x -> dato = y -> dato;
					y -> dato = aux;
				}
				y = y -> siguiente;
			}
			x = x -> siguiente;
		}
	}
}
void imprimirDatos(Nodo *inicio){
	Nodo * aux = inicio;
	if(inicio == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			printf("%d ", aux -> dato);
			aux = aux -> siguiente;
		}
	}
}
void quitarElementoCola( Nodo *&inicio, Nodo *&fin,int n){
	n = inicio -> dato;
	Nodo *aux = reservar_memoria;
	inicio = inicio->siguiente;
	aux = inicio;
	delete aux;
}
void Eliminar_ElementoCola(Nodo *&inicio,Nodo *&fin){
	Nodo *aux = inicio;

	if(inicio == fin){
		inicio = NULL;
		fin = NULL;
	}else{
		inicio = inicio -> siguiente;
	}
	delete aux;
	printf("La Cola fue Borrada Exitosamente!\n");
}
void buscarElementoCola(Nodo *inicio, Nodo *fin){
	fflush(stdin);
	Nodo *colita = inicio;
	int datos;
	bool encontrado = false;
	if(colaVacia(inicio) == true){
		printf("\nCola Vacia!\n");
	}
	if(colaVacia(inicio) == false){
		printf("\nIngrese dato a buscar: ");
		scanf("%d",&datos);
		system("cls");
	}
	while((colita != NULL)){
		if(datos == colita->dato){
			encontrado = true;
			printf("\nDato Encontrado: %d\n",colita->dato);
		}
		colita = colita->siguiente;
	}
	if(encontrado == false){
		printf("\nDato no encontrado: %d\n",datos);
	}
}
bool colaVacia(Nodo *cabeza){
	return (cabeza == NULL)? true : false;
}
void editarElementoCola(Nodo *&inicio, Nodo *&fin){
	fflush(stdin);
	Nodo *colita = inicio;
	int datos;
	char rpt;

	bool encontrado = false;
	if(colaVacia(inicio) == true){
		printf("\nPila Vacia!\n");
	}else{
		do{
			printf("\nIngrese dato a Modificar: ");
			scanf("%d",&datos);
			system("cls");
			while((colita != NULL)){
				if(datos == colita->dato){
					encontrado = true;
					printf("\nDato Encontrado: %d\n",colita->dato);
					printf("\nIngrese el nuevo dato: ");
					scanf("%d",&colita->dato);
					printf("\nDato modificado!\n\n");
				}
				colita = colita->siguiente;
			}
			if(encontrado == false){
				printf("\nDato no encontrado: %d\n",datos);
			}
			printf("\nQuieres Modificar otro dato(s/n): ");
			fflush(stdin);
			scanf("%c",&rpt);
			system("cls");
		}while((rpt == 'S') || (rpt == 's'));
	}
}
void guardarElementosCola(Nodo *&inicio){
	int dato;
	Nodo *polo = inicio;
	archivo = fopen("cola.txt", "w");
	while(polo != NULL){
		dato = polo->dato;
		fprintf(archivo, "%d\n", dato);
		polo = polo->siguiente;

	}
	fclose(archivo);
}
