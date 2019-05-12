/********************************************
* Joseph R. Hunter - CS 239 - Assignment 12 *
********************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MEDTAX 0.015

void print_header(void);
char get_menu(void);
int get_number(void);
void get_quit(void);
void tax_time(void);
float get_income(void);
void robot_run(void);
void move_robot(int field[9][9]);
void print_field(int field[9][9]);

int main(void){

	char menu;
	int quit = 0;

	print_header();

	while ( quit == 0 ){
		menu = get_menu();
		switch ( menu ){
			case 'A':
			case 'a':
				puts("MultiPack v. 1.0 was produced and released in 2014 by Joseph R. Hunter");
				break;
			case 'C':
			case 'c':
				puts("Look for Cubic Case in a future MultiPack Update!");
				break;
			case 'Q':
			case 'q':
				get_quit();
				puts("Thank you for using MultiPack v. 1.0!");
				return 0;
			case 'R':
			case 'r':
				robot_run();
				break;
			case 'S':
			case 's':
				print_header();
				break;
			case 'T':
			case 't':
				tax_time();
				break;
		}	//End of Switch
	}	//End of While
}

/***************************** Robot Run Functions ******************************/

void robot_run(void){

	int field[9][9], i, j;

	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			field[i][j] = 0;
		}	//End of jFor
	}	//End of iFor

	move_robot(field);
}

void move_robot(int field[9][9]){

	int n, i = 5, j = 5, ctr = 0;

	do{
	ctr++;
	srand((unsigned)time(NULL));
	n = random()%1600;
	usleep(1000000);
	if (n > 0 && n <= 400){
		field[i][j]++;
		i++;
	}
	else if (n > 400 && n <= 800){
		field[i][j]++;
		i--;
	}
	else if (n > 800 && n <= 1200){
		field[i][j]++;
		j++;
	}
	else if (n > 1200 && n <= 1600){
		field[i][j]++;
		j--;
	}
	system("clear");
	printf("Randomizing moves. Currently making move %i. Please hold on.\n", ctr);
	print_field(field);
	}
	while ((i >= 0 && i < 9) && (j >=0 && j < 9));

	system("clear");
	printf("Robot moved %i steps.\n", ctr);
	print_field(field);
}

void print_field(int field[9][9]){

	int i, j;

	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			printf("%i\t", field[i][j]);
		}	//End of jFor
	puts("\n");
	}	//End of iFor

}

/***************************** Robot Run Functions ******************************/
/***************************** Tax Time Functions *******************************/
void tax_time(void){

	float salary, income_tax, medicare_tax, total_tax;

	salary = get_income();
//	printf("income = %.2f\n", salary);
	if (salary >= 0 && salary <= 6000){
		puts("You owe no taxes");
	}	//End of If
	else if (salary > 6000 && salary <= 34000){
		medicare_tax = salary * MEDTAX;
		printf("Medicare tax: $%.2f\n", medicare_tax);
		income_tax = (salary - 6000) * 0.15;
		printf("Income tax: $%.2f\n", income_tax);
	}	//End of ElseIf
	else if (salary > 34000 && salary <= 80000){
		medicare_tax = salary * MEDTAX;
		printf("Medicare tax: $%.2f\n", medicare_tax);
		income_tax = ((salary - 34000) * 0.3) + 4200;
		printf("Income tax: $%.2f\n", income_tax);
	}	//End of ElseIf
	else if (salary > 80000 && salary <= 180000){
		medicare_tax = salary * MEDTAX;
		printf("Medicare tax: $%.2f\n", medicare_tax);
		income_tax = ((salary - 80000) * 0.4) + 18000;
		printf("Income tax: $%.2f\n", income_tax);
	}
	else if (salary > 180000){
		medicare_tax = salary * MEDTAX;
		printf("Medicare tax: $%.2f\n", medicare_tax);
		income_tax = ((salary - 180000) * 0.45) + 58000;
		printf("Income tax: $%.2f\n", income_tax);
	}
	total_tax = medicare_tax + income_tax;
	puts("----------------------------------------------------------------------------------");
	puts("- \tMedicare Tax\t\tIncome Tax\t\tTotal Tax Owed           -");
	puts("----------------------------------------------------------------------------------");
	printf("\t$%10.2f\t\t$%10.2f\t\t$%10.2f\n", medicare_tax, income_tax, total_tax);
}

float get_income(void){

	char projection[15];
	int i, redo;
	float income;

	do{
		redo = 0;
		memset(projection, 0, sizeof(projection));
		puts("Enter your projected yearly income, without commas: ");
		fgets(projection, sizeof(projection), stdin);
		for (i = 0; i < 15; i++){
			if (projection[i] == ','){
				redo++;
			}	//End of It
		}	//End of For
		if (redo > 0){
			puts("Please do not include commas");
		}	//End of If
	}	//End of Do
	while ( redo > 0 );

	sscanf(projection, "%f", &income);

	return income;
}
/***************************** Tax Time Functions *******************************/

/********************** Interface Functions *******************/
void print_header(void){

	int fortune;
	fortune = get_number();

	puts("/********************************************");
	puts("* Joseph R. Hunter - CS 239 - Assignment 12 *");
	puts("********************************************/\n");

	puts("|-------------------------------------------|");
	puts("|---------------- MultiPack ----------------|");
	puts("|-------------------------------------------|");
	puts(" [A]bout\t\t[Q]uit");
	puts(" [S]how Menu\t\t[R]obot Run");
	puts(" [C]ubic Case\t\t[T]ax Time");
	puts("|-------------------------------------------|");
	printf("|   Your lucky number is: %i                |\n", fortune);
	puts("|-------------------------------------------|");
}

char get_menu(void){

	char line[10];

	puts("Enter your choice: ");
	fgets(line, sizeof(line), stdin);

	return line[0];
}

int get_number(void){

	int n;

	srand((unsigned)time(NULL));
	n = random()%99;

	return n;
}

void get_quit(void){


	system("clear");
	puts("Quitting.");usleep(175000);
	system("clear");
	puts("Quitting..");usleep(175000);
	system("clear");
	puts("Quitting...");usleep(175000);
	system("clear");
	puts("Quitting....");usleep(175000);
	system("clear");
	puts("Quitting.....");usleep(175000);
	system("clear");
	puts("Quitting......");usleep(175000);
	system("clear");
	puts("Quitting.......");usleep(175000);
	system("clear");
	puts("Quitting........");usleep(175000);
	system("clear");
	puts("Quitting.........");usleep(175000);
	system("clear");
	puts("Quitting..........");usleep(175000);
	system("clear");
	puts("Quitting...........");usleep(175000);
	system("clear");
	puts("Quitting............");usleep(155000);
}
/********************** Interface Functions *******************/

