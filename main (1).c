#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> // for rand and srand functions
#include <time.h>   // for time function to seed random number generator

// rules
// Rock beats scissors
// Paper beats rock
// Scissors beats paper

char *item[] = {"Rock", "Paper", "Scissors"};
bool nCheck(int num);
void runGame(int playerChoice, int *playerScore, int *computerScore); 


int main(void) {
    int choice = 0;
    int num_elements = sizeof(item) / sizeof(item[0]);
    int playerScore = 0;
    int computerScore = 0;

    printf("Welcome to Rock-Paper-Scissors (Best of 3)!\n");

    while (playerScore < 2 && computerScore < 2) {
        printf("\nPlease enter: ");
        for (int i = 0; i < num_elements; i++) {
            printf("%d: %s ", i, item[i]);
        }

        if (scanf("%d", &choice) == 1) {
            bool result = nCheck(choice);

            if (result) {
                runGame(choice, &playerScore, &computerScore);
            } else {
                printf("Invalid number\n");
            }
        }
    }

    if (playerScore > computerScore) {
        printf("\nCongratulations! You won the best of 3!\n");
    } else {
        printf("\nComputer won the best of 3. Better luck next time!\n");
    }

    return 0;
}

bool nCheck(int num) {
    if (num >= 0 && num < 3)
        return true;
    else
        return false;
}

void runGame(int playerChoice, int *playerScore, int *computerScore) {
    // Generate a random number between 0 and 2 for the computer's choice
    srand(time(NULL)); // Seed the random number generator with the current time
    int computerChoice = rand() % 3;

    printf("You chose: %s\n", item[playerChoice]);
    printf("Computer chose: %s\n", item[computerChoice]);

    // Determine the winner based on the game rules
    int result = (playerChoice - computerChoice + 3) % 3;

    if (result == 0) {
        printf("It's a tie!\n");
    } else if (result == 1) {
        printf("You win this round!\n");
        (*playerScore)++;
    } else {
        printf("Computer wins this round!\n");
        (*computerScore)++;
    }

    printf("Current Score: You: %d, Computer: %d\n", *playerScore, *computerScore);
}
