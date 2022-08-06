#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STR_(X) #X
#define STR(X) STR_(X)

// CONSTANTS

#define CELL_STATE_DEAD '.'
#define CELL_STATE_ALIVE 'O'
#define W_MIN 0
#define W_MAX 20
#define H_MIN 0
#define H_MAX 20
#define N_MIN 0
#define N_MAX 20
#define RULE_LENGTH 9
#define RULE_LIVE '1'
#define RULE_DEAD '0'

// GLOBAL VARIABLES

short w, h, n;
char surviving_rule[RULE_LENGTH + 1];
char birth_rule[RULE_LENGTH + 1];
char cell[H_MAX][W_MAX + 1];

void in() {
    scanf("%hd %hd %hd\n", &h, &w, &n);
    scanf("%" STR(RULE_LENGTH) "s\n", surviving_rule);
    scanf("%" STR(RULE_LENGTH) "s\n", birth_rule);
    for (int i = 0; i < h; i++) {
        scanf("%" STR(W_MAX) "s\n", cell[i]);
    }

    /*
    printf("properties: %hd %hd %hd\n", w, h , n);
    printf("survive rule: %s\n", surviving_rule);
    printf("birth rule: %s\n", birth_rule);
    for (int i = 0; i < h; i++) {
        printf("%d: %s\n", i, cell[i]);
    }
    */
}

int is_alive(int y, int x) {
    //printf("is_alive(%d, %d, %d)\n", y, x, cell[y][x] == CELL_STATE_ALIVE);
    return 0 <= y && y < h && 0 <= x && x < w && cell[y][x] == CELL_STATE_ALIVE;
}

int calculate_neighbors(int y, int x) {
    return is_alive(y - 1, x) +
           is_alive(y - 1, x + 1) +
           is_alive(y, x + 1) +
           is_alive(y + 1, x + 1) +
           is_alive(y + 1, x) +
           is_alive(y + 1, x - 1) +
           is_alive(y, x - 1) +
           is_alive(y - 1, x - 1);
}

void solution() {
    char swap_cell[h][w];

    for (int i = 0; i < n; i++) {
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int neighbors_count = calculate_neighbors(y, x);
                bool survive = surviving_rule[neighbors_count] == RULE_LIVE && cell[y][x] == CELL_STATE_ALIVE;
                bool birth = birth_rule[neighbors_count] == RULE_LIVE && cell[y][x] == CELL_STATE_DEAD;
                //printf("(%d;%d) -> neighbors_count=%d, survive=%d, birth=%d\n", y, x, neighbors_count, survive, birth);
                swap_cell[y][x] = survive || birth ? 
                        CELL_STATE_ALIVE : CELL_STATE_DEAD;
            }
        }

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                cell[y][x] = swap_cell[y][x];
            }
        }
    }
}

void out() {
    for (int i = 0; i < h; i++) {
        printf("%s\n", cell[i]);
    }
}

int main() {
    in();
    solution();
    out();
    return 0;
}

