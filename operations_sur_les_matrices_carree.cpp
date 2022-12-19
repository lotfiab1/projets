#include<stdio.h> 
#include<stdlib.h> 

int mat1[10][10]; //matrice 1
int mat2[10][10]; //matrice 2
int result[10][10]; //resultas des operation sur les matrice
int temp[10][10];
int ordre; //ordre de matrice

//fonction de remplissage de matrice 1 et matrice 2 :
void mat_info()
{
	int i, j;
	printf("Entrer la dimension du matrice carree: "); 
	scanf("%d", &ordre); 
	printf("Entrer les elements de matrice 1:\n"); 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) 
		{
			scanf("%d", &mat1[i][j]);
		}
	}
	printf("Entrer les elements de matrice 2:\n"); 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) 
		{
			scanf("%d",&mat2[i][j]);
		}
	}

}
//fonction affiche les matrices :
void affichage_matrices(){
	int i,j;
	printf("les elements de matrices 1 :\n");
	for(i=0;i<ordre;i++){
		for(j=0;j<ordre;j++){
			printf("%7d",mat1[i][j]);
		}
		printf("\n");
	}
	printf("les elements de matrice 2 :\n");
	for(j=0;j<ordre;j++){
		for(i=0;i<ordre;i++){
			printf("%7d",mat2[i][j]);
		}
		printf("\n");
	}
}
//Fonction qui affiche les resultats des autres fonction:
void affichage_resultat() 
{ 
	int i,j;
	printf("\nEntered Matrix:\n"); 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) 
		{
			printf("%d\t", result[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//Fonction pour l'addition de matrice 1 et matrice 2
void add() 
{ 
	int i, j; 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) 
		{
			result[i][j] = mat1[i][j] + mat2[i][j]; 
		}
	}
}

//Fonction de soustraction  de matrice 1 et matrice 2
void soustract() 
{ 
	int i, j; 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) 
		{
			result[i][j] = mat1[i][j] - mat2[i][j]; 
		}
	}
}

//Fonction de multiplicatin entre matrice 1 et matrice 2
void multip() 
{ 
	int i, j, k; 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) 
		{
			result[i][j] = 0; 
			for(k = 0; k < ordre; k++) 
			{
				result[i][j] += mat1[i][k] * mat2[k][j]; 
			}
		}
	}
}

//Function to find transpose of matrix
void transpose() 
{ 
	int i, j; 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) {
		  temp[j][i]=result[i][j];
		}
	}
	for(i=0;i<ordre;i++){
		for(j=0;j<ordre;j++){
			result[i][j]=0;
		}
	}
		for(i=0;i<ordre;i++){
		for(j=0;j<ordre;j++){
			result[i][j]=temp[i][j];
		}
	}
}

//Fonction determine le maximun de matrice resultat
int maximun() 
{ 
	int i, j; 
	int max = result[0][0]; 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) 
		{
			if(result[i][j] > max) 
			{
				max = result[i][j]; 
			}
		}
	}
	return max;
}

//Fonction determine le minimun de matrice resultat
int minimun() 
{ 
	int i, j; 
	int min = result[0][0]; 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) 
		{
			if(result[i][j] < min) 
			{
				min = result[i][j]; 
			}
		}
	}
	return min;
}

//Fontion affiche la menu des des fonction disonable pour tester
void affichage_menu() 
{
	printf("\nMENU:\n");
	printf("1. entrer les matrices a nouveau \n");
	printf("2. Affichage de matrice 1 et matrice 2\n");
	printf("3. soustraction\n");
	printf("4. Multiplication\n");
	printf("5. Addition\n");
	printf("6. Transposee de matrice resultat\n");
	printf("7. Minimun\n");
	printf("8. Maximun\n");
	printf("9. exit\n");
	printf("\nEntrer votre choix: ");
}

int main() 
{
	int choix;
	mat_info();
	while(1) 
	{
		affichage_menu();
		scanf("%d", &choix);
		switch(choix) 
		{
			case 1:
			    mat_info();
			    break;
			case 2:
				affichage_matrices();
				break;
			case 3:
				soustract();
				affichage_resultat();
				break;
			case 4:
				multip();
				affichage_resultat();
				break;
			case 5:
				add();
				affichage_resultat();
				break;
				
			case 6:
				transpose();
				affichage_resultat();
				break;

			case 7:
				printf("Minimum: %d\n", minimun());
				break;
			case 8:
				printf("Maximum: %d\n", maximun());
				break;
			case 9: 
			     exit(0);
				 break;	
			default:
				printf("\nchoix introuvable! ressayer a nouveau\n");
				break;
		}
	}}
