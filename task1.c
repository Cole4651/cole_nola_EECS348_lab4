#include <stdio.h>

#define NUMBER_OF_PLAYS 5

static const int scoring_plays[NUMBER_OF_PLAYS] = {2, 3, 6, 7, 8};

static void find_combinations(int remaining_score, int play_index,
							  int play_counts[])
{
	int count;

	if (play_index == NUMBER_OF_PLAYS - 1) {
		if (remaining_score % scoring_plays[play_index] == 0) {
			play_counts[play_index] =
				remaining_score / scoring_plays[play_index];

						printf("%d TD + 2pt, %d TD + FG, %d TD, "
								   "%d 3pt FG, %d Safety\n",
								   play_counts[4], play_counts[3], play_counts[2],
								   play_counts[1], play_counts[0]);
		}
		return;
	}

	for (count = 0; count * scoring_plays[play_index] <= remaining_score;
		 count++) {
		play_counts[play_index] = count;
		find_combinations(remaining_score -
							  count * scoring_plays[play_index],
						  play_index + 1, play_counts);
	}
}

int main(void)
{
	int score;
	int play_counts[NUMBER_OF_PLAYS] = {0};

	printf("Enter the score: ");
	if (scanf("%d", &score) != 1 || score < 0) {
		printf("Please enter a non-negative whole-number score.\n");
		return 1;
	}

	printf("Possible scoring combinations for %d points:\n", score);
	find_combinations(score, 0, play_counts);

	return 0;
}
