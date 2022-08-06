#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// CONSTANTS
#define N_MIN 2
#define N_MAX 500
#define L_MIN 1
#define L_MAX 1000
#define E_MIN 1
#define E_MAX 20

bool hasValue(int *array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}

int main() {

    int n, l, e;
    scanf("%d %d %d\n", &n, &l, &e);
    fprintf(stderr, "%d %d %d\n", n, l, e);

    int n1[l], n2[l];
    for (int i = 0; i < l; i++) {
        scanf("%d %d\n", &n1[i], &n2[i]);
        fprintf(stderr, "n1[%d] = %d, n2[%d] = %d\n", i, n1[i], i, n2[i]);
    }

    int ei[e];
    for (int i = 0; i < e; i++) {
        scanf("%d\n", &ei[i]);
        fprintf(stderr, "ei[%d] = %d\n", i, ei[i]);
    }

    bool removed[l];
    for (int i = 0; i < l; i++) removed[i] = false;

    int bfsQueue[n], first, last;

    for (;;) {

        int si;
        scanf("%d", &si);
        fprintf(stderr, "si = %d\n", si);

        bfsQueue[0] = si;
        first = 0;
        last = 0;
        for (int i = 1; i < n; i++) bfsQueue[i] = -1;

        bool stopWhile = false;
        int hod = 0;
        do {
            for (int i = 0; i < l; i++) {
                if (removed[i]) continue;

                if (n2[i] == bfsQueue[first] && hasValue(ei, e, n1[i])
                    || n1[i] == bfsQueue[first] && hasValue(ei, e, n2[i])) {
                    for (int i = 0; i < n; i++) {
                        fprintf(stderr, "%d ", bfsQueue[i]);
                    }
                    fprintf(stderr, "\n");
                    printf("%d %d\n", n1[i], n2[i]);
                    removed[i] = true;
                    stopWhile = true;

                    break;
                }

                if (n1[i] == bfsQueue[first]) {
                    if (!hasValue(bfsQueue, last + 1, n2[i])) {
                        bfsQueue[++last] = n2[i];
                    }
                    continue;
                }

                if (n2[i] == bfsQueue[first]) {
                    if (!hasValue(bfsQueue, last + 1, n1[i])) {
                        bfsQueue[++last] = n1[i];
                    }
                    continue;
                }
            }

        } while (!stopWhile && ++first < n && bfsQueue[last] != -1);

    }

}

