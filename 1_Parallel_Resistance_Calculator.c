/*******************************************
 * Student, Joseph R. Hunter - Assignment 1*
 * ****************************************/
#include <stdio.h>

int main(void)
{
	float res1, res2, res3, result;
	//Ask user to enter resistance values
	printf("Enter the ohm values of three resistors: ");
	scanf("%f %f %f", &res1, &res2, &res3);
	result = 1.0 /((1.0/ res1) + (1.0 / res2) + (1.0 / res3));
	printf("The resistance of %f and %f and %f in parallel is %f.\n", res1, res2, res3, result);
	return 0;
}
