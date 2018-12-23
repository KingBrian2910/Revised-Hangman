#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "Minilib.h"


struct Name 
{
	char name[100];
	char jawab[100];
	int score;
	struct Name *nPtr;
	struct Name *jPtr;
	struct Name *nextPtr;
}; 



typedef struct Name nm;
typedef nm *nmPtr;
typedef nm *jbPtr;
typedef nm *scrPtr;


void pushname(nmPtr *tpPtr, char* n[100]);
void push( scrPtr *topPtr, int info );
void printStack( scrPtr currentPtr, nmPtr crPtr );

int o=0;

int main()
{	
	scrPtr stackPtr = NULL; 
	nmPtr stPtr = NULL;
	
	
    char a='a',z, word[100][100],spot[1000],neWorld[255][255],txt[255], temp[255];
    int i=0,W=0,j=0,m=0,choice=0,ch,x=0, freq[26] = {0}, flag[26] = {0}, loc[1000][26]={0},c,f=0,score,count=0,ascore[3],highscore=0;
    FILE *file;
    FILE *sfile;
    FILE *fpointer;
    
    file = fopen("Jawaban.txt","r");
   	while(fgets(txt, sizeof(txt), file))
	{
		strcpy(temp,txt);
		for(i=0;i<strlen(temp)-1;i++)
		{
			neWorld[m][i] = temp[i];
		}
		temp[0] = '\0';
		m++;
    }
    fclose(file);
    
    h:
    home();
    choice=toupper(getch());
    if (choice == 'A')
    {
        about();
        getch();
        goto h;
    }
    else if (choice == 'B')
    {
        rule();
        getch();
        goto h;
    }
    else if (choice == 'C')
    {
      goto game;
    }
    else if (choice == 'D')
    {
    	int l;
    	system("cls");
    	printStack( stackPtr, stPtr );
    	printf("\n\nDo you want to save current scores?\nY yes\nN no");
    	l=toupper(getch());
    	if (l == 'Y')
    	{	
			fpointer=fopen("Highscore.txt", "a");
    		while ( stackPtr != NULL && stPtr != NULL) 
			{
				fprintf( fpointer, "\n\t\t%s  %d\n", stPtr->name, stackPtr->score );
				stackPtr = stackPtr->nextPtr;
				stPtr = stPtr->nPtr;
			}
			fclose(fpointer);
			system("cls");
			printf("\n\n\t\tYour data has been successfully saved, \n\t\tgoto log in the main menu to see all the score history");
			getch();
    		goto h;
		}
		else 
		{
			goto h;
		}
	}
	else if (choice == 'E')
	{
		system("cls");
		fpointer=fopen("Highscore.txt", "r");
		
		char singleline[150];
		while(!feof(fpointer))
		{
			fgets(singleline, 150, fpointer);
			puts(singleline);
		}
		
		fclose(fpointer);
		getch();
		goto h;
	}
	
    else if (choice == 'F')
    {
        return 0;
    }
    else
    {
    	system("cls");
    	printf("Im sorry, what you chose was invalid, please choose one of the options given");
    	getch();
    	goto h;
	}
	
	char n[100];

    game:
    system("cls");
    printf("Please Enter Player name !!\n\n");
    scanf("%s", n);
    pushname( &stPtr, n);
    getch();
    system("cls");
    W = rand()%9;
    switch(W)
    {
        case 0 :
            printf("\n\nClue : Seleksi Masuk perguruan tinggi");
			strcpy(word[o],neWorld[W]);
			break;
        case 1 :
            printf("\n\nClue : Kejaran Dika Tak Tercapai");
            strcpy(word[o],neWorld[W]);
            break;
        case 2 :
            printf("\n\nClue : institusi pembelajaran");
            strcpy(word[o],neWorld[W]);
            break;
        case 3:
            printf("\n\nClue : Tempat pengambilan asupan gizi");
			strcpy(word[o],neWorld[W]);
            break;
        case 4:
            printf("\n\nClue : Kandang kuda besi");
			strcpy(word[o],neWorld[W]);
            break;
        case 5:
            printf("\n\nClue : Pengganti kuda");
			strcpy(word[o],neWorld[W]);
            break;
        case 6:
            printf("\n\nClue : Kecerobohan");
			strcpy(word[o],neWorld[W]);
            break;
        case 7:
            printf("\n\nClue : Bensin manusia");
			strcpy(word[o],neWorld[W]);
            break;
        case 8:
            printf("\n\nClue : negara yang jangkauan pantai Terpanjang");
            strcpy(word[o],neWorld[W]);
            break;
        case 9:
            printf("\n\nClue : Negara populasi terbanyak");
			strcpy(word[o],neWorld[W]);
            break;
    }
    scan(word,loc,flag,freq);
    blocks(loc,word,spot);
    score = input_check(loc,word,spot,freq);
    printf("Answer : %s",word);
    ascore[count] = score;
    word[0][0] = '\0';
    push( &stackPtr, score );
    getch();
    printf("\n______________________________");
    printf("\n\n\t\tWould you like to try again?");

    printf("\n\t\tY  yes\n\t\tN  no");
    ch=toupper(getch());
    if (ch == 'Y')
    {
    	count++;
        system("cls");
        goto game;
    }
    else
    {
    	getch();
    	goto h;
    }
return 0;
}

void home()
{
    system("cls");
    printf("\n\n\t\t---------------------------");
    printf("\n\t\tWELCOME TO THE HANGMAN GAME");
    printf("\n\t\t---------------------------\n\n");
    printf("\n\nPLEASE CHOOSE WHAT WOULD YOU LIKE TO DO:");
    printf("\n[A]  About Us\n[B]  How to Play\n[C]  Start\n[D]  Highscore\n[E]  Game Log\n[F]  Exit");
}

void push( scrPtr *topPtr, int info )
{
	scrPtr newPtr; 
	
	newPtr = malloc( sizeof( nm ) );

	if ( newPtr != NULL ) 
	{
		newPtr->score = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	} 
}

void pushname(nmPtr *tpPtr, char* n[100])
{
	nmPtr brPtr; 
	
	brPtr = malloc( sizeof( nm ) );

	if ( brPtr != NULL ) 
	{
		strcpy(brPtr->name,n);
		brPtr->nPtr = *tpPtr;
		*tpPtr = brPtr;
	}
	
printf("%s",brPtr->name);
}

void printStack( scrPtr currentPtr, nmPtr crPtr )
{
	if ( currentPtr == NULL && crPtr == NULL )
	{
		printf( "The stack is empty.\n\n" );
	} 
	else 
	{
		printf( "The game score is:\n" );
 		while ( currentPtr != NULL && crPtr != NULL) 
		{
			printf( "\n\t\t%s  %d\n", crPtr->name, currentPtr->score );
			currentPtr = currentPtr->nextPtr;
			crPtr = crPtr->nPtr;
		}
		
	}
}

void pushjawab(jbPtr *ptPtr, char* j[100])
{
 jbPtr rbPtr;

 rbPtr = malloc( sizeof( nm ) );

 if ( rbPtr != NULL )
 {
  strcpy(rbPtr->jawab,j);
  rbPtr->jPtr = *ptPtr;
  *ptPtr = rbPtr;
 }

}




