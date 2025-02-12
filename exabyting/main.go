package main

import (
	"fmt"
	"sort"
	"strings"
)

func reverseString(s string) string {
	runes := []rune(s)
	n := len(runes)

	for i := 0; i < n/2; i++ {
		runes[i], runes[n-1-i] = runes[n-1-i], runes[i]

	}

	return string(runes)
}

func palindrome(s string) bool {
	runes := []rune(s)
	n := len(runes)
	verdict := false

	for i := 0; i < n/2; i++ {
		runes[i], runes[n-1-i] = runes[n-1-i], runes[i]
	}

	if string(runes) == s {
		verdict = true
	}

	return verdict
}

func anagram(s1, s2 string) string {
	verdict := "no"
	chars1 := strings.Split(s1, "")
	sort.Strings(chars1)
	var1 := strings.Join(chars1, "")

	char2 := strings.Split(s2, "")
	sort.Strings(char2)
	var2 := strings.Join(char2, "")

	if var1 == var2 {
		verdict = "yes"
	}
	return verdict
}

//go-routine

func add(a, b int, resultChan chan int) {
	resultChan <- a + b
}

func multi(a, b int, resultChan chan int) {
	resultChan <- a * b
}

func main() {
	// fmt.Println(reverseString("hello"))
	// fmt.Println(palindrome("anaa"))
	// fmt.Println(anagram("asd", "dssa"))

	resultChan := make(chan int, 2)

	a, b := 5, 3

	go add(a, b, resultChan)
	go multi(a, b, resultChan)

	addResult := <-resultChan
	multiResult := <-resultChan

	fmt.Println(addResult)
	fmt.Println(multiResult)

}
