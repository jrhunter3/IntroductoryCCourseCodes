/********************************************
 * Joseph R. Hunter - CS 239 - Assignment 7 *
 *******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define t_lim 2000	//Max Number of Trials
#define s_lim 20	//Max number of Sides

void print_header(void);
void print_about(void);
char get_menu(void);
int get_sides(void);
int get_trials(void);
void run_trials(void);
void print_histogram(void);

int quit = 0, t = 100, s = 6, trials_ran = 0;
int roll_sum = 11;		//number of possible results
int results[t_lim];
int i = 1;

main(void){

	char menu;

	print_header();
	printf("Default settings:\t%i Trials with a %i Sided Dice\n\n", t, s);
	
	while( quit == 0 ){
    		menu = get_menu();
		switch ( menu ){
			case 's':
			case 'S':
            			s = get_sides();
            			if (s > s_lim){
                			printf("Input exceeds limit. Number of sides set to %i\n", s_lim);
  	             		 	s = s_lim;
				}	//End If Statement
        		break;
			case 'e':
			case 'E':
				t = get_trials();
				if ( t > t_lim ){
	                		printf("Input exceeds limit. Number of trials set to %i\n", t_lim);
	                		t = t_lim;
				}	//End If Statement
        		break;
        		case 'p':
			case 'P':
				print_histogram();
            		break;
			case 'r':
			case 'R':
				trials_ran++;
				run_trials();
			break;
        		case 'a':
			case 'A':
	        		print_about();
			break;
		        case 'q':
			case 'Q':
	        		printf("Quitting... Thank you for using DieSim 2.0.  With DieSim, you're on a roll!\n");
	       			quit = 1;
			break;
			case 'b':
			case 'B':
				puts("Building additional pylons...");
			break;
		}	//End Switch
	}	//End of While Statement
}	//End of Main

void print_header(void){

	puts("/*******************************************");
	puts("* Joseph R. Hunter - CS 239 - Assignment 7 *");
	puts("*******************************************/\n");

	puts("+++++++++++++++++ Die Roll Simulator +++++++++++++++++++");
	puts("[E]nter number of trials		[P]rint Histogram");
	puts("[S]elect number of sides		[A]bout");
	puts("[R]un Trials				[Q]uit");
	puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}	//End Function

void print_about(void){

	puts("+++++++++++++++++ Die Roll Simulator +++++++++++++++++++");
	puts("[E]nter number of trials		[P]rint Histogram");
	puts("[S]elect number of sides		[A]bout");
	puts("[R]un Trials				[Q]uit");
	puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}	//End Function

char get_menu(void){

	char choice, line[10];

	puts("Enter your choice: ");
	fgets(line, sizeof(line), stdin);

	return line[0];
}	//End Function

int get_sides(void){

	char line[10];
	int sides;

	puts("Enter number of sides: ");
	fgets(line, sizeof(line), stdin);
	sides = atoi(line);

	return sides;
}	//End Function

int get_trials(void){

	char line[10];
	int trials;

	puts("Enter number of trials: ");
	fgets(line, sizeof(line), stdin);
	trials = atoi(line);

	return trials;
}	//End Function

void run_trials(void){

	int n;
	printf("running %i trials...\n", t);

	roll_sum = 2 * s - 1;
	for ( i = 1; i<= t; i++ ){
		n = random()%roll_sum;
		results[i] = n;
	}	//End For Statement
}	//End of Function

void print_histogram(void){

	int frequency;

	if ( trials_ran != 0 ){
		printf("Displaying results of %i trials\n\nResult          Frequency\n", t);
	       			
		for ( i = 1; i <= roll_sum; i++ ){
			frequency = results[i];
			printf("%5i)  %10i  ", i + 1, frequency);
			while ( frequency > 0 ){
	       			if ( frequency >= 100 ){
	               			printf("X");
	               			frequency = frequency - 100;
				}	//End of If Statement
	       			else if ( frequency >= 10){
	               			printf("x");
		      			frequency = frequency - 10;
				}	//End of Else If Statement
				else{
	              			printf("o");
		      			frequency = frequency - 1;
				}	//End of Else Statement
			}	//End of While Statement
			printf("\n");
		}	//End of For Statement

		printf("Legend:\tX = 100,  x = 10,  o = 1\n");
	}	//End of If Statement
	else {
		puts("No results to display. Please run trials first\n");
	}	//End of Else Statement 
}	//End of Function
