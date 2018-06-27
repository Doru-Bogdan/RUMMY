#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include "structuri.h"
#include "functii.h"


int main()
{
    int nrpl;
    v = (int*)malloc(5 * sizeof(int));
    wellcome();
    printf("Scrieti numarul de jucatori: ");
    scanf("%d", &nrpl);
    inregistrare(nrpl);
    creeare_pachet();
    amestecare();
    gameplay(nrpl);
    afis(nrpl);
    fisier(nrpl);

return 0;
}
