import java.util.Scanner;

import static java.lang.Integer.max;

public class B {

    private static int n;
    private static boolean[] a;
    private static int answer;

    public static void main(String[] args) {
        in();
        solution();
        out();
    }

    private static void in() {

        Scanner in = new Scanner(System.in);

        n = in.nextInt();
        a = new boolean[n];

        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() == 1;
        }

    }

    private static void solution() {

        answer = 0;
        int currentHappyTime = 0;

        for (int i = 0; i < 2 * n; i++) {

            if (a[i % n]) {
                currentHappyTime++;
            } else {
                currentHappyTime = 0;
            }

            answer = max(answer, currentHappyTime);

        }

    }

    private static void out() {
        System.out.println(answer);
    }

}
