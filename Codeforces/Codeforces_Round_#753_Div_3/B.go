package main
 
import "fmt"
 
const (
	T_MIN = 1
	T_MAX = int64(1e4)
	X_MIN = int64(-1e14)
	X_MAX = int64(1e14)
	N_MIN = 0
	N_MAX = int64(1e14)
)
 
func evenCase(x, n int64) int64 {
	n4 := n % 4
	switch n4 {
	case 0:
		return x
	case 1:
		return x - n
	case 2:
		return x + 1
	case 3:
		return x + n + 1
	}
	return 0
}
 
func oddCase(x, n int64) int64 {
	n4 := n % 4
	switch n4 {
	case 0:
		return x
	case 1:
		return x + n
	case 2:
		return x - 1
	case 3:
		return x - n - 1
	}
	return 0
}
 
func main() {
	var t int
	fmt.Scanf("%v\n", &t)
	for i := 0; i < t; i++ {
		var x, n int64
		fmt.Scanf("%v %v\n", &x, &n)
		if x&1 == 0 {
			fmt.Println(evenCase(x, n))
		} else {
			fmt.Println(oddCase(x, n))
		}
	}
}

