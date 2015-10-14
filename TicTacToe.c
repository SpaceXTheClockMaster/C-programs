#include <stdio.h>

//global variable declaration
int i, j;
char str1[5], str2[5];
int arr[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

//function declarations
void name(); //dpne
void enter1(); //done
void display(); //done
void enter2(); //done
int check();
void draw();
int drawcheck();
void congo1(); //done
void congo2(); //done

int main ()
{
i=10;
printf("\nWelcome to Tic-tac-toe, %s & %s", str1, str2);
while(i==10)
{
name();

enter1();
i= check();
i = drawcheck();
if (i==1)
{congo1(); break;}
else if(i==2)
{draw(); break;}

enter2();
i=check();
i=drawcheck();
if (i==1)
{congo2(); break;}
else if(i==2)
{draw(); break;}

i=10;
}

}

int check()
{
    int flag;
//rowcheck
    for (i=0, j=0; j<=2; j++)
    {
    if(arr[i][j] != 0)
        flag = 1;
    else
        {flag = 2; break;}
    }
    if (flag==1) return 1;

    for (i=1, j=0; j<=2; j++)
    {
    if(arr[i][j] != 0)
        flag = 1;
    else
        {flag = 2; break;}
    }
    if (flag == 1) return 1;

      for (i=2, j=0; j<=2; j++)
    {
    if(arr[i][j] != 0)
        flag = 1;
    else
        {flag = 2; break;}
    }
    if (flag==1) return 1;

//col check:
}

void name()
{
printf("\nWelcome Player 1, please enter your name: "); gets(str1);
printf("Welcome Player 2, please enter your name: "); gets(str2);
}

void congo1()
{
printf("%s has won, congratulations!", str1);
}

void congo2()
{
printf("%s has won, congratulations!", str2);
}

void display()
{
    int a, b;
    printf("\nDisplaying tic-tac-toe table:\n");
    if (a=0; a<=2; a++)
    {
        if(b=0; b<=2; b++)
        {
            printf("%d", arr[a][b]);
        }
        printf("\n");
    }
}

void enter1()
{
    back:
    printf("\nIt's %s's turn. Please select the row & column you want to insert at: ", str1);
    scanf("%d %d", &i, &j);
    if(arr[i][j] != 0)
    {printf("Invalid choice."); goto back;}
    else
    arr[i][j] = 1;
}

void draw()
{
printf("\nThe match is a draw, no-one wins :( ");
}

int drawcheck()
{

}

void enter2()
{
    back2:
    printf("\nIt's %s's turn. Please select the row & column you want to insert at: ", str2);
    scanf("%d %d", &i, &j);
    if(arr[i][j] != 0)
    {printf("Invalid choice."); goto back2;}
    else
    arr[i][j] = 2;
}

