package main

import (
	"fmt"
)

type stack []int

/*
https://www.hackerrank.com/challenges/maximum-element/problem
wrong solution (too complex)
type solution struct {
	Size     int
	CurMax   int
	Stack    stack
	MaxStack stack
}

func (s solution) Push(i int) {
	if i > s.CurMax {
		s.CurMax = i
	}
	s.Stack = s.Stack.Push(i)
	s.MaxStack = s.MaxStack.Push(s.CurMax)
	s.Size++
}

func (s stack) Push(i int) stack {
	return append(s, i)
}

func (s stack) Pop(i int) (int, stack) {
	l := len(s)
	return s[l-1], s[:l-1]
}
*/

func main() {
	//Enter your code here. Read input from STDIN. Print output to STDOUT
	var l int
	fmt.Scanf("%d", &l)
	max := -1
	maxStack := []int{}
	size := 0

	for i := 0; i < int(l); i++ {
		var m, n int
		fmt.Scanf("%d %d", &m, &n)
		// fmt.Printf("%d %v\n", m, maxStack)
		switch m {
		case 1:
			if n > max {
				max = n
			}
			maxStack = append(maxStack, max)
			size++
		case 2:
			size--
			if size == 0 {
				maxStack = []int{}
				max = -1
			} else {
				maxStack = maxStack[:size]
				max = maxStack[size-1]
			}
		case 3:
			fmt.Println(max)
		}
	}
}
