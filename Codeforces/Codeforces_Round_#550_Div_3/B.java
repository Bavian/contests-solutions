import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class B {

    private static int n;
    private static int[] a;

    private static int answer;

    public static void main(String[] args) {
        in();
        solution();
        out();
    }

    private static void in() {

        try ( BufferedReader br = new BufferedReader(new InputStreamReader(System.in)) ) {

            n = Integer.parseInt( br.readLine() );
            a = new int[n];

            int i = 0;
            for (String stringNumber : br.readLine().split(" ")) {
                a[i++] = Integer.parseInt(stringNumber);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void solution() {

        int[] oddNumbers = Arrays.stream(a).filter(B::isOdd).sorted().toArray();
        int[] evenNumbers = Arrays.stream(a).filter(x->!isOdd(x)).sorted().toArray();

        int minLength = Integer.min(oddNumbers.length, evenNumbers.length);

        int[] maxLengthArray = oddNumbers.length > evenNumbers.length ? oddNumbers : evenNumbers;

        for (int i = 0; i < maxLengthArray.length - minLength - 1; i++) {
            answer += maxLengthArray[i];
        }


    }

    private static boolean isOdd(int x) {
        return x % 2 == 0;
    }

    private static void out() {
        System.out.println(answer);
    }

}
