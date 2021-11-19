package main
 
import (
	"bufio"
	"fmt"
	"os"
	"sort"
)
 
const (
	N_MIN = 1
	N_MAX = int(2 * 1e5)
	A_MIN = int(-1e9)
	A_MAX = int(1e9)
)
 
func max(a int, b int) int {
	if a < b {
		return b
	}
	return a
}
 
func test(array []int) int {
	maxFromMin := A_MIN
	sort.Ints(array)
	sum := 0
	for _, v := range array {
		//fmt.Println("test", v, sum, v-sum)
		maxFromMin = max(maxFromMin, v-sum)
		sum += v - sum
	}
	return maxFromMin
}
 
func main() {
	var t int
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &t)
	for i := 0; i < t; i++ {
		var length int
		fmt.Fscan(reader, &length)
		array := make([]int, length)
		for j := 0; j < length; j++ {
			fmt.Fscan(reader, &array[j])
		}
		fmt.Println(test(array))
	}
}

