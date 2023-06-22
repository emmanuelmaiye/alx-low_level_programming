#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * positive_or_negative - prints whether a number is positive, negative, or zero
 * @i: integer to check
 *
 * Return: void
 */
void positive_or_negative(int i)
{
	if (i > 0)
		printf("%d is positive\n", i);
	else if (i < 0)
		printf("%d is negative\n", i);
	else
		printf("%d is zero\n", i);
}

int main(void)
{
	int number;

	srand(time(0));
	number = rand() - RAND_MAX / 2;
	positive_or_negative(number);

	return (0);
}
