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

int initSocios(eSocio list[], int len)
{
    int ret = 0;

    if(list != NULL && len > 0)
    {

        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        };
    }
    else
    {
        ret = -1;
    };

    return ret;
};

int findEmpty(eSocio list[],int len)
{
    int index = -1;
    for(int i=0; i< len ; i++)
    {
        if( list[i].isEmpty == 1)
        {
            index = i ;
            break;
        };
    };
    return index ;
};

int findSocio(eSocio list[],int len, int file)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {

        if( list[i].codigoSocio == file && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;

};


int funcion_opciones()
{
    int opcionIngresada;
    char auxOpcion[7];


    system("cls");
    printf("\n******* MENU DE OPCIONES ******* \n\n");
    printf(" 1- ALTA \n");
    printf(" 2- MODIFICAR \n");
    printf(" 3- BAJA \n");
    printf(" 4- LISTAR \n");
    printf(" 5- LISTAR LIBROS \n");
    printf(" 6- LISTAR AUTORES \n");
    printf(" 7- PRESTAMOS \n");
    printf(" 8- SALIR \n ");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-8 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 8\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};


int addSocio(eSocio list[],int len)
{
    eSocio nuevoSocio;

    int index;
    char auxiliarLastName[32];
    char auxiliarName[32];
    char auxiliarSexo[32];
    char auxiliarTelefono[51];
    char auxiliarEmail[51];
    char auxiliarDia[12];
    char auxiliarMes[12];
    char auxiliarAnio[21];
    int fechaCorrecta=-1;
    float ret;
    int apellido=0,nombre=0,sexo=0,telefono=0,email=0,fecha=0;


    if((list != NULL) && (MAXSOCIOS > 0))
    {
        system("cls");
        fflush(stdin);
        index=findEmpty(list,len);
        printf("-----ALTA SOCIO-----\n\n");

        if(index==-1)
        {
            printf("NO HAY ESPACIO EN EL SISTEMA");
            ret=-1;
            system("pause");
        }
        else
        {
            printf("SOCIO NUEVO, SU CODIGO DE SOCIO ES: %d \n",index);
            nuevoSocio.codigoSocio=index;

        ///
            if(apellido==0)
            {
                while(!funcion_getStringLetras("Ingrese Apellido: ",auxiliarLastName))
                {
                    printf("ERROR- EL APELLIDO TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                    apellido=1;

                };
                apellido=1;
            }
            printf("\nApellido: %s \n",auxiliarLastName);
        ///
            if(nombre==0)
            {
                while(!funcion_getStringLetras("Ingrese Nombre: ",auxiliarName))
                {
                    printf("ERROR- EL NOMBRE TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                    nombre=1;


                };
                 nombre=1;
            }
            printf("\nNombre: %s - Apellido: %s \n",auxiliarName,auxiliarLastName);
        ///
            if(sexo==0)
            {
                while(!funcion_getStringLetras("Ingrese Sexo: ",auxiliarSexo))
                {
                    printf("ERROR- EL Sexo TIENE QUE CONTENER SOLO LETRAS \n\n");
                    system("pause");
                    system("cls");
                    sexo=1;
                };
                sexo=1;
            }
            printf("\nNombre: %s - Apellido: %s  - Sexo: %s\n",auxiliarName,auxiliarLastName,auxiliarSexo);

        ///

            if(telefono==0)
            {
                while(!funcion_getStringNumerosFlotantes("Ingrese el telefono SIN GUIONES!:",auxiliarTelefono))
                {
                    printf("ERROR- EL TELEFONO SOLO TIENE QUE TENER NUMEROS \n\n");
                    system("pause");
                    system("cls");
                    telefono=1;
                };
                //auxiliarTelefono=funcion_ValidarTelefono(auxiliarTelefono);
                telefono=1;
            }
            printf("\nNombre:%s - Apellido:%s  - Sexo:%s  - Telefono:%f\n",auxiliarName,auxiliarLastName,auxiliarSexo,auxiliarTelefono);
      ///

            if(email==0)
            {
                while(!funcion_getStringLetras("Ingrese el email, SOLAMENTE LO QUE VA ANTES DEL ARROBA!!!",auxiliarEmail))
                {
                    printf("ERROR- EMAIL INCORRECTO \n\n");
                    system("pause");
                    system("cls");
                    email=1;
                };
                email=1;
            }
            printf("\nNombre:%s - Apellido:%s  - Sexo:%s  - Telefono:%f - Email:%s\n",auxiliarName,auxiliarLastName,auxiliarSexo,auxiliarTelefono,auxiliarEmail);

    ///

            if(fecha==0)
            {
                do
                {
                    system("cls");
                    printf("****** Fecha de Ingreso ******\n\n");

                    while(!funcion_getStringNumeros("Ingrese dia: ", auxiliarDia))
                    {
                        printf("ERROR- EL DIA TIENE QUE CONTENER SOLO NUMEROS \n\n");
                        system("pause");
                        system("cls");

                    };
                    while(!funcion_getStringNumeros("Ingrese mes: ", auxiliarMes))
                    {
                        printf("ERROR- EL MES TIENE QUE CONTENER SOLO NUMEROS \n\n");
                        system("pause");
                        system("cls");

                    };
                    while(!funcion_getStringNumeros("Ingrese año: ", auxiliarAnio))
                    {
                        printf("ERROR- EL ANIO TIENE QUE CONTENER SOLO NUMEROS \n\n");
                        system("pause");
                        system("cls");

                    };

                    fechaCorrecta=funcion_ValidarFecha(auxiliarDia,auxiliarMes,auxiliarAnio);

                }while(fechaCorrecta==0);

                fecha=1;
            }
            printf("\nNombre:%s - Apellido:%s  - Sexo:%s  - Telefono:%0.2f - Email:%s \n\nFecha de Ingreso\n\nDia %s - Mes %s - Anio %s \n\n",auxiliarName,auxiliarLastName,auxiliarSexo,auxiliarTelefono,auxiliarEmail,auxiliarDia,auxiliarMes,auxiliarAnio);
            system("pause");

            while((nombre==1)&&(apellido==1)&&(sexo==1)&&(email==1)&&(telefono==1)&&(fecha==1))
            {
                strcpy(nuevoSocio.name,auxiliarName);
                strcpy(nuevoSocio.lastName,auxiliarLastName);
                strcpy(nuevoSocio.sexo,auxiliarSexo);
                nuevoSocio.telefono=atof(auxiliarTelefono);
                strcpy(nuevoSocio.email,auxiliarEmail);
                nuevoSocio.dia=atoi(auxiliarDia);
                nuevoSocio.mes=atoi(auxiliarMes);
                nuevoSocio.anio=atoi(auxiliarAnio);

                nuevoSocio.isEmpty=0;
                list[index]=nuevoSocio;
                system("cls");
                printf("\n\n********NUEVO SOCIO, BIENVENIDO*********\n\n");
                //viewSocio(list[index]);
                printf("\n\n\n");
                ret=0;
                break;
            }
        }

    }
    else
    {
        ret =-1;
    }

    return ret;

};


int funcion_opcionesModificacion()
{
    int opcionIngresada;
    char auxOpcion[7];


    system("cls");
    printf("\n******* MENU DE OPCIONES *******");
    printf("\n Que desea modificar?\n");
    printf(" 1- NOMBRE \n");
    printf(" 2- APELLIDO \n");
    printf(" 3- SEXO \n");
    printf(" 4- TELEFONO \n");
    printf(" 5- EMAIL \n");
    printf(" 6- DIA INGRESO \n");
    printf(" 7- MES INGRESO \n");
    printf(" 8- ANIO INGRESO \n");
    printf(" 9- NO MODIFICAR NADA \n ");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-7 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al \n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};

void viewSocio(eSocio aSocio)
{

    printf(" \nCodigo de Socio:%d - Apellido:%s -  Nombre:%s- Sexo:%s - Telefono:%d -  Email:%s-  Dia:%d-  Mes:%d-  Anio:%d \n ", aSocio.codigoSocio, aSocio.lastName, aSocio.name, aSocio.sexo, aSocio.telefono,aSocio.email,aSocio.dia,aSocio.mes,aSocio.anio);
};


void viewSocios(eSocio list[], int len)
{

    system("cls");


    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewSocio(list[i]);
        }
    }

};



int removeSocio(eSocio* list, int len)
{
    int index;
    char next[3];
    int id;
    char auxId[4];


    system("cls");
    printf("  *** BAJA SOCIO ***\n\n");

    while(!funcion_getStringNumeros("Ingrese Codigo de Socio: ", auxId))
    {
        printf("ERROR- EL LEGAJO TIENE QUE TENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");
    };
    id=atoi(auxId);

    index = findSocio(list, len, id);

    while (index == 0)
    {
        printf("NO HAY NINGUN SOCIO CON ESE CODIGO %d\n\n", id);
        while(!funcion_getStringNumeros("Ingrese un legajo existente: ", auxId))
        {
            printf("ERROR- EL ID TIENE QUE TENER SOLO NUMEROS \n\n");
            system("pause");
            system("cls");
        };
        id=atoi(auxId);
        index = findSocio(list, len, id);

    }


    while (index == 1)
    {
        viewSocio(list[index]);

        while(!funcion_getStringLetras("\nQUIERE BORRAR USUARIO DEL SISTEMA? si/no: ",next))
        {
            printf("\n ERROR DEBE CONTENER SOLO LETRAS");
        }

        fflush(stdin);


        if(strcmp(next,"si") && strcmp(next,"SI"))
        {
            printf("NO SE REALIZO LA BAJA\n\n");
            break;


        }
        else if(strcmp(next,"no")&& strcmp(next,"NO"))
        {

            list[index].isEmpty = 1;
            printf("SE HIZO LA BAJA DEL EMPLEADO CORRECTAMENTE\n\n");
            break;


        }
    }

    return -1;
};


void modifySocio(eSocio list[], int len)
{
    int id;
    char auxId[5];
    int index;
    char newLastName[51];
    char newName[51];
    char newSexo[31];
    char newTelefono[31];
    char newEmail[51];
    int newDia;
    int newMes;
    int newAnio;
    char seguir='s';
    int exit = 1;



    system("cls");
    printf("  *** Modificar  empleado ***\n\n");

    while(!funcion_getStringNumeros("Ingrese legajo: ", auxId))
    {
        printf("ERROR- EL CODIGO TIENE QUE TENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");
    };

    id=atoi(auxId);

    index=findSocio(list,len,id);

    while (index == -1)
    {
        printf("NO HAY NINGUN SOCIO CON ESE LEGAJO %d\n\n", id);
        while(!funcion_getStringNumeros("Ingrese un legajo existente: ", auxId))
        {
            printf("ERROR- EL LEGAJO TIENE QUE TENER SOLO NUMEROS \n\n");
            system("pause");
            system("cls");
        };
        id=atoi(auxId);
        index = findSocio(list, len, id);

    }


    while ((index >= 0) && (index <=1000))
    {
        viewSocio(list[index]);

        do
        {
            switch(funcion_opcionesModificacion())
            {
            case 1:
                fflush(stdin);
                viewSocio(list[index]);
                while(!funcion_getStringLetras("Ingrese nombre nuevo: ", newName))
                {
                    printf("ERROR- EL NOMBRE TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].name,newName);
                exit = 0;
                break;

            case 2:
                fflush(stdin);
                viewSocio(list[index]);
                while(!funcion_getStringLetras("Ingrese apellido nuevo: ",newLastName))
                {
                    printf("ERROR- EL APELLIDO TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].lastName,newLastName);
                exit = 0;
                break;

            case 3:
                fflush(stdin);
                viewSocio(list[index]);
                while(!funcion_getStringLetras("Ingrese sexo nuevo: ",newSexo))
                {
                    printf("ERROR- EL SEXO TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].sexo,newSexo);
                exit = 0;
                break;

            case 4:
                fflush(stdin);
                viewSocio(list[index]);
                while(!funcion_getStringNumeros("Ingrese apellido nuevo: ",newTelefono))
                {
                    printf("ERROR- EL TELEFONO TIENE QUE CONTENER SOLO NUMEROS\n\n ");
                    system("pause");
                    system("cls");
                };
                list[index].telefono=atoi(newTelefono);
                exit = 0;
                break;

            case 5:
                fflush(stdin);
                viewSocio(list[index]);
                while(!funcion_getStringLetras("Ingrese el email, SOLAMENTE LO QUE VA ANTES DEL ARROBA!!!",newEmail))
                {
                    printf("ERROR- EMAIL INCORRECTO \n\n");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].email,newEmail);
                exit = 0;
                break;

            case 6:
                fflush(stdin);
                viewSocio(list[index]);
                while(!funcion_getStringNumeros("Ingrese el nuevo dia de ingreso: ",newDia))
                {
                    printf("ERROR- EL DIA TIENE QUE CONTENER SOLO NUMEROS\n\n ");
                    system("pause");
                    system("cls");
                };
                list[index].dia=atoi(newDia);
                exit = 0;
                break;

            case 7:
                fflush(stdin);
                viewSocio(list[index]);
                while(!funcion_getStringNumeros("Ingrese el nuevo mes de ingreso: ",newMes))
                {
                    printf("ERROR- EL DIA TIENE QUE CONTENER SOLO NUMEROS\n\n ");
                    system("pause");
                    system("cls");
                };
                list[index].mes=atoi(newMes);
                exit = 0;
                break;

            case 8:
                fflush(stdin);
                viewSocio(list[index]);
                while(!funcion_getStringNumeros("Ingrese el nuevo año de ingreso: ",newAnio))
                {
                    printf("ERROR- EL ANIO TIENE QUE CONTENER SOLO NUMEROS\n\n ");
                    system("pause");
                    system("cls");
                };
                list[index].anio=atoi(newAnio);
                exit = 0;
                break;

            case 9:
                printf("Volviendo a menu principal");
                exit = 1;

                break;

            default:
                printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 8\n\n");
                system("pause");
                break;
            }

            if(exit==0)
            {
                printf("\n     *** MODIFICACCION EXITOSA ***");
                printf("\nDesea continuar modificando? \n\n");
                scanf("%c",&seguir);

                fflush(stdin);
                system("cls");
                break;
            }
            else
            {
                printf("\n\nEsta por salir de modificacion esta seguro? s/n \n\n");
                scanf("%c",&seguir);

                fflush(stdin);
                system("cls");
            }

            return;

        }while(seguir == 's' || seguir == 'S');
    }
};
