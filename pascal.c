#include <stdio.h>

#define BUF_SIZE 512

void pascal(int n) {
	/*int a[n][n];
	int i;
	for (i = 0; i < n; i++) {
		int j;
		for (j = 0; j < i; j++)
			;
	}*/
	printf("So far so good\n");
}

int main (void) {
	printf("Please select a number: ");
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
