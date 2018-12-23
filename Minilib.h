#include<stdlib.h>

int about()
{
    system("cls");
    printf("\n\n\t\t\t\tHELLO!!");
    printf("\n\t [1] Thankyou for trying our game out");
    printf("\n\t [2] This game is created for the purposes of the mini project assigned to us");
    printf("\n\t [3] This game was created by Dika and Brian of the electrical eng.");
    printf("\n\t [4] We hope you enjoy this game");
    printf("\n\t [5] Press any key to go back to home");
}

int rule()
{
    system("cls");
    printf("\n\n\t\t\t\tHELLO!!");
    printf("\n\t Thankyou for trying our game out");
    printf("\n\t The rules are simple");
    printf("\n\t [1] The game will pick you a random word from our library");
    printf("\n\t [2] A clue will be given to you to try guessing the word");
    printf("\n\t [3] Guess the word by picking random letters");
    printf("\n\t [4] You will be given 6 lives");
    printf("\n\t [5] Try not to lose!!");
    printf("\n\n\t  Press any key to go back");
}
int scan (char *word,int loc[1000][26],int *flag,int *freq)
{
    int x, i;
	char a ='a',z;
    for (i = 0; i <strlen(word); i++)
    {
        for (x=0;x<26;x++)
        {
            z=a+x;
            if (*(word+i) == z)
            {
                loc[i][x] = 1;
                flag[x] = 1;
                freq[x]++;
            }
        }
    }
}

int result (int loc[1000][26],char *word)
{
    int i,x; char z,a='a';
    for (i = 0; i < strlen(word); i++)
    {
        for (x=0;x<26;x++)
        {
            if (loc[i][x] == 1)
            {
                z = a + x;
                printf("%c",z);
            }
        }
    }
;
}

int blocks (int loc[1000][26],char *word,char *spot)
{
    int i;
    for (i=0;i<strlen(word);i++)
    {
        spot[i] = '_';
    }
}

int input_check (int loc[1000][26],char *word,char *spot,int freq[26])
{
    char p, neWord[255];
	int g=0,h=0,t,i,x=0,memo[26]={0},life=0,li=0,k=0,m=0;
    li=strlen(word)-1;
    blank();
    while(g != strlen(word))
    {
        x=0;
        for (i=0;i<strlen(word);i++)
        {
            printf("%c ",spot[i]);
        }
    strcpy(neWord,word);
    printf("\ninput:");
	scanf("%s",&p);
    system("cls");
    
    for(i = 0; i<strlen(word); i++)
    {
    	if(p==neWord[i] && spot[i]!=p)
    	{
    		spot[i] = p;
    		g++;
    		k++;
    		x++;
		}
		
		if(spot[i] == p && x==0)
		{
			life++;
			k++;
		}
	}
	if(k==0)
	{
		life++;
	}
    k=0;
    x=0;
//    int x = (int)(p);
//    x-=97;
//    for (i = 0; i<strlen(word); i++)
//    {
//        if (loc[i][x] == 1 && memo[x]!=freq[x])
//        {
//            memo[x] = 1;
//            spot[i] = p;
//            g++;
//        }
//      else
//        {
//            k++;
//        };
//
//    }
//
//if(k<strlen(word))
//{k=0;}
//
//if(k==strlen(word))
//{k=1;}
//
//life+=k;
//k=0;
//if(life<0){life=0;}

    switch(life)
    {
        case 1 : one();     break;
        case 2 : two();     break;
        case 3 : three();   break;
        case 4 : four();    break;
        case 5 : five();    break;
        case 6 : six();     break;
        default : blank();
    }
    if(life == 6) {printf("\n\t\tYou Have Fail!!!...\n\n");return;}
}
	int score = 600000-(life*100000);
    printf(" Your score is : %d  \n",score);
    return score;
}
void one()
{
    int i;
    for (i=0;i<14;i++)
    {
        printf("                  |\n");
    }
}
void two()
{
    int i;
    printf("\t-----------\n");
    for (i=0;i<13;i++)
    {
        printf("                  |\n");
    }
}
void three()
{
    int i;
    printf("\t-----------\n");
             printf("\t|\t  |\n");
                for (i=0;i<12;i++)
                {
                printf("                  |\n");
                }
}
void four ()
{
    int i;
    printf("\t-----------\n");
    printf("\t|\t  |\n");
    printf("     -------      |\n");
    printf("     | o o |      |\n");
    printf("     |  -  |      |\n");
    printf("     -------      |\n");
    for (i=0;i<8;i++)
    {
        printf("                  |\n");
    }
}
void five ()
{
    int i;
    printf("\t-----------\n");
    printf("\t|\t  |\n");
    printf("     -------      |\n");
    printf("     | o o |      |\n");
    printf("     |  -  |      |\n");
    printf("     -------      |\n");

    printf("        |         |\n");
    printf("   -----+------   |\n");
    printf("        |         |\n");
    printf("        |         |\n");
    for (i=0;i<4;i++)
    {
        printf("                  |\n");
    }

}

void six ()
{
    int i;
    printf("\t-----------\n");
    printf("\t|\t  |\n");
    printf("     -------      |\n");
    printf("     | o o |      |\n");
    printf("     |  -  |      |\n");
    printf("     -------      |\n");

    printf("        |         |\n");
    printf("   -----+------   |\n");
    printf("        |         |\n");
    printf("        |         |\n");

    printf("        ^         |\n");
    printf("      /   \\       |\n");
    printf("     /     \\      |\n");
}

void blank()
{
    int i;
    for (i=0;i<14;i++)
    {
        printf("\n");
    }

}

void gui(life)
{
    switch(life)
    {
        case 1 : one();     break;
        case 2 : two();     break;
        case 3 : three();   break;
        case 4 : four();    break;
        case 5 : five();    break;
        case 6 : six();     break;
        default : blank();
    }

}
