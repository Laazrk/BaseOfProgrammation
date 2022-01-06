#include <stdio.h>
#include <stdlib.h>

int main()
{
   int NB_ELEMENT = 10;
   int tab[10]={3,8,100,1,45,2,47,4,46,76};
   int tmp=0;
   int j=0;
   int i;
   for(i = 0; i<NB_ELEMENT;i++)
   {
       printf((" %d "), tab[i]);

   }
   printf("\n");
   for(i = 0; i<NB_ELEMENT;i++)
    {
       for(j=i+1;j<NB_ELEMENT;j++)
       {
           if(tab[i]>tab[j])
           {
               tmp=tab[i];
               tab[i]=tab[j];
               tab[j]=tmp;
           }


       }
       printf((" %d "), tab[i]);

   }

}
