#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistd.h>
#include <strings.h>

#include <sys/wait.h>

#include <stdlib.h>

       #include <stdlib.h>




#define NUM_OF_ARG  10
#define SPACE_ASCII 32U

extern char **environ;

int Last_Occur(char *s, char c, int Start_From)
{
    int i, k = 0;
    for (i = strlen(s) - 1; i >= Start_From; i--) {
	if (s[i] == c) {
	    k = 1;
	    break;
	}
    }


    if (k == 1) {
	return i;

    } else {
	return -1;

    }

}

int First_Occur(char *s, char c, int Start_From)
{
    int i, k = 0;

    for (i = Start_From; i < strlen(s) - 1; i++) {
	if (s[i] == c) {
	    k = 1;
	    break;

	}

    }

    if (k == 1) {
	return i;

    } else {
	return -1;

    }



}



int main()
{

    char Buff[100];
    int len = 0;

    int Ret_ID = -1;
    int status = -1;
    int Find_Element=-1;

    char ptr_Arg[NUM_OF_ARG][NUM_OF_ARG];
    char *argument_list[NUM_OF_ARG];


			/*Data base of variables*/
    char Variables_Name_list[NUM_OF_ARG][NUM_OF_ARG];
    int R_Iterator = 0;
    int C_Iterator = 0;
    
    char Variables_Value_list[NUM_OF_ARG][NUM_OF_ARG];
    int R1_Iterator = 0;
    int C1_Iterator = 0;

    int First_Space = -1;
    int Eq_Flag = -1;

    int Start_Arg = 0;
    int Row_Iterator = 0;
    int Col_Iterator = 0;

    while (1) {
	
	Find_Element=-1;	
	First_Space = -1;
	Eq_Flag = -1;
	
	Start_Arg = 0;
	Row_Iterator = 0;
	Col_Iterator = 0;
	
	
    C1_Iterator = 0;
	
    C_Iterator = 0;
	printf("Execute Commands>  ");
	if (fgets(Buff, 100, stdin) == NULL) 
	{


	    printf("error getting command name");
	    return -1;

	} 
	else {


	    len = strlen(Buff);
	    Buff[len - 1] = 0;



	    if (strlen(Buff) == 0) 
	    {
			
		continue;


	    }


	    else {
			
		for (int i = 0; i < strlen(Buff); i++) {
			


		    if (Buff[i] != SPACE_ASCII) {
				
		
		



			if ((First_Space =
			     First_Occur(Buff, SPACE_ASCII, i)) == -1) {

			    First_Space = strlen(Buff);

			}

			Row_Iterator = 0;

			for (Start_Arg = i; Start_Arg < First_Space;
			     Start_Arg++) {
					 
					 
				if(Buff[Start_Arg]=='=')
					{

						Eq_Flag=1;	
					}
					 
					 

			    ptr_Arg[Col_Iterator][Row_Iterator] =
				Buff[Start_Arg];
			    Row_Iterator++;




			}
			ptr_Arg[Col_Iterator][Row_Iterator] = '\0';
			argument_list[Col_Iterator] =
			    ptr_Arg[Col_Iterator];

			i = Start_Arg;
			Col_Iterator++;

		    }

		}

		argument_list[Col_Iterator] = NULL;
		

		
		if(Eq_Flag==1)
		{
			
			int Eq_Loc=First_Occur(ptr_Arg[0], '=', 0);
			 

			for(int i=0;i<Eq_Loc;i++)
			{
				
				Variables_Name_list[R_Iterator][C_Iterator++]=ptr_Arg[0][i];

				
			}
			    Variables_Name_list[R_Iterator][C_Iterator]='\0';

			for(int i=Eq_Loc+1 ; i<Row_Iterator; i++ )
			{
				
				Variables_Value_list[R1_Iterator][C1_Iterator++]=ptr_Arg[0][i];

				
			}	
				Variables_Value_list[R1_Iterator][C1_Iterator++]='\0';	
		
		R_Iterator ++;
		R1_Iterator ++;
		
	

		

	    }

}
	    Ret_ID = fork();

	    if (Ret_ID < 0) {

		printf("Fork is Failed");
		return -1;


	    }

	    else if (Ret_ID > 0) {

		wait(&status);

	    }

	    else if (Ret_ID == 0) {
			
			
			if(Eq_Flag==1)
			{
				
			continue;	
				
			}


			
			/*Display data base*/
			if(	(strcmp(argument_list[0],"set"))==0	)
			{
				
				
				for(int i=0;i<R_Iterator;i++)
				{
					
					
				printf("%s=%s\n",Variables_Name_list[i],Variables_Value_list[i]);	
					
					
				}
				
				
			}
			else if(	(strcmp(argument_list[0],"export"))==0	)
			{
				
				if(	argument_list[1]==NULL	)
				{
					
				printf("please enter valid variable\n");
				continue;	
					
				}
				
				for(int i=0;i<R_Iterator;i++)
				{
					
					if(	(	strcmp(Variables_Name_list[i],argument_list[1])	)	==0)
					{
						
						
						Find_Element=i;
						
						
					}
									
					
				}
				
				if(Find_Element!=-1)
				{
					
					
				       setenv(Variables_Name_list[Find_Element], Variables_Value_list[Find_Element], 1)  ;
				       
	
					
				}
				else
				{
					
					
				printf("Please enter valid variable\n");	
					
				}
				
				
				
				
				
				
				
			}
			
			else
			{


					if (execvp(argument_list[0], argument_list) == -1) {

						printf("Failed in exec function\n");


					}

			}

	    }


	}



    }

}
