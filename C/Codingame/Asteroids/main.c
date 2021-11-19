#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <math.h>

//#define DEBUG_FLAG true

#define STR_(X) #X
#define STR(X) STR_(X)

// CONSTANTS

#define W_MIN 0
#define W_MAX 20
#define H_MIN 0
#define H_MAX 20
#define T_MIN 0
#define T_MAX 10000
#define MAP_EMPTY_SPACE '.'

// GLOBAL VARIABLES

short w, h, t1, t2, t3;
char t_map[3][H_MAX][W_MAX + 1];

// SOLUTION

void debug_printf(const char* format, ...) {
    #ifdef DEBUG_FLAG
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    #endif
}

void in() {
    scanf("%hd %hd %hd %hd %hd\n", &w, &h, &t1, &t2, &t3);
    for (int y = 0; y < h; y++) {
        scanf("%" STR(W_MAX) "s %" STR(W_MAX) "s\n", t_map[0][y], t_map[1][y]);
        debug_printf("t_map=%s %s\n", t_map[0][y], t_map[1][y]);
    }

    debug_printf("%d %d %d %d %d\n1:\n", w, h, t1, t2, t3);
    for (int y = 0; y < h; y++) {
        debug_printf("%s\n", t_map[0][y]);
    }
    debug_printf("2:\n");
    for (int y = 0; y < h; y++) {
        debug_printf("%s\n", t_map[1][y]);
    }
}

int roundToBottom(double x) {
    /*
    debug_printf("roundToBottom(%f): ", x);
    int integer_x = floor(x);
    debug_printf("integer=%d ", integer_x);
    int result = integer_x + (x > integer_x);
    debug_printf("result=%d\n", result);
    debug_printf("shit: %d\n", x > integer_x);
    return result;
    */
    return floor(x);
}

double square(double a) {
    return a * a;
}

double float_div(double a, double b) {
    return a / b;
}

void calculate_horizontal(int y1, int x1, int y2, int x2, double *y3, double *x3) {
    debug_printf("Found horizontal line\n");
    double v = float_div(x2 - x1, t2 - t1);
    debug_printf("v=%f\n", v);
    *y3 = y1;
    *x3 = v * (t3 - t2) + x2;
}

void calculate_vertical(int y1, int x1, int y2, int x2, double *y3, double *x3) {
    debug_printf("Found vertical line\n");
    double v = float_div(y2 - y1, t2 - t1);
    debug_printf("v=%f\n", v);
    *y3 = v * (t3 - t2) + y2;    
    *x3 = x1;
}

void calculate_diagonal(int y1, int x1, int y2, int x2, double *y3, double *x3) {
    debug_printf("Found diagonal line\n");
    double v_2 = float_div(square(x2 - x1) + square(y2 - y1), square(t2 - t1));
    double k = float_div(y1 - y2, x1 - x2);
    double x3_2 = float_div(v_2 * square(t3 - t2), 1 + square(k));
    debug_printf("v_2=%f\nk=%f\nx3_2=%f\n", v_2, k, x3_2);

    double dx3 = sqrt(x3_2);
    double x3_s_1 = dx3 + x2;
    double x3_s_2 = -dx3 + x2;

    double y3_s_1 = x3_s_1 * k + y1 - x1 * k;
    double y3_s_2 = x3_s_2 * k + y1 - x1 * k;

    debug_printf("Answer is (%f; %f) or (%f; %f)\n", x3_s_1, y3_s_1, x3_s_2, y3_s_2);

    *x3 = x2 > x1 ? x3_s_1 : x3_s_2;
    *y3 = x2 > x1 ? y3_s_1 : y3_s_2;
}

void proccess_2_map(int y1, int x1) {
    for (int y2 = 0; y2 < h; y2++) {
        for (int x2 = 0; x2 < w; x2++) {
            if (t_map[1][y2][x2] == t_map[0][y1][x1]) {
                debug_printf("(%d; %d; %d) -> (%d; %d; %d)\n", x1, y1, t1, x2, y2, t2);

                double y3, x3;
                if (y1 == y2) {
                    calculate_horizontal(y1, x1, y2, x2, &y3, &x3);
                } else if (x1 == x2) {
                    calculate_vertical(y1, x1, y2, x2, &y3, &x3);
                } else {
                    calculate_diagonal(y1, x1, y2, x2, &y3, &x3);
                }

                int y3_rounded = roundToBottom(y3);
                int x3_rounded = roundToBottom(x3);
                debug_printf("Answer is (%d, %d, %d)\n", x3_rounded, y3_rounded, t3);
                if (0 <= y3_rounded && y3_rounded < h &&
                    0 <= x3_rounded && x3_rounded < w) {
                    if (t_map[2][y3_rounded][x3_rounded] == MAP_EMPTY_SPACE ||
                            t_map[1][y2][x2] < t_map[2][y3_rounded][x3_rounded]) {
                        t_map[2][y3_rounded][x3_rounded] = t_map[1][y2][x2];
                    }
                }
            }
        }
    }
}

void solution() {
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            t_map[2][y][x] = MAP_EMPTY_SPACE;
        }
    }

    for (int y1 = 0; y1 < h; y1++) {
        for (int x1 = 0; x1 < w; x1++) {
            if (t_map[0][y1][x1] != 'K') {
                //continue;
            }

            if (t_map[0][y1][x1] != MAP_EMPTY_SPACE) {
                proccess_2_map(y1, x1);
            }
        }
    }
}

void out() {
    debug_printf("3:\n");
    for (int y = 0; y < h; y++) {
        printf("%s\n", t_map[2][y]);
    }
}

int main() {
    in();
    solution();
    out();
    return 0;
}

