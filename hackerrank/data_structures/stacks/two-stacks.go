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
 * Complete the twoStacks function below.
 * https://www.hackerrank.com/challenges/game-of-two-stacks/problem
 */

type stack struct {
	Elements []int32
	Size     int
}

func (s *stack) Push(x int32) {
	s.Elements = append(s.Elements, x)
	s.Size++
}

func (s *stack) Pop() int32 {
	el := s.Elements[s.Size-1]
	s.Elements = s.Elements[:s.Size-1]
	s.Size--
	return el
}

func (s *stack) Top() int32 {
	return s.Elements[s.Size-1]
}

func (s *stack) Empty() bool {
	return s.Size == 0
}

/*
func max(x, y int32) int32 {
	if x > y {
		return x
	}
	return y
}

func recurTwoStacks(m, sum, steps, x int32, a, b []int32, asize, bsize int) int32 {
	if sum+x > m {
		return steps
	}
	if asize > 0 && bsize > 0 {
		return max(
			recurTwoStacks(m, sum+x, steps+1, a[0], a[1:], b, asize-1, bsize),
			recurTwoStacks(m, sum+x, steps+1, b[0], b[1:], a, asize, bsize-1),
		)
	}
	if asize > 0 {
		return recurTwoStacks(m, sum+x, steps+1, a[0], a[1:], b, asize-1, 0)
	}
	if bsize > 0 {
		return recurTwoStacks(m, sum+x, steps+1, b[0], b[1:], a, 0, bsize-1)
	}

	return steps
}
*/

func coucou(sum, x int32, acc *stack) int32 {
	if sum <= x || acc.Empty() {
		return sum
	}
	sum = sum - acc.Pop()
	return coucou(sum, x, acc)
}

func twoStacks(x int32, a []int32, b []int32) int32 {
	/*
	 * Write your code here.
	 */
	/*
		 var sum, steps int32
		sum = 0
		steps = 0
		asize := len(a)
		bsize := len(b)

		return max(
			recurTwoStacks(x, sum, steps, a[0], a[1:], b, asize-1, bsize),
			recurTwoStacks(x, sum, steps, b[0], b[1:], a, asize, bsize-1),
		)
	*/
	var sum int32
	sum = 0
	acc := stack{
		Elements: []int32{},
		Size:     0,
	}

	for _, el := range a {
		if sum+el > x {
			break
		}
		sum = sum + el
		acc.Push(el)
	}

	count := acc.Size
	for j, el := range b {
		if acc.Size < 0 {
			break
		}
		sum = coucou(sum+el, x, &acc)
		if sum <= x && j+acc.Size >= count {
			count = j + acc.Size + 1
		}
	}
	return int32(count)
}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

	stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
	checkError(err)

	defer stdout.Close()

	writer := bufio.NewWriterSize(stdout, 1024*1024)

	gTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	g := int32(gTemp)

	for gItr := 0; gItr < int(g); gItr++ {
		nmx := strings.Split(readLine(reader), " ")

		nTemp, err := strconv.ParseInt(nmx[0], 10, 64)
		checkError(err)
		n := int32(nTemp)

		mTemp, err := strconv.ParseInt(nmx[1], 10, 64)
		checkError(err)
		m := int32(mTemp)

		xTemp, err := strconv.ParseInt(nmx[2], 10, 64)
		checkError(err)
		x := int32(xTemp)

		aTemp := strings.Split(readLine(reader), " ")

		var a []int32

		for aItr := 0; aItr < int(n); aItr++ {
			aItemTemp, err := strconv.ParseInt(aTemp[aItr], 10, 64)
			checkError(err)
			aItem := int32(aItemTemp)
			a = append(a, aItem)
		}

		bTemp := strings.Split(readLine(reader), " ")

		var b []int32

		for bItr := 0; bItr < int(m); bItr++ {
			bItemTemp, err := strconv.ParseInt(bTemp[bItr], 10, 64)
			checkError(err)
			bItem := int32(bItemTemp)
			b = append(b, bItem)
		}

		result := twoStacks(x, a, b)

		fmt.Fprintf(writer, "%d\n", result)
	}

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
