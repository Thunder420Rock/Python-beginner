#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	const int MIN = 100;
	const int MAX = 100;
	int guess;
	int guesses;
	int answer;
	srand(time(0));
	answer = (rand() % MAX) + MIN;


	do
	{
		printf("State your guess");
		scanf("%d", &guess);
		if (guess > answer)
		{
			printf("Too high");
		}
		else if (guess < answer)
		{
			printf("Too Low");

		}
		else
		{
			printf("Correct!");

		}
		guesses++;

	} while (guess != answer);

	printf("***************************************");
	printf("answer: %d", answer);
	printf("Guesses: %d", guesses);
	printf("***************************************");

	return 0;
}
