/* Copyright (c) 2023, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

/* This file demonstrates my semi-useless trashbag concept in use.
 * I guess it decreases the chance to not free or to double free _slightly_.
 * I was stuck with a computer with Notepad++ being bored.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TB_IMPL
#include "trashbag.h"

void
somefunc(void)
{
	struct TrashBag sf_tb = TB_new(malloc, free);
	char *mystr = TB_push(&sf_tb, sizeof (char) * 20);
	
	sprintf(mystr, "I like trains");
	printf("str is \"%s\" and is %lu long\n", mystr, strlen(mystr));
	
	TB_free(&sf_tb);
}

int
main()
{
	struct TrashBag main_tb = TB_new(malloc, free);
	int *myint = TB_push(&main_tb, sizeof (int));
	float *myflt = TB_push(&main_tb, sizeof (float));

	*myint = 7;
	*myflt = 1.4;
	
	printf("*myint = %i, *myflt = %f\n", *myint, *myflt);
	
	somefunc();
	
	TB_free(&main_tb);
	
	return 0;
}
