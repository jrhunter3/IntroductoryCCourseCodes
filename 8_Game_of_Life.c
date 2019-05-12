/*******************************************
* Joseph R. Hunter - CS 239 - Assignment 8 *
*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE_LIM 180 
#define GENS_LIM 50

void print_header(void);
void set_array(void);
void enter_array(void);
char get_menu(void);
int get_size(void);
int get_gens(void);
void print_array(void);
void copy_array(void);
void evolve_array(void);

int current[SIZE_LIM];
int next[SIZE_LIM];
int quit = 0, gens = 10, size = 25;

main(void){

	int i;
	char menu;
	print_header();
	printf("Default settings:\t%i generations with a %i population size\n\n", gens, size);
	set_array();

	while ( quit == 0 ){
		menu = get_menu();
		switch (menu ){
			case 'a':
			case 'A':
				printf("Game of Life is the first in a line of products from LifeSim Inc.\n"
				"The game was created 2 November 2014.  Game of Life gives you the option to\n"
				"enter a population size, which adjusts the size of an array from left to\n"
				"right. You also have the option to select the number of generations, which\n"
				"adjusts how long the program runs down the screen. You can have the program\n"
				"randomize an initial population, or you can input an exact population of\n"
				"your own to begin the game with. Finally, there is an option to display a\n"
				"continual loop of the game, but beware that the game may never end.  If you\n"
				"wish to escape an infinite loop, press CTRL+C on your keyboard.  Enjoy the\n"
				"game of life!\n");
				print_header();
				break;
			case 'c':
			case 'C':
				gens = get_gens();
				if (gens > GENS_LIM){
					printf("Input exceeds limit.  Number of generations set to %i\n", GENS_LIM);
					gens = GENS_LIM;
				}	//End of If Statement
				break;
			case 's':
			case 'S':
				size = get_size();
				if (size > SIZE_LIM){
					printf("Input exceeds limit.  Population size set to %i\n", SIZE_LIM);
					size = SIZE_LIM;
				}	//End of If Statement
				break;
			case 'r':
			case 'R':
				puts("Creating population now....");
				set_array();
				usleep(1000000);
				break;
			case 'e':
			case 'E':
				enter_array();
				break;
			case 'i':
			case 'I':
				for ( ; ; ){
					evolve_array();
					usleep(100000);
				}	//End of For Statement
				break;
			case 'b':
			case 'B':
				for ( i = 0; i < gens; i++ ){
					evolve_array();
					usleep(100000);
				}	//End of For Statement
				break;
			case 'q':
			case 'Q':
				quit = 1;
				puts("Quitting...");
				usleep(1000000);
				puts("Thank you for playing the Game of Life, by LifeSim Inc.");
		}	//End of Switch Function
	}	//End of While Function
}	//End of Main Function

void print_header(void){

	puts("/*******************************************");
	puts("* Joseph R. Hunter - CS 239 - Assignment 8 *");
	puts("*******************************************/");

	puts("|-----------------------------------------|");
	puts("|------ Welcome to the Game of Life ------|");
	puts("|-----------------------------------------|");
	puts(" [A]bout\t\t[I]nfinite Loop");
	puts(" [S]et Size\t\t[C]hoose Generations");
	puts(" [R]andomize Population\t[E]nter Population");
	puts(" [B]egin Game\t\t[Q]uit\t");
	puts("|-----------------------------------------|");
	puts("|Game of Life is a product of LifeSim Inc.|");
	puts("|  At LifeSim, we put life in your hands! |");
	puts("|-----------------------------------------|");
}	//End of Function

char get_menu(void){

	char choice, line[10];

	puts("Enter your choice: ");
	fgets(line, sizeof(line), stdin);

	return line[0];
}	//End of Function

void set_array(void){

	int i, n;

	for (i = 0; i < size; i++){
		n = random()%2;
		current[i] = n;
	}	//End of For Statement
}	//End of Function

void enter_array(void){

	char line[size];
	int i;

	puts("Enter desired number of elements into array (0 = Dead, 1 = Alive): ");
	for (i = 0; i < size; i++){
		fgets(line, sizeof(line), stdin);
		current[i] = atoi(line);
	}	//End of For Statement
}	//End of Function

int get_size(void){

	char line[10];
	int s;

	puts("Enter size of population: ");
	fgets(line, sizeof(line), stdin);
	s = atoi(line);

	return s;
}	//End of Function

int get_gens(void){

	char line[10];
	int g;

	puts("Enter number of generations: ");
	fgets(line, sizeof(line), stdin);
	g = atoi(line);

	return g;
}	//End of Function

void print_array(void){

	int i;

	for ( i = 1; i < size; i++ ){
		if (current[i] == 0){
			putchar(' ');
		}	//End of If Statement
		if (current[i] == 1){
			putchar('X');
		}	//End of If Statement
	}	//End of For Statement
	putchar('\n');
}	//End of Function

void copy_array(void){

	int i;
	
	for (i = 0; i < size; i++){
		current[i] = next[i];
	}	//End of For Statement
}	//End of Function

void evolve_array(void){

	int i;
	/* Rules of the Game of Life */
	for ( i = 0; i < size; i++ ){
		if ((current[i] < current[i-1]) && (current[i] < current[i+1])){
			next[i] = 1;	//101
		}	//End of If Statement
		else if ((current[i] < current[i-1]) && (current[i] == current[i+1])){
			next[i] = 1;	//100
		}	//End of If Statement
		else if ((current[i] == current[i-1]) && (current[i] < current[i+1])){
			next[i] = 1;	//001
		}	//End of If Statement
		else if ((current[i] == current[i-1]) && (current[i] == current[i+1])){
			next[i] = 0;	//111 or 000
		}	//End of If Statement
		else if ((current[i] > current[i-1]) && (current[i] > current[i+1])){
			next[i] = 1;	//010
		}	//End of If Statement
		else if ((current[i] > current[i-1]) && (current[i] == current[i+1])){
			next[i] = 1;	//011
		}	//End of If Statement
		else if ((current[i] == current [i-1]) && (current[i] > current[i+1])){
			next[i] = 1;	//110
		}	//End of If Statement
	}	//End of For Statement
		copy_array();
		print_array();
}	//End of Function
