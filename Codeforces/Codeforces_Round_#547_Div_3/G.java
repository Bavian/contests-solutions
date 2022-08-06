import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class G {

    private static int n, k;
    private static Tree tree;

    private static int r;
    private static int[] c;

    public static void main(String[] args) throws IOException {
        in();
        solution();
        out();
    }

    private static void in() {

        Scanner in = new Scanner(System.in);

        n = in.nextInt();
        k = in.nextInt();

        tree = new Tree(n);
        c = new int[n];

        for (int i = 1; i < n; i++) {
            tree.addEdge(in.nextInt(), in.nextInt());
        }

    }

    private static void solution() {

        long[] sum = new long[n + 1];

        for (int i = 1; i <= n; i++) {
            sum[ tree.getAmountOfAdjacentVertices(i) ]++;
        }

        for (int i = n - 2; i > 0; i--) {
            sum[i] += sum[i + 1];
        }

        r = n - 1;
        while (sum[r] <= k) {
            r--;
        }

        tree.paint(r);

        for (int i = 0; i < n - 1; i++) {
            c[i] = tree.getColorOfEdge(i);
        }

    }

    private static void out() throws IOException {

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(r + "\n");

        for (int i = 0; i < n - 1; i++) {
            bw.write(c[i] + (i == n - 1 ? "\n" : " "));
        }

        bw.close();

    }

}

class Tree {

    private ArrayList<ArrayList<Pair<Integer, Integer>>> edges;
    private int amountOfEdges;
    private int[] edgesColors;

    Tree(int n) {

        edges = new ArrayList<>();
        edgesColors = new int[n - 1];
        amountOfEdges = 0;

        for (int i = 0; i < n; i++) {
            edges.add(new ArrayList<>());
        }

    }

    void addEdge(int a, int b) {

        edges.get(a - 1).add( new Pair<>(b - 1, amountOfEdges) );
        edges.get(b - 1).add( new Pair<>(a - 1, amountOfEdges) );

        amountOfEdges++;

    }

    int getAmountOfAdjacentVertices(int a) {
        return edges.get(a - 1).size();
    }

    void paint(int colors) {
        dfsPaintingEdges(0, colors,-1, -1);
    }

    private void dfsPaintingEdges(int vertex, int colors, int previousVertex, int lastColor) {

        int color = 0;
        for (int i = 0; i < edges.get(vertex).size(); i++) {

            if (previousVertex == edges.get(vertex).get(i).vertex) {
                continue;
            }

            if (color == lastColor) {

                lastColor = -1;
                color = (color + 1) % colors;

            }

            edgesColors[ edges.get(vertex).get(i).numberOfEdge ] = color + 1;

            dfsPaintingEdges( edges.get(vertex).get(i).vertex, colors, vertex, color);

            color = (color + 1) % colors;

        }

    }

    int getColorOfEdge(int i) {
        return edgesColors[i];
    }
}

class Pair<T1, T2> {

    T1 vertex;
    T2 numberOfEdge;

    Pair(T1 vertex, T2 numberOfEdge) {
        this.vertex = vertex;
        this.numberOfEdge = numberOfEdge;
    }

}
