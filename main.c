#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 2000


int E[];        //L'ensemble
int pos = 0;    //var globale qui gère les positions dans la table de tous les ensembles
int Ebit[max];  //Table de bits


/*********************************************************************************************************************/


int SubSetSum(int Tab[],int n, int s)
{
    int resault,resault1,resault2 ;
    if (s == 0)
    {
        return 1 ; //True
    }
    if (s < 0) return 0 ; //False
    if ((n==0) && (s>0)) return 0 ; //False
    else
    {
        resault1 = SubSetSum(Tab,n-1,s-E[n-1]) ;
        if (resault1 == 1)
        {
            Ebit[n-1] = 1 ;
            Tab[pos] = E[n-1] ;
            pos++ ;
        }
        resault2 = SubSetSum(Tab,n-1,s) ;
        resault =  resault1 + resault2  ;
        if (resault >= 1) return 1 ;
        else return 0 ;
    }
}


/*********************************************************************************************************************/

//Affiche un ensemble nom
void afficher_ensemle(int Ens[],char *nom,int taille)
{
    int j ;
    printf(" %s = { " , nom ) ;
    for (j = 0; j<taille ;j++)
    {
        printf("%d",Ens[j]) ;
        if (j != taille-1) printf(" ,") ;
    }
    printf(" } \n") ;
}


/*********************************************************************************************************************/

//Vérifie si l'élément elmt appartient a l'ensemble Ens
int exist_element(int Ens[],int taille,int elmt)
{
    int i = 0;
    while (i<taille)
    {
        if (Ens[i] == elmt) return 1 ;
        i++ ;
    }
}


/*********************************************************************************************************************/

void Afficher_tous_les_ensemble(int T[],int taille,int sum)
{
    int i, j=0 ,k, somme =0 ,nb = 1,cpt=taille;
    int sous_ens[max]  ;
    int Ens_opt[max];
    for (i=0 ; i<taille ; i++)
    {
        somme = somme + T[i] ;
        sous_ens[j] = T[i] ;
        j++ ;
        if (somme == sum)
        {
            printf(" Sous ensemle %d" , nb) ;
            nb++ ;
            afficher_ensemle(sous_ens,"",j) ;

            //Récuerer l'ensemble optimal
            if(j<cpt)
            {
                for(k=0;k<j;k++){Ens_opt[k]=sous_ens[k];}
                cpt=j;
            }
            j = 0 ;
            somme = 0 ;
        }
    }
    printf("\n\n\t/********************/\n\n Sous ensemle optimal : ") ;
    afficher_ensemle(Ens_opt,"",cpt) ;
}

/*********************************************************************************************************************/


int main()
{
    int Tab[max];
    int n ,s ,num,nbr_ensembles ;

    printf("\n   /***************************  SubSetSum  ***************************/\n\n");
    printf("        /**********************  Question 1 **********************/\n\n");
    //Récupérer la taille de l'ensemble
    printf("Donner le nombre d'elements de votre ensemble: ") ;
    scanf("%d", &n) ;


    //Récupérer les éléments un par un et remplir la table des bits
    printf("\nIntroduisez les elements : \n") ;
    int i ;
    for (i = 0 ;i< n;i++)
    {   printf("Element[%d] = ",i+1);
        scanf("%d", &num) ;
        E[i] = num ;
        Ebit[i] = 0 ;
    }

    //Affichage de l'ensemble
    afficher_ensemle(E,"E",n) ;


    //Récuerer la somme s
    printf("\nIntroduisez la somme : ") ;
    scanf("%d", &s) ;


    //Trouver les sous ensembles

    // Question 1
    nbr_ensembles=SubSetSum(Tab,n,s);
    if ( nbr_ensembles>= 1){ printf("\nTRUE , Il existe au moins un sous-ensemble de E tq la somme de ses elements est egale a %d",s) ;
        printf("\nNombre des ensembles possibles: %d",nbr_ensembles);
    }
    else
    {
        printf("\n FALSE  Il n'existe aucun sous-ensemble de E tq la somme de ses elements est egale a %d",s) ;
        return 0 ;

    }

    //Question2

    printf("\n\n\n        /**********************  Question 2 **********************/\n\n");
    afficher_ensemle(Ebit,"Tab des bits",n) ;
    printf("\n\n  L'ensemle contenant tous les elements de tous les ensembles : \n\t {"  ) ;
    for (i = 0 ; i< n ; i++)
    {
        if (Ebit[i] == 1)
        {
            printf(" %d ",E[i]) ;
        }
    }
    printf("}");

    //Question3

    printf("\n\n\n        /**********************  Question 3 **********************/\n\n");
    printf("\n Les sous ensembles sont :\n") ;
    Afficher_tous_les_ensemble(Tab,pos,s) ;
    printf("\n  /*******************************   FIN   *******************************/\n\n");
    return 0;
}

