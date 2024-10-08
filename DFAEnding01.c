//  Implement a DFA for L = { set of all strings over {0,1} such that  string end with 01
#include<stdio.h>
#include <string.h>
#define MAX_INPUT_LENGTH 20

// State Definitions
enum states { q0, q1, qf };
enum states delta(enum states, char);

int main() {
	char input[MAX_INPUT_LENGTH];
	enum states curr_state = q0;
	int i = 0;
	
	printf("Enter a binary string: ");
	fgets(input, MAX_INPUT_LENGTH, stdin);
	input[strcspn(input, "\n")] = 0;

	char ch = input[i];
	while( ch !='\0') {
	    curr_state = delta(curr_state,ch);
		ch = input[++i];
  	}
  	
	if (curr_state == qf)
	   printf("\n The string %s is accepted.\n",input);
	else 
	    printf("\n The string %s is not accepted.\n",input);	   	
   return 0;			
}


enum states delta(enum states s, char ch) {
	enum states curr_state;
	switch(s) {
		case q0:
			if (ch=='0')
				curr_state = q1;
			else
				curr_state = q0;
			break;
		case q1:
			if (ch=='1')
				curr_state = qf;
			else
				curr_state = q1;
			break;
		case qf:
			if (ch=='0')
				curr_state = q1;
			else
				curr_state = q0;
			break;
	}	
	return curr_state;
}

