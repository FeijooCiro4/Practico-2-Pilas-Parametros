#include <stdio.h>
#include <stdlib.h>
#include "Pila/pila.h"

void vaciarPilas(Pila *a, Pila *b, Pila *c);
int potenciar(int base, int exponente);
int pedirInt(void);
void vaciarPila(Pila *a);
void ingresarPila(Pila *p);
void mostrarPila(Pila *p);
void pasarPila(Pila *a, Pila *b);
void invertirPila(Pila *a);
int retornarMenor(Pila *a, Pila *b);
void eliminarElemento(Pila *a, Pila *b, int elem );
void ordenarSeleccion(Pila *a, Pila *b, Pila *c);
void ordenarInsersion(Pila *a, Pila *b, Pila *c);
void ordenarOrdenadaInsersion(Pila *a, Pila *b, Pila *c);
int sumarPila_INF(Pila *a);
int sumarPila(Pila *a);
int contarPila(Pila *a);
float dividirElementos(float a, float b);
float promediarPila(Pila *a);
int pasarAUnDigito(Pila *a);

int main(){
    int opc;
    Pila p, q, r;

    inicpila(&p);
    inicpila(&q);
    inicpila(&r);

    do{
        printf("\tBIENVENIDO\n\n");
        printf("Ingrese una de estas opciones: \n"
            "\t1. Ingresar una pila.\n"
            "\t2. Pasar datos de una pila a otra.\n"
            "\t3. Pasar datos de una pila a otra conservando el orden.\n"
            "\t4. Eliminar el elemento de menor valor dentro de una pila.\n"
            "\t5. Ordenar pilas de mayor a menor.\n"
            "\t6. Ordenar la insercion de un numero en una lista ordenada.\n"
            "\t7. Ordenar por insersion.\n"
            "\t8. Sumar los primeros dos elementos de una pila.\n"
            "\t9. Calcular el promedio de una pila.\n"
            "\t10. Pasar a un digito los elementos de una pila.\n"
            "\t0. Salir.\n\n");
        printf("Inserte aqui: ");
        scanf("%d", &opc);

        switch(opc){
        case 1:
            ingresarPila(&p);
            mostrarPila(&p);

            vaciarPilas(&p, &q, &r);
            break;
        case 2:
            ingresarPila(&p);
            system("cls");

            printf("\tAntes del pase.\n");
            printf("Pila p: ");
            mostrarPila(&p);
            printf("Pila q: ");
            mostrarPila(&q);

            pasarPila(&p, &q);

            printf("\n\tDespues del pase.\n");
            printf("Pila p: ");
            mostrarPila(&p);
            printf("Pila q: ");
            mostrarPila(&q);

            vaciarPilas(&p, &q, &r);
            break;
        case 3:
            ingresarPila(&p);
            system("cls");

            printf("\tAntes del pase.\n");
            printf("Pila p: ");
            mostrarPila(&p);
            printf("Pila q: ");
            mostrarPila(&q);

            pasarPila(&p, &q);

            printf("\n\tMitad el pase.\n");
            printf("Pila p: ");
            mostrarPila(&p);
            printf("Pila q: ");
            mostrarPila(&q);

            pasarPila(&q, &r);

            printf("\n\tDespues del pase.\n");
            printf("Pila q: ");
            mostrarPila(&q);
            printf("Pila r: ");
            mostrarPila(&r);

            vaciarPilas(&p, &q, &r);
            break;
        case 4:
            ingresarPila(&p);
            system("cls");

            printf("\tAntes del pase.\n");
            printf("Pila p: ");
            mostrarPila(&p);

            eliminarElemento(&p, &q, retornarMenor(&p, &q));
            pasarPila(&q, &p);

            printf("\tDespues del pase.\n");
            printf("Pila p: ");
            mostrarPila(&p);

            vaciarPilas(&p, &q, &r);
            break;
        case 5:
            ingresarPila(&p);
            system("cls");

            printf("\tAntes del pase.\n");
            printf("Pila p: ");
            mostrarPila(&p);

            ordenarSeleccion(&p, &q, &r);

            printf("\tDespues del pase.\n");
            printf("Pila q: ");
            mostrarPila(&q);

            vaciarPilas(&p, &q, &r);
            break;
        case 6:
            system("cls");
            apilar(&p, 1);
            apilar(&p, 2);
            apilar(&p, 3);
            apilar(&p, 4);

            printf("\tAntes del pase.\n");
            printf("Pila p: ");
            mostrarPila(&p);

            ordenarOrdenadaInsersion(&p, &q, &r);

            printf("\n\tDespues del pase.\n");
            printf("Pila p: ");
            mostrarPila(&p);

            vaciarPilas(&p, &q, &r);
            break;
        case 7:
            ingresarPila(&p);
            system("cls");

            printf("\tAntes del pase.\n");
            printf("Pila p: ");
            mostrarPila(&p);

            ordenarInsersion(&p, &q, &r);

            printf("\n\tDespues del pase.\n");
            printf("Pila q: ");
            mostrarPila(&q);

            vaciarPilas(&p, &q, &r);
            break;
        case 8:
            ingresarPila(&p);
            system("cls");

            printf("La suma de los primeros dos elementos de esta pila es: %df\n\n", sumarPila_INF(&p));

            vaciarPilas(&p, &q, &r);
            break;
        case 9:
            ingresarPila(&p);
            system("cls");

            printf("El promedio de esta pila es: %.1f\n\n", promediarPila(&p));

            vaciarPila(&p);
            vaciarPila(&q);
            vaciarPila(&r);
            system("pause");
            system("cls");
            break;
        case 10:
            ingresarPila(&p);
            system("cls");

            printf("El digito formado de esta pila es: %d\n\n", pasarAUnDigito(&p));

            vaciarPilas(&p, &q, &r);
            break;
        case 0:
            system("cls");
            printf("Gracias por probar el programa.\n");
            break;
        default:
            printf("\nOpcion incorrecta.\n");
            vaciarPilas(&p, &q, &r);
            break;
        }
    }while(opc != 0);

    return 0;
}
void vaciarPilas(Pila *a, Pila *b, Pila *c){
    vaciarPila(a);
    vaciarPila(b);
    vaciarPila(c);
    system("pause");
    system("cls");
}

int potenciar(int base, int exponente){
    int result = 1;
    for(int i=0; i<exponente; i++){
        result *= base;
    }
    return result;
}

int pedirInt(){
    int num;
    printf("Ingrese un numero entero: ");
    scanf("%d", &num);

    return num;
}

void vaciarPila(Pila *a){
    while(!pilavacia(a)){
        desapilar(a);
    }
}

void ingresarPila(Pila *p){
    int cantIngresos, num = 0;

    printf("Ingrese la cantidad de elementos en la pila: ");
    scanf("%d", &cantIngresos);

    for(int i=1; i<=cantIngresos; i++){
        printf("Ingrese un numero entero: ");
        scanf("%d", &num);
        apilar(p, num);
    }
}

void pasarPila(Pila *a, Pila *b){
    while(!pilavacia(a)){
        apilar(b, desapilar(a));
    }
}

void invertirPila(Pila *a){
    Pila b, c;
    inicpila(&b);
    inicpila(&c);

    pasarPila(a, &b);
    pasarPila(&b, &c);
    pasarPila(&c, a);
}

int retornarMenor(Pila *a, Pila *b){
    int menor = tope(a);
    while(!pilavacia(a)){
        if(menor > tope(a)){
            menor = tope(a);
        }
        apilar(b, desapilar(a));
    }
    pasarPila(b, a);
    return menor;
}

void eliminarElemento(Pila *a, Pila *b, int elem ){
    while(!pilavacia(a)){
        if(elem == tope(a)){
            desapilar(a);
        } else {
            apilar(b, desapilar(a));
        }
    }
}

void ordenarSeleccion(Pila *a, Pila *b, Pila *c){
    while(!pilavacia(a)){
        int menor = retornarMenor(a, b);
        eliminarElemento(a, b, menor);

        while(!pilavacia(b) && tope(a) > menor){
            apilar(c, desapilar(b));
        }
        apilar(b, menor);
        pasarPila(c, b);
    }
}

void ordenarInsersion(Pila *a, Pila *b, Pila *c){
    while(!pilavacia(a)){
        int temp = desapilar(a);

        while(!pilavacia(b) && tope(b) < temp){
            apilar(c, desapilar(b));
        }
        apilar(b, temp);
        pasarPila(c, b);
    }
}

void ordenarOrdenadaInsersion(Pila *a, Pila *b, Pila *c){
    int num = pedirInt();
    apilar(a, num);
    ordenarInsersion(a, b, c);
    pasarPila(b, a);
}

int sumarPila_INF(Pila *a){
    int sum = desapilar(a);
    sum += tope(a);

    return sum;
}

int sumarPila(Pila *a){
    int sum = 0;
    Pila aux;

    inicpila(&aux);

    while(!pilavacia(a)){
        sum += tope(a);
        apilar(&aux, desapilar(a));
    }
    pasarPila(&aux, a);

    return sum;
}

int contarPila(Pila *a){
    int cont = 0;
    Pila aux;

    inicpila(&aux);

    while(!pilavacia(a)){
        cont++;
        apilar(&aux, desapilar(a));
    }
    pasarPila(&aux, a);

    return cont;
}

float dividirElementos(float a, float b){
    if(b != 0){
        return a / b;
    } else {
        printf("ERROR: No se puede realizar la division.\n\n");
        return 0;
    }
}

float promediarPila(Pila *a){
    int cantElem = contarPila(a);
    int sum = sumarPila(a);

    return dividirElementos(sum, cantElem);
}

int pasarAUnDigito(Pila *a){
    int cont = 0, top = 0, mult = 0, result = 0;
    invertirPila(a);

    while(!pilavacia(a)){
        cont = contarPila(a) - 1;
        top = desapilar(a);
        mult = top*potenciar(10, cont);
        result += mult;
    }
    return result;
}

void mostrarPila(Pila *p){
    int cont = contarPila(p);
    Pila aux;

    inicpila(&aux);
    invertirPila(p);

    printf("\nBase .............................................. Tope\n");
    for(int i=0; i<cont; i++){
        printf(" %d |", tope(p));
        apilar(&aux, desapilar(p));
    }
    printf("\nBase .............................................. Tope\n\n");
    pasarPila(&aux, p);
    invertirPila(p);
}
