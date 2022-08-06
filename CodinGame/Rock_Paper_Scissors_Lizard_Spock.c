#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int log2_n(int n) {
    int result = 0;
    while ((n << result) > 0) {
        result++;
    }
    return result;
}

// CONSTANTS

#define SIGN_ROCK 'R'
#define SIGN_PAPER 'P'
#define SIGN_SCISSORS 'C'
#define SIGN_LIZARD 'L'
#define SIGN_SPOCK 'S'
#define N_MIN 2
#define N_MAX 1024
#define ROUNDS_MAX 11

// GLOBAL VARIABLES

int n;
char participants[N_MAX + 1];
int table[ROUNDS_MAX][N_MAX];
int rounds_count;

// SOLUTION

void in() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        int number;
        char sign;
        scanf("%d %c\n", &number, &sign);
        participants[number] = sign;
        table[0][i] = number;
    }
}

int compete(int p1, int p2) {
    char s1 = participants[p1];
    char s2 = participants[p2];
    
    // Scissors cuts Paper
    if (s1 == SIGN_SCISSORS && s2 == SIGN_PAPER) {
        return p1;
    } else if (s2 == SIGN_SCISSORS && s1 == SIGN_PAPER) {
        return p2;
    }
    
    // Paper covers Rock
    if (s1 == SIGN_PAPER && s2 == SIGN_ROCK) {
        return p1;
    } else if (s2 == SIGN_PAPER && s1 == SIGN_ROCK) {
        return p2;
    }

    // Rock crushes Lizard
    if (s1 == SIGN_ROCK && s2 == SIGN_LIZARD) {
        return p1;
    } else if (s2 == SIGN_ROCK && s1 == SIGN_LIZARD) {
        return p2;
    }

    // Lizard poisons Spock
    if (s1 == SIGN_LIZARD && s2 == SIGN_SPOCK) {
        return p1;
    } else if (s2 == SIGN_LIZARD && s1 == SIGN_SPOCK) {
        return p2;
    }

    // Spock smashes Scissors
    if (s1 == SIGN_SPOCK && s2 == SIGN_SCISSORS) {
        return p1;
    } else if (s2 == SIGN_SPOCK && s1 == SIGN_SCISSORS) {
        return p2;
    }

    // Scissors decapitates Lizard
    if (s1 == SIGN_SCISSORS && s2 == SIGN_LIZARD) {
        return p1;
    } else if (s2 == SIGN_SCISSORS && s1 == SIGN_LIZARD) {
        return p2;
    }

    // Lizard eats Paper
    if (s1 == SIGN_LIZARD && s2 == SIGN_PAPER) {
        return p1;
    } else if (s2 == SIGN_LIZARD && s1 == SIGN_PAPER) {
        return p2;
    }

    // Paper disproves Spock
    if (s1 == SIGN_PAPER && s2 == SIGN_SPOCK) {
        return p1;
    } else if (s2 == SIGN_PAPER && s1 == SIGN_SPOCK) {
        return p2;
    }

    // Spock vaporizes Rock
    if (s1 == SIGN_SPOCK && s2 == SIGN_ROCK) {
        return p1;
    } else if (s2 == SIGN_SPOCK && s1 == SIGN_ROCK) {
        return p2;
    }

    // Rock crushes Scissors
    if (s1 == SIGN_ROCK && s2 == SIGN_SCISSORS) {
        return p1;
    } else if (s2 == SIGN_ROCK && s1 == SIGN_SCISSORS) {
        return p2;
    }

    // in case of a tie, the player with the lowest number wins (it's scandalous but it's the rule)
    return p1 < p2 ? p1 : p2;
}

void solution() {
#define i rounds_count
    for (i = 0; n >> i > 1; i++) {
        for (int j = 0; j < n >> i; j += 2) {
            table[i + 1][j / 2] = compete(table[i][j], table[i][j + 1]);
        }
    }
#undef i
}

void out() {
    int competitors[rounds_count];
    int competotors_count = 0;
    int winner = table[rounds_count][0];
    int winner_index = 0;
    for (int i = rounds_count - 1; i >= 0; i--) {
        int p1_index = winner_index * 2;
        int p2_index = p1_index + 1;

        if (table[i][p1_index] == winner) {
            competitors[competotors_count++] = table[i][p2_index];
            winner_index = p1_index;
        } else {
            competitors[competotors_count++] = table[i][p1_index];
            winner_index = p2_index;
        }
    }

    printf("%d\n", winner);
    for (int i = competotors_count - 1; i > 0; i--) {
        printf("%d ", competitors[i]);
    }
    printf("%d\n", competitors[0]);
}

int main() {
    in();
    solution();
    out();
    return 0;
}

