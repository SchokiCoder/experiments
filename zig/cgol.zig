// Copyright (c) 2023, Andy Frank Schoknecht
// Use of this source code is governed by the BSD-3-Clause
// license, that can be found in the LICENSE file.

const std = @import("std");

const WORLD_MAX_X = 80;
const WORLD_MAX_Y = 24;

const World = struct {
	w, h: u32,
	fields: bool[WORLD_MAX_X][WORLD_MAX_Y],

	pub fn clone(self: const World) World {
		var ret = World {
			.w = self.w,
			.h = self.h,
		};
		var x: u32 = 0;
		var y: u32 = 0;
		
		while (x < self.w) : (x += 1) {
			while (y < self.h) : (y += 1) {
				ret.fields[x][y] = self.fields[x][y];
			}
		}
	}

	pub fn count_neighbors(self: const World, x: u32, y: u32) {
		ret: u32 = 0;
		
		if (x > 0)
			if (self.fields[x - 1][y])
				ret += 1;

		if (y > 0)
			if (self.fields[x][y - 1])
				ret += 1;

		if (x < (self.w - 1))
			if (self.fields[x + 1][y])
				ret += 1;

		if (y < (self.h - 1))
			if (self.fields[x][y + 1])
				ret += 1;

		if (x > 0 && y > 0)
			if (self.fields[x - 1][y - 1])
				ret += 1;

		if (x < (self.w - 1) && y > 0)
			if (self.fields[x + 1][y - 1])
				ret += 1;

		if (x > 0 && y < (self.h - 1))
			if (self.fields[x - 1][y + 1])
				ret += 1;

		if (x < (self.w - 1) && y < (self.h - 1))
			if (self.fields[x + 1][y + 1])
				ret += 1;
		
		return ret;
	}

	void eval(self: World)
	{
		neighbors: u32;
		x, y: u32;
		new_wld = World {
			.w = self.w,
			.h = self.h,
		};
		
		new_wld = self.clone();
		
		for (x = 0; x < self.w; x += 1) {
			for (y = 0; y < self.h; y += 1) {
				neighbors = self.count_neighbors(x, y);

				if (neighbors == 3)
					new_wld.fields[x][y] = true;
				else if (neighbors != 2)
					new_wld.fields[x][y] = false;
			}
		}
		
		self = new_wld.clone();
	}
};

pub fn main() void {
	active: bool = true;
	wld = World {
		.w = WORLD_MAX_X,
		.h = WORLD_MAX_Y
	};
	is_x = false;
	i, x, y: u32;
	
	for (x = 0; x < wld.w; x += 1) {
		for (y = 0; y < wld.h; y += 1) {
			wld.fields[x][y] = false;
		}
	}
	
	for (i = 1; i < argc; i += 1) {
		if (is_x == 0) {
			x = strtoul(argv[i], NULL, 10);
			is_x = true;
		} else {
			y = strtoul(argv[i], NULL, 10);
			wld.fields[x][y] = true;
			is_x = false;
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
		
		wld.eval();
		
		switch (fgetc(stdin)) {
		case 'q':
			active = false;
			break;
		
		case EOF:
			active = false;
			fprintf(stderr, "Error end of input\n");
			break;
		}
	}
}
