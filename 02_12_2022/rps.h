#ifndef RPS_H
#define RPS_H

int calculate_score(char opponent_selection, char player_selection);
char get_selection(char opponent_selection, char wanted_outcome);

enum rps {
    ROCK = 1,
    PAPER,
    SCISSORS
};

enum result_score {
    WIN = 6,
    TIE = 3,
    LOSE = 0
};

#endif