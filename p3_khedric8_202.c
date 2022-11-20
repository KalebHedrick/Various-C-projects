#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
 struct a_node{
    char string[50][50];
    int amountStrings;
    struct a_node *next;
};
typedef struct a_node node;
void addNode(node **head, char add_string[50], int set_num, int user_add);
void clear(node **head, int set_num);
void print(node **head, int set_num);
void copy(node **head, int copy_from,int copy_to);
void removeNode(node **head,char add_string[50], int set_num);
void unionSets(node **head, int dest_set, int set_1, int set_2);
void intersection(node **head, int dest_set, int set_1, int set_2);
void symmetricdifference(node **head, int dest_set, int set_1, int set_2);
void printAll(node **head,int set_num);
int strcmpa(char *s1, char *s2)
{
    while (*s1 && tolower(*s1) == tolower(*s2))
    {
        s1++;
        s2++;
    }
    return tolower(*s1) - tolower(*s2);
}
void sets_create(node **head, int Set_Amount) {
 node *currNode = *head;
 int i;
    for(i= 0; i < Set_Amount-1; i++) {
        (currNode)->next = (node *)malloc(sizeof(node));
        currNode = (currNode)->next;
    }
}
int main()
{
    char inBuf[50];
    int Set_Amount,set_num,set_num2,set_num3,quit = 0;
    char user_input;
    char temp_input[50];
    char user_String[50];
    int i;
    int user_add = 0;
    node *headstr = NULL;
    node *currNode2;
    printf("Enter the number of sets to create: ");
    fgets(inBuf, 50, stdin);
    sscanf(inBuf, "%i", &Set_Amount);
    headstr = (node *)malloc(sizeof(node));
   sets_create(&headstr,Set_Amount);
    while(quit == 0) {
        printf("Choose from the menu prompt below:\n");
        printf("\t*****Menu Options*****\n");
        printf("\tAdd String: a or A\n");
        printf("\tRemove String: r or R\n");
        printf("\tUnion: u or U\n");
        printf("\tIntersection: i or I\n");
        printf("\tSymmetric Difference: s or S\n");
        printf("\tCopy: c or C\n");
        printf("\tClear: z or Z\n");
        printf("\tPrint Set: p\n");
        printf("\tPrint All Sets: P\n");
        printf("\tQuit: q or Q\n");
        fgets(inBuf, 50, stdin);
        sscanf(inBuf, "%s", temp_input);
        if (strlen(temp_input) > 1) {
            user_input = 'N';
        }
        else {
            user_input = temp_input[0];
        }
        switch(user_input) {
            case 'a':
            case 'A':
                printf("Enter in the set you want to add to Set 0 - Set %i]\n",Set_Amount-1);
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &set_num);
                printf("Enter in the string you want to add\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%s", user_String);
                addNode(&headstr,user_String,set_num,user_add);
                break;
            case 'p':
                printf("What set do you want to print?\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &set_num);
                print(&headstr,set_num);
                break;
            case 'P':
                printAll(&headstr,Set_Amount);
                break;
            case 'Z':
            case 'z':
                printf("What set do you want to clear?\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &set_num);
                clear(&headstr, set_num);
                break;
            case 'R':
            case 'r':
                printf("What set do you want to remove from?\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &set_num);
                printf("Enter in the string you want to remove\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%s", user_String);
                removeNode(&headstr,user_String,set_num);
                break;
            case 'c':
            case 'C':
                printf("What set do you want to copy to?\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &set_num2);
                printf("What set do you want to copy from?\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &set_num);
                copy(&headstr,set_num,set_num2);
                break;
            case 'u':
            case 'U':
                printf("What is your destination set?\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &set_num);
                printf("Union Set 1?\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &set_num2);
                printf("Union Set 2?\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &set_num3);
                unionSets(&headstr,set_num,set_num2,set_num3);
                break;
            case 'i':
            case 'I':
                printf("What is your destination set?\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &set_num);
                printf("Intersection Set 1?\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &set_num2);
                printf("Intersection Set 2?\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &set_num3);
                intersection(&headstr,set_num,set_num2,set_num3);
                break;
            case 's':
            case 'S': 
                printf("What is your destination set?\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &set_num);
                printf("Symmetrical difference Set 1?\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &set_num2);
                printf("Symmetrical difference Set 2?\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &set_num3);
                symmetricdifference(&headstr,set_num,set_num2,set_num3);
                break;
            case 'q':
            case 'Q':
                currNode2 = headstr->next;
                for (i=0; i < Set_Amount; i++) {
                    free(headstr);
                    if (i+1 == Set_Amount) {
                        break;
                    }
                    headstr = currNode2;
                    currNode2 = headstr->next;
                }
                printf("Memory freed successfully\n");
                quit = 1;
                break;
            default:
                printf("Invalid menu option, please select a valid option\n");
        }
        }
    return 0;
}
void addNode(node **head, char new_string[50],int set_num,int user_add) {
    int i,k = 0;
    node *currNode = *head;
    char temp_string[50][50];
    int index = 0;
    for(i = 0; i < set_num; i++) {
        currNode = currNode->next;
    }
    if (currNode->amountStrings == 0) {
        strcpy(currNode->string[currNode->amountStrings],new_string);
        currNode->amountStrings++;
        return;
    }
    else {
    for(i = 0; i < currNode->amountStrings; i++) {
        if (strcmpa(new_string,currNode->string[i]) == 0 && user_add == 0) {
            printf("Duplicate string, entry is not valid\n");
            return;
        } 
        else if (user_add == 1 && strcmpa(new_string,currNode->string[i]) == 0) {
            return;
        }
    }
    for(i = 0; i < currNode->amountStrings; i++) {
        if (strcmpa(new_string,currNode->string[i]) > 0) {
            index = i+1;
        }
    }
    for(i = 0; i < currNode->amountStrings+1; i++) {
    if (i == index) {
        k = 1;
        strcpy(temp_string[i],new_string);
        strcpy(temp_string[i+k],currNode->string[i]);
    }
    else {
        strcpy(temp_string[i+k],currNode->string[i]);
    }
    }
    currNode->amountStrings++;
    for(i = 0; i < currNode->amountStrings; i++) {
        strcpy(currNode->string[i],temp_string[i]);
    }
    }
}
void print(node **head, int set_num) {
    node *currNode = *head;
    int i;
    for(i = 0; i < set_num; i++) {
        currNode = currNode->next;
    }
    printf("Set %i:{",set_num);
    for (i = 0; i < currNode->amountStrings; i++) {
        if (i+1 == currNode->amountStrings) {
            printf("%s",currNode->string[i]);
        }
        else {
        printf("%s, ",currNode->string[i]);
        }
    }
    printf("}\n");
}
void printAll(node **head,int set_num) {
    node *currNode = *head;
    int i;
    for(i = 0; i < set_num; i++) {
        if (currNode->amountStrings == 0) {
            currNode = currNode->next;
        }
        else {
            print(head,i);
            currNode = currNode->next;
        }
    }
}
void removeNode(node **head,char remove_string[50], int set_num) {
    node *currNode = *head;
    int i,k = 0;
    char temp[50][50];
    int removed = 0;
    char empty[50] = "";
    for(i = 0; i < set_num; i++) {
        currNode = currNode->next;
    }
    for(i = 0; i < currNode->amountStrings; i++) {
        if (strcmpa(currNode->string[i],remove_string)==0) {
            removed = 1;
            k++;
        }
        else {
            strcpy(temp[i-k],currNode->string[i]);
        }
         
    }
    if (removed == 0) {
        printf("String does not exist in set\n");
    }
    else {
        currNode->amountStrings--;
        for(i = 0; i < currNode->amountStrings; i++) {
        strcpy(currNode->string[i],temp[i]);
        }
    }
}
void clear(node **head, int set_num) {
    node *currNode = *head;
    int i;
    char empty[50] = "";
    for(i = 0; i < set_num; i++) {
        currNode = currNode->next;
    }
    for(i = 0; i < currNode->amountStrings; i++) {
        strcpy(currNode->string[i],empty);
    }
    currNode->amountStrings = 0;
}
void copy(node **head, int copy_from,int copy_to) {
node *currNode = *head;
node *currNode2 = *head;
    int i;
    for(i = 0; i < copy_from; i++) {
        currNode = currNode->next;
    }
    for(i = 0; i < copy_to; i++) {
        currNode2 = currNode2->next;
    }
    for(i = 0; i < currNode->amountStrings; i++) {
    strcpy(currNode2->string[i],currNode->string[i]);
    }
    currNode2->amountStrings = currNode->amountStrings;
}
void unionSets(node **head, int dest_set, int set_1, int set_2) {
node *set1 = *head;
node *set2 = *head;
node *dest = *head;
int set_num = 0;
    int i;
    for(i = 0; i < set_1; i++) {
        set1 = set1->next;
    }
    for(i = 0; i < set_2; i++) {
        set2 = set2->next;
    }
for(i = 0; i < dest_set; i++) {
        dest = dest->next;
        set_num++;
    }
dest->amountStrings = 0;
for(i = 0; i < set1->amountStrings; i++) {
    addNode(head,set1->string[i],set_num,1);
}
for(i = 0; i < set2->amountStrings; i++) {
        addNode(head,set2->string[i],set_num,1);
    }
}
void intersection(node **head, int dest_set, int set_1, int set_2) {
node *set1 = *head;
node *set2 = *head;
node *dest = *head;
int set_num = 0;
    int i;
    int j;
    for(i = 0; i < set_1; i++) {
        set1 = set1->next;
    }
    for(i = 0; i < set_2; i++) {
        set2 = set2->next;
    }
for(i = 0; i < dest_set; i++) {
        dest = dest->next;
        set_num++;
    }
dest->amountStrings = 0;
for(i = 0; i < set1->amountStrings; i++) {
    for(j = 0; j < set2->amountStrings; j++) {
        if (strcmpa(set2->string[j],set1->string[i])==0) {
            addNode(head,set2->string[j],set_num,1);
        }
    }
}
}
void symmetricdifference(node **head, int dest_set, int set_1, int set_2) {
    node *set1 = *head;
node *set2 = *head;
node *dest = *head;
node intersection_temp;
intersection(head,dest_set,set_1,set_2);
int set_num = 0;
    int i;
    int j;
    int invalid = 0;
    for(i = 0; i < set_1; i++) {
        set1 = set1->next;
    }
    for(i = 0; i < set_2; i++) {
        set2 = set2->next;
    }
for(i = 0; i < dest_set; i++) {
        dest = dest->next;
        set_num++;
    }
    intersection_temp.amountStrings = dest->amountStrings;
    for(i = 0; i < dest->amountStrings; i++) {
    strcpy(intersection_temp.string[i],dest->string[i]);
    }
    unionSets(head,dest_set,set_1,set_2);
for(i = 0; i < intersection_temp.amountStrings; i++) {
    removeNode(head,intersection_temp.string[i],dest_set);
}
}