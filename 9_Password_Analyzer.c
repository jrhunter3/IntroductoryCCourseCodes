/*******************************************
* Joseph R. Hunter - CS 239 - Assignment 9 *
*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#define SIZE_LIM 64

void print_header(void);
char get_menu(void);
void enter_password(void);
void analyze_password(void);

int quit = 0;
char password[SIZE_LIM];

main(void){

	char menu;
	print_header();
	
	while ( quit == 0 ){
		menu = get_menu();
		switch (menu){
			case 'a':
			case 'A':
				puts("CryptGen Password Analyzer version 1.0 is a creation of Joseph R. Hunter, written on November 5, 2014!");
				break;
			case 'e':
			case 'E':
				enter_password();
				break;
			case 'r':
			case 'R':
				analyze_password();
				break;
			case 'q':
			case 'Q':
				quit = 1;
				puts("Quitting...");
				usleep(1000000);
				puts("Thank you for using Cryptgen Password Analyzer, by CryptGen Inc.");
				break;
			case 's':
			case 'S':
				print_header();
				break;
		}	//End of Switch
	}	//End of While Statement
}	//End of Main Function

void print_header(void){

	puts("/*******************************************");
	puts("* Joseph R. Hunter - CS 239 - Assignment 9 *");
	puts("*******************************************/");

	puts("|------------------------------------------|");
	puts("|------- CryptGen Password Analyzer -------|");
	puts("|------------------------------------------|");
	puts(" [A]bout\t\t[S]how Menu");
	puts(" [E]nter Password\t[R]un Analysis");
	puts(" [Q]uit");
	puts("|------------------------------------------|");
	puts("|CryptGen Password Analyzer is a product of|");
	puts("|CryptGen Inc.  At CryptGen, what goes in  |");
	puts("|      the crypt, stays in the crypt.      |");
	puts("|------------------------------------------|");
}	//End of Function

char get_menu(void){

	char line[10];

	puts("Enter your choice: ");
	fgets(line, sizeof(line), stdin);

	return line[0];
}	//End of Function

void enter_password(void){

	int i, stupid;

	memset(password, 0, SIZE_LIM);

	do{
		stupid = 0;
		puts("Password may be up to 64 characters and must use only alphanumeric");
		puts("and these special characters ! \" # $ % & ' - . : ; < = > ? @");
		puts("Enter your password: ");
		fgets(password, sizeof(password), stdin);
		for (i = 0; i < SIZE_LIM; i++){
			if (password[i] == ' '){
				stupid++;
			}	//End of If Statement
			else if ((password[i] > '\'' && password[i] < '-') || (password[i] > '.' && password[i] < '0') || (password[i] > 'Z' && password[i] < 'a')){
				stupid++;
			}	//End of Else If Statement
			else if (password[i] > 'z' && password[i] <= '~'){
				stupid++;
			}	//End of Else If Statement
		}	//End of For Statement
		if (stupid > 0){
			puts("\nPlease remember to not enter spaces or invalid special characters\n");
		}	//End of If Statement
	}	//End of While Statement
	while (stupid > 0);
}

void analyze_password(void){

	int i, dcount = 0, ucount = 0, lcount = 0, scount = 0, tcount;

	for (i = 0; i < SIZE_LIM; i++){
		if (password[i] >= 'A' && password[i] <= 'Z'){
			ucount++;
		}	//End of If Statement
		else if (password[i] >= 'a' && password[i] <= 'z'){
			lcount++;
		}	//End of Else If Statement
		else if (password[i] >= '0' && password[i] <= '9'){
			dcount++;
		}	//End of Else If Statement
		else if ((password[i] >= '!' && password[i] <= '\'') || (password[i] >= '-' && password[i] <= '.') || (password[i] >= ':' && password[i] <= '@')){
			scount++;
		}	//End of Else If Statement
	}	//End of For Statement
	printf("\nLower Case: %i\nUpper Case: %i\nDigits: %i\nSpecial Characters: %i\n", lcount, ucount, dcount, scount);

	tcount = (dcount + ucount + lcount + scount);
	if (tcount > 9 && dcount > 0 && ucount > 0 && lcount > 0 && scount > 0){
		puts("Pasword contains 4 types of characters and is above 9 characters.");
		puts("Password is STRONG!");
	}	//End of If Statement
	else if (tcount > 7 && ((dcount > 0 && ucount > 0 && lcount > 0) || (dcount > 0 && ucount > 0 && scount > 0) || (dcount > 0 && lcount > 0 && scount > 0) || (ucount > 0 && lcount > 0 && scount > 0))){
		puts("Password contains 3 types of characters and is above 7 characters.");
		puts("Password is MODERATE.");
	}	//End of Else If Statement
	else {
		puts("Password contains less than 3 types of characters or is less than 8 characters");
		puts("Password is WEAK...");
	}	//End of Else Statement
}	//End of Function

