import java.util.Scanner;

import static java.lang.Integer.max;

public class A {

    private static int INFINITY = 101;

    private static int n;
    private static int[] a;

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        n = in.nextInt();
        a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }

        System.out.println(tanos(0, n));

    }

    private static int tanos(int l, int r) {

        if (r - l == 1) {
            return 1;
        }

        for (int i = l + 1; i < r; i++) {

            if (a[i-1] > a[i]) {
                int m = (r + l) / 2;
                return max(tanos(l, m), tanos(m, r));
            }

        }

        return r - l;

    }

}
