#include "stdio.h"
#include "stdlib.h"
#include "curses.h"
#include "fact.h"
#include "rand.h"
#include "fib.h"

int main(void)
{
	
    char str[100];
    int number;



	while(1)
	{

    printf("Execute Commands > ");
    gets(str);
	
	
	if(str[0]=='e' && str[1]=='x'&&str[2]=='i'&&str[3]=='t')
	{
		
	    printf("\nGood Bye :)\n");
		return 0;

		
		
	}
	
	else if (str[0]=='r' && str[1]=='a'&&str[2]=='n'&&str[3]=='d')
	{
		printf("Result is ");
		Command_Rand();
		printf("\n");
	}
	
	else if (str[0]=='f' && str[1]=='a'&&str[2]=='c'&&str[3]=='t')
	{
		printf("Enter a number: ");
		gets(str);
		number=atoi(str);
		printf("Result is ");
		printf("%d\n",fact(number));
	
	
	}
	
	else if (str[0]=='f' && str[1]=='i'&&str[2]=='b')
	{
		printf("Enter a number: ");
		gets(str);
		number=atoi(str);
		printf("Result is ");
		printf("%d\n",fib(number));
	

	}
	
	else
	{
	    printf("You said: ");
    	    puts(str);
	
	
	}
	
	
  


	}

	
	
	return 0;
}
