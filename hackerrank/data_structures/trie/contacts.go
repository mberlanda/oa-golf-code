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
 * Complete the contacts function below.
 */

const numberOfCharacters = 26

type trie struct {
	Children map[rune]*trie
	Count    int32
	Name     string
}

func newTrie(v string) *trie {
	return &trie{
		Children: make(map[rune]*trie, numberOfCharacters),
		Count:    0,
		Name:     v,
	}
}

func (t *trie) add(str string) {
	current := t
	v := ""
	for _, s := range str {
		v := v + string(s)
		if current.Children[s] == nil {
			current.Children[s] = newTrie(v)
		}
		current = current.Children[s]
		current.Count++
	}
}

func (t *trie) find(str string) int32 {
	current := t
	for _, s := range str {
		if current.Children[s] == nil {
			return 0
		}
		current = current.Children[s]
	}
	return current.Count
}

func contacts(queries [][]string) []int32 {
	/*
	 * Write your code here.
	 */
	root := newTrie("")
	result := []int32{}
	for _, query := range queries {
		if query[0] == "add" {
			// fmt.Printf("Adding %s\n", query[1])
			root.add(query[1])
		}
		if query[0] == "find" {
			// fmt.Printf("Finding %s\n", query[1])
			result = append(result, root.find(query[1]))
		}
		// fmt.Println(query)
	}
	return result
}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

	stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
	checkError(err)

	defer stdout.Close()

	writer := bufio.NewWriterSize(stdout, 1024*1024)

	queriesRows, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)

	var queries [][]string
	for queriesRowItr := 0; queriesRowItr < int(queriesRows); queriesRowItr++ {
		queriesRowTemp := strings.Split(readLine(reader), " ")

		var queriesRow []string
		for _, queriesRowItem := range queriesRowTemp {
			queriesRow = append(queriesRow, queriesRowItem)
		}

		if len(queriesRow) != int(2) {
			panic("Bad input")
		}

		queries = append(queries, queriesRow)
	}

	result := contacts(queries)

	for resultItr, resultItem := range result {
		fmt.Fprintf(writer, "%d", resultItem)

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
