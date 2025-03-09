#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv) {
	int f_old = 0, f_new = 0;
	char buff[1000] = {0};
	int read_bytes = 0, written_bytes = 0, unlink_ret = 0;  //for read() write() unlink() error checking

	/*Checking for correct operands*/
        if (argc != 3)
        {
                printf("Enter 2 arguments\n");
                exit(2);
        }

	/*opening the file needed to be moved to copy its data*/
	f_old = open(argv[1], O_RDONLY, 0644);
	/*Check error*/
        if (f_old < 0 )
        {
                perror("Error opening file");
                exit(3);
        }
        //////////////
	/*copying data from file nedded to be moved*/
	read_bytes = read(f_old, buff, 1000);
	/*Check error*/
        if (read_bytes < 0 )
        {
                perror("Error reading file");
                exit(4);
        }
        //////////////

	/*checking if the second arg is a directory or a file where if a directory -> the file will 
	 * not be renamed, else if it is a file name -> the file will be moved and renamed.
	 *so we create a file with write only option to fill it with the copied data*/ 
	f_new = open(argv[2], O_WRONLY | O_CREAT, 0644);
	/*here we will not use error checking because if the user enters the second argument only as a
	 * directory it will always exit with error 3 as we can't open a directory with write-only
	 * option, So we will just ignore it.*/
	/*Check error
        if (f_new < 0 )
        {
		printf("%d\n",f_new);
                perror("Error opening file2");
                exit(3);
        }*/
	 struct stat statbuf;
    if (stat(argv[2], &statbuf) == -1) {
        perror("fstat error");
        close(f_new);
        exit(6);
    }

    if (S_ISDIR(statbuf.st_mode)) {
     	close(f_new);
	strcat(argv[2], argv[1]);
	f_new = open(argv[2], O_WRONLY | O_CREAT, 0644);
    }

    write(f_new, buff, strlen(buff));
    /*On success, unlink() returns 0.
      On failure, it returns -1*/
    unlink_ret = unlink(argv[1]);	//removing original file
    /*Check error*/
        if (unlink_ret != 0 )
        {
                perror("can't remove file");
                exit(7);
        }
     //////////////

	close(f_old);
	close(f_new);

	return 0;
}
