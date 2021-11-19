package main

import "fmt"

const N_MIN = 0
const N_MAX = 1500
const S_MIN = 0
const S_MAX = 1 << 32 -1 

func solution(n int) {
    sum := 0
	start := 1
	nSquare := n * n
	for step := n - 1; step > 0; step -= 2 {
		//fmt.Printf("step = %v\tsum = %v\n", step, sum)
		sum += start * 4 + step * 6
		start += step * 4
		//fmt.Println(start)
	}

	if (n % 2 != 0) {
		sum += nSquare
	}

	fmt.Println(sum)
}

func main() {
	var n int
    fmt.Scan(&n)
    solution(n)
	//solution(4)
}


/*
1	2	3	4	5
16	17	18	19	6
15	24	25	20	7
14	23	22	21	8
13	12	11	10	9
*/

