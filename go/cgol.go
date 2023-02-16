/* Copyright (c) 2023, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

package main

import "fmt"

const WORLD_MAX_X uint = 80
const WORLD_MAX_Y uint = 24

type World struct {
	w, h uint
	fields[WORLD_MAX_X][WORLD_MAX_Y] bool
};

func copy_world(out World) (ret World) {
	var x, y uint
	
	for x = 0; x < out.w; x += 1 {
		for y = 0; y < out.h; y += 1 {
			ret.fields[x][y] = out.fields[x][y];
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
	var new_wld World = World {
		w: wld.w,
		h: wld.h,
	}
	
	copy_world(wld, &new_wld);
	
	for x = 0; x < wld.w; x += 1 {
		for y = 0; y < wld.h; y += 1 {
			neighbors = count_neighbors(wld, x, y)

			if neighbors == 3 {
				new_wld.fields[x][y] = 1
			} else if neighbors != 2 {
				new_wld.fields[x][y] = 0
			}
		}
	}
	
	copy_world(&new_wld, wld)
}

func main(argc int, argv []string) int {
	var active bool = true;
	var wld World = World {
		w: WORLD_MAX_X,
		h: WORLD_MAX_Y,
	};
	var is_x bool = false;
	var i, x, y uint;
	
	for x = 0; x < wld.w; x += 1 {
		for y = 0; y < wld.h; y += 1 {
			wld.fields[x][y] = false;
		}
	}
	
	for i = 1; i < argc; i += 1 {
		if is_x == 0 {
			x = strtoul(argv[i], NULL, 10);
			is_x = 1;
		} else {
			y = strtoul(argv[i], NULL, 10);
			wld.fields[x][y] = 1;
			is_x = 0;
		}
	}
	
	for active {
		for y = 0; y < wld.h; y += 1 {
			printf("\n");
			
			for x = 0; x < wld.w; x += 1 {
				if wld.fields[x][y] {
					printf("x");
				} else {
					printf(" ");
				}
			}
		}
		
		eval_world(&wld);
		
		switch fgetc(stdin) {
		case 'q':
			active = 0;
			break;
		
		case EOF:
			active = 0;
			fprintf(stderr, "Error end of input\n");
			break;
		}
	}
	
	return 0;
}
