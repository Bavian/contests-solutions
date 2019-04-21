import java.util.ArrayList;
import java.util.Collection;
import java.util.LinkedList;
import java.util.Scanner;

public class D {

    private static int n;
    private static String a, b;

    private static ArrayList<LinkedList<Integer>> leftBoots = new ArrayList<>();
    private static ArrayList<LinkedList<Integer>> rightBoots = new ArrayList<>();

    private static Collection<Pair> answer;

    public static void main(String[] args) {
        in();
        solution();
        out();
    }

    private static void in() {

        Scanner in = new Scanner(System.in);

        n = in.nextInt();

        a = in.next().replace('?', (char) ('z' + 1));
        b = in.next().replace('?', (char) ('z' + 1));

    }

    private static void solution() {

        leftBoots = new ArrayList<>();
        rightBoots = new ArrayList<>();

        for (char i = 0; i <= 'z' - 'a'; i++) {
            leftBoots.add(new LinkedList<>());
            rightBoots.add(new LinkedList<>());
        }

        leftBoots.add(new LinkedList<>());
        rightBoots.add(new LinkedList<>());

        for (int i = 0; i < a.length(); i++) {
            leftBoots.get(a.charAt(i) - 'a').add(i + 1);
        }

        for (int i = 0; i < b.length(); i++) {
            rightBoots.get(b.charAt(i) - 'a').add(i + 1);
        }

        answer = new ArrayList<Pair>();

        for (char i = 0; i <= 'z' - 'a'; i++) {
            makePairs(i, i);
        }

        char multiColor = 'z' - 'a' + 1;

        for (char i = 0; i <= 'z' - 'a'; i++) {
            makePairs(multiColor, i);
            makePairs(i, multiColor);
        }

        makePairs(multiColor, multiColor);

    }

    private static void makePairs(char leftColor, char rightColor) {

        while (leftBoots.get(leftColor).size() > 0 && rightBoots.get(rightColor).size() > 0) {

            LinkedList<Integer> left = leftBoots.get(leftColor);
            LinkedList<Integer> right = rightBoots.get(rightColor);

            answer.add(new Pair(left.getFirst(), right.getFirst()));

            left.removeFirst();
            right.removeFirst();

        }

    }

    private static void out() {

        System.out.println(answer.size());

        for (Pair pair : answer) {
            System.out.println(pair.getLeft() + " " + pair.getRight() );
        }

    }

}

class Pair {

    private int left, right;

    Pair(int left, int right) {
        this.left = left;
        this.right = right;
    }

    int getRight() {
        return right;
    }

    int getLeft() {
        return left;
    }

}

