import java.util.Arrays;
import java.util.Scanner;

import static java.lang.Integer.min;

public class C {

    private static int[] FAIL = {-1};

    private static int n;
    private static int[] p, q;

    public static void main(String[] args) {
        in();
        solution();
        out();
    }

    private static void in() {

        Scanner in = new Scanner(System.in);

        n = in.nextInt();
        p = new int[n];
        q = new int[n - 1];

        for (int i = 0; i < n - 1; i++) {
            q[i] = in.nextInt();
        }

    }

    private static void solution() {

        p[0] = 1;
        int minimum = p[0];

        for (int i = 1; i < n; i++) {
            p[i] = p[i - 1] + q[i - 1];
            minimum = min(minimum, p[i]);
        }

        for (int i = 0; i < n; i++) {
            p[i] -= minimum - 1;
        }

        boolean[] isUsed = new boolean[n + 1];

        for (int i = 0; i < n; i++) {

            try {

                isUsed[p[i]] = true;

            } catch (IndexOutOfBoundsException e) {

                p = FAIL;
                break;

            }

        }

        for (int i = 1; i <= n; i++) {

            if(!isUsed[i]) {

                p = FAIL;
                break;

            }

        }

    }

    private static void out() {

        System.out.print(p[0]);

        for (int i = 1; i < p.length; i++) {
            System.out.print(" " + p[i]);
        }

    }

}
