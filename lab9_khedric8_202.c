#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct
{
    int day;
    int month;
    int year;
} DOB;
typedef struct
{
    int ID;
    char FirstName[50];
    char LastName[50];
    DOB Dob;
    double Salary;
} Person;
void insertData(Person **person, int N, int *doubleMax);
void updateData(Person *person, int N);
void SearchData(Person *person, int N);
void Printdata(Person *person, int N);
int main()
{
    int N = 3;
    int done = 0;
    char inBuf[50];
    char user_input;
    Person *employees;
    int doubleMax = 0;
    employees = calloc(N, sizeof(Person));
    if (employees == NULL)
    {
        printf("Error allocating memory!\n");
        exit(1);
    }
    do
    {
        printf("Enter your Choice:\n");
        printf("\'i\' - Insert data\n");
        printf("\'u\' - Update data\n");
        printf("\'s\' - Search employee\n");
        printf("\'p\' - Print the database\n");
        printf("\'q\' - Quit\n");
        fgets(inBuf, 50, stdin);
        sscanf(inBuf, "%c", &user_input);
        if (user_input == 'q' || user_input == 'Q')
        {
            done = 1;
            free(employees);
        }
        else if (user_input == 'i' || user_input == 'I')
        {
            insertData(&employees, N, &doubleMax);
            if (doubleMax == N)
            {
                N = N * 2;
            }
        }
        else if (user_input == 'u' || user_input == 'U')
        {
            updateData(employees, N);
        }
        else if (user_input == 's' || user_input == 'S')
        {
            SearchData(employees, N);
        }
        else if (user_input == 'p' || user_input == 'P')
        {
            Printdata(employees, doubleMax);
        }
        else
        {
            printf("%c is not a valid choice\n", user_input);
        }
    } while (done != 1);
    return 0;
}
void insertData(Person **employees, int N, int *doubleMax)
{
    char inBuf[50];
    int ID;
    char FirstName[50];
    char LastName[50];
    int day;
    int month;
    int year;
    int i;
    double salary;
    printf("Enter id: ");
    fgets(inBuf, 50, stdin);
    sscanf(inBuf, "%i", &ID);
    for (i = 0; i < N; i++)
    {
        if ((*employees)[i].ID == ID)
        {
            printf("Error! ID is already in the database\n");
            return;
        }
    }
    printf("Enter First Name: ");
    fgets(inBuf, 50, stdin);
    sscanf(inBuf, "%s", FirstName);
    printf("Enter Last Name: ");
    fgets(inBuf, 50, stdin);
    sscanf(inBuf, "%s", LastName);
    printf("Enter day: ");
    fgets(inBuf, 50, stdin);
    sscanf(inBuf, "%i", &day);
    printf("Enter month: ");
    fgets(inBuf, 50, stdin);
    sscanf(inBuf, "%i", &month);
    printf("Enter year: ");
    fgets(inBuf, 50, stdin);
    sscanf(inBuf, "%i", &year);
    printf("Enter salary: ");
    fgets(inBuf, 50, stdin);
    sscanf(inBuf, "%lf", &salary);
    *doubleMax = *doubleMax + 1;
    if (*doubleMax == N)
    {
        (*employees) = realloc((*employees), sizeof(Person) * (N * 2));
    }
    (*employees)[*doubleMax - 1].ID = ID;
    (*employees)[*doubleMax - 1].Dob.day = day;
    (*employees)[*doubleMax - 1].Dob.month = month;
    (*employees)[*doubleMax - 1].Dob.year = year;
    (*employees)[*doubleMax - 1].Salary = salary;
    strcpy((*employees)[*doubleMax - 1].FirstName, FirstName);
    strcpy((*employees)[*doubleMax - 1].LastName, LastName);
}
void updateData(Person *employees, int N)
{
    int i;
    char inBuf[50];
    int IDExists = 0;
    int ID;
    int option;
    char FirstName[50];
    char LastName[50];
    int day;
    int month;
    int year;
    int currUser;
    double salary;
    int option_valid = 0;
    printf("Enter id: ");
    fgets(inBuf, 50, stdin);
    sscanf(inBuf, "%i", &ID);
    for (i = 0; i < N; i++)
    {
        if (employees[i].ID == ID)
        {
            IDExists = 1;
            currUser = i;
        }
    }
    if (IDExists == 0)
    {
        printf("ID doesn't exist\n");
        return;
    }
    else
    {
        do
        {
            printf("Which data do you want to update?\n1 - First Name\n2 - Last Name\n3 - DOB\n4 - Salary\n5 - Do not update\n");
            fgets(inBuf, 50, stdin);
            sscanf(inBuf, "%i", &option);
            switch (option)
            {

            case 1:
                printf("Enter new First name: ");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%s", FirstName);
                strcpy(employees[currUser].FirstName, FirstName);
                option_valid = 1;
                break;
            case 2:
                printf("Enter new Last name: ");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%s", LastName);
                strcpy(employees[currUser].LastName, LastName);
                option_valid = 1;
                break;
            case 3:
                printf("Enter day: ");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &day);
                printf("Enter month: ");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &month);
                printf("Enter year: ");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &year);
                employees[currUser].Dob.day = day;
                employees[currUser].Dob.month = month;
                employees[currUser].Dob.year = year;
                option_valid = 1;
                break;
            case 4:
                printf("Enter salary: ");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%lf", &salary);
                employees[currUser].Salary = salary;
                option_valid = 1;
                break;
            case 5:
                return;
            default:
                printf("Option is not valid, try it again\n");
                break;
            }
        } while (option_valid == 0);
    }
}
void SearchData(Person *employees, int N)
{
    char inBuf[50];
    int IDExists = 0;
    int currUser;
    int ID, i;
    printf("Enter id: ");
    fgets(inBuf, 50, stdin);
    sscanf(inBuf, "%i", &ID);
    for (i = 0; i < N; i++)
    {
        if (employees[i].ID == ID)
        {
            IDExists = 1;
            currUser = i;
        }
    }
    if (IDExists == 0)
    {
        printf("ID Not Found\n");
        return;
    }
    printf("*********************************************************\n");
    printf("ID: %i\n", employees[currUser].ID);
    printf("First Name: %s\n", employees[currUser].FirstName);
    printf("Last Name: %s\n", employees[currUser].LastName);
    printf("DOB: %i/%i/%i\n", employees[currUser].Dob.month, employees[currUser].Dob.day, employees[currUser].Dob.year);
    printf("Salary: %.2f\n", employees[currUser].Salary);
    printf("*********************************************************\n");
}
void Printdata(Person *employees, int N)
{
    int i;
    char name[50];
    printf("*********************************************************\n");
    printf("ID      Name                    DOB             Salary\n");
    for (i = 0; i < N; i++)
    {
        strcpy(name,employees[i].FirstName);
        strcat(name, " ");
        strcat(name,employees[i].LastName);
        printf("%-5i\t%-16s\t%-i/%i/%-4i\t%-.2f\n", employees[i].ID, name, employees[i].Dob.month,
        employees[i].Dob.day, employees[i].Dob.year, employees[i].Salary);
    }
    printf("*********************************************************\n");
}