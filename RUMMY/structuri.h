#define CARTI 104

struct player{
        char nume[10];
        int scor : 32;
        char numar_j[15];
        char culoare_j[4];
    }pl[4];

struct _carte{
        char numar_c;
        char culoare_c;
    }carte_j[CARTI];

int *v;


