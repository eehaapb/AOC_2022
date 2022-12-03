#include "rps.h"
#include <stdio.h>
#define MAX_INPUT_SIZE 100

int calculate_score(char opponent_selection, char player_selection) {

    if (opponent_selection == 'A') {
        if (player_selection == 'Z') {
            return LOSE + SCISSORS;
        }

        if (player_selection == 'X') {
            return TIE + ROCK;
        }

        return WIN + PAPER;
    }

    if (opponent_selection == 'B') {
        if (player_selection == 'X') {
            return LOSE + ROCK;
        }

        if (player_selection == 'Y') {
            return TIE + PAPER;
        }

        return WIN + SCISSORS;
    }

    if (opponent_selection == 'C') {
        if (player_selection == 'Y') {
            return LOSE + PAPER;
        }

        if (player_selection == 'Z') {
            return TIE + SCISSORS;
        }

        return WIN + ROCK;
    }

    return 0;
}

int main(int argc, char **argv) {

    int score_total = 0;
    FILE *fp;
    char buffer[MAX_INPUT_SIZE];

    fp = fopen(argv[1], "r");

    
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char fst = buffer[0];
        char snd = buffer[2];
        printf("1st char: %c, 2nd char: %c\n", fst, snd);
        printf("Read score: %d\n", calculate_score(fst, snd));
        score_total += calculate_score(fst, snd);
    }

    printf("Score total is %d\n", score_total);

    return 0;
}