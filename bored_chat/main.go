// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright (C) 2024  Andy Frank Schoknecht

package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
	"strings"
)

const ReadMsgsDefaultNum = 10

func actionReadMessages(conn net.Conn, reader *bufio.Reader) {
	fmt.Printf("Print X amount of recent messages: [%v] ",
		ReadMsgsDefaultNum)
	//numMsgs := getInput(reader)
	// TODO: conn.Read(numMsgs)
}

func actionSendMessage(conn net.Conn, reader *bufio.Reader) {
	fmt.Printf("Type message, and send with enter:\n")
	//msg := getInput(reader)
	// TODO: conn.Send(msg)
}

func getInput(reader *bufio.Reader) string {
	s, err := reader.ReadString('\n')
	if err != nil {
		panic(err)
	}
	return s
}

func main() {
	var reader = bufio.NewReader(os.Stdout)

	conn, err := net.Dial("tcp", "127.0.0.1:82")
	if err != nil {
		panic(err)
	}
	defer conn.Close()

	mainloop:
	for {
		fmt.Printf(`Actions:
r:	Read messages
s:	Send a message
q:	Quit`)
		action := getInput(reader)
		action = strings.ToLower(action)
		switch action {
		case "r":
			actionReadMessages(conn, reader)

		case "s":
			actionSendMessage(conn, reader)

		case "q":
			break mainloop

		default:
			fmt.Printf("Invalid action requested.\n")
		}
	}
}
