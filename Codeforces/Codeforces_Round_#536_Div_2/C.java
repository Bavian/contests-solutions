package codeforces.round536.div2;

import java.util.Scanner;
import java.util.Arrays;

public class C {

	private static int n;
	private static int[] a;
	private static long result;

	private static void in() {

		Scanner in = new Scanner(System.in);

		n = in.nextInt();
		a = new int[n];

		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}

	}

	private static void solution() {
		
		Arrays.sort(a);

		for (int i = 0; i < n / 2; i++) {
			long sum = a[i] + a[n - i - 1];
			result += sum * sum;
		}

	}

	private static void out() {
		System.out.println(result);
	}

	public static void main(String[] args) {
		in();
		solution();
		out();
	}

}