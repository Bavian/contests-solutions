package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	T_MIN        = 1
	T_MAX        = int(1e4)
	N_MIN        = 1
	N_MAX        = int(1e6)
	M_MIN        = 1
	M_MAX        = int(1e6)
	S_LENGTH_MIN = 1
	S_LENGTH_MAX = int(1e6)
	LEFT         = 'L'
	UP           = 'U'
	RIGHT        = 'R'
	DOWN         = 'D'
)

var inputFile = os.Stdin
var outputFile = os.Stdout

var t int
var n, m [T_MAX]int
var s [T_MAX]string
var r, c [T_MAX]int

func in() {
	reader := bufio.NewReader(inputFile)
	fmt.Fscan(reader, &t)
	for i := 0; i < t; i++ {
		fmt.Fscan(reader, &n[i], &m[i], &s[i])
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solution(i int) {
	c[i] = 1
	r[i] = 1

	var left, up, right, down int
	var vertical, horizontal int
	for _, direction := range s[i] {
		switch direction {
		case LEFT:
			horizontal--
		case UP:
			vertical++
		case RIGHT:
			horizontal++
		case DOWN:
			vertical--
		}
		left = max(left, -horizontal)
		up = max(up, vertical)
		right = max(right, horizontal)
		down = max(down, -vertical)

		if left+right >= m[i] || up+down >= n[i] {
			return
		}

		c[i] = left + 1
		r[i] = up + 1
	}
	return
}

func out() {
	writer := bufio.NewWriter(outputFile)
	for i := 0; i < t; i++ {
		fmt.Fprintln(writer, r[i], c[i])
	}
	writer.Flush()
}

func main() {
	in()
	for i := 0; i < t; i++ {
		solution(i)
	}
	out()
}
