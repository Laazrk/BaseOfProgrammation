#include <stdio.h>
#include <stdlib.h>


int main()
{
  int person[]={1,2,3,3};
  int limit = 3;
  int boat = 0;
  int taille_tableau= sizeof(person)/sizeof(int); // le nombre d'elements
  //methode 1 : pour chaque chiffre additionner et voir si ca match avec la limite (enelver les chiffres une fois utilisé) sinon passer une fois à la fin
  //refaire la meme chose mais en scrutant les chiffres égales à la limite

  for(int i=0;i <taille_tableau;i++)        //l'élément i fixe du tableau
  {
      for(int j = i+1; j<taille_tableau; j++)
      {
          if(person[i] + person[j] == limit) // voir si la somme du element i + element J qui evolue au fur et a mesure est égale à la limite
          {
              boat++;
              person[i]=limit+1; //exclure de la boucle
              person[j]=limit+1;

          }

      }
      if (person[i] == limit){
        boat++;
        person[i]=limit+1;
      }
      if(person[i] !=limit+1)
      {
          boat++;
      }
  }
  printf("nombre de bateau %d ",boat);
}



