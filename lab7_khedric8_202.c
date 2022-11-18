#include <stdlib.h>
#include <stdio.h>
#define SIZE 50
int main( int argc, char *argv[] )  {
    FILE *ptInput;  /*INITIALIZING FILE POINTERS*/
    FILE *ptOutput;
    /*initializes needed variables and pointers*/
    int gnum, num1, num2;
    char gpa[SIZE];
    char class[SIZE];
    char name[SIZE];
    int leng = 0;
    char inBuf[SIZE];
    double finalGPA;
    char *ptTRASH;
    int count = 0;
    if (argc != 3) {
        printf("ERROR, IMPROPER ARGUMENTS!");  /*CHECKING FOR CORRECT NUMBER OF ARGUMENTS*/
        return 0;
    }
    ptInput = fopen(argv[1],"r");      /*DECLARING POINTERS WITH INPUT AND OUTPUT FILE*/
    ptOutput = fopen(argv[2],"w");
   if (ptInput == NULL) {  /* BONUS CHECK TO MAKE SURE ARUGMENT IS A VALID FILE NAME*/
    printf("INVALID");
   }
    do {          /*LOOP THAT ITERATES EACH LINE OF TEXT FILE USING NUMBER IN LINE 1*/
        fgets(inBuf, SIZE, ptInput);
        if (leng == 0) {
            leng = atoi(inBuf);          /*DECLARES THE LINE ONE NUMBER FOR LENGTH*/
            continue;
        }
        else {
            /*sscanf reads line and declares each variable to its value*/
          sscanf(inBuf, "%i %[^,], %i %s %i %s",&gnum,name,&num1,class,&num2,gpa);
          finalGPA = strtod(gpa,&ptTRASH); /*this method turns gpa string into a double*/
          /* These print the values with proper formatting onto the output file*/
          fprintf(ptOutput,"%-25s ",name);
          fprintf(ptOutput,"%-10i ",gnum);
          fprintf(ptOutput,"%-8.2f ",finalGPA);
          fprintf(ptOutput,"%-10s ",class);
          fprintf(ptOutput,"%-3i ",num2);
          fprintf(ptOutput,"%3i ",num1);
        }
        if (count+1 != leng) {   /*This prints a new line if there is another line to print*/
            fprintf(ptOutput,"\n");
        }
        count++;
    }
    while (count != leng);
    fclose(ptInput); /* closes input and output files*/
    fclose(ptOutput);
    return 0;
}