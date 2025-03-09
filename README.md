# unix-utilities
This repository contains implementations of basic Unix utilities in C, as part of my learning and practice of system programming. The utilities implemented include pwd, echo, cp, and mv, each demonstrating key concepts of system-level programming, such as working with system calls, file I/O operations, and error handling.

## Utilities

The following Unix-like utilities are implemented in this repository:

1. **myPWD**: Prints the current working directory using the `getcwd()` system call.
2. **myECHO**: Prints a user-input string to `stdout`.
3. **cmCP**: Creates a copy of a given source file to a given destination directory.
4. **myMV**: Moves a file to another directory, possibly with a new name.

## Compilation

myPWD: gcc myPWD.c -o myPWD
myECHO: gcc myECHO.c -o myECHO
cmCP: gcc cmCP.c -o cmCP
myMV: gcc myMV.c -o myMV

## Example of output
1- ./myPWD
    /home/ismail-malash/Desktop/SysProgInLinux
    
2- ./myECHO Hello Eng.Reda This is Ismail talking!
    Hello Eng.Reda This is Ismail talking!

3- ./myCP new.txt new_file.txt
    diff new.txt new_file.txt 
    /*no output as no difference*/

4- ./myMV new.txt ../new_file.txt
    ls ../
    finder-test.sh  github_token  gstreamertut  new.txt  SysProgInLinux
    ls
    myCP  myCP.c  myECHO  myECHO.c  myMV  myMV.c  myPWD  myPWD.c

   
