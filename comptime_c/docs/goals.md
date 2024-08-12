While making smng, I wanted to implement a hash algorithm,
that is also applied to some constants.
Let's just ignore that all of this was inherently foolish in that case.
This still got me thinking on how to practically make C code run at
compile time. Maybe I could've instead implemented the algorithm as a macro,
but that sounds not very fun,
especially if this would have been needed for a more complex piece of logic...

So why not just generate a binary, that generates a header,
which contains the needed values?
This allows every bit of code to be used at runtime and compile time.
This is might not be practical, needed, or maintainable...
but it's fun.

It might not be practical, bringing only minor runtime speed gains,
depending on where and how it's used.

It might not be needed due to compiler optimizations,
but I am not sure if currently gcc or clang would've applied the algorithm at
comptime simply because it's used on a constant.

It might not be maintainable, increasing code complexity exponentially,
and thus landing me in suckless.org's torture chambers.

It might be fun, and cause a lot of smiles. So I'll take it.
