#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char **argv) {
	char buffer[1000] = {0};
	int f_org = 0, f_cp = 0;
	int read_bytes = 0, written_bytes = 0;  //for read() write() error checking
	
	/*Checking for correct operands*/
	if (argc != 3)
	{
		printf("Enter 2 arguments\n");
	        exit(2);
	}
	
	/*opening first file with read-only option to copy from*/ 
	f_org = open(argv[1], O_RDONLY, 0644);
	/*Check error*/
	if (f_org < 0 )
	{ 
		perror("Error opening file");
          	exit(3);
	}
	//////////////
	/*copying file content to a buffer*/
	read_bytes = read(f_org, buffer, 1000);
	/*Check error*/
	if (read_bytes < 0 )
        {
                perror("Error reading file");
                exit(4);
        }
        //////////////
	
	/*opening second file with write-only and create option to create the file specified and write the copied data to it*/
	f_cp = open(argv[2], O_CREAT | O_WRONLY, 0644);
	/*Check error*/
	if (f_cp < 0 )
        {
                perror("Error opening file");
                exit(3);
        }
        //////////////
	/*writing copied content to the new file*/
	write(f_cp, buffer, strlen(buffer));
	/*Check error*/
	if (written_bytes < 0 )
        {
                perror("Error writing file");
                exit(5);
        }
        //////////////
	
	/*closing both files*/
	close(f_org);
	close(f_cp);

	return 0;
}
