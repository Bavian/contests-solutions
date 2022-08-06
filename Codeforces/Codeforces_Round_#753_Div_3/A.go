package main
 
import "fmt"
 
const (
	ALPHABET_SIZE = 26
	T_MIN         = 1
	T_MAX         = 1000
	WORD_MIN      = 1
	WORD_MAX      = 50
)
 
func calculateDistance(a int, b int) int {
	diff := a - b
	if diff < 0 {
		return -diff
	}
	return diff
}
 
func parseDictionary(alphabet *string) (dictionary []int) {
	dictionary = make([]int, ALPHABET_SIZE)
	for index, letter := range *alphabet {
		//fmt.Printf("parse: %v, %c\n", index, letter)
		dictionary[letter-'a'] = index
	}
	return
}
 
func test(alphabet *string, word *string) (result int) {
	dictionary := parseDictionary(alphabet)
	previousLetter := (*word)[0]
	for _, letter := range *word {
		//fmt.Printf("test: %v %c\n", letter, letter)
		result += calculateDistance(
			dictionary[previousLetter-'a'],
			dictionary[letter-'a'],
		)
		previousLetter = byte(letter)
	}
	return
}
 
func main() {
	var t int
	fmt.Scanf("%v\n", &t)
	//fmt.Printf("%v\n", t)
	for i := 0; i < t; i++ {
		var alphabet, word string
		fmt.Scanf("%s\n%s\n", &alphabet, &word)
		//fmt.Printf("%s\n%s\n", alphabet, word)
		fmt.Printf("%v\n", test(&alphabet, &word))
	}
}

