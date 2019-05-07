#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "libros.h"

void harcodeoLibros(eLibros* list)
{
    eLibros x[]=
    {
        {1,"Titanic",01},
        {2,"Cien años de Soledad",02},
        {3,"Don Quijote",01},
        {4,"Hamlet",02},
        {5,"El Principito",03},
        {6,"La Odisea",04},
        {7,"Lo que el viento se llevo",05},
        {8,"Movy Dick",05},
        {9,"Alicia en el pais de las maravillas",02},
        {10,"El señor de los anillos",04},
    };
    for(int i = 0; i< 10; i++)
    {
        list[i] = x[i];
    }
};

void viewLibro(eLibros aLibros)
{
    printf("\nCodigo de Libro:%d  -  Titulo:%s  - Codigo de Autor:%d",aLibros.codigoDeLibro,aLibros.titulo,aLibros.codigoAutor);
};

void viewLibros(eLibros list[], int len)
{
    system("cls");

    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewLibro(list[i]);
        }
    }
};
