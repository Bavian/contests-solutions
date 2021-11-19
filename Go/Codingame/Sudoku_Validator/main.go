package main

import "fmt"

// CONSTANTS

const N = 9
const SUB_TABLE_SIZE = 3
const COLLECTED_VALUE = 1 << N - 1

// STRUCTS

type Condition struct {
	storage int16
}

func (this *Condition) turnOn(index int8) {
	this.storage |= 1 << index
}

func (this *Condition) isTurnedOn(index int) bool {
	return this.storage & (1 << index) > 0
}

func (this *Condition) isCollected() bool {
	return this.storage == COLLECTED_VALUE
}

// GLOBAL VARIABLES

var sudoku [N][N]int8
var answer bool = true

// INPUT

func in() {
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			fmt.Scan(&sudoku[i][j])
		}
	}
}

// SOLUTION

func checkRows() {
	for i := 0; i < N; i++ {
		used := Condition{0}
		for j := 0; j < N; j++ {
			used.turnOn(sudoku[i][j] - 1)
		}
		answer = answer && used.isCollected()
	}
}

func checkColumns() {
	for j := 0; j < N; j++ {
		used := Condition{0}
		for i := 0; i < N; i++ {
			used.turnOn(sudoku[i][j] - 1)
		}
		answer = answer && used.isCollected()
	}
}

func checkSubTable(i, j int) bool {
	used := Condition{0}
	for subI := i; subI < i + SUB_TABLE_SIZE; subI++ {
		for subJ := j; subJ < j + SUB_TABLE_SIZE; subJ++ {
			used.turnOn(sudoku[subI][subJ] - 1)
		}
	}
	return used.isCollected()
}

func checkSubTables() {
	for i := 0; i < N; i += SUB_TABLE_SIZE {
		for j := 0; j < N; j += SUB_TABLE_SIZE {
			answer = answer && checkSubTable(i, j)
		}
	}
}

func solution() {
	checkRows()
	checkColumns()
	checkSubTables()
}

// OUTPUT

func out() {
	fmt.Println(answer)
}

func main() {
	in()
	solution()
	out()
}

