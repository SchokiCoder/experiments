/* Copyright (c) 2023, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

package main

import ("fmt"; "os"; "strconv")

const WORLD_MAX_X uint = 80
const WORLD_MAX_Y uint = 24

type World struct {
	w, h uint
	fields[WORLD_MAX_X][WORLD_MAX_Y] bool
};

func copy_world(src World) (ret World) {
	var x, y uint
	
	ret.w = src.w
	ret.h = src.h
	
	for x = 0; x < src.w; x += 1 {
		for y = 0; y < src.h; y += 1 {
			ret.fields[x][y] = src.fields[x][y]
		}
	}
	
	return;
}

func count_neighbors(wld World, x, y uint) (ret uint) {
	if x > 0 {
		if wld.fields[x - 1][y] {
			ret += 1
		}
	}

	if y > 0 {
		if wld.fields[x][y - 1] {
			ret += 1
		}
	}

	if x < (wld.w - 1) {
		if wld.fields[x + 1][y] {
			ret += 1
		}
	}

	if y < (wld.h - 1) {
		if wld.fields[x][y + 1] {
			ret += 1
		}
	}

	if x > 0 && y > 0 {
		if wld.fields[x - 1][y - 1] {
			ret += 1
		}
	}

	if x < (wld.w - 1) && y > 0 {
		if wld.fields[x + 1][y - 1] {
			ret += 1
		}
	}

	if x > 0 && y < (wld.h - 1) {
		if wld.fields[x - 1][y + 1] {
			ret += 1
		}
	}

	if x < (wld.w - 1) && y < (wld.h - 1) {
		if wld.fields[x + 1][y + 1] {
			ret += 1
		}
	}
	
	return
}

func eval_world(wld *World) {
	var neighbors uint
	var x, y uint
	var new_wld World;
	
	new_wld = copy_world(*wld)
	
	for x = 0; x < wld.w; x += 1 {
		for y = 0; y < wld.h; y += 1 {
			neighbors = count_neighbors(*wld, x, y)

			if neighbors == 3 {
				new_wld.fields[x][y] = true
			} else if neighbors != 2 {
				new_wld.fields[x][y] = false
			}
		}
	}
	
	*wld = copy_world(new_wld)
}

func main() {
	var active bool = true
	var wld World = World {
		w: WORLD_MAX_X,
		h: WORLD_MAX_Y,
	}
	var is_x bool = false
	var x, y uint
	var conv uint64
	var err error
	var i int
	
	for x = 0; x < wld.w; x += 1 {
		for y = 0; y < wld.h; y += 1 {
			wld.fields[x][y] = false
		}
	}
	
	for i = 0; i < len(os.Args); i += 1 {
		if is_x == false {
			conv, err = strconv.ParseUint(os.Args[i], 10, 32)
			x = (uint) (conv)
			is_x = true
		} else {
			conv, err = strconv.ParseUint(os.Args[i], 10, 32)
			y = (uint) (conv)
			is_x = false
		}
		
		if err != nil {
			is_x = false
		} else if is_x {
			wld.fields[x][y] = true
		}
	}
	
	for active {
		for y = 0; y < wld.h; y += 1 {
			fmt.Print("\n")
			
			for x = 0; x < wld.w; x += 1 {
				if wld.fields[x][y] {
					fmt.Print("x")
				} else {
					fmt.Print(" ")
				}
			}
		}
		
		eval_world(&wld);
		
		switch fgetc(stdin) {
		case 'q':
			active = false
			break
		
		case EOF:
			active = false;
			fprintf(stderr, "Error end of input\n")
			break
		}
	}
}
