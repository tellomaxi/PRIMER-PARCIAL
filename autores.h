typedef struct
{
    int codigoAutor;
    char lastName[32];
    char name[32];
    int isEmpty;
}eAutor;

void harcodeoAutor(eAutor* list);
void viewAutor(eAutor aAutores);
void viewAutores(eAutor list[], int len);
