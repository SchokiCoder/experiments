// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright (C) 2024  Andy Frank Schoknecht

package main

import (
	"net"
	"os"
)

func handleArgs() (string, *os.File) {
	var err error
	var file *os.File
	var filepath, ip string

	if len(os.Args) < 3 {
		panic("Not enough arguments given.")
	}

	ip = os.Args[1]
	filepath = os.Args[2]

	file, err = os.Create(filepath)
	if err != nil {
		panic(err)
	}

	return ip, file
}

func main() {
	var buf []byte
	var conn net.Conn
	var err error
	var file *os.File
	var ip string

	ip, file = handleArgs()
	defer file.Close()	

	conn, err = net.Dial("udp", ip)
	if err != nil {
		panic(err)
	}
	defer conn.Close()

	for {
		_, err = conn.Read(buf)
		if err != nil {
			panic(err)
		}

		if len(buf) != 0 {
			file.Write(append(buf, '\n'))
		}
	}
}
