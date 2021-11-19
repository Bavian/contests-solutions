#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TO_STR_(X) #X
#define TO_STR(X) TO_STR_(X)

// CONSTANTS

#define N_MIN 1
#define N_MAX 100
#define VAL_MIN -10000
#define VAL_MAX 10000
#define VALUE_LENGTH_MAX 6
#define REF_MIN 0
#define REF_MAX N_MIN - 1
#define ARGUMENT_ADDRESS '$'
#define ARGUMENT_EMPTY '_'
#define COMMAND_LENGTH_MAX 5

#define COMMAND_VALUE "VALUE"
#define COMMAND_ADD "ADD"
#define COMMAND_SUB "SUB"
#define COMMAND_MULT "MULT"

// GLOBAL VARIABLES

long long table[N_MAX];
char calculated[N_MAX];
char command[N_MAX][COMMAND_LENGTH_MAX + 1];
char arguments[2][N_MAX][VALUE_LENGTH_MAX + 1];

// SOLUTION

char is_ref(char* argument) {
    return argument[0] == ARGUMENT_ADDRESS;
}

int parse_argument(char* argument, long long* table) {
    if (argument[0] == ARGUMENT_EMPTY) {
        return 0;
    }

    if (is_ref(argument)) {
        return atoi(argument + 1);
    }
    return atoi(argument);
}

long long solve_cell(int index) {
    if (calculated[index]) {
        return table[index];
    }


    int value1 = parse_argument(arguments[0][index], table);
    if (is_ref(arguments[0][index])) {
        value1 = solve_cell(value1);
    }

    int value2 = parse_argument(arguments[1][index], table);
    if (is_ref(arguments[1][index])) {
        value2 = solve_cell(value2);
    }

    if (strcmp(command[index], COMMAND_VALUE) == 0) {
        table[index] = value1;
    } else if (strcmp(command[index], COMMAND_ADD) == 0) {
        table[index] = value1 + value2;
    } else if (strcmp(command[index], COMMAND_SUB) == 0) {
        table[index] = value1 - value2;
    } else if (strcmp(command[index], COMMAND_MULT) == 0) {
        table[index] = value1 * value2;
    }

    calculated[index] = 1;
    return table[index];
}

int main() {
    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%" TO_STR(COMMAND_LENGTH_MAX) "s ", command[i]);
        scanf("%" TO_STR(VALUE_LENGTH_MAX) "s ", arguments[0][i]);
        scanf("%" TO_STR(VALUE_LENGTH_MAX) "s\n", arguments[1][i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%lld\n", solve_cell(i));    
    }
}

