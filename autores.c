#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "autores.h"

void harcodeoAutor(eAutor* list)
{
    eAutor x[]=
    {
        {01,"Cervantes","Miguel"},
        {02,"Capote","Truman"},
        {03,"Austen","Jane"},
        {04,"Verne","Julio"},
        {05,"Wilde","Oscar"},
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = x[i];
    }
};


void viewAutor(eAutor aAutor)
{
  printf("\nCodigo de Autor:%d - Apellido:%s - Nombre:%s\n",aAutor.codigoAutor,aAutor.lastName,aAutor.name);
};

void viewAutores(eAutor list[],int len)
{
    system("cls");

    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewAutor(list[i]);
        }
    }
};
