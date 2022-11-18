#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int friend_count = 0;
struct BirthNode
{
    char name[50];
    int dob;
    int mob;
    int yob;
    struct BirthNode *next;
};
typedef struct BirthNode node;
int in_list(node **firstData, node new_data) {
    node *currNode2 = *firstData;
    int i;
    for (i = 0; i < friend_count; i++)
    {
        if ((currNode2)->dob == new_data.dob &&
            (currNode2)->mob == new_data.mob &&
            (currNode2)->yob == new_data.yob &&
            strcmpi((currNode2)->name, new_data.name) == 0)
        {
            return 1;
        }
        currNode2 = currNode2->next;
    }
    return 0;
}
        node *getNode(int dob, int mob, int yob, char name[])
        {
            node *newNode = (node *)malloc(sizeof(node));
            newNode->dob = dob;
            newNode->yob = yob;
            newNode->mob = mob;
            strcpy((newNode)->name, name);
            newNode->next = NULL;
            return newNode;
        }
        node *deleteNode(node * *firstData, node data)
        {
            int i;
            node *currNode = (*firstData);
            node *last = *firstData;
            node *retur_n = &data;
            currNode = currNode->next;
            if (friend_count == 0)
            {
                return NULL;
            }
            if ((*firstData)->dob == data.dob &&
                (*firstData)->mob == data.mob &&
                (*firstData)->yob == data.yob &&
                strcmp((*firstData)->name, data.name) == 0)
            {
                (*firstData) = currNode;
                friend_count--;
                return retur_n;
            }
            for (i = 0; i < friend_count; i++)
            {
                if (currNode->dob == data.dob &&
                    currNode->mob == data.mob &&
                    currNode->yob == data.yob &&
                    strcmpi((currNode)->name, data.name) == 0)
                {
                    last->next = currNode->next;
                    free(currNode);
                    free(last);
                    friend_count--;
                    return retur_n;
                }
                last = currNode;
                currNode = currNode->next;
            }
            return NULL;
        }
        int insertNode(node * *firstData, node data)
        {
            node *currNode = *firstData;
            node *temp;
            node *temp2;
            int i;
            if ((*firstData)->dob == 0)
            {
                (*firstData) = getNode(data.dob, data.mob, data.yob, data.name);

                friend_count++;
                return 1;
            }
            else
            {
                for (i = 0; i < friend_count; i++)
                {

                    {
                        if ((currNode)->mob == data.mob)
                        {
                            if ((currNode)->dob == data.dob)
                            {
                                if ((currNode)->yob == data.yob)
                                {
                                    if (strcmpi((currNode)->name, data.name) == 0)
                                    {
                                        return 0;
                                    }
                                }
                                else if ((currNode)->yob < data.yob)
                                {
                                    if (((currNode)->next) == NULL) /*make a new node*/
                                    {
                                        currNode->next = getNode(data.dob, data.mob, data.yob, data.name);
                                    }
                                    else if ((((currNode)->next) != NULL) && ((((currNode))->next)->yob > data.yob))
                                    {
                                        temp2 = (currNode)->next;
                                        temp = getNode(data.dob, data.mob, data.yob, data.name);
                                        temp->next = temp2;
                                        (currNode)->next = temp;
                                        friend_count++;
                                        return 1;
                                    }
                                }
                                else if ((currNode)->yob > data.yob)
                                {
                                    temp2 = getNode(data.dob, data.mob, data.yob, data.name);

                                    temp2->next = (*firstData);
                                    (*firstData) = (temp2);
                                    friend_count++;
                                    return 1;
                                }
                            }

                            else if ((currNode)->dob < data.dob)
                            {
                                if (((currNode)->next) == NULL) /*make a new node*/
                                {
                                    currNode->next = getNode(data.dob, data.mob, data.yob, data.name);
                                }
                                else if ((((currNode)->next) != NULL) && ((((currNode))->next)->dob > data.dob))
                                {
                                    temp2 = (currNode)->next;
                                    temp = getNode(data.dob, data.mob, data.yob, data.name);
                                    temp->next = temp2;
                                    (currNode)->next = temp;
                                    friend_count++;
                                    return 1;
                                }
                            }
                            else if ((currNode)->dob > data.dob)
                            {
                                temp2 = getNode(data.dob, data.mob, data.yob, data.name);

                                temp2->next = (*firstData);
                                (*firstData) = (temp2);
                                friend_count++;
                                return 1;
                            }
                        }
                        else if ((currNode)->mob < data.mob)
                        {
                            if (((currNode)->next) == NULL) /*make a new node*/
                            {
                                currNode->next = getNode(data.dob, data.mob, data.yob, data.name);
                            }
                            else if ((((currNode)->next) != NULL) && ((((currNode))->next)->mob > data.mob))
                            {
                                temp2 = (currNode)->next;
                                temp = getNode(data.dob, data.mob, data.yob, data.name);
                                temp->next = temp2;
                                (currNode)->next = temp;
                                friend_count++;
                                return 1;
                            }
                        }
                        else if ((currNode)->mob > data.mob)
                        {
                            temp2 = getNode(data.dob, data.mob, data.yob, data.name);

                            temp2->next = (*firstData);
                            (*firstData) = (temp2);
                            friend_count++;
                            return 1;
                        }
                    }
                    (currNode) = (currNode)->next;
                }
                friend_count++;
            }
            return 1;
        }
        void printList(node * head)
        {
            int i;
            node *currNode = head;
            printf("************ List content ************\n");
            for (i = 0; i < friend_count; i++)
            {

                printf("%i/%i/%i %s\n", currNode->mob, currNode->dob, currNode->yob, currNode->name);
                currNode = currNode->next;
            }
        }
        int main()
        {
            int quit = 0;
            int user_input;
            int dob, mob, yob, i, valid_data = 0;
            char name[50];
            char inBuf[50];
            int insert_worked;
            node *head = NULL;
            node new_data;
            node *currNode = head;
            node *delete = NULL;
            do
            {
                printf("************ Friends birthday list ************\n");
                printf("Friends in the list: %i\n", friend_count);
                printf("(1) Insert data\n");
                printf("(2) Delete data\n");
                printf("(3) Print List\n");
                printf("(4) Quit\n");
                printf("*****************************************\n");
                fgets(inBuf, 50, stdin);
                sscanf(inBuf, "%i", &user_input);
                if (user_input > 4 || user_input < 1)
                {
                    printf("Invalid input, reenter your input\n");
                    continue;
                }
                else
                {
                    switch (user_input)
                    {
                    case 1:
                        if (head == NULL)
                        {
                            head = (node *)malloc(sizeof(node));
                            head->dob = 0;
                        }
                        while (valid_data == 0)
                        {
                            printf("Enter dob\n");
                            fgets(inBuf, 50, stdin);
                            sscanf(inBuf, "%i", &dob);
                            printf("Enter mob\n");
                            fgets(inBuf, 50, stdin);
                            sscanf(inBuf, "%i", &mob);
                            printf("Enter yob\n");
                            fgets(inBuf, 50, stdin);
                            sscanf(inBuf, "%i", &yob);
                            printf("Enter the Name\n");
                            fgets(inBuf, 50, stdin);
                            sscanf(inBuf, "%[^\n]", name);
                            if ((dob < 1 || dob > 31) || (mob < 1 || mob > 12) || (yob < 1930 || yob > 2022))
                            {
                                printf("One of the data values entered was INVALID OR OUT OF RANGE, please reenter all values\n");
                            }
                            else
                            {
                                new_data.dob = dob;
                                new_data.mob = mob;
                                new_data.yob = yob;
                                strcpy(new_data.name, name);
                                insert_worked = insertNode(&head, new_data);
                                if (insert_worked == 0)
                                {
                                    printf("Data already exists, please reenter.\n");
                                }
                                valid_data = 1;
                            }
                        }
                        break;
                    case 2:
                        if (head == NULL)
                        {
                            head = (node *)malloc(sizeof(node));
                            head->dob = 0;
                        }
                        while (valid_data == 0)
                        {
                            printf("Enter dob\n");
                            fgets(inBuf, 50, stdin);
                            sscanf(inBuf, "%i", &dob);
                            printf("Enter mob\n");
                            fgets(inBuf, 50, stdin);
                            sscanf(inBuf, "%i", &mob);
                            printf("Enter yob\n");
                            fgets(inBuf, 50, stdin);
                            sscanf(inBuf, "%i", &yob);
                            printf("Enter the Name\n");
                            fgets(inBuf, 50, stdin);
                            sscanf(inBuf, "%[^\n]", name);
                            if ((dob < 1 || dob > 31) || (mob < 1 || mob > 12) || (yob < 1930 || yob > 2022))
                            {
                                printf("One of the data values entered was INVALID OR OUT OF RANGE, please reenter all values\n");
                            }
                            else
                            {
                                new_data.dob = dob;
                                new_data.mob = mob;
                                new_data.yob = yob;
                                strcpy(new_data.name, name);
                                }
                                if (in_list(&head,new_data) == 0)
                                {
                                    printf("*** Delete data ***\n");
                                    printf("Name: %s\n", new_data.name);
                                    printf("Month of birth: %i\n", new_data.mob);
                                    printf("Day of birth: %i\n", new_data.dob);
                                    printf("Year of birth: %i\n", new_data.yob);
                                    printf("################ Data Does not exist ###############\n");
                                }
                                else
                                {
                                    delete = deleteNode(&head, new_data);
                                    printf("*** Delete data ***\n");
                                    printf("Name: %s\n", new_data.name);
                                    printf("Month of birth: %i\n", new_data.mob);
                                    printf("Day of birth: %i\n", new_data.dob);
                                    printf("Year of birth: %i\n", new_data.yob);
                                }
                                valid_data = 1;
                            }
                        break;
                    case 3:
                        printList(head);
                        break;
                    case 4:
                        for (i = 0; i < friend_count-1; i++)
                        {
                            currNode = currNode->next;
                            free(currNode);
                        }
                        free(head);
                        quit = 1;
                        printf("Memory successfully freed");
                        break;
                    }
                }
                valid_data = 0;
            } while (quit == 0);
            return 0;
        }