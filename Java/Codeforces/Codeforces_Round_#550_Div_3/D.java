import java.io.*;
import java.util.ArrayList;
import java.util.Collection;
import java.util.LinkedList;

public class D {

    private static final int MIN_A = 1;
    private static final int MAX_A = (int) (2 * 1e5);

    private static int n;
    private static int[] a;

    private static Collection<Answer> answers;

    public static void main(String[] args) {
        in();
        solution();
        out();
    }

    private static void in() {

        try ( BufferedReader br = new BufferedReader(new InputStreamReader(System.in)) ) {

            n = Integer.parseInt(br.readLine());
            a = new int[n];

            String[] numbers = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(numbers[i]);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void solution() {

        answers = new LinkedList<>();

        int[] sort = new int[MAX_A + 1];
        int max = a[0];

        for (int i = 0; i < a.length; i++) {

            sort[a[i]]++;
            max = sort[a[i]] > sort[max] ? a[i] : max;

        }

        ArrayList<Integer> points = new ArrayList<>();

        for (int i = 0; i < n; i++) {

            if (a[i] == max) {
                points.add(i);
            }

        }

        for (int i = points.get(0); i > 0; i--) {
            normalize(i, i - 1);
        }

        for (int i = 0; i < points.size() - 1; i++) {

            int j = points.get(i);

            //System.out.printf("points[%d] = %d\n", i, points.get(i));

            while(j + 1 < points.get(i + 1)) {

                //System.out.println("j: " + j);

                normalize(j, j + 1);

                j++;

            }

        }

        for (int i = points.get(points.size() - 1); i < n - 1; i++) {
            normalize(i, i + 1);
        }

    }

    private static void normalize(int i, int j) {

        if (a[i] != a[j]) {

            int k = a[i] < a[j] ? 2 : 1;

            a[j] = a[i];

            answers.add(new Answer(k, j + 1, i + 1));

        }

    }

    private static void out() {

        StringBuilder res = new StringBuilder();

        res.append(answers.size());
        res.append('\n');

        int i = 0;
        for (Answer answer : answers) {

            res.append(answer.getT());
            res.append(' ');

            res.append(answer.getI());
            res.append(' ');

            res.append(answer.getJ());
            res.append('\n');

            i++;

        }

        try (BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            bw.write(res.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }

    }



}

class Answer {

    private int t, i, j;

    Answer(int t, int i, int j) {

        this.t = t;
        this.i = i;
        this.j = j;

    }

    int getT() {
        return t;
    }

    int getI() {
        return i;
    }

    int getJ() {
        return j;
    }
}