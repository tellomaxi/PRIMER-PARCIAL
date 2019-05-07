typedef struct
{
    int codigoSocio;
    char lastName[51];
    char name[32];
    char sexo[32];
    int telefono;
    char email[32];
    int dia;
    int mes;
    int anio;
    int isEmpty;
}eSocio;

int initSocios(eSocio list[], int len);
int findEmpty(eSocio list[],int len);
int findSocio(eSocio list[],int len, int file);
int addSocio(eSocio list[], int len);
int funcion_opcionesModificacion();
//int removeSocio(eSocio* list, int len)
void viewSocio(eSocio aSocio);
void viewSocios(eSocio list[], int len);
void modifySocio(eSocio list[], int len);
