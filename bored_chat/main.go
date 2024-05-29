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

const (
	ReadMsgResponse = "BC"
	ReadMsgsDefaultNum = 10
	SendMsgMaxTries = 10
)

func actionReadMessages(conn net.Conn, reader *bufio.Reader) {
	fmt.Printf("Print X amount of recent messages: [%v]\n",
		ReadMsgsDefaultNum)
	//numMsgs := getInput(reader)
	// TODO: conn.Read(numMsgs)
}

func actionSendMessage(conn net.Conn, reader *bufio.Reader) {
	fmt.Printf("Type message, and send with enter:\n")
	msg := getInput(reader)

	for i := 0; i <= SendMsgMaxTries; i++ {
		var err error
		var response [10]byte

		_, err = conn.Write([]byte(msg))
		if err != nil {
			continue
		}

		_, err = conn.Read(response[:])
		if err != nil {
			continue
		}
		if string(response[:]) == ReadMsgResponse {
			break
		} else {
			continue
		}
	}
}

func getInput(reader *bufio.Reader) string {
	s, err := reader.ReadString('\n')
	if err != nil {
		panic(err)
	}
	return s
}

func listen(conn net.Conn) {
	var err error
	var msg []byte
	var msgsFile os.File

	msgsFile, err = os.CreateTemp("", "bc_messages")
	if err != nil {
		panic("Could not create a temp file for messages.")
	}
	defer os.Remove(tempFile.Name())

	for {
		_, err = conn.Read(msg)
		if err != nil {
			panic("Should this even panic?")
		}

		if msg {
			save to temp file

			conn.Send(ReadMsgResponse)
		}
	}
}

func main() {
	var action string
	var reader = bufio.NewReader(os.Stdout)

	conn, err := net.Dial("udp", "127.0.0.1:81")
	if err != nil {
		panic(err)
	}
	defer conn.Close()

	go listen()

	mainloop:
	for {
		fmt.Printf(`Actions:
r:	Read messages
s:	Send a message
q:	Quit
`)
		action = getInput(reader)
		action = strings.ToLower(action)
		switch action[0] {
		case 'r':
			actionReadMessages(conn, reader)

		case 's':
			actionSendMessage(conn, reader)

		case 'q':
			break mainloop

		default:
			fmt.Printf("Invalid action requested.\n")
		}
	}
}
