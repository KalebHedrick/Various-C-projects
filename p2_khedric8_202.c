/* Kaleb Hedrick G01311347
 * CS 262 Lab Section 202
 * Project 2
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *ptInput;
    FILE *ptOutput;
    int dx, dy, n, r, i, j, k;
    int dotspot = 0;  /* used for getting output file name*/
    char inBuf[50];
    char input_name[50];
    char *input_string;
    int locations_x[50]; /*array of coords for the locations*/
    int locations_y[50];
    int survey_responses[50];  
    int next_test_case = 0;
    int x_axis, y_axis;   /*used to iterate through grid*/
    int optimal_x, optimal_y; /*stores optimal coords*/ 
    char grid[1000][1000]; /*allocates data for grid*/
    int temp_optimal_location = 0; /*optimal location data and temp variables*/
    int curr_best_location = 0;
    int instance_num; /*counter for instances*/
    /* statements to make sure proper filenames and files are used*/
    if (argc < 2)
    {
        printf("Error! You	must specify	input filename: ./p2 <input_filename>");
        exit(0);
    }
    input_string = argv[1];
    ptInput = fopen(argv[1], "r");
    if (ptInput == NULL)
    {
        printf("Error! The %s file can\'t be opened", input_string);
        exit(0);
    }

    /* OUTPUT FILE NAME CODE UNDER THIS COMMENT*/
    for (i = 0; i < strlen(input_string); i++)
    {
        if (input_string[i] == '.')
        {
            dotspot = i;                         /*MARKS LOCATION OF DOT IN INPUT STRING*/
            break;
        }
    }
    strncpy(input_name, input_string, dotspot); /*sets the name of the output file + opens it*/
    input_name[dotspot] = '\0';
    strcat(input_name, ".out");
    ptOutput = fopen(input_name, "w");
    /* OUTPUT FILE NAME CODE ABOVE THIS COMMENT*/

    while (next_test_case != 1)
    { /* LOOP TO GET DATA AND PROCESS CALCULATIONS*/
        fgets(inBuf, 50, ptInput);
        sscanf(inBuf, "%i%i%i%i", &dx, &dy, &n, &r);   /* gets data for calculations*/
        if (dx == 0 && dy == 0 && n == 0 && r == 0)   
        {
            next_test_case = 1;   /*checks if last test case, if so breaks statement*/
            break;
        }
        else
        {
            instance_num++;
            fprintf(ptOutput, "Instance %i:\n", instance_num); /*prints the instance*/

            for (i = 0; i < n; i++)
            {
                fgets(inBuf, 50, ptInput);
                sscanf(inBuf, "%i%i", &locations_x[i], &locations_y[i]);
            }
            for (i = 0; i < r; i++)
            {
                fgets(inBuf, 50, ptInput);  /*initilizes survey response array*/
                sscanf(inBuf, "%i", &survey_responses[i]);
            }
            for (i = 0; i < 1000; i++)
            {                                /*INITIALIZES A BLANK GRID*/
                for (j = 0; j < 1000; j++)
                {
                    grid[i][j] = '-';
                }
            }
            for (i = 0; i < n; i++)
            {
                grid[locations_x[i]][locations_y[i]] = '*'; /*SETS ALL CAFE LOCATIONS IN GRID*/
            }
            for (k = 0; k < r; k++)
            {
                curr_best_location = 0;
                for (y_axis = dy; y_axis >= 1; y_axis--)
                {                                      /*FIND AND SET ALL OPTIMAL COORDINATES*/
                    for (x_axis = 1; x_axis <= dx; x_axis++)
                    {
                        for (i = 0; i < n; i++)
                        {
                            if (abs(locations_x[i] - x_axis) + abs(locations_y[i] - y_axis) <= survey_responses[k])
                            {
                                temp_optimal_location++;
                            }
                        }
                            if (temp_optimal_location > curr_best_location) /*checks if current coord iteration is more optimal than last optimal coord*/
                            {
                                curr_best_location = temp_optimal_location;
                                optimal_x = x_axis;
                                optimal_y = y_axis;
                            }
                            if (temp_optimal_location == curr_best_location)
                            {
                                if (y_axis < optimal_y)
                                {
                                    curr_best_location = temp_optimal_location;
                                    optimal_x = x_axis;
                                    optimal_y = y_axis;
                                }
                                else if (optimal_y > y_axis)
                                {
                                    /*KEEPS SAME OPTIMAL COORDINATE*/
                                }
                                else /*Y COORDS ARE EQUAL*/
                                {
                                    if (x_axis < optimal_x)
                                    {
                                        curr_best_location = temp_optimal_location;
                                        optimal_x = x_axis;
                                        optimal_y = y_axis;
                                    }
                                    else
                                    {
                                        /*KEEPS SAME OPTIMAL COORDINATE*/
                                    }
                                }
                            }
                            temp_optimal_location = 0; 
                }
                }
                grid[optimal_x][optimal_y] = '$'; /*draws optimal coord*/
                for (i = 0; i < n; i++) /*draws coord as @ if it is optimal and on a cafe location*/
                {
                    if (optimal_x == locations_x[i] && optimal_y == locations_y[i])
                    {
                        grid[locations_x[i]][locations_y[i]] = '@';
                    }
                }
                if (curr_best_location == 0) { /*prints -1 if there is no solution*/
                    fprintf(ptOutput, "-1(-1,-1)\n");
                }
                else {  /*prints optimal coord and all locations in range*/
                fprintf(ptOutput, "%i(%i,%i)\n",curr_best_location,optimal_x,optimal_y);
                }
            }
                for (y_axis = dy; y_axis >= 1; y_axis--) /*prints full grid map*/
                {
                    for (x_axis = 1; x_axis <= dx; x_axis++)
                    {
                        fprintf(ptOutput, "%c", grid[x_axis][y_axis]);
                    }
                    fprintf(ptOutput, "\n");
                }

    }
    }
    fclose(ptInput);
    fclose(ptOutput);
        return 0;
    }