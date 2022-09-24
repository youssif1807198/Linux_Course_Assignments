#include<stdio.h>  

int fact(int temp)
{
	int i,fact=1;    
   
    for(i=1;i<=temp;i++)
    {    
      fact=fact*i;    
    }
	
	return fact;

}



