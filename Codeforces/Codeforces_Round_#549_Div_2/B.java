import java.util.Scanner;

import static java.lang.Long.max;

public class B {

    private static int n;
    private static long answer;

    public static void main(String[] args) {
        in();
        solution();
        out();
    }

    private static void in() {
        n = (new Scanner(System.in)).nextInt();
    }

    private static void solution() {

        answer = getMul(n);

        int number = 0;

        int len = lenght();

        for (int i = len - 1; i >= 0; i--) {

            int digit = getDigit(i + 1);

            if (digit != 0 || i == len - 1) {

                if (digit != 1 || i != len - 1) {
                    answer = max(getMul(number) * (digit - 1) * pow(9, i), answer);
                } else {
                    answer = max(answer, pow(9, i));
                }
            } else {
                break;
            }

            number = number * 10 + digit;

        }

    }

    private static int pow(int number, int p) {

        int res = 1;

        for (int i = 0; i < p; i++) {
            res *= number;
        }

        return res;

    }

    private static int lenght() {

        int m = n;
        int len = 0;

        while (m / 10 > 0) {
            m /= 10;
            len++;
        }

        return len + 1;
    }

    private static int getDigit(int number) {

        int m = n;

        for (int i = 0; i < number - 1; i++) {
            m /= 10;
        }

        return m % 10;

    }

    private static long getMul(int number) {

        long res = 1;
        int m = number;

        while (m / 10 > 0) {
            res *= m % 10;
            m /= 10;
        }

        if (m != 0) {
            res *= m;
        }

        return res;

    }

    private static int putNines(int number, int amount) {

        for (int i = 0; i < amount; i++) {
            number = number * 10 + 9;
        }

        return number;

    }

    private static void out() {
        System.out.println(answer);
    }

}
