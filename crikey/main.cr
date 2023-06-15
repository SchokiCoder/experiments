/* Copyright (c) 2023, Andy Frank Schoknecht
 * Use of this source code is governed by the BSD-3-Clause
 * license, that can be found in the LICENSE file.
 */

module main;

import stdio;

/* This is an example for how a simple memory-safe language could look like.
 * It's just a prototype mock-up and very likely some fine tuning will be
 * necessary.
 *
 * As baseline i use C2.
 * My memory safety comes from giving functions that allocate or free memory an
 * attribute.
 * This way my compiler can track where memory is allocated and freed.
 * The goal is to automatically call free when appropriate...
 *
 * I think my trashbag concept is easier. since you just have to call free once.
 * How hard could that be?
 */

/* Here i have my own pseudo alloc and free functions, because i can't force
 * everyone to use stdlib malloc/realloc/free.
 *
 * But how is the compiler supposed to know which free to call?
 * malloc/realloc/free are bound to each other by being in the same module.
 * Forgetting to have one of those functions while one of them is defined
 * results in a compiler warning that can be turned off.
 *
 * So if i call main.my_alloc() at the end of the pointers life on the stack,
 * main.free() will be called.
 */

/* malloc attribute takes one parameter, indicating where the pointer is
 * returned. (0 == return)
 */
fn void* my_alloc(u32 size) (@malloc=0)
{
	// ...
}

/* realloc attribute takes two parameters.
 * first  == where is pointer returned
 * second == where did pointer come from
 */
fn void* my_realloc(void* ptr, u32 size) (@realloc=(0, 1))
{
	// ...
}

/* free attribute takes one parameter, indicating where pointer to free came
 * from
 */
fn void my_free(void* ptr) (@free=1)
{
	// ...
}

fn i32 main()
{
	i32* intptr = my_alloc(sizeof(i32));
	
	*intptr = 24 * 56;
	
	stdio.printf("%d\n", intptr);
	
	return 0;
	
} // <- main.free(intptr);

/* Concerns
 *
 * # What if i have pointers within pointers?
 *
 * The compiler needs to check if a pointer holds a pointer.
 * If so, it needs to check if that inner pointer came from a alloc func.
 *
 * Or i just forbid pointers within pointers... but that could go wrong.
 * That would mean multidimensional arrays living on heap... no more.
 * NO, this not a good solution, DONT DO THIS ^
 */
