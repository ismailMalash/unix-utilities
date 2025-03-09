#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define std_out 1
int main(int argc, char **argv)
{
	int written_bytes = 0;

	/*loop and write each argument(string) to the standard output(terminal)*/
	for (int i = 1; i < argc; i++)
	{
		written_bytes = write(std_out, argv[i], strlen(argv[i]));
		/*Check error*/
        	if (written_bytes < 0 )
        	 {
                	perror("Error writing stdout");
               		 exit(5);
       		 }
        	//////////////
		if (i < argc - 1) 
		{
            			written_bytes = write(std_out, " ", 2);
				/*Check error*/
        			if (written_bytes < 0 )
        			{
                			perror("Error writing stdout");
                			exit(5);
        			}
        			//////////////        			
	      	}
	}
	
	if (argc > 1)
	{
		written_bytes = write(std_out, "\n", 2);        //just printing new line in case of argument/s existed
        	/*Checking error*/
        	if (written_bytes < 0 )
        	{
                	perror("Error writing stdout");
                	exit(5);
        	}
        	//////////////
	}

	return 0;
}
