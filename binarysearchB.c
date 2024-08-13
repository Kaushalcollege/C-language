#include<stdio.h>
 
int SOD(int x)
{
   int sodsum=0;
   for(int i=2; i<x; i++)
   {
     if(x%i==0)
     {
        sodsum = sodsum +i;
     }
   }
   return sodsum;
}
long CSOD(int y)
{
    int a=y;
    long csodsum=0;
    for (int i=1;i<=y;i++)
    {
        csodsum= csodsum + SOD(i);
    }
    return csodsum;
}
int main()
{
    int hehe;
    long hehereturn;
    scanf("%d", &hehe);
    hehereturn=CSOD(hehe);
    printf("%ld\n", hehereturn);
    return 0;
}