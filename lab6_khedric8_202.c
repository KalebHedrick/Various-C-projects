#include <stdlib.h>
#include <stdio.h>
void InitArray(int *numArray, int arrayLength);
void ShuffleArray(int *numArray, int arrayLength);
int compare(const void * a, const void * b) {
    return (*(int*)a - *(int*)b)*-1;
}
int getMemory(int *myArray, int N) {
    if (N > 500 || N < 2) {
        printf("Error, size is not in range [2-500]");
        exit(1);
    }
myArray = malloc(sizeof(int) * N);
if(myArray == NULL){
printf("Error allocating memory!\n");
exit(1);
}
free(myArray);
return 0;
}
int main( int argc, char *argv[] )  {
    int seed;
    int N;
    int i;
    int k;
    int myArra[15];
    int *myArrayPointer = myArra;
    seed = atoi(argv[1]);
    N = atoi(argv[2]);
    srand(seed);
    getMemory(myArra, N);
for (k = 0; k < 10; k++) {
    InitArray(myArra,N);
    for (i = 0; i < N; i++) {
        printf("%i ",myArra[i]);
        
}
    printf("\n");
    ShuffleArray(myArra,N);
    for (i = 0; i < N; i++) {
        printf("%i ",myArra[i]);
        
}
    printf("\n");
qsort(myArra, N, sizeof(int), compare);
for (i = 0; i < N; i++) {
        printf("%i ",myArra[i]);
        
}
    printf("\n");
    printf("\n");
}
return 0;
}
void InitArray(int *numArray, int arrayLength) {
int i;
for (i = 1; i <= arrayLength; i++) {
    numArray[i-1] = i;
}
}
void ShuffleArray(int *numArray, int arrayLength) {
    int i,j,temp;
for (i = arrayLength-1; i > 0; i--) {
j = rand()%(i+1);
temp = numArray[j];
numArray[j] = numArray[i];
numArray[i] = temp;
}

}
