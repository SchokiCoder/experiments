/* Copyright (c) 2023 - 2024, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

#ifndef _CGEN_H
#define _CGEN_H

#include <stdio.h>

enum CG_Scope {
	CG_S_NORMAL,
	CG_S_EXTERN,
	CG_S_STATIC
};

void
CG_print_headerbegin(FILE *file, const char *headerguard);

void
CG_print_definition(const char *name, const char *value);

void
CG_print_variable(const enum CG_Scope scope,
                  const char *type,
                  const char *name,
                  const char *value);

void
CG_print_headerend();

#endif /* _CGEN_H */
