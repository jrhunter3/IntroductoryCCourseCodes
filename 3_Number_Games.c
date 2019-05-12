/***********************************
 * Joseph R. Hunter - Laboratory 3 *
 * ********************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printHeader(void);
int flipAcoin(void);
void announceResult(int result);
void numberStats(void);
void triad(void);
void ordinals(void);

main()
{
	/* Any variable declarations needed */
	printHeader();
	int result = flipAcoin();
	announceResult(result);
	numberStats();
	triad();
	ordinals();
}

void printHeader(void){
	printf("/***********************************\n");
	printf("*  Joseph R. Hunter - Laboratory 3 *\n");
	printf("************************************\n");
	}

int flipAcoin(void){
	int n;
	/* Next line initializes the random number generator */
	srand((unsigned)time(NULL));
	n = random()%99;	//integer amount 0 to 1600
	n = 1 + n;		//now from 1 to 100
	if (n <= 50){
	n = 0;
	}
	else if (n > 50){
	n = 1;
	}
	return n;
}

void announceResult(int result){
	int flippedCoin = result;	
	
	if (flippedCoin == 1){
	printf("Tails\n");
	}
	else if (flippedCoin == 0){
	printf("Heads\n");
	}
}

void numberStats(void){
	int one, two, result;
	
	printf("numberStats:  Please enter two positive integers: "); 
	scanf("%d %d", &one, &two);

	if (one > two){
		printf("%d is larger\n%d is smaller\n", one, two);
		result = one + two;
		printf("%d + %d = %d\n", one, two, result);
		result = one - two;
		printf("%d - %d = %d\n", one, two, result);
		result = one * two;
		printf("%d * %d = %d\n", one, two, result);
		result = one % two;
		printf("%d %% %d = %d\n", one, two, result);
	}
	else if (two > one){
		printf("%d is larger\n%d is smaller\n", two, one);
		result = two + one;
		printf("%d + %d = %d\n", two, one, result);
		result = two - one;
		printf("%d - %d = %d\n", two, one, result);
		result = two * one;
		printf("%d * %d = %d\n", two, one, result);
		result = two % one;
		printf("%d %% %d = %d\n", two, one, result);
	}
	else{
		printf("%d and %d are equal\n", one, two);
		result = one + two;
		printf("%d + %d = %d\n", one, two, result);
		result = one - two;
		printf("%d - %d = %d\n", one, two, result);
		result = one * two;
		printf("%d * %d = %d\n", one, two, result);
		result = one % two;
		printf("%d %% %d = %d\n", one, two, result);
	}
}

void triad(void){
	int one, two, three;
	printf("triad: Please enter three positive ints: ");
	scanf("%d %d %d", &one, &two, &three);

	printf("You entered %d, %d, and %d\n", one, two, three);

	if (one == two && two == three){
		printf("All are equal\n");
		printf("Sorted order: %d %d %d\n", one, two, three);
	}
	else if ((one == two && two < three) || (one < two && two == three) || (three > two && two > one)){
		printf("Not all equal\n");
		printf("Sorted order: %d %d %d\n", one, two, three);
	} 
	else if ((one == two && two > three) || (two > one && one > three)){
		printf("Not all equal\n");
		printf("Sorted order: %d %d %d\n", three, one, two);
	}
	else if ((one > two && two == three) || (one > three && three > two)){
		printf("Not all equal\n");
		printf("Sorted order: %d %d %d\n", two, three, one);
	}
	else if ((one == three && three > two) || (three > one && one > two)){
		printf("Not all equal\n");
		printf("Sorted order: %d %d %d\n", two, one, three);
	}
	else if ((one == three && three < two) || (two > three && three > one)){
		printf("Not all equal\n");
		printf("Sorted order: %d %d %d\n", one, three, two);
	}
	else if (one > two && two > three){
		printf("Not all equal\n");
		printf("Sorted order: %d %d %d\n", three, two, one);
	}
}

void ordinals(void){
	int ordinal;

	printf("ordinals: Please enter an int between 1 and 100: ");
	scanf("%d", &ordinal);

	if (ordinal > 100 || ordinal < 1){
		printf("You've entered a number outside of the parameter.  Please try again.\n");
	}
	else if (ordinal == 11 || ordinal == 12 || ordinal == 13){
		printf("%dth\n", ordinal);
	}
	else if (ordinal % 10 == 1){
		printf("%dst\n", ordinal);
	}
	else if (ordinal % 10 == 2){
		printf("%dnd\n", ordinal);
	}
	else if (ordinal % 10 == 3){
		printf("%drd\n", ordinal);
	}
	else{
		printf("%dth\n", ordinal);
	}
}
