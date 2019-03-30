package codeforces.round536.div2;

import java.util.Objects;
import java.util.Scanner;
import java.lang.Comparable;
import java.util.TreeSet;

import java.lang.NullPointerException;

public class B {

	private static int n, m;
	private static int[] a, c, t, d;
	private static long[] result;

	private static void in() {
		
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		m = in.nextInt();

		a = new int[n];
		c = new int[n];

		t = new int[m];
		d = new int[m];
		result = new long[m];

		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}

		for (int i = 0; i < n; i++) {
			c[i] = in.nextInt();
		}

		for (int i = 0; i < m; i++) {
			t[i] = in.nextInt();
			d[i] = in.nextInt();
			result[i] = 0;
		}

	}

	private static void solution() {

		Dish[] menu = new Dish[n];
		TreeSet<Dish> q = new TreeSet<>();

		for (int i = 0; i < n; i++) {
			menu[i] = new Dish(a[i], c[i], i);
			q.add(menu[i]);
		}

		for (int i = 0; i < m; i++) {

			Dish dish = menu[ t[i] - 1 ];
			int order = d[i];
			
			q.remove(dish);

			try {
				do {

					if (Objects.requireNonNull(dish).isOrderPossible(order)) {

						result[i] += dish.makeOrder(order);
						q.add(dish);
						order = 0;

					} else {

						order -= dish.getAmmount();
						result[i] += dish.makeOrder(dish.getAmmount());
					
						dish = q.pollFirst();

					}

				} while (order > 0);
			} catch (NullPointerException e) {
				result[i] = 0;
			}

			if (q.size() == 0) {
				break;
			}

		}

	}

	private static void out() {

		for (int i = 0; i < m; i++) {
			System.out.println(result[i]);
		}

	}

	public static void main(String[] args) {
		in();
		solution();
		out();
	}

}

class Dish implements Comparable<Dish> {

	private int a, c, number;
	
	Dish(int a, int c, int number) {
	
		this.a = a;
		this.c = c;
		this.number = number;

	}

	private int getNumber() {
		return number;
	}

	private int getPrice() {
		return c;
	}

	int getAmmount() {
		return a;
	}

	boolean isOrderPossible(int d) {
		return getAmmount() >= d;
	}

	long makeOrder(int d) {
		a -= d;
		return getPrice() * (long)d;
	}

	public int compareTo(Dish dish) {

		if (getNumber() == dish.getNumber()) {
			return 0;
		}

		if (getPrice() == dish.getPrice()) {
			return getNumber() < dish.getNumber() ? -1 : 1;
		}

		return getPrice() < dish.getPrice() ? -1 : 1;

	}
}