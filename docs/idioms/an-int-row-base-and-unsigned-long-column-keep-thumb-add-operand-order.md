# An int row base and unsigned-long column keep Thumb add operand order

summary: A row address plus a scaled column can emit the right instructions with both add operands reversed. Binding the full-word row address to an int local while the column is unsigned long preserves the original operand order; unsigned-long row and column expressions can commute it.

Found in: src/matched/ov/ov197_func_0220B31C.c (0x0220B31C), src/matched/ov/ov197_func_0220B3EC.c (0x0220B3EC), dsi/1.1p1 -O4,p Thumb.

Both helpers read a halfword from a 0x90-byte row and a four-byte column.
The original uses `adds r1,r0,r7` for the guard, and `adds r2,r2,r7`
for the later call argument. The inline unsigned-address spelling emitted
`adds r1,r7,r0` and `adds r2,r7,r2`: four concrete bytes differed while
every relocation resolved. Merely casting the object pointer to u32 or
making the column unsigned did not fix 0220B3EC.

The successful row spelling is:

```c
typedef unsigned long u32;
int page;
/* i is u32; the page byte is loaded afresh at each original read. */
page = (u32)p + ((unsigned char *)p)[0x533] * 0x90;
value = *(unsigned short *)(page + i * 4 + 0x150);
```

The address calculation before assignment and after addition to i is
unsigned 32-bit arithmetic. The int local preserves the whole address word;
it narrows neither the pointer nor the index.

In 0220B31C this named int row spelling changed DIFF 4 to EXACT 208.
In 0220B3EC the bounded permuter's temporaries and one load cast first
reduced DIFF 4 to DIFF 2; changing page from unsigned long to int then
produced EXACT 204, confirmed by a fixed-flag one run. Its final source
retains those other winning mutations.

The related long-index idiom describes register colouring, and the
distinct-arithmetic-types row idiom describes separate address lifetimes.
Here the residue is the operand order of two existing Thumb adds.
