#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STR_(X) #X
#define STR(X) STR_(X)

// CONSTANTS

#define COMMAND_SIZE_MAX 6
#define COMMAND_ENCODE "ENCODE"
#define COMMAND_DECODE "DECODE"
#define N_MIN 0
#define N_MAX 26
#define ROTORS_COUNT 3
#define ROTOR_SIZE 27
#define MESSAGE_SIZE_MIN 1
#define MESSAGE_SIZE_MAX 50

// GLOBAL VARIABLES

char command[COMMAND_SIZE_MAX + 1];
int n;
char rotors[ROTORS_COUNT][ROTOR_SIZE + 1];
char message[MESSAGE_SIZE_MAX + 1];

// SOLUTION

void in() {
    scanf("%" STR(COMMAND_SIZE_MAX) "s\n", command);
    scanf("%d\n", &n);
    for (int i = 0; i < ROTORS_COUNT; i++) {
        scanf("%" STR(ROTOR_SIZE) "s\n", rotors[i]);
    }
    scanf("%" STR(MESSAGE_SIZE_MAX) "s\n", message);
}

void encode() {
    // Apply ceasar
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = (message[i] - 'A' + n + i) % ('Z' - 'A' + 1) + 'A';
    }

    // Apply rotors
    for (int i = 0; i < ROTORS_COUNT; i++) {
        for (int j = 0; message[j] != '\0'; j++) {
            message[j] = rotors[i][message[j] - 'A'];
        }
    }
}

void decode() {
    // Apply rotors
    for (int i = ROTORS_COUNT - 1; i >= 0; i--) {
        for (int j = 0; message[j] != '\0'; j++) {
            int letter_index = 0;
            for (int v = 0; rotors[i][v] != '\0'; v++) {
                if (message[j] == rotors[i][v]) {
                    letter_index = v;
                    break;
                }
            }
            message[j] = letter_index + 'A';
        }
    }

    // Apply ceasar
    for (int i = 0; message[i] != '\0'; i++) {
        int next = ((int)message[i]) - n - i;
        while (next < 'A') {
            next += 'Z' - 'A' + 1;
        }
        message[i] = next;
    }
}

void out() {
    printf("%s\n", message);
}

int main() {
    in();
    if (strcmp(command, COMMAND_ENCODE) == 0) {
        encode();
    } else if (strcmp(command, COMMAND_DECODE) == 0) {
        decode();
    }
    out();
    return 0;
}

