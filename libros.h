typedef struct
{
    int codigoDeLibro;
    char titulo[52];
    int codigoAutor;
    int isEmpty;
}eLibros;

void harcodeoLibros(eLibros* list);
void viewLibro(eLibros aLibros);
void viewLibros(eLibros list[], int len);
