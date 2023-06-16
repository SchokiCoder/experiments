/* Copyright (c) 2023, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

/* Don't run for every candy wrapper to the trash can.
 * Just put it in a bag and bring it all out at the end of the day.
 */

#ifndef _TRASHBAG_H
#define _TRASHBAG_H

#ifndef TB_MAX_LEN
#define TB_MAX_LEN 256
#endif

typedef long unsigned TB_size;

/* Do not directly touch the content of this struct.
 */
struct TrashBag {
	void*   (*allocfn)(TB_size);
	void*   (*reallocfn)(void*, TB_size);
	void    (*freefn)();
	TB_size len;
	void    *ptrs[TB_MAX_LEN];
};

struct TrashBag
TB_new(void* (*allocfn)(TB_size),
       void* (*reallocfn)(void*, TB_size),
       void (*freefn)());

void* TB_malloc(struct TrashBag *tb, const TB_size size);

/* This is costly. Avoid if possible.
 */
void*
TB_realloc(const struct TrashBag *tb,
           void *ptr,
	   const TB_size new_size);

void TB_free(struct TrashBag *tb);


#ifdef TB_IMPL

struct TrashBag
TB_new(void* (*allocfn)(TB_size),
       void* (*reallocfn)(void*, TB_size),
       void (*freefn)())
{
	struct TrashBag ret = {
		.allocfn = allocfn,
		.reallocfn = reallocfn,
		.freefn = freefn,
		.len = 0
	};
	
	return ret;
}

void*
TB_malloc(struct TrashBag *tb, const TB_size size)
{
	tb->ptrs[tb->len] = tb->allocfn(size);
	tb->len += 1;
	return tb->ptrs[tb->len - 1];
}

void*
TB_realloc(const struct TrashBag *tb,
           void *ptr,
	   const TB_size new_size)
{
	TB_size i;
	
	for (i = 0; i < tb->len; i += 1) {
		if (ptr == tb->ptrs[i]) {
			return tb->reallocfn(ptr, new_size);
		}
	}
	
	return NULL;
}

void
TB_free(struct TrashBag *tb)
{
	TB_size i;
	
	for (i = 0; i < tb->len; i += 1) {
		tb->freefn(tb->ptrs[i]);
#ifndef TB_UNSAFE
		tb->ptrs[i] = NULL;
#endif
	}
	tb->len = 0;
}

#endif /* TB_IMPL */

#endif /* _TRASHBAG_H */
