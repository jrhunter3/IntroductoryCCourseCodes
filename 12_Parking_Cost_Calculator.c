/*********************************************
 * Joseph R. Hunter - CS 239 -Assignment 11b *
 ********************************************/
#include <stdio.h>
#include <string.h>

void print_header(void);
float get_charge(void);

char time_in[10], time_out[10];
float parking_charge;

main(void){

	print_header();
// Ask user to enter the time strings (using a 24-hour clock).
	puts("Enter the time in using 24-hour format hh:mm ");
	fgets(time_in, sizeof(time_in), stdin);
	puts("Enter the time out using 24-hour format hh:mm ");
	fgets(time_out, sizeof(time_out), stdin);

	get_charge();
	printf("The charge is $%.2f\n", parking_charge);
}

void print_header(void){

	puts("/*********************************************");
	puts(" * Joseph R. Hunter - CS 239 -Assignment 11b *");
	puts(" ********************************************/");
}	

float get_charge(void){

	char str[2] = ":";
	char *str1;
	int ihours, iminutes, ohours, ominutes, itotal, ototal;

	str1 = strtok(time_in, str);
	sscanf(str1, "%i", &ihours);
	str1 = strtok(NULL, str);
	sscanf(str1, "%i", &iminutes);

	str1 = strtok(time_out, str);
	sscanf(str1, "%i", &ohours);
	str1 = strtok(NULL, str);
	sscanf(str1, "%i", &ominutes);
/* Use below to test parsed time read */
//	printf("Entry Time- %i:%i\tExit Time- %i:%i\n", ihours, iminutes, ohours, ominutes);

	ihours = ihours * 60;
	ohours = ohours * 60;
	itotal = ihours + iminutes;
	ototal = ohours + ominutes;

	if (((ototal - itotal) >= 0) && ((ototal - itotal) <= 120)){
		parking_charge = 4.00;
	}
	else if (((ototal - itotal) > 120) && ((ototal - itotal) <= 180)){
		parking_charge = 6.00;
	}
	else if (((ototal - itotal) > 180) && ((ototal - itotal) <= 240)){
		parking_charge = 8.00;
	}
	else {
		parking_charge = 10.00;
	}
}
