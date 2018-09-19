package main

import (
	"fmt"
	"io/ioutil"
	"strings"
)

//cheak if error is an error
func check(e error) {
	if e != nil {
		panic(e)
	}
}

func main() {
	buf, err := ioutil.ReadFile("rosalind_grph.txt")
	check(err)
	data := strings.Split(string(buf), ">")[1:]

	labels := make([]string, 0)
	strs := make([]string, 0)

	for _, e := range data {
		e_arr := strings.Split(e, "\n")

		lb := e_arr[0]
		s := e_arr[1]
		for _, v := range e_arr[2:] {
			s = s + v
		}
		labels = append(labels, lb)
		strs = append(strs, s)
	}

	/* for i := range labels {
	 *      fmt.Printf("%s %s \n", labels[i], strs[i])
	 * }
	 * fmt.Println(labels)
	 * fmt.Println(strs)
	 */

	fmt.Printf(" >> %s %s \n", labels[2], strs[2])
	for i, e := range strs {
		for j, v := range strs[i:] {
			//if e != v {
			fmt.Printf("%s %s %s : %s %s %s \n", labels[i], e[len(e)-3:], e, labels[j], v[:3], v)
			//if e[len(e)-3:] == v[:3] {
			//	fmt.Printf("%s %s \n", labels[i], labels[j])
			//}
			//}
		}
	}
	fmt.Printf(" >> %s %s \n", labels[2], strs[2])
}
