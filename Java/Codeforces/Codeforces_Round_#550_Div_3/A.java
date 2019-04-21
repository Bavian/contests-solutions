import java.io.*;
import java.util.Arrays;

public class A {

    private static String[] ANSWERS = {"No", "Yes"};

    private static int n;
    private static String[] tasks;

    private static byte[] answers;

    public static void main(String[] args) {
        in();
        solution();
        out();
    }

    private static void in() {

        try( BufferedReader br = new BufferedReader(new InputStreamReader(System.in)) ) {

            n = Integer.parseInt( br.readLine() );
            tasks = new String[n];

            for (int i = 0; i < n; i++) {
                tasks[i] = br.readLine();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void solution() {

        answers = new byte[n];

        for (int i = 0; i < n; i++) {
            answers[i] = test(tasks[i]);
        }

    }

    private static byte test(String str) {

        char[] sortedSymbols = str.toCharArray();
        Arrays.sort(sortedSymbols);

        for (int i = 1; i < sortedSymbols.length; i++) {

            if ( Math.abs(sortedSymbols[i] - sortedSymbols[i - 1]) != 1 ) {
                return 0;
            }

        }

        return 1;

    }

    private static void out() {

        try (BufferedWriter br = new BufferedWriter( new OutputStreamWriter(System.out) )) {

        for (int i = 0; i < n; i++) {
            br.write(ANSWERS[answers[i]] + "\n");
        }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}
