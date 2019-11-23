package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

/* https://www.hackerrank.com/challenges/find-the-running-median/problem
 * Complete the runningMedian function below.
 * TODO: this could be solved following https://coder.today/tech/2017-10-13_fast-priority-queues-in-golang-hierarchical-heap/
 */

type heap struct {
	Value    int32
	Size     int32
	Previous *heap
	Next     *heap
}

func (h *heap) swap(j *heap) {
	tmp := h.Previous
	h.Next = j
	j.Previous = tmp
	j.Next = h
}

func emptyHeap() *heap {
	return &heap{
		Size: 0,
		Next: nil,
	}
}

func (h *heap) add(val int32) *heap {
	return &heap{
		Value: val,
		Size:  h.Size + 1,
		Next:  h,
	}
}

func median(min *heap, max *heap) float64 {

}

func runningMedian(a []int32) []float64 {
	/*
	 * Write your code here.
	 */
	var median float64
	minHeap := &heap{
		Size: 0,
		Next: nil,
	}
	maxHeap := &heap{}

}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

	stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
	checkError(err)

	defer stdout.Close()

	writer := bufio.NewWriterSize(stdout, 1024*1024)

	aCount, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)

	var a []int32

	for aItr := 0; aItr < int(aCount); aItr++ {
		aItemTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		aItem := int32(aItemTemp)
		a = append(a, aItem)
	}

	result := runningMedian(a)

	for resultItr, resultItem := range result {
		fmt.Fprintf(writer, "%f", resultItem)

		if resultItr != len(result)-1 {
			fmt.Fprintf(writer, "\n")
		}
	}

	fmt.Fprintf(writer, "\n")

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
