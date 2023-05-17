/* Copyright (c) 2023, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

#ifndef _VALUE_BAKERY_H
#define _VALUE_BAKERY_H

#define VALUE_MAX_LEN 64

struct ValueDough {
	char *name;
	int preprocessor;
	char *type;
	char value[VALUE_MAX_LEN];
};

void
bake_values(const char              *filename,
	    const struct ValueDough  vdough[],
	    const long unsigned	     n);

#endif /* _VALUE_BAKERY_H */
