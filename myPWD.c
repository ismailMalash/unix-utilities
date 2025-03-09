#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define std_out 1

int main(void)
{
	char cwd[80] = {0};
	int write_ret = 0;

	if (getcwd(cwd, 80) == NULL)
	{
		printf("Error 1 Happened!\n");
		exit(2);
	}

	write_ret = write(std_out, cwd, 80);
	if(write_ret < 0)
	{
		printf("Error 2 Happened!\n");
		exit(3);
	}
	
	write_ret = write(std_out, "\n", 2);
	if(write_ret < 0)
        {
                printf("Error 2 Happened!\n");
                exit(3);
        }

	return 0;
}
