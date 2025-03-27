/* Copyright (c) 2023, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

#include <assert.h>
#include <stdlib.h>

#define TB_IMPL
#include <trashbag.h>

static const unsigned long MATRIX_LEN_X = 10;
static const unsigned long MATRIX_LEN_Y = 10;
static const int TESTVAL = 128;

int main()
{
	struct TrashBag tb;
	unsigned long i;
	int **matrix;

	tb = TB_new(malloc, realloc, free);

	// non contigous memory allocation, too bad
	matrix = TB_malloc(&tb, (sizeof(*matrix) * MATRIX_LEN_X));
	for (i = 0; i < MATRIX_LEN_X; i++) {
		matrix[i] = TB_malloc(&tb, (sizeof(**matrix) * MATRIX_LEN_Y));
	}

	matrix[9][9] = TESTVAL;
	assert(TESTVAL == matrix[9][9]);

	TB_free(&tb);

	return 0;
}
