#include <stdio.h>
#include <stdlib.h>

typedef struct nodoarbol {
    int clave;
    struct nodoarbol *izq;
    struct nodoarbol *der;
} NODO;

NODO *nuevoNodo();
NODO *insertarNodo(NODO *arbol, int valor);
void inorden(NODO *R);
void preorden(NODO *R);
void postorden(NODO *R);
void treefree(NODO *R);

int main()
{
    NODO *raiz = NULL;
    int valor;
    char opcion;

    printf("Creacion del arbol binario\n\n");
    raiz = insertarNodo(raiz, 50);

    do {
        printf("Desea agregar otro nodo? (s/n): ");
        scanf(" %c", &opcion);

        if (opcion == 's') {
            raiz = insertarNodo(raiz, valor);
        } else if (opcion == 'n') {
            printf("Terminando la creacion del arbol.\n");
        } else {
            printf("Opcion invalida. Intenta nuevamente.\n");
            fflush(stdin);
        }
    } while (opcion != 'n');

    printf("\n\nPreorden: ");
    preorden(raiz);
    printf("\n\nInorden: ");
    inorden(raiz);
    printf("\n\nPostorden: ");
    postorden(raiz);

    treefree(raiz);

    return 0;
}

NODO *nuevoNodo()
{
    NODO *nuevoNodo = (NODO *)malloc(sizeof(NODO));

    printf("Ingrese valor para el nodo (Recuerda que no se puede repetir): ");
    scanf("%d", &(nuevoNodo->clave));

    nuevoNodo->der = NULL;
    nuevoNodo->izq = NULL;

    return nuevoNodo;
}

NODO *insertarNodo(NODO *arbol, int valor)
{
    if (arbol == NULL) {
        printf("Ingrese valor para el nuevo nodo: ");
        scanf("%d", &valor);
    }

    if (valor < arbol->clave) {
        arbol->izq = insertarNodo(arbol->izq, valor);
    } else if (valor > arbol->clave) {
        arbol->der = insertarNodo(arbol->der, valor);
    }

    return arbol;
}

void preorden(NODO *rarbol)
{
    if (rarbol != NULL) {
        printf(" %d ", rarbol->clave);
        preorden(rarbol->izq);
        preorden(rarbol->der);
    }
}

void inorden(NODO *rarbol)
{
    if (rarbol != NULL) {
        inorden(rarbol->izq);
        printf(" %d ", rarbol->clave);
        inorden(rarbol->der);
    }
}

void postorden(NODO *rarbol)
{
    if (rarbol != NULL) {
        postorden(rarbol->izq);
        postorden(rarbol->der);
        printf(" %d ", rarbol->clave);
    }
}

void treefree(NODO *rarbol)
{
    if (rarbol != NULL) {
        treefree(rarbol->izq);
        treefree(rarbol->der);
        free(rarbol);
    }
}
