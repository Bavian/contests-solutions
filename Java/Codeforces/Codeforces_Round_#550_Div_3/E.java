import java.io.*;

public class E {

    private static int k;
    private static String s, t;

    private static String answer;

    public static void main(String[] args) {
        in();
        solution();
        out();
    }

    private static void in() {

        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {

            k = Integer.parseInt(br.readLine());
            s = br.readLine();
            t = br.readLine();

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void solution() {

        int[] sum = new int[k];

        for (int i = 0; i < k; i++) {

            sum[i] += toInt(s, s.length() - i - 1) + toInt(t, t.length() - i - 1);

            if (i < k - 1) {

                sum[i + 1] += sum[i] / ('z' - 'a' + 1) > 0 ? 1 : 0;
                sum[i] %= 'z' - 'a' + 1;

            }

        }

        StringBuilder res = new StringBuilder();

        for (int i = sum.length - 1; i >= 0; i--) {

            res.append( (char) (sum[i] / 2 + 'a') );

            if (i > 0) {
                sum[i - 1] += sum[i] % 2 == 0 ? 0 : 'z' - 'a' + 1;
            }

        }

        res.append('\n');

        answer = res.toString();

    }

    private static int toInt(String str, int i) {
        return i < str.length() ? str.charAt(i) - 'a' : 0;
    }

    private static void out() {

        try (BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            bw.write(answer);
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}
