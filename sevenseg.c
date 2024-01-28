#define MAX_LEN 100
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
void main(void) {
    printf("This is a 7-segment display! Press \"Enter\" after providing any number in keyboard.\n");
    fflush(stdout);
    int segment_width;//width of horizontal segments in the 7-segment display
    int segment_height;
    int pos_int;
    int input_error;//flag to show whether some error is detected in user's input
    int input_error_height;
    int input_error_int;
    char string[MAX_LEN + 1];//placeholder to hold user's input from keyboard
    char string_h[MAX_LEN + 1];
    char string_int[MAX_LEN + 1];
    while (1) {
        printf("Please enter the length of horizontal segments (from 3 to 40):\n");
        fflush(stdout);
        input_error = segment_width = 0;
        for (int i = 0; i < MAX_LEN; i++) {
            if (i == 3) {//Given input must be a 1 or 2-digit positive integer.
                input_error = 1;
                break;
            }
            string[i] = getchar();
            if (string[i] == '\n') {//end of user's input
                string[i] = '\0';//string terminator
                break;
            } else if (string[i] < '0' || string[i] > '9') {//not a digit is given by user
                input_error = 1;
                break;
            } else
                segment_width = 10 * segment_width //accounts for previously entered digits...
                                + (string[i] - '0')//converting ASCII code of string[i] to its numerical value...
                        ;//converting the number entered by user to an integer...

        }
        if (input_error)//if an error found in user's input
            while (getchar() != '\n');//gets rid of the remaining of user's input in the same line
        if (segment_width < 3 || segment_width > 40 || input_error) {
            printf("The given value is not acceptable!\n");
            fflush(stdout);
            continue;
        } else
            while (1) {
                printf("Please enter the length of vertical segments (from 3 to 40):\n");
                fflush(stdout);
                input_error_height = segment_height = 0;
                for (int i = 0; i < MAX_LEN; ++i) {
                    if (i == 3) {//Given input must be a 1 or 2-digit positive integer.
                        input_error_height = 1;
                        break;
                    }
                    string_h[i] = getchar();
                    if (string_h[i] == '\n') {//end of user's input
                        string_h[i] = '\0';//string terminator
                        break;
                    } else if (string_h[i] < '0' || string_h[i] > '9') {//not a digit is given by user
                        input_error_height = 1;
                        break;
                    } else
                        segment_height = 10 * segment_height + (string_h[i] - '0');
                    if (segment_height > 2 * segment_width || segment_height < segment_width / 2) {
                        input_error_height = 1;
                        break;

                    }
                }
                if (input_error_height)//if an error found in user's input
                    while (getchar() != '\n');//gets rid of the remaining of user's input in the same line
                if (segment_height < 3 || segment_height > 40 || input_error_height) {
                    printf("The given value is not acceptable!\n");
                    fflush(stdout);
                    continue;
                } else
                    break;
            }

        while (1) {
            printf("Please enter a positive integer\n");
            fflush(stdout);
            input_error_int = pos_int = 0;
            for (int i = 0; i < MAX_LEN; i++) {
                if (i < 0) {
                    input_error_int = 1;
                    break;
                }
                string_int[i] = getchar();

                if (string_int[i] == '\n') {//end of user's input
                    string_int[i] = '\0';//string terminator
                    break;
                } else if (string_int[i] < '0' || string_int[i] > '9') {//not a digit is given by user
                    input_error_int = 1;
                    break;
                } else
                    pos_int = 10 * pos_int + (string_int[i] - '0');

            }
            if (input_error_int)//if an error found in user's input
                while (getchar() != '\n');//gets rid of the remaining of user's input in the same line
            if (pos_int < 0 || input_error_int) {
                printf("The given value is not acceptable!\n");
                fflush(stdout);
                continue;
            } else
                break;

        }

            }

        char c = getchar();
        while (c != EOF)
            c = getchar();
        printf("END");
    }
