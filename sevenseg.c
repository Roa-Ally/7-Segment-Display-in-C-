#define MAX_LEN 100
#include<stdio.h>
void main(void){
	printf("This is a 7-segment display! Press \"Enter\" after providing any number in keyboard.\n");
	int segment_width;//width of horizontal segments in the 7-segment display
	int input_error;//flag to show whether some error is detected in user's input
	char string[MAX_LEN + 1];//placeholder to hold user's input from keyboard
	while(1){
		printf("Please enter the length of horizontal segments (from 3 to 40):\n");
		input_error = segment_width = 0;
		for(int i = 0; i < MAX_LEN;i++){
			if(i == 3){//Given input must be a 1 or 2-digit positive integer.
				input_error = 1;
				break;
			}
			string[i] = getchar();
			if(string[i] == '\n'){//end of user's input
				string[i] = '\0';
				break;
			}else if(string[i] < '0' || string[i] > '9'){//not a digit is given by user
				input_error = 1;
				break;
			}else
				segment_width = 10 * segment_width //accounts for previously entered digits...
					+ (string[i] - '0')//converting ASCII code of string[i] to its numerical value...
					;//converting the number entered by user to an integer...
		}
		if(input_error)//if an error found in user's input
			while(getchar()!= '\n');//gets rid of the remaining of user's input in the same line
		if(segment_width < 3 || segment_width > 40 || input_error)
			printf("The given value is not acceptable!\n");
		else
			break;
			
	}
	char c = getchar();
	while(c != EOF)
		c = getchar();
	printf("END");
 
}