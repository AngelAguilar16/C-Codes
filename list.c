#include <stdio.h>
#include <stdlib.h>
 
typedef struct snodo{ //snodo es el nombre de la estructura
    int valor;
    struct snodo *sig; //El puntero siguiente para recorrer la lista enlazada
}tnodo; //tnodo es el tipo de dato para declarar la estructura
 
typedef tnodo *tpuntero; //Puntero al tipo de dato tnodo para no utilizar punteros de punteros
 
void insertarEnLista (tpuntero *cabeza, int e);
void imprimirLista (tpuntero cabeza);
void borrarLista (tpuntero *cabeza);
 
int main(){
    int e,op;
    tpuntero cabeza; //Indica la cabeza de la lista enlazada, si la perdemos no podremos acceder a la lista
    cabeza = NULL; //Se inicializa la cabeza como NULL ya que no hay ningun nodo cargado en la lista
    while(op != 4){
        printf("\n\n\t\tMenu\n\n");
        printf("1) Ingresar datos\n");
        printf("2) Mostrar datos\n");
        printf("3) Eliminar datos\n");
        printf("4) Salir\n");
        printf("Ingresa tu opcion: ");
        scanf("%d", &op);
        switch (op){
            case 1:
                printf("Ingrese elementos, -1 para terminar: ");
                scanf("%d",&e);
        
                while(e!=-1){
                    insertarEnLista (&cabeza, e);
                    printf ("Ingresado correctamente");
                    printf ("\n");
                    printf("Ingrese elementos, -1 para terminar: ");
                    scanf("%d",&e);
                }
                break;
            case 2:
                printf ("\nSe imprime la lista cargada: ");
                imprimirLista (cabeza);
                break;
            case 3:
                printf ("\nSe borra la lista cargada\n");
                borrarLista (&cabeza);
                break;

            default:
                break;
        }
    }
     
    printf ("\n");
    return 0;
}
 
 
void insertarEnLista (tpuntero *cabeza, int e){
    tpuntero nuevo; //Creamos un nuevo nodo
    nuevo = malloc(sizeof(tnodo)); //Utilizamos malloc para reservar memoria para ese nodo
    nuevo->valor = e; //Le asignamos el valor ingresado por pantalla a ese nodo
    nuevo->sig = *cabeza; //Le asignamos al siguiente el valor de cabeza
    *cabeza = nuevo; //Cabeza pasa a ser el ultimo nodo agregado
}
 
void imprimirLista(tpuntero cabeza){
    while(cabeza != NULL){ //Mientras cabeza no sea NULL
        printf("%4d",cabeza->valor); //Imprimimos el valor del nodo
        cabeza = cabeza->sig; //Pasamos al siguiente nodo
    }
}
 
void borrarLista(tpuntero *cabeza){ 
    tpuntero actual; //Puntero auxiliar para eliminar correctamente la lista
  
    while(*cabeza != NULL){ //Mientras cabeza no sea NULL
        actual = *cabeza; //Actual toma el valor de cabeza
        *cabeza = (*cabeza)->sig; //Cabeza avanza 1 posicion en la lista
        free(actual); //Se libera la memoria de la posicion de Actual (el primer nodo), y cabeza queda apuntando al que ahora es el primero
    }
}