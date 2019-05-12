/**********************************
* Joseph R. Hunter - Assignment 5 *
**********************************/

#include <stdio.h>

void print_header(void);
int get_menu_choice(void);
void get_multiplication_table(void);
void get_modulus_table(void);
int get_modulus(void);

main(void){

	int choice;
	
	print_header();
	choice = get_menu_choice();

	if (choice == 1){
		get_multiplication_table();
	}
	else{
		get_modulus_table();
	}

	/*Use line below to check choice value*/
	//printf("Choice Value = %d\n", choice);
}

void print_header(void){

	printf("/**********************************\n");
	printf("* Joseph R. Hunter - Assignment 5 *\n");
	printf("**********************************/\n");
}

int get_menu_choice(void){

	int selection;
	
	do{
		printf("What would you like to do today?\n");
		printf("1 - Multiplication Table\n");
		printf("2 - Modulus Table\n");
		printf("Please enter your selection ");
		scanf("%d", &selection);
	}
	while ( selection < 1 || selection > 2 );

	return selection;
}

void get_multiplication_table(void){

	int i, j;

	printf("\n---------------------------------------------------------------\n");
	printf("|--------------------Multiplication Table---------------------|\n");
	printf("---------------------------------------------------------------\n\n");

	printf("*   |");
	for (i = 1; i < 10; ++i)
		printf("%#3d   ", i);
		printf("\n");

	for (i = 1; i < 64; ++i)
		printf("-");
		printf("\n");

	for (i = 1; i < 10; ++i){
		printf("%#2d  |", i);
			for (j = 1; j < 10; ++j)
				printf("%#3d   ", i * j);
				printf("\n");
	}
	printf("\n");
}

void get_modulus_table(void){

	int i, j, m;
	m = get_modulus();

	printf("\n--------------------------------------------------------------\n");
	printf("|-----------------------Modulus Table------------------------|\n");
	printf("--------------------------------------------------------------\n\n");

	printf("*   |");
	for (i = 1; i < 10; ++i)
		printf("%#3d   ", i);
		printf("\n");

	for (i = 1; i < 64; ++i)
		printf("-");
		printf("\n");

	for (i = 1; i < 10; ++i){
		printf("%#2d  |", i);
			for (j = 1; j < 10; ++j)
				printf("%#3d   ", (i * j) %  m );
				printf("\n");
	}
	printf("\n");
	
	/*Use line below to check modulus value*/
	//printf("Modulus Value = %d\n", m);
}

int get_modulus(void){
	
	int modulus;
	
	do{
		printf("Please enter a value between the range of 2 to 15: ");
		scanf("%d", &modulus);
	}
	while ( modulus < 2 || modulus > 15 );

	return modulus;
}
