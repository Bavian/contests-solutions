import java.util.Scanner;

import static java.lang.Integer.parseInt;

public class A {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        String[] time1 = in.nextLine().split(":");
        String[] time2 = in.nextLine().split(":");

        int     hour1 = parseInt(time1[0]),
                minute1 = parseInt(time1[1]),
                hour2 = parseInt(time2[0]),
                minute2 = parseInt(time2[1]);

        int answer = ( toMinute(hour1, minute1) + toMinute(hour2, minute2) ) / 2;

        System.out.println( normalize(answer / 60) + ":" + normalize(answer % 60) );

    }

    private static int toMinute(int hour, int minute) {
        return hour * 60 + minute;
    }

    private static String normalize(int x) {
        return x < 10 ? "0" + x : String.valueOf(x);
    }

}
