void inregistrare(int nrpl) // Inregistrarea player
{
    int i;
    while(nrpl <= 1 || nrpl > 4)
    {
        printf("Numar jucatori neacceptat \n");
        printf("Scrieti numarul de jucatori: ");
        scanf("%d", &nrpl);
    }
    for(i=1;i<=nrpl;i++)
    {
        printf("Scrieti numele player %i (maxim 10 caractere):",i);
        scanf("%s", &pl[i].nume);
        pl[i].scor = 0;
    }
    system("cls");
}

void creeare_pachet() // Crearea pachetelor de carti
{
    int i, j;
    char *carte , *culoare;
    carte = (char *) malloc(13 * sizeof(char));
    culoare = (char *) malloc(4 * sizeof(char));
    culoare[0] = 'r'; culoare[1] = 'n'; culoare[2] = 'v'; culoare[3] = 'a';
    carte[0] = '1'; carte[1] = '2'; carte[2] = '3'; carte[3] = '4';
    carte[4] = '5'; carte[5] = '6'; carte[6] = '7'; carte[7] = '8';
    carte[8] = '9'; carte[9] = 'k'; carte[10] = 'l'; carte[11] = 'm';
    carte[12] = 'n';  // 10 este notat cu k, 11 este notat cu l, 12 este notat cu m, 13 este notat cu n
    int k = 0;
    for(i = 0 ; i < 13 ; i++)
    {
            for(j = 0 ; j < 4 ; j++)
              {
                  carte_j[k].numar_c = carte[i];
                  carte_j[k].culoare_c = culoare[j];
                  k++;
              }
    }
    for(i = 0 ; i < 13 ; i++)
    {
            for(j = 0 ; j < 4 ; j++)
              {
                  carte_j[k].numar_c = carte[i];
                  carte_j[k].culoare_c = culoare[j];
                  k++;
              }
    }

    for(i = 0 ; i < CARTI; i++)
        printf("%c%c ", carte_j[i].numar_c, carte_j[i].culoare_c);
}

void wellcome()
{
    printf("             WELLCOME TO RUMMY \n\n");
}

void amestecare() // functia de amestecare a cartilor
{
    int i;
    for(i = 0 ; i < CARTI ; i++)
    {
        int a = rand() % CARTI;
        struct _carte temp = carte_j[i];
        carte_j[i] = carte_j[a];
        carte_j[a] = temp;
    }
    printf("\n\n");
    for(i = 0 ; i < CARTI; i++)
        printf("%c%c ", carte_j[i].numar_c, carte_j[i].culoare_c);
        //Sleep(3000);
        system("cls");
        printf("\n\n");
}

void carte_noua(int j, int nr) // Algoritm de eliminare a cartilor pentru primele miscari
{
    int var1, var, i;
    char f[2], d[2];
    printf("Cartea noua a jucatorului %d este: ", j);
        printf("%c%c\n", carte_j[nr].numar_c, carte_j[nr].culoare_c );
        printf("O acceptati sau nu (raspundeti cu 0 sau 1): ");
        scanf("%d", &var1);
        while(var1 != 1 && var1 != 0)
        {
            printf("Raspundeti cu 0 sau 1 !!!\n");
            scanf("%d", &var1);
        }
        switch(var1)
        {
            case 1 :{
                pl[j].numar_j[14] = carte_j[nr].numar_c;
                pl[j].culoare_j[14] = carte_j[nr].culoare_c;
                printf("Cartea pe care doriti sa o eliminati are culoarea:");
                scanf("%s", &f);
                while(f[0] != 'n' && f[0] != 'a' && f[0] != 'v' && f[0] != 'r')
                {
                    printf("ATENTIE! AI GRESIT, BAGA CULOAREA BUNA: ");
                scanf("%s", &f);
                }
                printf("Cartea pe care doriti sa o eliminati are numarul:");
                scanf("%s", &d);
                while(d[0] != '1' && d[0] != '2' && d[0] != '3' && d[0] != '4' &&
                       d[0] != '5' && d[0] != '6' && d[0] != '7' && d[0] != '8' &&
                       d[0] != '9' && d[0] != 'k' && d[0] != 'l' && d[0] != 'm' && d[0] != 'n')
                {
                    printf("ATENTIE! AI GRESIT, BAGA NUMARUL BUN: ");
                scanf("%s", &d);
                }
                for(i = 0 ; i < 15 ; i++)
                    if(pl[j].culoare_j[i] == f[0] && pl[j].numar_j[i] == d[0])
                        var = i;
                for(i = var ; i < 15 ; i++)
                {
                    pl[j].culoare_j[i] = pl[j].culoare_j[i+1];
                    pl[j].numar_j[i] = pl[j].numar_j[i+1];
                }
                break;
                    }
            case 0 : {
                    printf("Cartea nu a fost acceptata! \n");
                    break;
                     }
        }
}

void carte_noua_1(int j, int nr, int *v) // Algoritm de eliminare a cartilor dupa decizie
{
    int var2, var1, var, i;
    char f[2], d[2];
    printf("Cartea noua a jucatorului %d este: ", j);
        printf("%c%c\n", carte_j[nr].numar_c, carte_j[nr].culoare_c );
        printf("O acceptati sau nu: ");
        scanf("%d", &var1);
        while(var1 != 1 && var1 != 0)
        {
            printf("Raspundeti cu 0 sau 1 !!!\n");
            scanf("%d", &var1);
        }
        switch(var1)
        {
            case 1 :{
                pl[j].numar_j[v[j]] = carte_j[nr].numar_c;
                pl[j].culoare_j[v[j]] = carte_j[nr].culoare_c;
                v[j]++;
                printf("Doriti sa eliminati o carte? Raspundeti doar cu 0 sau 1: ");
                scanf("%d", &var2);
                while(var2!= 1 && var2 != 0)
                {
                    printf("Raspundeti cu 0 sau 1 !!!\n");
                    scanf("%d", &var2);
                }
                if(var2 == 1)
                {
                    printf("Cartea pe care doriti sa o eliminati are culoarea:");
                    scanf("%s", &f);
                    while(f[0] != 'n' && f[0] != 'a' && f[0] != 'v' && f[0] != 'r')
                    {
                        printf("ATENTIE! AI GRESIT, BAGA CULOAREA BUNA: ");
                        scanf("%s", &f);
                    }
                    printf("Cartea pe care doriti sa o eliminati are numarul:");
                    scanf("%s", &d);
                    while(d[0] != '1' && d[0] != '2' && d[0] != '3' && d[0] != '4' &&
                       d[0] != '5' && d[0] != '6' && d[0] != '7' && d[0] != '8' &&
                       d[0] != '9' && d[0] != 'k' && d[0] != 'l' && d[0] != 'm' && d[0] != 'n')
                    {
                        printf("ATENTIE! AI GRESIT, BAGA NUMARUL BUN: ");
                        scanf("%s", &d);
                    }
                    for(i = 0 ; i < v[j] ; i++)
                    if(pl[j].culoare_j[i] == f[0] && pl[j].numar_j[i] == d[0])
                            var = i;
                    for(i = var ; i < v[j] ; i++)
                    {
                        pl[j].culoare_j[i] = pl[j].culoare_j[i+1];
                        pl[j].numar_j[i] = pl[j].numar_j[i+1];
                    }
                    }
                    break;
                    }
            case 0 : {
                    printf("Cartea nu a fost acceptata! \n");
                    break;
                     }
        }
}

void gameplay(int nrpl)
{
    int i, j = 1, k = 0;
    int nr = 15, a = 0;
    while(j <= nrpl) // Impartirea cartilor
    {
        for(i = a ; i < nr ; i++)
      {
        pl[j].numar_j[k] = carte_j[i].numar_c;
        pl[j].culoare_j[k] = carte_j[i].culoare_c;
        k++;
      }
      k = 0;
      j++;
      a = nr;
      nr = nr + 14;
    }

    struct player temp;

    for(i = 0 ; i < 14 ; i++) // Ordonarea initiala a cartilor
        for(k = i+1 ; k < 15 ; k++)
        {
            if(pl[1].culoare_j[i] > pl[1].culoare_j[k])
            {
                temp.culoare_j[0] = pl[1].culoare_j[i];
                temp.numar_j[0] = pl[1].numar_j[i];
                pl[1].culoare_j[i] = pl[1].culoare_j[k];
                pl[1].numar_j[i] = pl[1].numar_j[k];
                pl[1].culoare_j[k] = temp.culoare_j[0];
                pl[1].numar_j[k] = temp.numar_j[0];
            }
        }

    for(j = 2; j <= nrpl ; j++)
          for(i = 0 ; i < 13 ; i++)
            for(k = i+1 ; k < 14 ; k++)
          {
                if(pl[j].culoare_j[i] > pl[j].culoare_j[k])
              {
                temp.culoare_j[0] = pl[j].culoare_j[i];
                temp.numar_j[0] = pl[j].numar_j[i];
                pl[j].culoare_j[i] = pl[j].culoare_j[k];
                pl[j].numar_j[i] = pl[j].numar_j[k];
                pl[j].culoare_j[k] = temp.culoare_j[0];
                pl[j].numar_j[k] = temp.numar_j[0];
              }
          }

    for(i = 1 ; i < 14 ; i++)
        for(k = i+1 ; k < 15 ; k++)
        {
            if(pl[1].culoare_j[i] == pl[1].culoare_j[k])
                if(pl[1].numar_j[i] > pl[1].numar_j[k])
            {
                temp.numar_j[1]= pl[1].numar_j[i];
                pl[1].numar_j[i] = pl[1].numar_j[k];
                pl[1].numar_j[k] = temp.numar_j[1];
            }
        }

    for(j = 2; j <= nrpl ; j++)
          for(i = 0 ; i < 13 ; i++)
            for(k = i+1 ; k < 14 ; k++)
              if(pl[j].culoare_j[i] == pl[j].culoare_j[k])
                if(pl[j].numar_j[i] > pl[j].numar_j[k])
              {
                temp.numar_j[1]= pl[j].numar_j[i];
                pl[j].numar_j[i] = pl[j].numar_j[k];
                pl[j].numar_j[k] = temp.numar_j[1];
              }

    fflush(stdin);
    char f[2], d[2];
          printf("Cartile jucatorului 1 sunt:\n");
          for(i = 0 ; i < 15 ; i++)
            printf("%c%c " , pl[1].numar_j[i] , pl[1].culoare_j[i]);
    printf("\n");
    printf("Cartea pe care doriti sa o eliminati are culoarea:");
    scanf("%s", &f);
    while(f[0] != 'n' && f[0] != 'a' && f[0] != 'v' && f[0] != 'r')
    {
        printf("ATENTIE! AI GRESIT, BAGA CULOAREA BUNA: ");
        scanf("%s", &f);
    }
    printf("Cartea pe care doriti sa o eliminati are numarul:");
    scanf("%s", &d);
    while(d[0] != '1' && d[0] != '2' && d[0] != '3' && d[0] != '4' &&
          d[0] != '5' && d[0] != '6' && d[0] != '7' && d[0] != '8' &&
          d[0] != '9' && d[0] != 'k' && d[0] != 'l' && d[0] != 'm' && d[0] != 'n')
    {
        printf("ATENTIE! AI GRESIT, BAGA NUMARUL BUN: ");
        scanf("%s", &d);
    }
    int var, var1;
    for(i = 0 ; i < 15 ; i++)
        if(pl[1].culoare_j[i] == f[0] && pl[1].numar_j[i] == d[0])
        var = i;
    for(i = var ; i < 15 ; i++)
    {
        pl[1].culoare_j[i] = pl[1].culoare_j[i+1];
        pl[1].numar_j[i] = pl[1].numar_j[i+1];
    }
    nr = nr - 14;
    for(j = 2 ; j <= nrpl ; j++)
    {
        printf("Cartile jucatorului %d sunt:\n", j);
        for(i = 0 ; i < 14 ; i++)
            printf("%c%c " , pl[j].numar_j[i] , pl[j].culoare_j[i]);
        printf("\n");
        carte_noua(j, nr);
        nr++;
    }
    for(i = 1 ; i <= nrpl ; i++)
        v[i] = 14;
    j = 1;
    int cont = 0, elem_1;
    fflush(stdin);
    fflush(stdout);
    char s[2];
    while(nr < 102 && v[j] != 2)
    {
        printf("Cum doriti sa sortati cartile? Suita sau terta? Raspundeti cu s sau t! : "); // Decizia player de a sorta cortile
        scanf("%s", &s);
        while(s[0] != 's' && s[0] != 't')
        {
            printf("Nu ati introdus corect!!! Mai incercati: ");
            scanf("%s", &s);
        }
        switch(s[0])
        {
            case 's' : {
                            carte_noua_1(j, nr, v);
                            for(i = 0 ; i < v[j] - 1 ; i++) // Sortarea cartilor pentru suita
                             for(k = i+1 ; k < v[j] ; k++)
                             {
                                if(pl[j].culoare_j[i] > pl[j].culoare_j[k])
                                {
                                temp.culoare_j[0] = pl[j].culoare_j[i];
                                temp.numar_j[0] = pl[j].numar_j[i];
                                pl[j].culoare_j[i] = pl[j].culoare_j[k];
                                pl[j].numar_j[i] = pl[j].numar_j[k];
                                pl[j].culoare_j[k] = temp.culoare_j[0];
                                pl[j].numar_j[k] = temp.numar_j[0];
                                }
                             }
                            for(i = 0 ; i < v[j] - 1 ; i++)
                             for(k = i+1 ; k < v[j] ; k++)
                              if(pl[j].culoare_j[i] == pl[j].culoare_j[k])
                               if(pl[j].numar_j[i] > pl[j].numar_j[k])
                               {
                                temp.numar_j[1]= pl[j].numar_j[i];
                                pl[j].numar_j[i] = pl[j].numar_j[k];
                                pl[j].numar_j[k] = temp.numar_j[1];
                               }
                            printf("Cartile jucatorului %d sunt:\n", j);
                            for(i = 0 ; i < v[j] ; i++)
                                printf("%c%c " , pl[j].numar_j[i] , pl[j].culoare_j[i]);
                            printf("\n");
                            i = -1;
                            while(i < 14) // Compararea cartilor pentru punctaj
                            {
                                i++;
                                if(pl[j].culoare_j[i] == pl[j].culoare_j[i + 1] || pl[j].culoare_j[i] == pl[j].culoare_j[i - 1])
                                {
                                    if((pl[j].numar_j[i + 1] - pl[j].numar_j[i] == 1) || (pl[j].numar_j[i] == '9' && pl[j].numar_j[i+1] == 'k') || (pl[j].numar_j[i] - pl[j].numar_j[i - 1] == 1))
                                    {
                                        elem_1 = i;
                                        cont++;
                                    }
                                    else if(cont < 3)
                                        cont = 0;
                                        else break;
                                }
                                else if(cont >= 3)
                                    break;

                            }
                            if(cont >= 3) // Initializarea etalarii
                            {
                                printf("Va puteti etala cu %d carti!! Doriti sa faceti aceasta miscare:", cont);
                                scanf("%d", &var1);
                                while(var1!= 1 && var1 != 0)
                                {
                                    printf("Raspundeti cu 0 sau 1 !!!\n");
                                    scanf("%d", &var1);
                                }
                                switch(var1)
                                {
                                    case 1 : {
                                                pl[j].scor = pl[j].scor + cont * 5;
                                                elem_1 = elem_1 - cont + 1;
                                                for(k = (i - cont) ; k < v[j] ; k++)
                                                {
                                                    pl[j].culoare_j[k] = pl[j].culoare_j[k + cont];
                                                    pl[j].numar_j[k] = pl[j].numar_j[k + cont];
                                                }
                                                v[j] = v[j] - cont;
                                                printf("Cartile jucatorului %d sunt:\n", j);
                                                for(i = 0 ; i < v[j] ; i++)
                                                    printf("%c%c " , pl[j].numar_j[i] , pl[j].culoare_j[i]);
                                                break;
                                             }
                                    case 0 : {
                                                printf("Etalare anulata!!!");
                                                break;
                                             }
                                }
                            }
                            cont = 0;
                            nr++;
                            j++;
                            if(j > nrpl)
                                j = 1;
                            system("cls");
                            printf("\n");
                            break;
                       }
            case 't' :{
                        carte_noua_1(j, nr, v);
                        for(i = 0 ; i < v[j] - 1 ; i++) // Sortarea pentru terta
                         for(k = i+1 ; k < v[j] ; k++)
                         {
                            if(pl[j].culoare_j[i] != pl[j].culoare_j[k] && pl[j].numar_j[i] == pl[j].numar_j[k])
                            {
                            temp.culoare_j[0] = pl[j].culoare_j[i + 1];
                            temp.numar_j[0] = pl[j].numar_j[i + 1];
                            pl[j].culoare_j[i + 1] = pl[j].culoare_j[k];
                            pl[j].numar_j[i + 1] = pl[j].numar_j[k];
                            pl[j].culoare_j[k] = temp.culoare_j[0];
                            pl[j].numar_j[k] = temp.numar_j[0];
                            }
                         }
                        printf("Cartile jucatorului %d sunt:\n", j); // Compararea cartilor pentru punctaj
                            for(i = 0 ; i < v[j] ; i++)
                                printf("%c%c " , pl[j].numar_j[i] , pl[j].culoare_j[i]);
                        printf("\n");
                            i = -1;
                        while(i < 14)
                        {
                            i++;
                            if((pl[j].culoare_j[i] != pl[j].culoare_j[i + 1] || pl[j].culoare_j[i] != pl[j].culoare_j[i - 1]
                               || pl[j].culoare_j[i] == pl[j].culoare_j[i + 1] || pl[j].culoare_j[i] == pl[j].culoare_j[i - 1])
                               && (pl[j].numar_j[i] == pl[j].numar_j[i + 1] || pl[j].numar_j[i] == pl[j].numar_j[i - 1]))
                            {
                                printf("%c%c ", pl[j].numar_j[i], pl[j].culoare_j[i]);
                                elem_1 = i;
                                cont++;
                            }
                            else if(cont < 3)
                                cont = 0;
                                else break;
                        }
                        if(cont >= 3) // Initializarea etalarii
                        {
                            printf("Va puteti etala cu %d carti!! Doriti sa faceti aceasta miscare:", cont);
                            scanf("%d", &var1);
                            while(var1!= 1 && var1 != 0)
                            {
                                printf("Raspundeti cu 0 sau 1 !!!\n");
                                scanf("%d", &var1);
                            }
                            switch(var1)
                            {
                                case 1 : {
                                            pl[j].scor = pl[j].scor + cont * 5;
                                            elem_1 = elem_1 - cont + 1;
                                            for(k = (i - cont) ; k < v[j] ; k++)
                                            {
                                                pl[j].culoare_j[k] = pl[j].culoare_j[k + cont];
                                                pl[j].numar_j[k] = pl[j].numar_j[k + cont];
                                            }
                                            v[j] = v[j] - cont;
                                            printf("Cartile jucatorului %d sunt:\n", j);
                                            for(i = 0 ; i < v[j] ; i++)
                                                printf("%c%c " , pl[j].numar_j[i] , pl[j].culoare_j[i]);
                                            break;
                                         }
                                case 0 : {
                                            printf("Etalare anulata!!!");
                                            break;
                                         }
                            }
                        }
                        nr++;
                        j++;
                        if(j > nrpl)
                        j = 1;
                        system("cls");
                        printf("\n");
                        break;
                      }
        }
    }
}

void afis(int nrpl) // Afisarea scorurilor finale
{
    int i;
    for(i = 1 ; i <= nrpl - 1 ; i++)
        printf("Player %s are intr-un final scorul %d\n", pl[i].nume, pl[i].scor);
}

void fisier(int nrpl)
{
    int i;
    FILE *fp;
    fp = fopen("scor.txt","w+");
    for(i = 1 ; i <= nrpl ; i++)
    fprintf(fp, "Player %s are %d puncte. \n", pl[i].nume, pl[i].scor);
}
