#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "autores.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"


#define MAXSOCIOS 1001
#define MAXPRESTAMOS 1001
#define MAXAUTORES 50
#define MAXLIBROS 100
int funcion_opciones();

int main()
{
    eAutor autores[MAXAUTORES];
    eLibros libros[MAXLIBROS];
    //eSocio socio[MAXSOCIOS];

    harcodeoAutor(autores);
    harcodeoLibros(libros);

    char seguir='s';
    eSocio socio[MAXSOCIOS];
    initSocios(socio,MAXSOCIOS);
    int flagNoIngresoSocio=0;


    do
    {
        switch(funcion_opciones())
        {
        case 1:
            addSocio(socio,MAXSOCIOS);
            flagNoIngresoSocio++;
            break;
        case 2:
            if(flagNoIngresoSocio==0)
            {
                printf("Error, no existen empleados en el sistema");
                break;
            }
            else
            {
                modifySocio(socio,MAXSOCIOS);
            };
            break;

        case 3:
            if (flagNoIngresoSocio== 0)
                {
                    printf("\nNO EXISTEN SOCIOS EN EL SISTEMA\n\n");
                    break;
                }
                else
                {
                    removeSocio(socio, MAXSOCIOS);
                };
                break;
        default:
            printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 5\n\n");
            system("pause");
            break;

        }
        printf("\n Desea continuar? si/no \n\n");
        scanf("%c",&seguir);

        fflush(stdin);
        system("cls");

    }while (seguir == 's' || seguir == 'S');



    printf("\n\n Saliendo...\n\n");


    return 0;
}
