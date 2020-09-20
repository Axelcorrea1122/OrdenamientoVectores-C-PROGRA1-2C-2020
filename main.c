#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSO 0
#define VERDADERO 1
#define TAM_VEC 10

int* buscarMenor(int* v, int* desde, int* hasta);
void intercambiar(int* a, int* b);
void mostrarVec(int* v, int c);
void ordenarVecSeleccionAsc(int* v, int c);
void ordenarVecBurbujaAsc(int v[], int ce);
void cargarVecRandom(int* v, int c);

int main()
{
    int vec[TAM_VEC] = {8,5,3,4,9,6,1,2,7,0};
    int ce = TAM_VEC;
    //int vec [100000];
    //int ce = 100000;

    //cargarVecRandom(vec,ce);

    mostrarVec(vec, ce);
    //int tAntes = time(NULL);
    ordenarVecBurbujaAsc(vec, ce);
    //int tDespues = time(NULL);
    mostrarVec(vec, ce);

    //int tRecord = tDespues - tAntes;

    //printf("El ordenamiento tardo %d segundos",tRecord);

    return 0;
}


void ordenarVecBurbujaAsc(int* v, int ce)
{
    int huboIntercambio=VERDADERO;
    int* ult = v+(ce-1);

    for( int* i=v+1 ; i<=ult && huboIntercambio ; i++){
            huboIntercambio = FALSO;
        for( int* j=v ; j<= ult-(i-v) ; j++){
            if(*j > *(j+1)){
                intercambiar(j, j+1);
                huboIntercambio = VERDADERO;
            }
        }
    }


    /**int i=1;
    int huboIntercambio;
    do{
        huboIntercambio=FALSO;

        for(int j=0 ; j<=ce-1-i ; j++){
            if(v[j] > v[j+1]){
                intercambiar(&v[j], &v[j+1]);
                huboIntercambio = VERDADERO;
            }
        }
        i++;
    }while(i<ce&&huboIntercambio);**/
    //####OTRA FORMA DE HACER EL RECORRIDO CON UN DO WHILE
}

void ordenarVecSeleccionAsc(int* v, int c)
{
    int *m;
    int* ult = v+(c-1);
    for( int* i=v ; i<=ult-1 ; i++){
        m = buscarMenor(v, i, ult);

        if(*i != *m)
            intercambiar(i, m);
    }
}

void mostrarVec(int v[], int c)
{
    int* ult = v+(c-1);
    for(int* i=v ; i<=ult ; i++){
        printf("[%d]", *i);
    }
    putchar('\n');
}

void intercambiar(int* a, int* b)
{
    int bCopia = *b;
    *b = *a;
    *a = bCopia;
}

void cargarVecRandom(int* v, int c)
{
    srand(time(NULL));

    for(int i=0 ; i<c ; i++){
        v[i] = rand();
    }
}

int* buscarMenor(int* v, int* desde, int* hasta)
{
    int* m = desde;

    for(int* i = desde+1 ; i<=hasta ; i++){
        if(*i < *m)
            m = i;
    }
    return m;
}
