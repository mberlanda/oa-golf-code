package main

import (
	"fmt"
	"os"
)

// Global declarations

func assert(t bool, msg string){
	if (!t){
		fmt.Fprintf(os.Stderr, msg)
		os.Exit(1)
	}
}

type Node struct {
	Data int
	Left *Node
	Right *Node
}

func NewNode(data int) *Node {
	return &Node{
		Data: data,
		Left: nil,
		Right: nil,
	}
}

func (n *Node) Insert(data int) *Node {
	if (n == nil) {
		return NewNode(data)
	}
	if (data <= n.Data) {
		n.Left = n.Left.Insert(data)
	} else {
		n.Right = n.Right.Insert(data)
	}

	return n
}

// Problems
/* 1. build123()
      2
    /   \
   1     3
*/
func build123() *Node {
	var root *Node = nil

	root = root.Insert(2)
	root = root.Insert(1)
	root = root.Insert(3)

	return root
}

// 2. size()
func (n *Node) size() int {
	if (n == nil) {
		return 0
	}
	return n.Left.size() + 1 + n.Right.size()
}

// 3. maxDepth()
func max(a int, b int) int {
	if (a>b) {
		return a
	}
	return b
}

func (n *Node) maxDepth() int {
	if (n == nil){
		return 0
	}
	var lDepth, rDepth int
	lDepth = n.Left.maxDepth()
	rDepth = n.Right.maxDepth()

	return max(lDepth, rDepth) + 1
}

func main(){
	var n *Node = nil
	var m *Node = build123()
	// testSize
	assert(n.size() == 0, "Empty node has size 0\n")
	assert(m.size() == 3, "build123 node has size 3\n")
	// testMaxDepth
	assert(n.maxDepth() == 0, "Empty node has maxDepth 0\n")
	assert(m.maxDepth() == 2, "build123 node has maxDepth 2\n")
}