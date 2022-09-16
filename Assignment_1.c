#include <stdio.h>
#include<conio.h>

int main(void)
{
	
    char str[100];



	while(1)
	{

    printf("Execute Commands > ");
    gets(str);
	
	
	if(str[0]=='e' && str[1]=='x'&&str[2]=='i'&&str[3]=='t')
	{
		
	    printf("\nGood Bye :)");
		return 0;

		
		
	}
	
	
    printf("You said: ");
    puts(str);  


	}

	
	
	return 0;
}