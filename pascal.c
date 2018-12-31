/*
	Element i,j in Pascal's Triangle = i! / (j! * (i - j)!)
*/

#include <stdio.h>
#include <limits.h>	//For MAX_INT
#include <stdlib.h>	//For exit()

#define BUF_SIZE 512

void errF(char * s, int i) {
	printf("%s%i. Please try a smaller number.\n", s, i);
	exit(1);
}

long f(int n) {	//Factorial function
	long ans = 1, i;
	for (i = 1; i <= n; i++) {
		if (ans * i > INT_MAX)
			errF("Integer overflow for factorial function when multiplying ", i);
		else ans *= i;
	}
	return (int) ans;	
}

void pascal(int n) {
	int i;
	for (i = 0; i < n; i++) {
		int j;
		for (j = 0; j <= i; j++)
			printf("%ld ", f(i) / (f(j) * f(i - j)));
		printf("\n");
	}
}

int main (void) {
	printf("Please select a number up to 13: ");
	char buffer[BUF_SIZE];
	int n;
	while (fgets(buffer, BUF_SIZE, stdin) != NULL) {
		if (sscanf(buffer, "%i", &n) != 1)
			printf("Error, please try again.\n");
		else {
			pascal(n);
			break;
		}
	}
	printf("\n\tThank you and have a pleasant day!\n");
	return 0;
}
