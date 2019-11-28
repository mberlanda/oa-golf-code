package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

/*
 * Complete the equalStacks function below.
 * https://www.hackerrank.com/challenges/equal-stacks/problem
 */

type stack []int32

type solution struct {
	Stack stack
	Size  int32
	Sum   int32
}

func fromList(h []int32) solution {
	sol := solution{
		Stack: stack{},
		Size:  0,
		Sum:   0,
	}
	for _, n := range h {
		sol.Stack = sol.Stack.push(n)
		sol.Sum = sol.Sum + n
		sol.Size++
	}
	return sol
}

func (s stack) push(i int32) stack {
	return append(s, i)
}

// these functions is adapted to the
// way the data are passed to the problem
func (s stack) pop() (int32, stack) {
	return s[0], s[1:]
}

func (sol *solution) Decrease() int32 {
	l, s := sol.Stack.pop()
	sol.Size--
	sol.Stack = s
	sol.Sum = sol.Sum - l
	return sol.Sum
}

func recSolution(s1, s2, s3 solution) int32 {
	if s1.Size == 0 || s2.Size == 0 || s3.Size == 0 {
		return 0
	}
	if s1.Sum == s2.Sum && s2.Sum == s3.Sum {
		return s1.Sum
	}
	if s1.Sum > s2.Sum || s1.Sum > s3.Sum {
		s1.Decrease()
	}
	if s2.Sum > s1.Sum || s2.Sum > s3.Sum {
		s2.Decrease()
	}
	if s3.Sum > s1.Sum || s3.Sum > s2.Sum {
		s3.Decrease()
	}
	return recSolution(s1, s2, s3)
}

func equalStacks(h1 []int32, h2 []int32, h3 []int32) int32 {
	/*
	 * Write your code here.
	 */
	s1 := fromList(h1)
	s2 := fromList(h2)
	s3 := fromList(h3)

	fmt.Printf("%v\n", s1.Stack)
	fmt.Printf("%v\n", s2.Stack)
	fmt.Printf("%v\n", s3.Stack)

	return recSolution(s1, s2, s3)
}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

	stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
	checkError(err)

	defer stdout.Close()

	writer := bufio.NewWriterSize(stdout, 1024*1024)

	n1N2N3 := strings.Split(readLine(reader), " ")

	n1Temp, err := strconv.ParseInt(n1N2N3[0], 10, 64)
	checkError(err)
	n1 := int32(n1Temp)

	n2Temp, err := strconv.ParseInt(n1N2N3[1], 10, 64)
	checkError(err)
	n2 := int32(n2Temp)

	n3Temp, err := strconv.ParseInt(n1N2N3[2], 10, 64)
	checkError(err)
	n3 := int32(n3Temp)

	h1Temp := strings.Split(readLine(reader), " ")

	var h1 []int32

	for h1Itr := 0; h1Itr < int(n1); h1Itr++ {
		h1ItemTemp, err := strconv.ParseInt(h1Temp[h1Itr], 10, 64)
		checkError(err)
		h1Item := int32(h1ItemTemp)
		h1 = append(h1, h1Item)
	}

	h2Temp := strings.Split(readLine(reader), " ")

	var h2 []int32

	for h2Itr := 0; h2Itr < int(n2); h2Itr++ {
		h2ItemTemp, err := strconv.ParseInt(h2Temp[h2Itr], 10, 64)
		checkError(err)
		h2Item := int32(h2ItemTemp)
		h2 = append(h2, h2Item)
	}

	h3Temp := strings.Split(readLine(reader), " ")

	var h3 []int32

	for h3Itr := 0; h3Itr < int(n3); h3Itr++ {
		h3ItemTemp, err := strconv.ParseInt(h3Temp[h3Itr], 10, 64)
		checkError(err)
		h3Item := int32(h3ItemTemp)
		h3 = append(h3, h3Item)
	}

	result := equalStacks(h1, h2, h3)

	fmt.Fprintf(writer, "%d\n", result)

	writer.Flush()
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
	if err != nil {
		panic(err)
	}
}
