import java.util.Arrays;
import java.util.Scanner;

public class A {

    private static int n;
    private static int[] doors;
    private static int answer;

    public static void main(String[] args) {
        in();
        solution();
        out();
    }

    private static void in() {

        Scanner in = new Scanner(System.in);

        n = in.nextInt();
        doors = new int[n];

        for (int i = 0; i < n; i++) {
            doors[i] = in.nextInt();
        }

    }

    private static void solution() {

        int leftCount = 0, rightCount = 0;
        leftCount = (int) Arrays.stream(doors).filter((x)->x==0).count();
        rightCount = (int) Arrays.stream(doors).filter((x)->x==1).count();

        for (int i = 0; i < doors.length; i++) {
            leftCount -= doors[i] == 0? 1 : 0;
            rightCount -= doors[i] == 1? 1 : 0;

            if (leftCount == 0 || rightCount == 0) {
                answer = i + 1;
                break;
            }
        }

    }

    private static void out() {
        System.out.println(answer);
    }

}
