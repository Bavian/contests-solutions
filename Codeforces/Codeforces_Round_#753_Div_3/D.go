package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const (
	T_MIN      = 1
	T_MAX      = int(1e4)
	N_MIN      = 1
	N_MAX      = int(2 * 1e5)
	A_MIN      = int(-1e9)
	A_MAX      = int(1e9)
	DIFF_MAX   = A_MAX - A_MIN + 1
	ANSWER_NO  = "NO"
	ANSWER_YES = "YES"
	COLOR_BLUE = 'B'
	COLOR_RED  = 'R'
)

func diff(a int, b int) (result int) {
	result = a - b
	if result < 0 {
		result = -result
	}
	return
}

func test(n int, array []int, colors string) bool {
	arrayLength := len(array)
	blues := make([]int, 0, arrayLength)
	reds := make([]int, 0, arrayLength)

	for index, color := range colors {
		switch color {
		case COLOR_BLUE:
			blues = append(blues, array[index])
		case COLOR_RED:
			reds = append(reds, array[index])
		}
	}

	sort.Ints(blues)
	sort.Ints(reds)
	for i := 1; i <= n; i++ {
		diffToBlue := DIFF_MAX
		if len(blues) > 0 {
			diffToBlue = blues[0] - i
		}

		diffToRed := DIFF_MAX
		if len(reds) > 0 {
			diffToRed = i - reds[0]
		}

		if diffToBlue >= 0 && diffToBlue != DIFF_MAX {
			blues = blues[1:]
		} else if diffToRed >= 0 && diffToRed != DIFF_MAX {
			reds = reds[1:]
		} else {
			return false
		}
	}

	return true
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(reader, &t)
	for i := 0; i < t; i++ {
		var n int
		fmt.Fscan(reader, &n)

		var array = make([]int, n)
		var colors string
		for j := 0; j < n; j++ {
			fmt.Fscan(reader, &array[j])
		}
		fmt.Fscan(reader, &colors)

		result := test(n, array, colors)
		if result {
			fmt.Println(ANSWER_YES)
		} else {
			fmt.Println(ANSWER_NO)
		}
	}
}
