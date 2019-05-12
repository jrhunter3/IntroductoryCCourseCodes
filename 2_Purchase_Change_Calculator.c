/****************************************
 *CS Lab Assignment 2 - Joseph R. Hunter*
 * **************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float purchaseAmt(void);	// function declaration

int main(void){
	double paidAmount, purchaseAmount;
	float totalDue, taxDue, changeDue, pennyTwo;
	int dollarOut, quarterOut, dimeOut, nickelOut, pennyOut, pennyOne;
	purchaseAmount = purchaseAmt();		//calls variable from random number generator

	printf("\n");
	printf("CS 239 Laboratory 2 - Joseph R. Hunter\n\n");
	
	printf("Amount due =  %.2f\n", purchaseAmount);
	
	taxDue = purchaseAmount * 0.06;
	printf("Tax due = %.2f\n", taxDue);

	totalDue = purchaseAmount * 1.06;
	printf("Total due = %.2f\n", totalDue);

	printf("Enter amount paid: ");
	scanf("%lf", &paidAmount);

	changeDue = paidAmount - totalDue;
	printf("Change due = %.2f\n", changeDue);
	//Begin change machine below
	dollarOut = changeDue;
	if (dollarOut == 1){
		printf("%d Dollar\n", dollarOut);
	}
	else if (dollarOut > 1){
		printf("%d Dollars\n", dollarOut);
	}
	changeDue = changeDue - dollarOut;

	quarterOut = changeDue / 0.25;
	if (quarterOut == 1){
		printf("%d Quarter\n", quarterOut);
	}
	else if (quarterOut > 1){
		printf("%d Quarters\n", quarterOut);
	}
	changeDue = changeDue - (quarterOut * 0.25);

	dimeOut = changeDue / 0.1;
	if (dimeOut == 1){
		printf("%d Dime\n", dimeOut);
	}
	else if (dimeOut > 1){
		printf("%d Dimes\n", dimeOut);
	}
	changeDue = changeDue - (dimeOut * 0.1);

	nickelOut = changeDue / 0.05;
	if (nickelOut == 1){
		printf("%d Nickel\n", nickelOut);
	}
	else if (nickelOut > 1){
		printf("%d Nickels\n", nickelOut);
	}
	changeDue = changeDue - (nickelOut * 0.05);

	pennyOne = changeDue / 0.01;
	pennyTwo = changeDue / 0.01;
	if (((pennyTwo - pennyOne) * 10)  >= 5.1)
		{
		pennyOut = (pennyOne + 1);
		}
	else 
		{
		pennyOut = pennyOne;
		}
	if (pennyOut == 1){
		printf("%d Penny\n", pennyOut);
	}
	else if (pennyOut > 1){
		printf("%d Pennies\n", pennyOut);
	}
	//printf("%d Penny One\n", pennyOne);
	//printf("%d Penny Two\n", pennyTwo);
}

/*-------------------------------------------------------------
| This function generates a purchaseAmount from 2.00 to 18.00 |
-------------------------------------------------------------*/

float purchaseAmt(void){
	float purchaseAmount, dollars, cents;
	long n;
		//Next line initializes the random number generatior
	srand((unsigned)time(NULL));
	n = random()%1600;		//integer amount 0 to 1600
	n = 200 + n;			//now from 200 to 1800
	dollars = (float)(n / 100);	//find dollars as a float
	cents = ((float)(n%100))/100.;	//find cents as a float
	purchaseAmount = dollars + cents;
	return (purchaseAmount);
}
