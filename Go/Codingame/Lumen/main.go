package main

import "fmt"

// TYPES

type Point struct {
	y, x int
}

// CONSTANTS

const N_MIN = 0
const N_MAX = 25
const L_MIN = 0
const L_MAX = 10
const TABLE_CANDLE = 'C'
const TABLE_EMPTY = 'X'

// GLOBAL VARIABLES
var n, l int
var table [N_MAX][N_MAX]byte
var result int

// INPUT

func in() {
	fmt.Scanf("%v\n%v\n", &n, &l)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			var str string
			fmt.Scanf("%s", &str)
			table[i][j] = str[0]
		}
	}
}

// SOLUTION

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(r int) int {
	if r < 0 {
		return -r
	}
	return r
}

func findLights() []Point {
	lights := make([]Point, n * n)
	lightNumber := 0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if (table[i][j] == TABLE_CANDLE) {
				lights[lightNumber] = Point{i, j}
				lightNumber++
			}
		}
	}
	return lights[:lightNumber]
}

func findNearestLight(point Point, lights []Point) int {
	nearest := L_MAX + 1
	for _, light := range lights {
		dist := max(
			abs(point.x - light.x),
			abs(point.y - light.y),
		)
		nearest = min(nearest, dist)
	}
	return nearest
}

func solution() {
	lights := findLights()
	/*
	fmt.Println(len(lights))
	for _, light := range lights {
		fmt.Println(light)
	}
	*/
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			nearest := findNearestLight(Point{i, j}, lights)
			//fmt.Printf("%v\t", nearest)
			if (nearest >= l) {
				result++
			}
		}
		//fmt.Print("\n")
	}
}

// OUTPUT

func out() {
	fmt.Println(result)
}

// ENTRY POINT

func main() {
	in()
	solution()
	out()
}

