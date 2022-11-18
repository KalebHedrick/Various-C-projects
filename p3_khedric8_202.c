#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void addNode();
void clear();
void print ();
void copy();
void removeNode();
void unionSets();
void intersection();
void symmetricdifference();
int strcmpa(char *s1, char *s2)
{
    while (*s1 && tolower(*s1) == tolower(*s2))
    {
        s1++;
        s2++;
    }
    return tolower(*s1) - tolower(*s2);
}
int main()
{
    char inBuf[50];
    int Set_Amount,quit = 0;
    char user_input;
    printf("Enter the number of sets to create: ");
    fgets(inBuf, 50, stdin);
    sscanf(inBuf, "%i", &Set_Amount);
    while(quit == 0) {
        printf("Add String: a or A\n");
        printf("Remove String: r or R\n");
        printf("Union: u or U\n");
        printf("Intersection: i or I\n");
        printf("Symmetric Difference: s or S\n");
        printf("Copy: c or C\n");
        printf("Clear: z or Z\n");
        printf("Print Set: p\n");
        printf("Print All Sets: P\n");
        printf("Quit: q or Q\n");
        fgets(inBuf, 50, stdin);
        sscanf(inBuf, "%c", &user_input);
        }
    return 0;
}