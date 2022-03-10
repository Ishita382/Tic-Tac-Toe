#include <stdio.h>
#include<conio.h>

int l=0;
int size=9;
char u;
 char computer;  //computer's character
    char player;   // players character
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int botchoice[9]= { 1,2,3,4,5,6,7,8,9 };
void choicemark();
void choicemark()
{
    system("cls");


     printf("\033[1;31m");
printf("\n\n                                     Lets play the game of Tic Tac Toe");

printf("\033[1;32m");
   printf("\n\n\n\n\nEnter the character you want to use:\nO or X : ");
   reset();
   scanf("%c",&u);
   if(u!='O'&&u!='X')
   {
       printf("Invalid Option\n");
       choicemark();


   }
if(u=='X')
    {
       computer='O';
        player='X';

    }
    else
        {
            computer='X';
        player='O';

    }


}


void red();
void reset();
void red () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;32m");
}

void reset () {
  printf("\033[0m");
}

int botturn();
void varyarray(int n);
void varyarray(int n)
{

    int i,j;
    for(i=0;i<size;i++)
    {

        if(botchoice[i]==n)
        {
            for(j=i;j<size;j++)
           botchoice[j]=botchoice[j+1];
           size--;

break;
        }
    }

}
int botturn()
{
    int k,b=botchoice[0],p,z;
    char temp;
    for(k=0;k<size;k++)
    {
        z=botchoice[k];
        temp=square[z];
        square[z]= computer;
       p=check();
       square[z]=temp;
       if (p==1)
{
     return z;
     break;
}



    }

  for(k=0;k<size;k++)
    {
        z=botchoice[k];
        temp=square[z];
        square[z]= player;
       p=check();
       square[z]=temp;
       if (p==1)
{
     return z;
     break;
}



    }




return b;


}


int checkwin();
void board();
int check();


int main()
{

    int Player = 1, i, choice;

    char mark;
    char computer;  //computer's character
    char player;   // players character
    choicemark();
    if(u=='X')
    {
       computer='O';
        player='X';

    }
    else
        {
            computer='X';
        player='O';

    }
    do
    {
        board();
        Player = (Player % 2) ? 1 : 2;
if(Player==1)
       {

         printf("\033[1;36m");

        printf("Please enter a number where you want to place your character:  ", Player);
        printf("\033[0m");

        scanf("%d", &choice);

       }
       else                   //computers turn
       {

      choice= botturn();

       }
        varyarray(choice);


        mark = (Player == 1) ? player : computer;

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            printf("\a\n\n\nInvalid move, Please enter a valid move.\nPress any key to continue. ");

            Player--;
            getch();
        }
        i = checkwin();

        Player++;
    }while (i ==  - 1);

    board();

    if (i == 1)
    {
        --Player;
       if(Player==1)
        {
            printf("\033[1;36m");
            printf(" \n\n");
            printf("\a* You win * \n\n");

        printf("\033[0m");
        }

        else
        {
         printf("\033[1;36m");
         printf("\n\n");

        printf("\a* Computer wins *\n\n");
        printf("\033[0m");
        }

    }

    else
    {

    printf("\033[1;36m");
         printf("\n\n");

        printf("\a* Game Draws *\n\n");

        printf("\033[0m");}
    getch();


    return 0;
}


int check()
{

    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

}


int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}




void board()
{


    system("cls");
  printf("\033[1;32m");
     printf("                                         Here you go!!\n");
    printf("\033[0m");
     printf("\033[1;33m");
    printf("Your character: ");
    printf("\033[0m");
    printf("%c\n",player);
     printf("\033[1;33m");
    printf("Computer character: ");
    printf("\033[0m");
    printf("%c\n\n\n\n",computer);
    printf("                                  |     |     \n");

if(square[1]=='X')
{
  red();
    printf("                               %c  ", square[1]);
reset();
}
else if(square[1]=='O')
{
 yellow();
    printf("                               %c  ", square[1]);
reset();
}
else
  printf("                               %c  ", square[1]);
if(square[2]=='X')
{ printf("|");
  red();
    printf("  %c  ",  square[2]);
reset();
 printf("|");
}
else if(square[2]=='O')
{ printf("|");
  yellow();
    printf("  %c  ",  square[2]);
reset();
 printf("|");
}
else
    printf("|  %c  |",  square[2]);
if(square[3]=='X')
{
  red();
    printf("  %c \n", square[3]);

reset();
}
else if(square[3]=='O')
{
  yellow();
    printf("  %c \n", square[3]);

reset();
}
else
   printf("  %c \n", square[3]);






    printf("                             _____|_____|_____\n");
    printf("                                  |     |     \n");

    if(square[4]=='X')
{
  red();
    printf("                               %c  ", square[4]);
reset();
}
else if(square[4]=='O')
{
 yellow();
    printf("                               %c  ", square[4]);
reset();
}
else
  printf("                               %c  ", square[4]);
if(square[5]=='X')
{ printf("|");
  red();
    printf("  %c  ",  square[5]);
reset();
 printf("|");
}
else if(square[5]=='O')
{ printf("|");
  yellow();
    printf("  %c  ",  square[5]);
reset();
 printf("|");
}
else
    printf("|  %c  |",  square[5]);
if(square[6]=='X')
{
  red();
    printf("  %c \n", square[6]);

reset();
}
else if(square[6]=='O')
{
  yellow();
    printf("  %c \n", square[6]);

reset();
}
else
   printf("  %c \n", square[6]);


    printf("                             _____|_____|_____\n");
    printf("                                  |     |     \n");

   if(square[7]=='X')
{
  red();
    printf("                               %c  ", square[7]);
reset();
}
else if(square[7]=='O')
{
  yellow();
    printf("                               %c  ", square[7]);
reset();
}
else
  printf("                               %c  ", square[7]);
if(square[8]=='X')
{ printf("|");
  red();
    printf("  %c  ",  square[8]);
reset();
 printf("|");
}
else if(square[8]=='O')
{ printf("|");
  yellow();
    printf("  %c  ",  square[8]);
reset();
 printf("|");
}
else
    printf("|  %c  |",  square[8]);
if(square[9]=='X')
{
  red();
    printf("  %c \n", square[9]);

reset();
}
else if(square[9]=='O')
{
  yellow();
    printf("  %c \n", square[9]);

reset();
}
else
   printf("  %c \n", square[9]);

    printf("                                  |     |     \n\n");
}

