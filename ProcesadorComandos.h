#ifndef PROCESADORCOMANDOS_H_INCLUDED
#define PROCESADORCOMANDOS_H_INCLUDED

#include "ListaString.h"
#include "ABBPolinomio.h"
#include "Archivo.h"

void comandoCrear(ABBPolinomio &abb, ListaString ls);

void comandoSumar(ABBPolinomio &abb, ListaString ls);

void comandoMultiplicar(ABBPolinomio &abb, ListaString ls);

void comandoEvaluar(ABBPolinomio abb, ListaString ls);

void comandoEsRaiz(ABBPolinomio abb, ListaString ls);

void comandoMostrar(ABBPolinomio abb, ListaString ls);

void comandoGuardar(ABBPolinomio abb, ListaString ls);

void comandoRecuperar(ABBPolinomio &abb, ListaString ls);

#endif // PROCESADORCOMANDOS_H_INCLUDED
