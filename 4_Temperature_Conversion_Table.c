/***********************************
 * Joseph R. Hunter - Assignment 4 *
 **********************************/
#include <stdio.h>

void printHeader(void);
int get_menu_choice(void);
int get_min_value(void);
int get_max_value(void);
int get_step_value(void);
void create_celsius(int a, int b, int c);
void create_fahrenheit(int a, int b, int c);

main(void){

	int choice, skip = 0, min, max, interval;

	printHeader();

	choice = get_menu_choice();

	do
	{
		printf("Would you like to set the limits and interval for your table\n");
		printf("1 - Yes\n");
		printf("2 - No\n");
		printf("Please enter your selection: ");
		scanf("%d", &skip);
	}
	while (skip < 1 || skip > 2);
	
	if (choice == 1){
		if (skip == 1){
	
			min = get_min_value();
			max = get_max_value();
			interval = get_step_value();
			create_celsius(min, max, interval);
		}
		else{
		
			min = 32;
			max = 100;
			interval = 4;
			create_celsius(min, max, interval);
		}
	}
	else{
		if (skip == 1){
	
			min = get_min_value();
			max = get_max_value();
			interval = get_step_value();
			create_fahrenheit(min, max, interval);
		}
		else{
		
			min = 0;
			max = 100;
			interval = 5;
			create_fahrenheit(min, max, interval);
		}
	}
/* Use line below to check variable values */	
//printf("menu choice = %d\nskip value = %d\nminimum value = %d\nmaximum value = %d\nstep value = %d\n", choice, skip, min, max, interval);

	return 0;
}

void printHeader(void){

	printf("/**********************************\n");
	printf("* Joseph R. Hunter - Assignment 4 *\n");
	printf("**********************************/\n");

	printf("\n-----------------------------------------\n");
	printf("|Celsius and Fahrenheit Conversion Table|\n");
	printf("-----------------------------------------\n");
}

int get_menu_choice(void){

	int selection = 0;

	do
	{
	printf("\n1 - Convert Fahrenheit to Celsius\n");
	printf("2 - Convert Celsius to Fahrenheit\n");
	printf("\nEnter a selection: ");
	scanf("%d", &selection);
	}
	while (selection < 1 || selection > 2);

	return selection;
}

int get_min_value(void){

	int initial;

	printf("\nPlease enter an integer for your minimum intitial value: ");
	scanf("%d", &initial);

	return initial;
}

int get_max_value(void){

	int limit;

	printf("\nPlease enter an integer for your maximum value: ");
	scanf("%d", &limit);

	return limit;
}

int get_step_value(void){

	int step;

	printf("\nPlease enter an integer for your step value: ");
	scanf("%d", &step);

	return step;
}

void create_celsius(int a, int b, int c){

	int i = a, f;

	printf("Fahrenheit	Celsius\n");

/* Use line below to check variable values */
//	printf(" i = %d, a = %d, b = %d, c = %d\n");
	
	do
	{
	printf("%d		%d\n", i, f = (i - 32) / 1.8);
	i = i + c;
	}
	while (i <= b);
}

void create_fahrenheit(int a, int b, int c){

	int i = a, f;

	printf("Celsius		Fahrenheit\n");

/* Use line below to check variable values */
//	printf(" i = %d, a = %d, b = %d, c = %d\n", i, a, b, c);
	
	do
	{
	printf("%d		%d\n", i, f = (i * 1.8) + 32);
	i = i + c;
	}
	while (i <= b);
}
