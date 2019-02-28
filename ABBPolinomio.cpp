#include "ABBPolinomio.h"

void ABBPolinomioCrear(ABBPolinomio &a)
{
    a = NULL;
}

boolean ABBPolinomioEsVacio(ABBPolinomio a)
{
    boolean resu = FALSE;
    if (a==NULL)
    {
        resu = TRUE;
    }
    return resu;
}

//Precondici�n: Arbol NO vac�o
Polinomio ABBPolinomioDarRaiz(ABBPolinomio a)
{
    return a->info;
}

//Precondici�n: Arbol NO vac�o
ABBPolinomio darHijoIzq(ABBPolinomio a)
{
    return a->hizq;
}

//Precondici�n: Arbol NO vac�o
ABBPolinomio darHijoDer(ABBPolinomio a)
{
    return a->hder;
}

//Precondici�n: �rbol no sea vac�o
/// void ListarOrdenado(ABBPolinomios a)
void ListarABB(ABBPolinomio a)
{
     if (a != NULL)
     {
         ListarABB(a->hizq); ///ListarOrdenado(a -> hizq);
         mostrarPolinomio(a->info);
         ListarABB(a->hder); ///ListarOrdenado(a -> hder);
     }
}

boolean ABBPolinomioExiste(ABBPolinomio a, String nombrePolinomio)
{
    String straux;
    if (a == NULL)
        return FALSE;
    else
    {
        darNombrePolinomio(a->info,straux);
        if (streq(straux,nombrePolinomio))
            return TRUE;
        else
        {
            if (strmen(nombrePolinomio,straux))
                return ABBPolinomioExiste(a->hizq,nombrePolinomio);
            else
                return ABBPolinomioExiste(a->hder,nombrePolinomio);
        }
    }
}

void ABBPolinomioInsertar(ABBPolinomio &a, Polinomio p)
{
    if(a == NULL)
    {
        a = new nodoABB;
        a->info = p;
        a->hizq = NULL;
        a->hder = NULL;
    }
    else
    {
        String auxABB,auxPol;
        strcrear(auxABB);
        strcrear(auxPol);

        darNombrePolinomio(a->info,auxABB);
        darNombrePolinomio(p,auxPol);
        if (strmen(auxPol,auxABB))
            ABBPolinomioInsertar(a->hizq, p);
        else
            ABBPolinomioInsertar(a->hder, p);
    }
}

Polinomio darPolinomio(ABBPolinomio a, String nombrePol)
{
    String straux;
    darNombrePolinomio(a->info,straux);
    if(streq(straux,nombrePol))
        return a->info;
    else
    {
        if (strmen(nombrePol,straux))
        {
            /// OJO ACA!!! Llaman a ABBPolinomioExiste, que devuelve un boolean!!!
            /// habria que llamar recursivamente a la propia darPolinomio
            /// y retornar algo
            return darPolinomio(a->hizq,nombrePol);
        }
        else
        {
            /// OJO ACA!!! Llaman a ABBPolinomioExiste, que devuelve un boolean!!!
            /// habria que llamar recursivamente a la propia darPolinomio
            return darPolinomio(a->hder,nombrePol);
            /// y retornar algo
        }
    }
}

void ABBPolinomioEliminar(ABBPolinomio &a)
{
    if(a != NULL)
    {
        ABBPolinomioEliminar(a->hizq);
        ABBPolinomioEliminar(a->hder);
        borrarPolinomio(a->info);
        a = NULL;
    }
}

