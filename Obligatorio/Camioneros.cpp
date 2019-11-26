#include "Camioneros.h"

Camioneros :: Camioneros()
{
    abb = NULL;
}

bool Camioneros :: Member(long clave)
{
    return PerteneceEnArbol(abb,clave);
}

void Camioneros :: Insert(Camionero * c)
{
    InsertarEnArbol(abb,c);
}

bool Camioneros :: Empty()
{
    if(abb == NULL)
        return true;
    else
        return false;
}

Camionero * Camioneros :: Find(long clave)
{
    return ObtenerEnArbol(abb,clave);
}

void Camioneros :: listarCamioneros(Iterador &iter)
{
    cargarIterador(abb, iter);
}

Camioneros :: ~Camioneros()
{
    DestruirArbol(abb);
}

/*void listarCamioneroMaxTatuajes(Camionero*,&error)
{

}*/



///Auxiliares:
void Camioneros :: DestruirArbol(NodoABB * &a)
{
    if(a != NULL)
    {
        DestruirArbol(a->hizq);
        DestruirArbol(a->hder);
        delete(a->info);
        delete(a);
        a = NULL;
    }
}

bool Camioneros :: PerteneceEnArbol(NodoABB * a,long clave)
{
    bool encontre = false;
    while(!encontre && a != NULL)
    {
        if (clave == a->info->getCedula())
            encontre = true;
        else
        {
            if (clave < a->info->getCedula())
                a = a->hizq;
            else
                a = a->hder;
        }
    }
    return encontre;
}

void Camioneros :: InsertarEnArbol(NodoABB * &a, Camionero * c)
{

    if (a == NULL)
    {
        a = new NodoABB;
        a->info = c;
        a->hizq = NULL;
        a->hder = NULL;
    }
    else
    {
        if(c->getCedula() < a->info->getCedula())
            InsertarEnArbol(a->hizq,c);
        else
            InsertarEnArbol(a->hder,c);
    }
}

Camionero * Camioneros :: ObtenerEnArbol(NodoABB * a,long clave)
{
    if(clave == a->info->getCedula())
        return(a->info);
    else
    {
        if(clave < a->info->getCedula())
            return ObtenerEnArbol(a->hizq,clave);
        else
            return ObtenerEnArbol(a->hder,clave);
    }
}

void Camioneros :: cargarIterador(NodoABB * a, Iterador &iter)
{
    if (a != NULL)
    {
        /*cargarIterador(a->hizq, iter);
        iter.insertarObjeto(a->info);
        cargarIterador(a->hder, iter);*/

        cargarIterador(a->hder, iter);
        iter.insertarObjeto(a->info);
        cargarIterador(a->hizq, iter);
    }
}
