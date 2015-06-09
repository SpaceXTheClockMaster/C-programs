#include <math.h>
#include <stdio.h>

int main ()
{
int number[100], i, a, j, upper = 99, lower = 0, mid, m, b;

for (i=0; i<100; i++)
{number[i]= (rand() % ((100 - 0 + 1)) + 0);}
for (i = 0; i < 100; i++)
{
 for (j = i + 1; j < 100; j++)
 {
   if (number[i] > number[j])
   {
    a =  number[i];
    number[i] = number[j];
    number[j] = a;
   }
 }
} //sorted in ascending order

printf("Enter elements to be searched(1-100): ");
scanf("%d", &m);

while(lower <= upper)
{
 mid = (lower+upper)/2;

 if (m == number[mid])
 {
  b=1;
  break;
 }
 else if(m < number[mid])
 {
  upper = mid-1;
 }
 else
  lower = mid+1;
 }
 if(b==0)
 printf("\nThe number is not found.\n");
 else
 printf("\nThe number is found.\n");
 
 return 0;
}
