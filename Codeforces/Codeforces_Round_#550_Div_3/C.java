import java.io.*;
import java.util.Arrays;
import java.util.Collection;
import java.util.LinkedList;
import java.util.stream.Stream;

public class C {

    private static final int MIN_A = 0;
    private static final int MAX_A = (int) (2 * 1e5);
    private static final String[] ANSWER = {"NO", "YES"};

    private static int n;
    private static int[] a;

    private static byte answer_index;
    private static Collection<Integer> x;
    private static Collection<Integer> y;

    public static void main(String[] args) {
        in();
        solution();
        out();
    }

    private static void in() {

        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in)) ) {

            n = Integer.parseInt( br.readLine() );
            a = new int[n];

            int i = 0;
            for (String number : br.readLine().split(" ")) {
                a[i++] = Integer.parseInt(number);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void solution() {

        x = new LinkedList<>();
        y = new LinkedList<>();

        int[] sort = new int[MAX_A + 1];

        for (int number : a) {
            sort[number]++;
        }

        for (int i = MIN_A; i <= MAX_A; i++) {

            if (sort[i] != 0) {
                x.add(i);
                sort[i]--;
            }

        }

        for (int i = MAX_A; i >= MIN_A; i--) {

            if (sort[i] != 0) {
                y.add(i);
                sort[i]--;
            }

        }

        answer_index = (byte) (Arrays.stream(sort).allMatch(x -> x == 0) ? 1 : 0);

    }

    private static void out() {

        StringBuilder res = new StringBuilder();

        res.append(ANSWER[answer_index]);
        res.append('\n');

        if (answer_index == 1) {

            Stream.of(x, y).forEach(toOutput -> {

                res.append(toOutput.size());
                res.append('\n');

                int i = 0;
                for (int number : toOutput) {

                    res.append(number);
                    res.append(i == x.size() - 1 ? "" : " ");

                    i++;

                }

                res.append('\n');

            });
        }

        try (BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            bw.write(res.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}
