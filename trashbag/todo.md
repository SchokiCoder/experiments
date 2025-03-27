- [x] maybe replace Trashbag's pointer returns with index returns,
forcing pointer uses to be via index, this should make realloc's loop obsolete

Using indexes from Trashbag sucks.
I could live with `tb.ptrs[idx]`,
but since ptrs is a void pointer array you have to cast in various scenarios.
Using pointers to the pointers also suck,
and using copies of the pointers is highly unsafe, breaking with a realloc.

- [x] fix code fmt

- [x] update copyright
