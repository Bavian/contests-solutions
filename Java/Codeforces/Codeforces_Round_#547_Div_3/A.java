import java.util.Scanner;

public class A {

    private static final int[] FACTORS = {2, 3};

    private static int n, m, answer = 0;

    public static void main(String[] args) {
        in();
        solution();
        out();
    }

    private static void in() {

        Scanner in = new Scanner(System.in);

        n = in.nextInt();
        m = in.nextInt();

    }

    private static void solution() {

        if (m % n == 0) {

            int number = m / n;

            for (int factor : FACTORS) {

                while (number % factor == 0) {
                    number /= factor;
                    answer++;
                }

            }

            if (number > 1) {
                answer = -1;
            }

        } else {
            answer = -1;
        }

    }

    private static void out() {
        System.out.println(answer);
    }

}
