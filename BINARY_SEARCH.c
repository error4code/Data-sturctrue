#include<stdio.h>
int main()
{
    int a[10],x,f=0,u,mid,n,i,l=0;
    printf("\nEnter the array size\n");
    scanf("%d",&n);
    printf("\nEnter the element\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    u=n-1;
    mid=(l+u)/2;
    printf("\n Enter the element to search\n");
    scanf("%d",&x);

    while (l<u)
    {
       if(a[mid]==x)
       {
        f=1;
        break;

       }
       else if(a[mid]>x)
       {
        u=mid-1;
       }
       else{
        l=mid+1;
    
       }}
       if (f==1)
       {
        printf("\nElement found at %d",mid+1);

       }
       else
       {
        printf("\nElement not found");

       }
       
    
    return(0);

    
}