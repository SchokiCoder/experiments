/* Copyright (c) 2023, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

#include <stdio.h>
#include <stdlib.h>

#define WORLD_MAX_X 80
#define WORLD_MAX_Y 24

struct World {
	long unsigned w, h;
	int fields[WORLD_MAX_X][WORLD_MAX_Y];
};

void copy_world(const struct World *out, struct World *in)
{
	long unsigned x, y;
	
	for (x = 0; x < out->w; x += 1) {
		for (y = 0; y < out->h; y += 1) {
			in->fields[x][y] = out->fields[x][y];
		}
	}
}

long unsigned
count_neighbors(const struct World *wld,
                long unsigned       x,
                long unsigned       y)
{
	long unsigned ret = 0;
	
	if (x > 0)
		if (wld->fields[x - 1][y])
			ret += 1;

	if (y > 0)
		if (wld->fields[x][y - 1])
			ret += 1;

	if (x < (wld->w - 1))
		if (wld->fields[x + 1][y])
			ret += 1;

	if (y < (wld->h - 1))
		if (wld->fields[x][y + 1])
			ret += 1;

	if (x > 0 && y > 0)
		if (wld->fields[x - 1][y - 1])
			ret += 1;

	if (x < (wld->w - 1) && y > 0)
		if (wld->fields[x + 1][y - 1])
			ret += 1;

	if (x > 0 && y < (wld->h - 1))
		if (wld->fields[x - 1][y + 1])
			ret += 1;

	if (x < (wld->w - 1) && y < (wld->h - 1))
		if (wld->fields[x + 1][y + 1])
			ret += 1;
	
	return ret;
}

void eval_world(struct World *wld)
{
	unsigned int neighbors;
	long unsigned x, y;
	struct World new_wld = {
		.w = wld->w,
		.h = wld->h
	};
	
	copy_world(wld, &new_wld);
	
	for (x = 0; x < wld->w; x += 1) {
		for (y = 0; y < wld->h; y += 1) {
			neighbors = count_neighbors(wld, x, y);

			if (neighbors == 3)
				new_wld.fields[x][y] = 1;
			else if (neighbors != 2)
				new_wld.fields[x][y] = 0;
		}
	}
	
	copy_world(&new_wld, wld);
}

int main(int argc, char *argv[])
{
	int active = 1;
	struct World wld = {
		.w = WORLD_MAX_X,
		.h = WORLD_MAX_Y
	};
	int is_x = 0;
	long unsigned i, x, y;
	
	for (x = 0; x < wld.w; x += 1) {
		for (y = 0; y < wld.h; y += 1) {
			wld.fields[x][y] = 0;
		}
	}
	
	for (i = 1; i < argc; i += 1) {
		if (is_x == 0) {
			x = strtoul(argv[i], NULL, 10);
			is_x = 1;
		} else {
			y = strtoul(argv[i], NULL, 10);
			wld.fields[x][y] = 1;
			is_x = 0;
		}
	}
	
	while (active) {
		for (y = 0; y < wld.h; y += 1) {
			printf("\n");
			
			for (x = 0; x < wld.w; x += 1) {
				if (wld.fields[x][y]) {
					printf("x");
				} else {
					printf(" ");
				}
			}
		}
		
		eval_world(&wld);
		
		switch (fgetc(stdin)) {
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
