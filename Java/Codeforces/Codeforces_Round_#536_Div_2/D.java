package codeforces.round536.div2;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;

public class D {


    private static final int START = 1;

    private static int n, m;
    private static ArrayList< ArrayList<Integer> > graph;

    private static ArrayList<Integer> answer = new ArrayList<>();

    public static void main(String[] args) {
        in();
        solution();
        out();
    }

    private static void in() {

        Scanner in = new Scanner(System.in);

        n = in.nextInt();
        m = in.nextInt();

        graph = new ArrayList< ArrayList<Integer>>();

        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {

            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;

            graph.get(u).add(v);
            graph.get(v).add(u);

        }
    }

    private static void solution() {

        boolean[] used = new boolean[n];
        for (int i = 0; i < n; i++) {
            used[i] = false;
        }

        TreeSet<Integer> queue = new TreeSet<>();
        queue.add(START - 1);
        used[START - 1] = true;

        while (!queue.isEmpty()) {

            Integer element = queue.first();

            answer.add(element);

            for (Integer v : graph.get(element)) {
                if (!used[v]) {
                    used[v] = true;
                    queue.add(v);
                }
            }


            queue.remove(element);

        }

    }

    private static void out() {

        System.out.print(answer.get(0) + 1);
        for (int i = 1; i < answer.size(); i++) {
            System.out.print( " " + (answer.get(i) + 1) );
        }

    }

}
