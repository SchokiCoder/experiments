/* Copyright (c) 2023, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

#include <assert.h>
#include <stdlib.h>

#define TB_IMPL
#include <trashbag.h>

static const int TESTVAL = 128;

int main()
{
	struct TrashBag tb;
	int ***ogre;

	tb = TB_new(malloc, realloc, free);

	ogre = TB_malloc(&tb, sizeof(ogre));
	*ogre = TB_malloc(&tb, sizeof(*ogre));
	**ogre = TB_malloc(&tb, sizeof(**ogre));

	***ogre = TESTVAL;
	assert(TESTVAL == ***ogre);

	TB_free(&tb);

	return 0;
}
