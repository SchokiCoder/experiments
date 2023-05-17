## C

Well what is there to say about C?  
Implementing Conway's game of life was easy in it.  
Strange thing though:  
I tried changing the field type from int to an enum in order to eliminate one if
in the drawing part, that would have run for every field of every draw
(80 * 24 per full draw).  
With an enum it seems to decrease performance despite the removed if.  
If i instead use just a char as field type and plain char constants it seems to
increase performance only slightly.  


## Go

Porting from C to Go was fast and easy.  
Of course only as fast as i could do it with my prior non-existing knowledge of
the language but at no point did something happen that made go "What, why?"  
The __hardest__ part of it was figuring out the stdlib in order to get io
working.  


## Zig

This was actually frustrating to use.  
  
The first inconvenience that hit me was: no tabs.  
As a language that want's to replace C, i cannot understand how apparently no
one in the Zig community so far, was bothered enough by that to fix it.  
  
The second inconvenience was me, trying to optimize out the field array
initialization which happens at runtime in C and Go.  
This only runs once in the program but why not remove it if i can, right?  
Zig has a way for that but it looks absolutely ugly as soon as you try to use it
for any multidimensional array.  

```zig
var wld = [_][_]bool{ [_]bool{.{ false }} ** WORLD_H } ** WORLD_W;
```

This one line probably took me at least one hour of trying it myself with the
documented syntax after that only an already ansewered stack overflow thread
helped me actually accomplish it.  
It was not at all intuitive to use and reminds me of regex, in that this line is
bordering the territory of write-once text.  
If Conway's game of life becomes 3d then this line is becoming write-once...
once i figure out how to add a dimension to it.  
Imagine an employer asking what are you trying to do for the last 2 hours only
for him to find out that you are optimizing a section that runs once at start
and then never again. It's just not worth bothering.  
I just checked and 0.10.0 doesn't even accept this anymore "unable to infer
array size".  
