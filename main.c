//Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Bibliothèque permettant d'utiliser la fonction strlen

//prototypes
int choix(int);
void lancement(int);
void conversionDR();
int initDecimal();
int finalConvDR(int, int, int, char[]);
void conversionRD();
int finalConvRD(char[]);
int romain(char);


int main()
{
    int nChoix = 42;

    do{
        nChoix = choix(nChoix);
        lancement(nChoix);
    }while(nChoix!=0);

    printf("\nAurevoir\n");

    return 0;
}

//********************************************************* Menu *****************************************************//

//**************************************************************************
// Description : Fonction qui demande de choisir un programme a lancé
//
// Entrée : un entier
//
// Sortie : un entier
//
// Note :
//
//**************************************************************************

int choix(int nChoix){

    printf("Bienvenue dans un programme de convertion de nombre decimal et de chiffres romains.\n\nChoissisez la convertion que vous voulez lancer :\n    1. Decimal vers Romain\n    2. Romains vers Decimal\n    0. Quitter\n\n");
    do{
        fflush(stdin);
        scanf("%d", &nChoix);
        if(nChoix<0 || nChoix>2){
            printf("Choix non valide !\n");
        }
    }while(nChoix<0 || nChoix>2);

    return nChoix;
}

//**************************************************************************
// Description : Fonction qui lance le programme choisie
//
// Entrée : un entier
//
// Sortie : /
//
// Note :
//
//**************************************************************************

void lancement(int nChoix){

    if(nChoix==1){
        conversionDR();
    }else if(nChoix==2){
        conversionRD();
    }
}


//********************************************************* Convertion Décimal vers Romain *****************************************************//


//**************************************************************************
// Description : Fonction qui lance la conversion décimale vers romain
//
// Entrée : /
//
// Sortie : /
//
// Note :
//
//**************************************************************************

void conversionDR(){

    system("cls");

    int nX, nMultiple, nN, nZ;
    char cTableR[7] = {'M','D','C','L','X','V','I'};

    nX = initDecimal();

    if(nX>=1000){
        nZ = 4;
        nMultiple = 1000;
        nN = -2;
    }else if(nX>=100){
		nZ = 3;
		nMultiple = 100;
		nN = 0;
	}else if(nX>=10){
		nZ = 2;
		nMultiple = 10;
		nN = 2;
	}else{
		nZ = 1;
		nMultiple = 1;
		nN = 4;
	}

    printf("\nLe chiffre %d en decimal vaut ", nX);

	do{
        nX = finalConvDR(nX, nMultiple, nN, cTableR);
        nMultiple = nMultiple/10;
        nN = nN + 2;
        nZ--;
	}while(nZ > 0);

	printf(" en chiffre romain.\n\nPour retourner au menu principale, ");
	system("pause");
	system("cls");
}

//******************************************************
// Description : Fonction demandant un chiffre décimale
//
// Entrée : /
//
// Sortie : un entier, le chiffre à convertir
//
// Note : Le chiffre doit etre compris entre 1 et 3999
//
//******************************************************

int initDecimal(){

    int nX;

    printf("Bienvenue dans le programme de convertion de decimal en romain !\n\n");
    do{
        printf("Veuillez rentrer un chiffre entre 1 et 3999 : ");
        fflush(stdin);
        scanf("%d", &nX);
    }while(nX<=0 || nX>=4000);

    return nX;
}

//*******************************************************************************************************************
// Description : Fonction réalisant la conversion d'un nombre décimal à un chiffre romain
//
// Entrée : trois entier et un tableau de caractère
//
// Sortie : un entier, le reste du chiffre qui est en cours de conversion
//
// Note : la conversion se fait tout d'abord sur les mille, les centaines, les dizaines et enfin sur les unités
//
//*******************************************************************************************************************

int finalConvDR(int nX, int nMultiple, int nN, char cTableR[]){

    int nTemp, nI;

    if(nX>=(9*nMultiple)){
        nX = nX - (9*nMultiple);
        printf("%c%c", cTableR[2+nN], cTableR[0+nN]);
    }else if(nX>=(5*nMultiple)){
        nX = nX - (5*nMultiple);
        printf("%c", cTableR[1+nN]);
    }else if(nX>=(4*nMultiple)){
        nX = nX - (4*nMultiple);
        printf("%c%c", cTableR[2+nN], cTableR[1+nN]);
    }

    if(nX>=(1*nMultiple)){
        nTemp = nX/(1*nMultiple);
        nX = nX - ((1*nMultiple)*nTemp);
        for(nI=0;nI<nTemp;nI++){
            printf("%c", cTableR[2+nN]);
        }
    }

    return nX;
}


//********************************************************* Convertion Romain vers Décimal *****************************************************//


//**************************************************************************
// Description : Fonction qui lance la conversion romain vers décimale
//
// Entrée : /
//
// Sortie : /
//
// Note :
//
//**************************************************************************

void conversionRD(){

    system("cls");

    char cTableR[15];
    int nDecimal = -5;

    printf("Bienvenue dans le programme de convertion de romain en decimal !\n\n");

    printf("Veuillez rentrer un chiffre correct en romain : ");
    scanf("%s", cTableR);

    nDecimal = finalConvRD(cTableR);
    if(nDecimal<0){
        printf("\nVous avez ecrit un caractere non valide !\n\nPour retourner au menu principale, ");
    }else{
        printf("\nLe chiffre %s en romain vaut %d en decimal.\n\nPour retourner au menu principale, ", cTableR, nDecimal);
    }
    system("pause");
    system("cls");
}

//******************************************************************************************
// Description : Fonction réalisant la conversion d'un chiffre romain à un chiffre décimal
//
// Entrée : un tableau de caractère
//
// Sortie : un entier, la valeur une fois convertie
//
// Note :
//
//******************************************************************************************

int finalConvRD(char cTableR[]){

    int nDecimal = 0, nI;

    for(nI=0;nI<strlen(cTableR)-1;nI++){
        if(romain(cTableR[nI])==-5){
            nDecimal = nDecimal - 10000;
        }else if(romain(cTableR[nI]) >= romain(cTableR[nI+1])){
            nDecimal = nDecimal + romain(cTableR[nI]);
        }else{
            nDecimal = nDecimal - romain(cTableR[nI]);
        }
    }
    if(romain(cTableR[nI])==-5){
            nDecimal = nDecimal - 10000;
    }else{
        nDecimal = nDecimal + romain(cTableR[nI]);
    }

    return nDecimal;
}

//******************************************************************************
// Description : Fonction qui retourne la valeur décimale d'un caractère romain
//
// Entrée : un charactère
//
// Sortie : un entier
//
// Note :
//
//******************************************************************************

int romain(char cValeur){
    switch(cValeur){
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
        case '\0':
            return 0;
        default:
            return -5;
    }
}
