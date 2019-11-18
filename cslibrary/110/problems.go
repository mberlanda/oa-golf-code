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

/* 10. doubleTree()
    The tree...
       2
      / \
     1   3
    is changed to
          2
         / \
        2   3
       /   /
      1   3
     /
    1
*/

func (n *Node) doubleTree() {
	if (n == nil) { return }

	n.Left.doubleTree()
	n.Right.doubleTree()

	m := NewNode(n.Data)
	m.Left = n.Left
	n.Left = m
}

// 11. sameTree()
func sameTree(n *Node, m *Node) bool {
	if (n == nil && m == nil) { return true }
	if (n != nil && m != nil) {
		return n.Data == m.Data &&
			   sameTree(n.Left, m.Left) &&
			   sameTree(n.Right, m.Right)
	}
	return false
}

// 12. countTrees()
func countTrees(numKeys int) int {
	if (numKeys <= 1) { return 1 }
	sum := 0

	for i:= 1; i <= numKeys; i++ {
		left := countTrees(i - 1)
		right := countTrees(numKeys - i)

		sum += left * right
	}
	return sum
}

// 13. isBST()
func (n *Node) maxValue() *int {
	if (n == nil){
		return nil
	}
	if (n.Right != nil){
		return n.Right.maxValue()
	}
	return &n.Data
}

func isBST(n *Node) bool {
	if (n == nil) { return true }
	min := n.minValue()
	max := n.maxValue()

	if (min == nil || max == nil) {
		return false
	}

	if (n.Left != nil && *min > n.Data) { return false }
	if (n.Right != nil && *max <= n.Data) { return false }
	if (!isBST(n.Left) || !isBST(n.Right)) { return false }

	return true
}

// 14. isBST2()
func isBSTRec(n *Node, min int, max int) bool {
	if (n == nil) { return true }
	if (n.Data < min || n.Data > max) { return false }

	return isBSTRec(n.Left, min, n.Data) && isBSTRec(n.Right, n.Data+1, max)
}

func isBST2(n *Node) bool {
	// https://stackoverflow.com/a/6878625
	maxInt := int(^uint(0) >> 1)
	minInt := -maxInt - 1
	return isBSTRec(n, minInt, maxInt)
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
	// testDoubleTree
	d := build123()
	assert(fmt.Sprintf("%v ", treeArray(d)) == "[1 2 3] ", "d node has the given elems\n")
	d.doubleTree()
	assert(fmt.Sprintf("%v ", treeArray(d)) == "[1 1 2 2 3 3] ", "d node has the given elems after duplication\n")
	// testSameTree
	assert(sameTree(a, a), "a and m are the same tree\n")
	assert(sameTree(nil, nil), "nil and nil are the same tree\n")
	assert(!sameTree(nil, a), "nil and a are not the same tree\n")
	assert(!sameTree(a, d), "a and d are not the same tree\n")
	// testCountTrees
	assert(countTrees(0) == 1, "1 tree our of 0 numKeys\n")
	assert(countTrees(1) == 1, "1 tree our of 1 numKeys\n")
	assert(countTrees(2) == 2, "2 trees our of 2 numKeys\n")
	assert(countTrees(3) == 5, "5 trees our of 3 numKeys\n")
	assert(countTrees(4) == 14, "4 trees our of 14 numKeys\n")
	// testIsBST
	x := build123()
	y := build123()
	y.Left = NewNode(999)

	assert(isBST(nil), "nil isBST\n")
	assert(isBST2(nil), "nil isBST2\n")
	assert(isBST(x), "x isBST\n")
	assert(isBST2(x), "x isBST2\n")
	assert(!isBST(y), "y !isBST\n")
	assert(!isBST2(y), "y !isBST2\n")
}