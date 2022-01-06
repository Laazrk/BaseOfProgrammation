#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Count the number of Zero in this tab and place it at the front of the Array
 /*   int tab[5]={0,1,0,3,12};
    int count=0;
    int tmp = 0;
    for(int i=0;i < 5; i ++)
    {
        if (tab[i] != 0)         // Si la valeur de Tab est différent de Zero
        {
            tab[count]= tab[i];  // le tableau à la case i prend la valeur de tab à l'index count
            count = count +1;    // la variable count détecte le nombre de chiffre supérieur à zéro
        }

    }
    for(count ;count <5; count++)
        {
            tab[count]=0;

        }
    for(tmp=0; tmp<5; tmp++)
    {
         printf(" %d ",tab[tmp]);
    }

    return 0;*/

    int tab[5]={68,76,43,32,12};
    //int tab2[5]={1,45,89,100,34};

    int tmp; // Variable tampon

    for(int i = 0; i <5; i++)
    {
        for(int j = i+1; j<5; j++)
        {
          if(tab[i]>= tab[j])
          {
              tmp=tab[j];
              tab[j]=tab[i];
              tab[i]=tmp;

          }

        }

        printf(" %d ",tab[i]);
    }
     printf("\n");
    int tab2[5]={23,75,42,31,11};
    //int tab2[5]={1,45,89,100,34};



    for(int i = 0; i <5; i++)
    {
        for(int j = i+1; j<5; j++)
        {
          if(tab2[i]>= tab2[j])
          {
              tmp=tab2[j];
              tab2[j]=tab2[i];
              tab2[i]=tmp;

          }

        }

        printf(" %d ",tab2[i]);
    }

    int tab3[10];
    int i=0;
    int j=0;
    int h=0;

    while(h<10)
    {

        if(tab[i]<tab2[j])
           {
               tab3[h]=tab[i];
               i=i+1;
               h=h+1;
                       if(i == 4 && j == 4)
                        {

                        if (tab[i]>tab2[j])
                            {
                                tab3[h]=tab2[j];
                                h = h+1;
                                tab3[h]=tab[i];
                                break;
                            }
                        if (tab[i]<tab2[j])
                            {
                                tab3[h]=tab[i];
                                h = h+1;
                                tab3[h]=tab2[i];
                                break;

                            }



                        }

           }
        if (tab[i]>tab2[j])
            {
                tab3[h]=tab2[j];
                j=j+1;
                h=h+1;
                   if(i == 4 && j == 4)
                        {

                        if (tab[i]>tab2[j])
                            {
                                tab3[h]=tab2[j];
                                h = h+1;
                                tab3[h]=tab[i];
                                break;
                            }
                        if (tab[i]<tab2[j])
                            {
                                tab3[h]=tab[i];
                                h=h+1;
                                tab3[h]=tab2[i];
                                break;

                            }



                        }

            }

    }
    printf("\n");
    for(int k=0;k<10;k++)
    {

        printf(" %d ",tab3[k]);
    }


}
