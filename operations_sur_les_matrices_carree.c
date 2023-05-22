#include<stdio.h> 
#include<stdlib.h> 
int Ma1[100][100]; 
int Ma2[100][100]; 
int result[100][100]; 
int temp[100][100];
int ordre; 
void mat_info_Ma1_Ma2()
{
	int i, j;
	printf("Entrer la dimension du matrice carree: "); 
	scanf("%d", &ordre); 
	printf("Entrer les elements de matrice 1:\n"); 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) 
		{
			scanf("%d", &Ma1[i][j]);
		}
	}
	printf("Entrer les elements de matrice 2:\n"); 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) 
		{
			scanf("%d",&Ma2[i][j]);
		}
	}

}
void affichage_Ma1_Ma2(){
	int i,j;
	printf("les elements de matrices 1 :\n");
	for(i=0;i<ordre;i++){
		for(j=0;j<ordre;j++){
			printf("%7d",Ma1[i][j]);
		}
		printf("\n");
	}
	printf("les elements de matrice 2 :\n");
	for(j=0;j<ordre;j++){
		for(i=0;i<ordre;i++){
			printf("%7d",Ma2[i][j]);
		}
		printf("\n");
	}
}


void soustract_Ma1_Ma2() 
{ 
	int i, j; 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) 
		{
			result[i][j] = Ma1[i][j] - Ma2[i][j]; 
		}
	}
}

void add_Ma1_Ma2() 
{ 
	int i, j; 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) 
		{
			result[i][j] = Ma1[i][j] + Ma2[i][j]; 
		}
	}
}

void multip_Ma1_Ma2() 
{ 
	int i, j, k; 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) 
		{
			result[i][j] = 0; 
			for(k = 0; k < ordre; k++) 
			{
				result[i][j] += Ma1[i][k] * Ma2[k][j]; 
			}
		}
	}
}
void transpose_Ma_result() 
{ 
	int i, j; 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) {
		  temp[j][i]=result[i][j];
		}
	}
    for(i=0;i<order;i++){
       for(j=0;j<order;j++){
        result[i][j]=temp[i][j];
        }
    }
}
int maximun_Ma_result() 
{ 
	int i, j; 
	int Max = result[0][0]; 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) 
		{
			if(result[i][j] > Max) 
			{
				Max = result[i][j]; 
			}
		}
	}
	return Max;
}

int minimun_Ma_result() 
{ 
	int i, j; 
	int Min = result[0][0]; 
	for(i = 0; i < ordre; i++) 
	{
		for(j = 0; j < ordre; j++) 
		{
			if(result[i][j] < Min) 
			{
				Min = result[i][j]; 
			}
		}
	}
	return Min;
}
void affichage_Ma_result() 
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
	while(1) 
	{
		affichage_menu();
		scanf("%d", &choix);
		switch(choix) 
		{
			case 1:
			    mat_info_Ma1_Ma2();
			    break;
			case 2:
				affichage_Ma1_Ma2();
				break;
			case 3:
				soustract_Ma1_Ma2();
				affichage_Ma_result();
				break;
			case 4:
				multip_Ma1_Ma2();
				affichage_Ma_result();
				break;
			case 5:
				add_Ma1_Ma2();
				affichage_Ma_result();
				break;
				
			case 6:
				transpose_Ma_result();
				affichage_Ma_result();
				break;

			case 7:
				printf("Minimum: %d\n",minimun_Ma_result());
				break;
			case 8:
				printf("Maximum: %d\n",maximun_Ma_result() );
				break;
			case 9: 
			     exit(0);
				 break;	
			default:
				printf("\nchoix introuvable! ressayer a nouveau\n");
				break;
		}
	}
}

/* class project writted by me :) LoAb*/
