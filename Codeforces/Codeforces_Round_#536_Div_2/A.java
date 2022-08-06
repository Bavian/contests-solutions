package codeforces.round536.div2;

import java.util.Scanner;

import java.lang.ArrayIndexOutOfBoundsException;
import java.lang.StringIndexOutOfBoundsException;

public class A {

	public static void main(String[] args) {
		
		int n;
		String[] matrix;
		int result;

		//input

		Scanner in = new Scanner(System.in);
		n = in.nextInt();

		matrix = new String[n];

		for (int i = 0; i < n; i++) {
			matrix[i] = in.next();
		}

		//solution

		MatrixWithX matrixWithX = new MatrixWithX(matrix);
		result = matrixWithX.amountOfX();

		//output

		System.out.println(result);
	
	}

}

class MatrixWithX {

	private String[] matrix;

	MatrixWithX(String[] matrix) {
		this.matrix = matrix;
	}

	private boolean isLittleX(int i, int j) {

		try {
			return matrix[i].charAt(j) == 'X';
		} catch (ArrayIndexOutOfBoundsException | StringIndexOutOfBoundsException e) {
			return false;
		}

	}

	private boolean isBigX(int i, int j) {
		return	isLittleX(i, j) &&
				isLittleX(i - 1, j - 1) &&
				isLittleX(i - 1, j + 1) &&
				isLittleX(i + 1, j - 1) &&
				isLittleX(i + 1, j + 1);
	}

	int amountOfX() {

		int result = 0;
		for (int i = 0; i < matrix.length; i++) {
			
			for (int j = 0; j < matrix[i].length(); j++) {
				result += isBigX(i, j) ? 1 : 0;
			}

		}

		return result;
	}

}