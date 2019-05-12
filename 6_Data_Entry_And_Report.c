/********************************************
 * Joseph R. Hunter - CS 239 - Assignment 6 *
 *******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //Use to set INT_MIN and INT_MAX

/* typefef defines a structure of multiple variables to be returned from a function */
typedef struct data_store{
	int count;
	float sum;
	float avg;
	float min;
	float max;
} data_store;

void print_header(void);
int get_menu(void);
data_store  enter_data(void);

main(void){

	int menu, ctr = 0, count, fcount = 0;
	float avg, favg = 0, min = INT_MAX, fmin = INT_MAX, max = INT_MIN, fmax = INT_MIN, sum, fsum = 0;
	data_store report;

	print_header();

	do{
		menu = get_menu();
	
		if(menu == 1){
			ctr = ctr++;
			puts("****Enter -1 To Quit Data Entry****");
			report = enter_data();		//Sets subtitle for returned typedef values
			count = report.count;		//value exchange may not be necessary
			sum = report.sum;		//value exchange may not be necessary
			avg = report.avg;		//value exchange may not be necessary
			min = report.min;		//value exchange may not be necessary
			max = report.max;		//value exchange may not be necessary
			continue;
		}
		else if(menu == 2){
			if (ctr == 0){
				printf("No Data Has Been Entered.\n");
			}
			else{
				/* Use line below to test typedef return values */
				//printf("report.count =\t%-d\nreport.avg =\t%-f\nreport.min =\t%-f\nreport.max =\t%-f\n", report.count, report.avg, report.min, report.max);

				fcount = fcount + count;
				fsum = fsum + sum;
				favg = fsum / fcount;
				if (min < fmin){
					fmin = min;
				}
				if (max > fmax){
					fmax = max;
				}
					
				printf("Number of Data Items:\t%-d\n", fcount);
				printf("Mean Wind Speed:\t%-10.2f\n", favg);
				printf("Lowest Value:\t\t%-10.2f\n", fmin);
				printf("Highest Value:\t\t%-10.2f\n", fmax);
			} 
			continue;
		}
		else{
			printf("Quitting...\n");
			printf("...\n");
			printf("...\n");
		}
	}
	while( menu != 3 );

	/* Use code below to test get_menu */
	//printf("Menu Value = %d\n", menu);
}

void print_header(void){

	puts("/*******************************************");
	puts("* Joseph R. Hunter - CS 239 - Assignment 6 *");
	puts("*******************************************/");
}

int get_menu(void){

	char menu[2];
	int select;

	puts("\n+++++++++++ Wind Speed Analysis +++++++++++");
	puts("1 - Enter Data");
	puts("2 - Print Report");
	puts("3 - Quit Program");
	puts("+++++++++++++++++++++++++++++++++++++++++++\n");
	puts("Enter Selection: \a");
	
	do{
	fgets(menu, 2, stdin);
	select = atoi(menu);
	}
	while (select < 1 || select > 3);

	return select;
}

data_store enter_data(void){

	data_store ret;		//sets varable to return full typedef values

	char data[100];
	float value, mean, add = 0, low = INT_MAX, high = INT_MIN;
	int i = 0;

	puts("Enter Data Below:");
	while (value != -1){
		printf("\a");
		fgets(data, sizeof(data), stdin);
		sscanf("%10f", &data[0]);
		value = atoi(data);
		if (value != -1){
			i = i++;
			add = add + value;
			mean = add / (i - 1);
			if (i == 0){
				low = value;
				high = value;  
			}
			else if (i != 1){
				if (value < low){
					low = value;
				}
				else if (value > high){
					high = value;
				}
			}
		}
		else{
			break;
		}
	}
	
	/* Below typefef variables are defined */
	ret.count = i - 1;
	ret.sum = add;
	ret.avg = mean;
	ret.min = low;
	ret.max = high;	

	/* Use line below to test enter_data values */
	//printf("i value =\t%-10d\nadd value =\t%-10f\nmean value =\t%-10f\nlow value =\t%-10f\nhigh value =\t%-10f\n", i - 1, add, mean, low, high);
	return ret;
}
