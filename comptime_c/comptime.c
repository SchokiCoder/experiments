/* Copyright (c) 2023 - 2024, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

#include <stdio.h>

#include "djb2.h"
#include "cgen.h"

#define ARRSIZE(a) (sizeof(a) / sizeof(a[0]))

struct CmdParts {
	char *varname;
	char *cmdname;
};

int
main()
{
	struct CmdParts cmd_parts[] = {
		{"CMD_AP", "ap"},
		{"CMD_ADD_PROJECT", "add-project"},
		{"CMD_ERB", "erb"},
		{"CMD_EDIT_RECORD_BEGIN", "edit-record-begin"},
		{"CMD_ERE", "ere"},
		{"CMD_EDIT_RECORD_END", "edit-record-end"}
	};
	unsigned long i;
	char temp[128];

	CG_print_headerbegin(stdout, "_COMPTIME_H");

	for (i = 0; i < ARRSIZE(cmd_parts); i++) {
		sprintf(temp, "%lulu", djb2_encode(cmd_parts[i].cmdname));
		CG_print_definition(cmd_parts[i].varname, temp);
	}

	CG_print_headerend();

	return 0;
}
