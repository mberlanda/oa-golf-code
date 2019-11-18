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

// Node basic data structure
type Node struct {
	Data int
	Left *Node
	Right *Node
}

// NewNode create a new node reference
func NewNode(data int) *Node {
	return &Node{
		Data: data,
		Left: nil,
		Right: nil,
	}
}

// Insert add data into a BST
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
	var root *Node

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

// 4. minValue()
func (n *Node) minValue() *int {
	if (n == nil){
		return nil
	}
	if (n.Left != nil){
		return n.Left.minValue()
	}
	return &n.Data
}

/* 5. printTree()
    The tree...
        4
       / \
      2   5
     / \
    1   3
    Produces the output "1 2 3 4 5"
*/
func (n *Node) printTree() {
	if (n == nil){ return }

	n.Left.printTree()
	fmt.Printf("%d ", n.Data)
	n.Right.printTree()
}

/* 6. printPostorder()
    The tree...
        4
       / \
      2   5
     / \
    1   3
    Produces the output "1 3 2 5 4"
*/

func (n *Node) printPostOrder() {
	if (n == nil){ return }

	n.Left.printPostOrder()
	n.Right.printPostOrder()
	fmt.Printf("%d ", n.Data)
}

// 7. hasPathSum()
func (n *Node) hasPathSum(sum int) bool {
	if (n == nil){ return sum == 0 }

	return n.Left.hasPathSum(sum - n.Data) || n.Right.hasPathSum(sum - n.Data)
}

// 8. printPaths()
func printPathsRecur(n *Node, path []int, pathLen int) {
	if (n == nil) { return }

	newPath := make([]int, pathLen+1)
	copy(newPath, path)
	newPath[pathLen] = n.Data
	pathLen += 1

	if (n.Left == nil && n.Right == nil){
		fmt.Printf("%v\n", newPath)
	}

	printPathsRecur(n.Left, newPath, pathLen)
	printPathsRecur(n.Right, newPath, pathLen)
}

func (n *Node) printPaths() {
	path := []int{}
	printPathsRecur(n, path, 0)
}

/* 9. mirror()
    The tree...
        4
       / \
      2   5
     / \
    1   3
    is changed to
        4
       / \
      5   2
         / \
        3   1
*/

func (n *Node) mirror() {
	if (n == nil) { return }

	n.Left.mirror()
	n.Right.mirror()

	lChild := n.Left
	n.Left = n.Right
	n.Right = lChild
}

func treeArray(n *Node) []int{
	if (n == nil) { return []int{} }

	return append(
		append(treeArray(n.Left), n.Data),
		treeArray(n.Right)...
	)
}

func main(){
	var n *Node
	m := build123()
	// testSize
	assert(n.size() == 0, "Empty node has size 0\n")
	assert(m.size() == 3, "build123 node has size 3\n")
	// testMaxDepth
	assert(n.maxDepth() == 0, "Empty node has maxDepth 0\n")
	assert(m.maxDepth() == 2, "build123 node has maxDepth 2\n")
	// testMinValue
	assert(n.minValue() == nil, "Empty node has minValue nil\n")
	assert(*m.minValue() == 1, "build123 node has minValue 1\n")
	// testPrintTree
	t := &Node{
		Data: 4,
		Left: m,
		Right: NewNode(5),
	}
	fmt.Println("Test printTree:")
	n.printTree()
	fmt.Println()
	m.printTree()
	fmt.Println()
	t.printTree()
	fmt.Println()
	// testPrintPostOrder
	fmt.Println("Test printPostOrder:")
	n.printPostOrder()
	fmt.Println()
	m.printPostOrder()
	fmt.Println()
	t.printPostOrder()
	fmt.Println()
	// testHasPathSum
	assert(n.hasPathSum(0), "Empty node hasPathSum 0\n")
	assert(!n.hasPathSum(1), "Empty node not hasPathSum 1\n")
	assert(m.hasPathSum(3), "build123 node hasPathSum 3\n")
	assert(m.hasPathSum(5), "build123 node hasPathSum 5\n")
	assert(!m.hasPathSum(4), "build123 node not hasPathSum 4\n")
	// testPrintPaths
	fmt.Println("Test printPaths:")
	n.printPaths()
	m.printPaths()
	t.printPaths()
	// testMirror
	a := build123()
	b := build123()
	b.mirror()
	assert(fmt.Sprintf("%v ", treeArray(a)) == "[1 2 3] ", "a node has the given elems\n")
	assert(fmt.Sprintf("%v ", treeArray(b)) == "[3 2 1] ", "b node has the given elems\n")
}