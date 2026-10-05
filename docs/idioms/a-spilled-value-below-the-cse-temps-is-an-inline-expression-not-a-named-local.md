# A spilled value in a low stack slot is an inline expression, not a named local

summary: In a loop that spills several values, mwcc gives named locals the
higher spill slots and its own CSE temporaries the lower ones. When the
original spills a derived value (for example `(i / 4) * 16` or `(i % 4) * 6`)
into a slot BELOW the CSE temporaries such as `p + i*4`, the source did not
name it. Write the expression inline at every use and let the compiler CSE it.
A named local that is reused for the derived value (`py = py * 6;`) also
extends the live range of the first value and moves it out of a scratch
register.

```c
/* original: i/4 in r3, i%4 in r1 (short temps), (i/4)*16 at [sp,#8],
   (i%4)*6 at [sp,#0xc], p+i*4 at [sp,#0x10] */
px = i / 4;
py = i % 4;
...
func_021C2224(p, (u8)(px * 16), (u8)(py * 6), (u8)mode, (u8)slot);
...
func_021C22E8(p, p + 0x918 + i * 8, idx, slot, px * 16, py * 6);
```

The same function also needed the window loads written as
`*(void **)(p + i * 4 + 0x8F8)` at each use instead of a `w` local: the
original reloads them from the spilled `p + i*4` temp. With `w` locals, the
loop counter took a register and `mode` was spilled.

Found in: `src/matched/ov/ov099_func_021C2090.c` (0x021C2090, ov099), wave D4.
The last step was declaration order (`px, py` declared before `sel`) for one
scratch-register swap.

Tell: the slot order in the original does not follow the declaration order of
your named locals, and a value you named sits below a compiler temporary.
