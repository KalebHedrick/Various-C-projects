#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 25
int my_isDigit(char);
int game_logic(int net_height, char name[]);
int throw_ball(int net_height);

int game_logic(int net_height, char name[]) {
    int user_points = 75;
    int AI_points = 75;
    int user_bet = 0;
    int throwball = 0;
    char inBuf[50];
    char user_answer;
    printf("Each player is starting off with 75 points\n");
    while (user_points> 0 && AI_points> 0) {
        printf("%s's turn. How much would you like to bet towards your throw?\n",name);
        fgets(inBuf, SIZE, stdin);
        sscanf(inBuf, "%i", &user_bet);
        if (user_bet >11 || user_bet < 1) {
            printf("Invalid bet\n");
             continue;
        }
        if (user_bet > user_points) {
            printf("Invalid bet, not enough points\n");
             continue;
        }
        throwball = throw_ball(net_height);
        if (throwball > net_height) {
        printf("Ball Height: %i inche(s), the ball is over the net\n", throwball);
        user_points-=user_bet;
        printf("Deducting %i points\n",user_bet);
        printf("%s now has %i points\n",name,user_points);
        }
        else if(throwball <= net_height) {
            if (throwball <=  net_height/2) {
                printf("Ball Height: %i inche(s) Would you like to throw the ball again? Y | N",throwball);
                fgets(inBuf, SIZE, stdin);
                sscanf(inBuf, "%c",&user_answer);
                if (user_answer == 'Y' || user_answer=='y') {
                    throwball = throw_ball(net_height);
                     if (throwball > net_height) {
        printf("Ball Height: %i inche(s), the ball is over the net\n", throwball);
        user_points-=user_bet;
        printf("Deducting %i points\n",user_bet);
        printf("%s now has %i points\n",name,user_points);
        }
        else {
            printf("Adding 4 points to %s\n",name);
            user_points += 4;
                    printf("%s now has %i points\n",name, user_points);
                    
        }
                }
                else {
                    printf("Adding 2 points to %s\n",name);
		    user_points+=2;
                    printf("%s now has %i points\n",name, user_points);
                }
            }
            else {
                printf("Ball Height: %i inche(s), the ball is below the net\n", throwball);
                printf("Adding 2 points to %s\n",name);
                user_points+=2;
                printf("%s now has %i points\n",name, user_points);
            }
        }
        /*COMPUTERS TURN*/
        printf("Computers turn\n");
        throwball = throw_ball(net_height);
        if (throwball > net_height) {
            printf("Ball Height: %i inches, the ball is over the bet\n",throwball);
            printf("Deducting 9 points\n");
            AI_points -=9;
            printf("Computer now has %i points\n",AI_points);
        }
        else if (throwball < net_height/2) {
             printf("Ball Height: %i inche(s), the ball is below the net\n", throwball);
            throwball = throw_ball(net_height);
            if (throwball > net_height) {
            printf("Ball Height: %i inches, the ball is over the net\n",throwball);
            printf("Deducting 7 points\n");
            AI_points -=7;
            printf("Computer now has %i points\n",AI_points);
        }
        if (throwball < net_height) {
                printf("Ball Height: %i inche(s), the ball is below the net\n", throwball);
                printf("Adding 6 points\n");
                AI_points+=6;
                printf("Computer now has %i points\n",AI_points);
        }
            }
            else {
                printf("Ball Height: %i inche(s), the ball is below the net\n", throwball);
                printf("Adding 4 points\n");
                AI_points+=4;
                printf("Computer now has %i points\n",AI_points);
            }
        
    }
    if (user_points ==0 ) {
        printf("Congrats to %s for winning the game\n",name);
        return 1;
    }
    else {
	    return 0;
    }
}
int throw_ball(int net_height) {
    int ball_height;
    ball_height = rand()%(net_height+17);
    return ball_height;
}
int calculate_net_height(char height[]) {
    int i = 0;
    int inch;
    int inch2;
    int feet;
    int feet2;
    int lastInt;
    int net_inch;
    int Letters_valid = 0;
    int i_val=0;
    int t_val=0;
    int f_val=0; /*if equal to 4, in and ft exist in the string */
    for (i = 0; i < strlen(height);i++) {
        if (height[i] == 'i' || height[i] == 'I') {
            if(f_val == 0 || t_val == 0) { return 0;}
            height[i] = 'I'; 
            Letters_valid++;
            i_val = 1;
            }
        if (height[i] == 'n' || height[i] == 'N') {
            if(f_val == 0 || t_val == 0 || i_val ==0) { return 0;}
            height[i] = 'N';
             Letters_valid++;
            }
        if (height[i] == 'f' || height[i] == 'F') 
        {height[i] = 'F';
        f_val = 1;
        Letters_valid++;
         }
        if (height[i] == 't' || height[i] == 'T') {
            if (f_val == 0) {return 0;}
            height[i] = 'T'; 
            t_val = 1;
            Letters_valid++;
            }
    }
    for (i = 0; i < strlen(height);i++) {
        if (my_isDigit(height[i])==1) {
            feet = (int)height[i]-48;
            lastInt = i;
            if (my_isDigit(height[i+2])==1 || ((height[i+1]=='0') && height[i]=='0')) {
                return 0;
            }
            if (my_isDigit(height[i+1])==1) {
            feet = (int)height[i]-48;
            feet2 = (int)height[i+1]-48;
            if (feet == 0) {return 0;}
            feet = feet*10 + feet2;
            lastInt=i+2;
        }
        break;
        }
    }
    for (i = lastInt; i < strlen(height);i++) {
        if (my_isDigit(height[i])==1) {
            inch = (int)height[i]-48;
            if (my_isDigit(height[i+1])==1) {
            inch = (int)height[i]-48;
            inch2 = (int)height[i+1]-48;
            inch = inch*10 + inch2;
        }
        break;
        }
    }
    net_inch = feet*12 + inch;
    if (Letters_valid !=4) {return 0;}
    return net_inch;
}
int my_isDigit(char seed) {
    char *p = &seed;
    if (*p >= 48 && *p <=57) {
        return 1;
    }
    else {
        return 0;
    }
    return 1;
}
int is_valid_seed(char seed[]) {
    int i = 0;
    if (strlen(seed) > 5)
    {
        return 0;
    }
    for (i = 0; i < strlen(seed); i++)
    {
        if (my_isDigit(seed[i]) == 1)
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int my_isalpha(char name) {
    char *p = &name;
    if ((*p >= 65 && *p <=90) || (*p >= 97 && *p <= 122)) {
        return 1;
    }
    else {
        return 0;
    }
}
int is_valid_name(char name[])
{ 
    int i=0;
    if (strlen(name) > 7)
    {
        return 0;
    }
    for (i = 0; i < strlen(name); i++)
    {
        if (my_isalpha(name[i]) == 1|| name[i] == ' ')
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char name[SIZE], inBuf[SIZE], seed[SIZE], height[SIZE];
    int nameValid = 0;
    int seedValid = 0;
    int heightValid = 0;
    int seedd;
    int test;
    int playagain = 0;
    char restart;
    int wins = 0;
    int result = ' ';
    int AIwins = 0;
    do
    {
        printf("WELCOME TO GEHNTOO!!!\nPlease enter your Name\n");
        fgets(inBuf, SIZE, stdin);
        sscanf(inBuf, "%[^\n]", name);
        if (is_valid_name(name) == 1)
        {
            nameValid = 1;
        }
        else
        {
            printf("Invalid name\n");
        }
    } while (nameValid == 0);
    do
    {
        printf("Enter a seed value\n");
        fgets(inBuf, SIZE, stdin);
        sscanf(inBuf, "%s", seed);
        if (is_valid_seed(seed) == 1)
        {
            seedValid = 1;
        }
        else
        {
            printf("Invalid seed\n");
        }
    } while (seedValid == 0);
    seedd = atoi(seed);
    srand(seedd);
    printf("Seed to use is %i\n",seedd);
    do {
    printf("Enter feet and inches of game net (\"xxft xxin\")\n");
     fgets(inBuf, SIZE, stdin);
        sscanf(inBuf, "%[^\n]", height);
        test = calculate_net_height(height);
        if (test != 0)
        {
            heightValid = 1;
        }
        else
        {
            printf("Invalid height\n");
        }
    } while (heightValid == 0);
    while(playagain != 3) {
    printf("Height of the net: %i inches\n",test);
    result = game_logic(test,name);
    if (result == 1) {
        wins++;
    }
    else {AIwins++;}
    printf("Would you like to play again? Type Y or N\n");
    fgets(inBuf, SIZE, stdin);
    sscanf(inBuf, "%c",&restart);
        if (restart == 'Y' || restart == 'y') {
            playagain++;
        }
        else {
            playagain= 3;
}
    }
    printf("%s has won the game a total of %i time(s)\n",name,wins);
    printf("The computer has won the game a total of %i time(s)",AIwins);
    return 0;
}
