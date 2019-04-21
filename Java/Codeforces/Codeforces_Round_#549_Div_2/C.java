import java.util.ArrayList;
import java.util.Collection;
import java.util.Scanner;

public class C {

    private static int n;
    private static int[] p;
    private static boolean[] c;
    private static ArrayList<Integer> answer;

    public static void main(String[] args) {
        in();
        solution();
        out();
    }

    private static void in() {

        Scanner in = new Scanner(System.in);

        n = in.nextInt();
        p = new int[n + 1];
        c = new boolean[n + 1];

        for (int i = 1; i <= n; i++) {

            p[i] = in.nextInt();
            c[i] = in.nextInt() == 1;

        }

    }

    private static void solution() {

        ArrayList<Integer> toRemove = new ArrayList<>();
        boolean[] isNotToRemove = new boolean[n + 1];

        for (int i = 1; i <= n; i++) {

            if (!c[i]) {

                isNotToRemove[i] = true;

                try {
                    isNotToRemove[p[i]] = true;
                } catch (IndexOutOfBoundsException ignored) {}

            }

        }

        for (int i = 1; i <= n; i++) {

            if (!isNotToRemove[i]) {
                toRemove.add(i);
            }

        }

        answer = toRemove;

    }

    private static void out() {

        if (answer.isEmpty()) {
            System.out.println(-1);
        } else {
            System.out.print(answer.get(0));
            for (int i = 1; i < answer.size(); i++) {
                System.out.print(" " + answer.get(i));
            }
        }
    }

}
