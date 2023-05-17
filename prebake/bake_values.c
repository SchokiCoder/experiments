/* Copyright (c) 2023, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

#include <stdio.h>

#include "djb2.h"
#include "bakery.h"

#define ARRSIZE(a) (sizeof(a) / sizeof(a[0]))

struct Recipe {
	struct ValueDough  vdough;
	char              *ingredient;
};

int
main()
{
	long unsigned i;
	struct Recipe recipes[] = {
		{{"CMD_AP", 1, "long unsigned", ""}, "ap"},
		
		{{"CMD_ADD_PROJECT", 1, "long unsigned", ""}, "add-project"},
		
		{{"CMD_ERB", 1, "long unsigned", ""}, "erb"},
		
		{{"CMD_EDIT_RECORD_BEGIN", 1, "long unsigned", ""},
		    "edit-record-begin"},
		
		{{"CMD_ERE", 1, "long unsigned", ""}, "ere"},
		
		{{"CMD_EDIT_RECORD_END", 1, "long unsigned", ""},
		    "edit-record-end"}
	};
	struct ValueDough input[ARRSIZE(recipes)];
	
	for (i = 0; i < ARRSIZE(recipes); i += 1) {
		sprintf(recipes[i].vdough.value, "%lu", djb2_encode(recipes[i].ingredient));
		input[i] = recipes[i].vdough;
	}
	
	bake_values("_COMPTIME_H", input, ARRSIZE(input));
	
	return 0;
}
