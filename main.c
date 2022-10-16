#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int 
main(int argc, char *argv[])
{
	if (argv[1] == NULL) return -1;

	FILE *nums;
	unsigned int x, i;
       
	nums = fopen("nums.txt", "w+");
	x = atoi(argv[1]);
	if ( x == INT_MAX || x == INT_MIN ) return -1;

	fprintf(nums, "Initial number: %d\n", x); 
	printf("Number: %d\n", x);

	unsigned int digits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	unsigned int counter, numSum, firstDigit, max;
	counter = numSum = 0;
	max = x;

	while (x != 1) {
		x = (x % 2) ? 3*x+1 : x/2;
		counter++;
		numSum += x;

		if (x > max) max = x;

		firstDigit = x;
		while (firstDigit >= 10) firstDigit /= 10;

		digits[ firstDigit-1 ]++;

		fprintf(nums, "%d\n", x); 
	}

	printf("Amount of steps: %d\n", counter);
	printf("Highest point: %d\n", max);
	printf("Average value: %.1f\n", (float)numSum/counter+1);

	int digitSum = 0;
	for (i = 0; i < 9; i++) digitSum += digits[i];

	printf("\nLeading digit (percentage):");
	for (i = 0; i < 9; i++) {
		float percentage = (float)digits[i] / (float)digitSum * 100;
		printf("\n%d (%4.1f%%)| ", i+1, percentage);

		for (percentage; percentage >= 0.5; percentage -= 1.0f) {
			printf("=");
		}
	}
	printf("\n");

	fclose(nums);

	return 0;
}
