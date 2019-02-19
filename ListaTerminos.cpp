#include "ListaTerminos.h"

boolean listaTerminosEsVacia(ListaTerminos listaT)
{
    boolean EsVacia = FALSE;
    if (listaT == NULL)
        EsVacia = TRUE;
    return EsVacia;
}

void listaTerminosResto(ListaTerminos &listaT); /*borrar 1er valor*/


void listaTerminosCrear(ListaTerminos &listaT)
{
    listaT = NULL;
}

void listaTerminosInsertarOrdenado(ListaTerminos &listaT, Termino t)
{
    if(listaT == NULL)
    {
        listaT = new nodoT;
        listaT->info = t;
        listaT->Sig = NULL;
    }
    else
    {
        if(DarGradoTermino(t) >= DarGradoTermino(listaT ->info))
        {
            ListaTerminos aux = new nodoT;
            aux->info = t;
            aux->Sig = listaT;
            listaT = aux;
        }
        else
            listaTerminosInsertarOrdenado(listaT->Sig,t);
    }
}


void listaTerminosMostrar(ListaTerminos t)
{
    while (t->Sig != NULL)
    {
        MostrarTermino(t->info);
        t = t->Sig;
    }
}

long int evaluarPolinomio(ListaTerminos listaT, int valor)
{
    long int resultado  = 0;
    return resultado;
}

void sumarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado)
{

}

void multiplicarPolinomios(ListaTerminos listaA, ListaTerminos listaB, ListaTerminos &listaResultado)
{

}
/*
void levantarTerminos(file * f, ListaTerminos &listaT)
{

}

void bajarTerminos(file * f, ListaTerminos listaTerminos);
*/

boolean representaPolinomioNulo(ListaTerminos listaTerminos)
{
    boolean resu = FALSE;
    if (listaTerminos == NULL)
        resu = TRUE;
    return resu;
}

ListaTerminos reducePolinomio(ListaTerminos listaTerminos)
{
    ListaTerminos aux;
    return aux;
}
