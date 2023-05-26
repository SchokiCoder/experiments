/* Copyright (c) 2023, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

enum State {
	S_MARIO		= 0,
	S_SUPERMARIO	= 1,
	S_FIREMARIO	= 2,
	S_CAPEMARIO	= 3
};

enum Transition {
	T_MUSHROOM	= 0,
	T_FLOWER	= 1,
	T_FEATHER	= 2
};

void player_collect(enum State *s, const enum Transition t)
{
	if (S_MARIO == *s && T_MUSHROOM == t) {
		*s = S_SUPERMARIO;
		return;
	}
	
	switch (t) {
	case T_FLOWER:
		*s = S_FIREMARIO;
		break;
	
	case T_FEATHER:
		*s = S_CAPEMARIO;
		break;
	
	default:
		return;
	}
}

//TODO do i need this in C: enum Transition next_transition(long unsigned i)

int main() {
	enum State s;
	enum Transition t;
	long unsigned i;
	
	for (i = 0; i < 100000000; i += 1) {
		t = i % 3;
		player_collect(&s, t);
	}
	
	return 0;
}
