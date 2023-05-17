/* Copyright (c) 2023, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

#include "djb2.h"

long unsigned
djb2_encode(const char *str)
{
	long unsigned result = 5381;
	long unsigned i;
	char temp;

	for (i = 0; (temp = str[i]); i += 1) {
		result += ((result << 5) + result) + temp;
	}

	return result;
}
