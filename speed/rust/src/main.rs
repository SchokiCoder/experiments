/* This code is taken from:
 * https://github.com/0atman/noboilerplate/blob/main/scripts/24-rust-data-modelling.md
 * and was slightly modified.
 */

#[derive(Debug, PartialEq)]
enum State {
	Mario,
	SuperMario,
	FireMario,
	CapeMario,
}

#[derive(Debug)]
enum Transition {
	Mushroom,
	Flower,
	Feather,
}

#[derive(Debug)]
struct Player {
	state: State,
}

impl Player {
	pub fn new() -> Self {
		Self { state: State::Mario }
	}

	pub fn collect(&mut self, power: Transition) {
		use State::*;
		use Transition::*;

		match (&self.state, power) {
			(Mario, Mushroom) => self.state = SuperMario,
			(_,     Flower)   => self.state = FireMario,
			(_,     Feather)  => self.state = CapeMario,
			(_,     Mushroom) => {} // no change, 1up!
		}
	}
}

/* Here starts my own stuff for the the speed comparison.
 */

/* Copyright (c) 2023, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

fn next_transition(i: u32) -> Transition {
	return match i % 3 {
		0 => Transition::Mushroom,
		1 => Transition::Flower,
		2 => Transition::Feather,
		_ => panic!("How did you get here?")
	}
}

fn main() {
	let mut i: u32 = 0;
	let mut p = Player::new();
	let mut t: Transition;
	
	while i < 100_000_000 {
		t = next_transition(i);
		p.collect(t);
		i += 1;
	}
}
