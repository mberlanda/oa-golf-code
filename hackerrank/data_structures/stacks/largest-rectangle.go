package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// https://www.hackerrank.com/challenges/largest-rectangle/problem

type area struct {
	H int32
	W int
}

func (a *area) c(j int) int32 {
	return a.H * int32(j-a.W)
}

type stack struct {
	Elements []area
	Size     int
}

func (s *stack) Push(x area) {
	s.Elements = append(s.Elements, x)
	s.Size++
}

func (s *stack) Pop() area {
	el := s.Elements[s.Size-1]
	s.Elements = s.Elements[:s.Size-1]
	s.Size--
	return el
}

func (s *stack) Top() area {
	return s.Elements[s.Size-1]
}

func (s *stack) Empty() bool {
	return s.Size == 0
}

func max(a, b int32) int32 {
	if a > b {
		return a
	}
	return b
}

func (s *stack) Solve(n, max_area int32, i, w int) int32 {
	if s.Empty() || s.Top().H <= n {
		if w > -1 {
			s.Push(area{n, w})
		} else {
			s.Push(area{n, i})
		}
		return max_area
	}
	p := s.Pop()
	max_area = max(p.c(i), max_area)
	return s.Solve(n, max_area, i, p.W)
}

// Complete the largestRectangle function below.
func largestRectangle(h []int32) int64 {
	s := stack{}
	var max_area int32
	max_area = -1
	hsize := 0
	s.Push(area{0, 0})

	for i, n := range h {
		if s.Empty() || n > s.Top().H {
			s.Push(area{n, i})
		} else {
			max_area = s.Solve(n, max_area, i, -1)
		}
		hsize++
	}
	for _, el := range s.Elements {
		max_area = max(max_area, el.c(hsize))
	}
	return int64(max_area)
}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

	stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
	checkError(err)

	defer stdout.Close()

	writer := bufio.NewWriterSize(stdout, 1024*1024)

	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)

	hTemp := strings.Split(readLine(reader), " ")

	var h []int32

	for i := 0; i < int(n); i++ {
		hItemTemp, err := strconv.ParseInt(hTemp[i], 10, 64)
		checkError(err)
		hItem := int32(hItemTemp)
		h = append(h, hItem)
	}

	result := largestRectangle(h)

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
