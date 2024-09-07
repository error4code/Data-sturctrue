#include<stdio.h>
int main()
{
int a[10];
int i,n,flag=0,key;

printf("enter the array size");
scanf("%d",&n);
 printf("enter %d elements of the array",n);
 for(i=0;i<n;i++)
 {
    scanf("%d",&a[i]);

 }
printf("enter the elememt to search");
scanf("%d",&key);

for(i=0;i<n;i++)
{
    if(a[i]==key)
    {
         flag=1;
         break;
         
    }
}

    if (flag==1)
    {
        printf("element %d found at position %d",key,i+1);

    }
    else{
        printf("element %d not found",key);

    }




return 0;

}