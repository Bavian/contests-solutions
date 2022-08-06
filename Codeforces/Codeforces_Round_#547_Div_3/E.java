import javax.management.InstanceNotFoundException;
import java.util.Scanner;

import static java.lang.Long.min;

public class E {

    private static final long INFINITY = (long) 1e18;

    private static long h;
    private static int n;
    private static int[] d;

    private static long answer;

    public static void main(String[] args) {
        in();
        solution();
        out();
    }

    private static void in() {

        Scanner in = new Scanner(System.in);

        h = in.nextLong();
        n = in.nextInt();
        d = new int[n];

        for (int i = 0; i < n; i++) {
            d[i] = in.nextInt();
        }

    }

    private static void solution() {

        long damage = -d[0];

        for (int i = 1; i < n; i++) {
            damage -= d[i];
        }

        long t = 0;
        answer = INFINITY;

        for (int i = 0; i < n; i++) {

            t++;
            h += d[i];

            if (h <= 0) {
                answer = t;
                break;
            }

            if (damage > 0) {
                answer = min(answer, t + (h / damage + (h % damage > 0 ? 1 : 0)) * n);
            }

        }

        answer = answer == INFINITY ? -1 : answer;

    }

    private static void out() {
        System.out.println(answer);
    }

}
