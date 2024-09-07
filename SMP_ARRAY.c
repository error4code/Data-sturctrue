#include<stdio.h>
#define MAX 10
int main()
{
    int a[MAX],n;

    int i,sum=0;

    printf("\nenter the array size\n");
    scanf("%d",&n);


for ( i = 0; i < n; i++)
{
    printf("\nenter the element to be entered in the position[%d]\n",i+1);

    scanf("%d",&a[i]);
   
}
for(i=0;i<n;i++)
{
    sum=sum+a[i];
    
}
 
 printf("Sum of the array =%d",sum);
 return 0;

}