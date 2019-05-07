#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "autores.h"
#include "libros.h"

void harcodeoLibros(eLibros* list)
{

    eLibros x[]=
    {
        {001,"Titanic",001,0},
        {002,"Cien años de Soledad",003,0},
        {003,"Don Quijote",002,0},
        {004,"El Principito",004,0},
        {005,"Movy Dick",005,0},
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = x[i];
    }
};

void viewLibro(eLibros aLibros)
{
    printf(" \nID:%d - Nombre:%s - Codigo Autor:%d\n  ",aLibros.id,aLibros.titulo,aLibros.codigoA);
};

void viewlibros(eLibros list[], int len)
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

int funcion_opcionesLibros()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES LIBROS ******* \n\n");
    printf(" 1- LISTAR LIBROS \n");
    printf(" 2- SALIR \n");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-2 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 2\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};
int findLibro(eLibros list[],int len, int file)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {

        if( list[i].id == file && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;

};

