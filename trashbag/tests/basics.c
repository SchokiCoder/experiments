/* Copyright (c) 2023, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TB_IMPL
#include <trashbag.h>

static const int TEST_INT = 7;
static const float TEST_FLT = 4.5;

int
main()
{
	struct TrashBag tb;
	TB_size i;
	TB_size old_len;
	int *myi;
	float *myf;
	char *mystr;
	
	tb = TB_new(malloc, realloc, free);

	myi = TB_malloc(&tb, sizeof (int));
	*myi = TEST_INT;
	
	myf = TB_malloc(&tb, sizeof (float));
	*myf = TEST_FLT;
	
	assert(TEST_INT == *myi);
	assert(TEST_FLT == *myf);
	
	mystr = TB_malloc(&tb, sizeof (char) * 20);
	sprintf(mystr, "I like trains");
	
	assert(strlen(mystr) == 13);
	
	mystr = TB_realloc(&tb, mystr, 110);
	sprintf(mystr,
	        "Twenty-five years and my life is still\n"
		"Trying to get up that great big hill of hope\n"
		"For a destination\n");
	
	assert(strlen(mystr) == 102);
	
	old_len = tb.len;
	TB_free(&tb);
	
	assert(0 == tb.len);	
	for (i = 0; i < old_len; i += 1)
		assert(NULL == tb.ptrs[i]);
	
	return 0;
}
