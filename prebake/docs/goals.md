# Prebake

# Unsorted rant (TODO fix format, see cgol/goals.md)

C comptime functions via python make invokes a C/python script, in which values
get calculated (like djb2 hashes of commands ;) ) these get written into a
"comptime.h" the c compiler can then run using these values.  
  
Maybe it would be better to also use C for this.  
This way i can calculate results from the values of the actual code.  
For example: how else should i calculate something involving the size of a
particlar struct?  
Also no need to copy values into other scripts, eliminating points of failure.  
This would not change much build-wise.  
Just use printf in C for the results and redirect into a file.  
C programmers are also guaranteed to have a C compiler (less dependencies).  
  
However, using C for const generation may create insidous problems.  
Compiling the const generation binary "CGB" could differ depending on platform
and as such bring forth different values.  
On the other side, any algorithm used in the CGB will very likely also be used
by the main binary and such create the same deviating results and as such match
the results of the CGB.  
  
Yes, it can potentially increase the runtime performance insanely, but may at
the cost of simplicity i fear.  
This technique should be used SPARINGLY if at all.  
I feel like, it increases code complexity in 2 dimensions, for each value that
is generated this way.  
Each of these values not only needs to be correctly generated, but also needs
to be correct in the context of the original code itself.  
