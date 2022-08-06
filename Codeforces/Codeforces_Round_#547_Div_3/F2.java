import java.util.*;

public class F2 {

    private static int n;
    private static int[] a;

    private static Collection<Segment> answer;

    public static void main(String[] args) {
        in();
        solution();
        out();
    }

    private static void in() {

        Scanner in = new Scanner(System.in);

        n = in.nextInt();

        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }

    }

    private static void solution() {

        HashMap<Long, LinkedList<Segment>> segments = new HashMap<>();

        for (int i = 0; i < n; i++) {

            long sum = 0;

            for (int j = i; j < n; j++) {

                sum += a[j];

                if (segments.containsKey(sum)) {
                    segments.get(sum).add(new Segment(i, j));
                } else {
                    LinkedList<Segment> toPut = new LinkedList<>();
                    toPut.add(new Segment(i, j));
                    segments.put(sum, toPut);
                }

            }

        }

        answer = null;
        for (Map.Entry<Long, LinkedList<Segment>> sums : segments.entrySet()) {


            LinkedList<Segment> currentSegments = sums.getValue();
            Collections.sort(currentSegments);

            LinkedList<Segment> segmentsWithoutCrossing = new LinkedList<>();

            for (Segment segment : currentSegments) {


                if ( segmentsWithoutCrossing.isEmpty() || !segmentsWithoutCrossing.getLast().isCrossingToNextSegment(segment)) {

                    segmentsWithoutCrossing.add(segment);

                } else if (segmentsWithoutCrossing.getLast().getR() > segment.getR()) {

                    segmentsWithoutCrossing.removeLast();
                    segmentsWithoutCrossing.add(segment);

                }

            }

            answer = segmentsWithoutCrossing.size() > (answer != null ? answer.size() : 0) ? segmentsWithoutCrossing : answer;

        }

    }

    private static void out() {

        System.out.println(answer.size());

        for (Segment segment : answer) {
            System.out.println( (segment.getL() + 1) + " " + (segment.getR() + 1));
        }

    }

}

class Segment implements Comparable<Segment>{

    private int l, r;

    Segment(int l, int r) {
        this.l = l;
        this.r = r;
    }


    int getL() {
        return l;
    }

    int getR() {
        return r;
    }

    @Override
    public int compareTo(Segment segment) {

        if (l == segment.l && r == segment.r) {
            return 0;
        }

        return l != segment.l ? l - segment.l : r - segment.r;

    }

    boolean isCrossingToNextSegment(Segment segment) {
        if (l == segment.l || r == segment.r) {
            return true;
        } else if (l < segment.l) {
            return r >= segment.l;
        } else if (r > segment.r) {
            return l <= segment.r;
        } else {
            return true;
        }
    }

}