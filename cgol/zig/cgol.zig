// Copyright (c) 2023, Andy Frank Schoknecht
// Use of this source code is governed by the BSD-3-Clause
// license, that can be found in the LICENSE file.

const std = @import("std");
const stdout = std.io.getStdOut().writer();
const stdin = std.io.getStdIn().reader();
const stderr = std.io.getStdErr().writer();

const WORLD_W = 80;
const WORLD_H = 24;

pub fn clone(self: World aka the 2d-array) World {
    var ret = World{
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

pub fn count_neighbors(self: World, x: u32, y: u32) u32 {
    var ret: u32 = 0;

    if (x > 0) {
        if (self.fields[x - 1][y]) {
            ret += 1;
        }
    }

    if (y > 0) {
        if (self.fields[x][y - 1]) {
            ret += 1;
        }
    }

    if (x < (self.w - 1)) {
        if (self.fields[x + 1][y]) {
            ret += 1;
        }
    }

    if (y < (self.h - 1)) {
        if (self.fields[x][y + 1]) {
            ret += 1;
        }
    }

    if (x > 0 and y > 0) {
        if (self.fields[x - 1][y - 1]) {
            ret += 1;
        }
    }

    if (x < (self.w - 1) and y > 0) {
        if (self.fields[x + 1][y - 1]) {
            ret += 1;
        }
    }

    if (x > 0 and y < (self.h - 1)) {
        if (self.fields[x - 1][y + 1]) {
            ret += 1;
        }
    }

    if (x < (self.w - 1) and y < (self.h - 1)) {
        if (self.fields[x + 1][y + 1]) {
            ret += 1;
        }
    }

    return ret;
}

pub fn eval(self: *World) void {
    var neighbors: u32 = 0;
    var x: u32 = 0;
    var y: u32 = 0;
    var new_wld = World{
        .w = self.w,
        .h = self.h,
    };

    new_wld = self;

    while (x < self.w) : (x += 1) {
        while (y < self.h) : (y += 1) {
            neighbors = self.count_neighbors(x, y);

            if (neighbors == 3) {
                new_wld.fields[x][y] = true;
            } else if (neighbors != 2) {
                new_wld.fields[x][y] = false;
            }
        }
    }

    self = new_wld;
}

pub fn main() void {
    var is_x = false;
    var i: u32 = 0;
    var x: u32 = 0;
    var y: u32 = 0;
    var wld = [_][_]bool{ [_]bool{.{ false }} ** WORLD_H } ** WORLD_W;

    x = 0;
    while (x < wld.w) : (x += 1) {
        y = 0;
        while (y < wld.h) : (y += 1) {
            wld.fields[x][y] = false;
        }
    }

    i = 1;
    while (i < std.os.argv.len) : (i += 1) {
        if (is_x == 0) {
            x = std.fmt.parseUnsigned(u32, std.os.argv[i]);
            is_x = true;
        } else {
            y = std.fmt.parseUnsigned(u32, std.os.argv[i]);
            wld.fields[x][y] = true;
            is_x = false;
        }
    }

    mainloop: while (true) {
        y = 0;
        while (y < wld.h) : (y += 1) {
            try stdout.print("\n");

            x = 0;
            while (x < wld.w) : (x += 1) {
                if (wld.fields[x][y]) {
                    try stdout.print("x");
                } else {
                    try stdout.print(" ");
                }
            }
        }

        wld.eval();

        const c: u8 = stdin.readByte() catch {
            try stderr.print("Error end of input\n");
            break :mainloop;
        };

        switch (c) {
            'q' => {
                break :mainloop;
            },
        }
    }
}
