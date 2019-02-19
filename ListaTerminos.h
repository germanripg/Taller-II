#ifndef LISTATERMINOS_H_INCLUDED
#define LISTATERMINOS_H_INCLUDED

#include "Termino.h"
#include "Boolean.h"

typedef struct nodoT { Termino info;
                        nodoT * Sig;
                      } nodoTermino;

typedef nodoTermino * ListaTerminos;

boolean listaTerminosEsVacia(ListaTerminos listaT);

void listaTerminosResto(ListaTerminos &listaT); /*borrar 1er valor*/
/*Precondici�n: lista no vac�a*/

void listaTerminosCrear(ListaTerminos &listaT);

void listaTerminosInsertarOrdenado(ListaTerminos &listaT, Termino t);
/*inserta recursivamente ordenado por grado*/

void listaTerminosMostrar(ListaTerminos t);

long int evaluarPolinomio(ListaTerminos listaT, int valor);

void sumarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);

void multiplicarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado);

//void levantarTerminos(file * f, ListaTerminos &listaT);

//void bajarTerminos(file * f, ListaTerminos listaT);

boolean representaPolinomioNulo(ListaTerminos listaT);

ListaTerminos reducePolinomio(ListaTerminos listaT);

#endif // LISTATERMINOS_H_INCLUDED