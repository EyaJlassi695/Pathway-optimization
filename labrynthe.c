#include "labrynthe.h"
labrynthe* intialiser_labrynthe( int hauteur , int largeur){ 
    labrynthe* lab; 
    lab=(labrynthe*) malloc(sizeof(labrynthe));
    if(lab==NULL) {exit(EXIT_FAILURE);}
    lab->n=hauteur;
    lab->m=largeur;
    lab->cells=(cellule**)malloc(hauteur*sizeof(cellule*));
    for(int i=0;i<hauteur;i++){ 
        lab->cells[i]=(cellule*)malloc(largeur*sizeof(cellule));
        if(lab->cells[i]==NULL) exit(EXIT_FAILURE);}
        for(int i=0;i<hauteur;i++){ 
        for(int j=0;j<largeur;j++){ 
            lab->cells[i][j]=creer_cellule(i*largeur+j);
        }
    }
    return lab;}
    void afficher_lab(labrynthe* lab){
        
    printf(" ");
     for(int j=0;j<lab->m*2-1;j++){ 
        printf("_");

     }
     printf("\n");
     for(int i=0;i<lab->n;i++){ 
        printf("|"); 
        for(int k=0;k<lab->m;k++){ 
            if(lab->cells[i][k].mur[BAS]) printf("_");
            else printf(" ");
            if(lab->cells[i][k].mur[DROITE]) printf("|");
            else printf(" ");
        }
        printf("\n");
     }
            
           
        }
        void destruction_mur(labrynthe* lab,position pos ,int i,int j ){ 
            unsigned int n=lab->n;
    unsigned int m=lab->m;
    // Vérifier si la position est sur le bord de la grille
    if (i == 0 && pos == HAUT)return; // bord inférieur
    if (i == n-1 && pos == BAS) return ; // bord supérieur
    if (j == 0 && pos ==GUAUCHE) return; // bord gauche
    if (j == m-1 && pos == DROITE) return; // bord droite
   lab->cells[i][j].mur[pos]=false;
   //on detruit le mur dans le position pos de la cellule i ,j 
   // on change aussi la valeur "bool"de la mur voisine 
   // on change l'id de la cellule voisine 
   switch (pos)
   {
   case HAUT:
   lab->cells[i][j].id=lab->cells[i-1][j].id;
   lab->cells[i-1][j].mur[BAS]=false ; 
    break;
   
   case BAS:  
    lab->cells[i][j].id=lab->cells[i+1][j].id;
    lab->cells[i+1][j].mur[HAUT]=false ; 

    break;
    case DROITE:  
    lab->cells[i][j].id=lab->cells[i][j+1].id;
    lab->cells[i][j+1].mur[GUAUCHE]=false;

    break;
    case GUAUCHE:  
    lab->cells[i][j].id=lab->cells[i][j-1].id;
    lab->cells[i][j-1].mur[DROITE]=false;

    break;
   }
   } 
   
    bool estIsole(labrynthe* lab, int id){ 
        int i = id / lab->m;
    int j = id % lab->m;
    if (((i < 0) || (i >= lab->n)) || ((j < 0) || (j >= lab->m)))
        return false;
    else
        return (lab->cells[i][j].mur[DROITE] &&lab->cells[i][j].mur[GUAUCHE] &&lab->cells[i][j].mur[HAUT] &&lab->cells[i][j].mur[BAS]);
}
int id_Cellulle(labrynthe* laby,int id,position pos){
    int i = id / laby->m;
    int j = id % laby->m;
    if (((i < 0) || (i >= laby->n)) || ((j < 0) || (j >= laby->m)))
        return -2;
    switch (pos){
    case DROITE:
        if ((j+1)>=laby->m)
            return -1;
        else
            return (i*laby->m)+j+1;
        break;
    case GUAUCHE:
        if ((j-1)<0)
            return -1;
        else
            return (i*laby->m)+j-1;
        break;
    case BAS:
        if ((i+1)>=laby->n)
            return -1;
        else
            return ((i+1)*laby->m)+j;
        break;
    case HAUT:
        if ((i-1)<0)
            return -1;
        else
            return ((i-1)*laby->m)+j;
        break;
    }
}
    
void genererlabrynthe(labrynthe* laby ){  
    int n=laby->n;
    int m=laby->m;
     srand(time(NULL));
    int* T = (int*) malloc(sizeof(int)*laby->n*laby->m);
    int deb=0;
    int fin=0;
    int s0=0;
    int s1=0;
    position pos=0;
    T[0]=rand()%(n*m);
    fin+=1;
    while (fin<n*m){
        s0=deb+rand() % (fin-deb);
        pos=rand() % 4;
        s1 =id_Cellulle(laby,T[s0],pos);
        if (s1<0)
            continue;
        if (!estIsole(laby,s1))
            continue;
        destruction_mur(laby,pos,T[s0] / laby->m,T[s0] % laby->m);
        T[fin] = s1;
        fin+=1;
        if ((((id_Cellulle(laby,T[s0],HAUT)<0) || !estIsole(laby,id_Cellulle(laby,T[s0],HAUT))) 
        && ((id_Cellulle(laby,T[s0],BAS)<0) || !estIsole(laby,id_Cellulle(laby,T[s0],BAS))
        )) && (((id_Cellulle(laby,T[s0],GUAUCHE)<0) || !estIsole(laby,id_Cellulle(laby,T[s0],GUAUCHE))
        ) && ((id_Cellulle(laby,T[s0],DROITE)<0) || !estIsole(laby,id_Cellulle(laby,T[s0],DROITE)))
        )){
            s1=T[s0];
            T[s0]=T[deb];
            T[deb]=s1;
            deb+=1;
        }
    }
    free(T);
    
}


   
  
        