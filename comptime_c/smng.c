/* Copyright (c) 2023, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

#include <stdio.h>

#include "djb2.h"
#include "pregen.h"

int
main(const int argc, char *argv[])
{
	long unsigned cmd_hash = 0;
	int edit_begin = 0;
	
	if (argc <= 1) {
		printf("Demo version, no help available. Sorry :(\n");
		return 0;
	}
	
	cmd_hash = djb2_encode(argv[1]);
	
	switch (cmd_hash) {
	case CMD_AP:
		/* FALLTHROUGH */
	case CMD_ADD_PROJECT:
		printf("add project\n");
		break;
	
	case CMD_ERB:
		/* FALLTHROUGH */
	case CMD_EDIT_RECORD_BEGIN:
		edit_begin = 1;
		/* FALLTHROUGH */
	
	case CMD_ERE:
		/* FALLTHROUGH */
	case CMD_EDIT_RECORD_END:
		printf("edit record %s\n", (edit_begin == 1 ? "begin" : "end"));
		break;
		
	default:
		printf("unknown\n");
		break;
	}
	
	return 0;
}
