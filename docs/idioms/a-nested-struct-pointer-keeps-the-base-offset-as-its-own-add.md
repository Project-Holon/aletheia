# A nested struct pointer keeps the base offset as its own `adds`, a flat byte offset folds it

summary: `adds r0, r4, #4` followed by `adds r0, #0x5e` is two separate
values, the inner object's address and the field's offset within it; write
the inner object as a real nested struct member and take a pointer to it.
A flat `*(u8 *)(p + 0x62)` folds the pair into one `adds r4, #0x62`.

Found in: `src/matched/func_0202715C.c` (0x0202715C)

The original is five instructions after the call:

```
    ldr  r1, [pc, #0x10]
    ldr  r4, [r1]           /* r4 = the global's pointer, loaded BEFORE the call */
    bl   #0x20274b4
    adds r0, r4, #4         /* the inner object starts at +4  */
    movs r1, #1
    adds r0, #0x5e          /* the field is at +0x5e of it    */
    strb r1, [r0]
```

0x5e and 0x62 are both within the `strb` immediate's reach (+31 is the
limit for `strb`, so neither fits as a plain `strb r1, [r0, #k]` and both
need an `adds` first). The question is only whether the compiler computes
ONE address or TWO, and that is decided by the source's type structure,
not by the arithmetic:

```c
char *p = g;  ...  *(u8 *)(p + 0x62) = 1;          /* adds r4, #0x62  -- one value  */
*(u8 *)((char *)&g->in + 0x5e) = 1;                /* also folds                    */
struct Inner *in = &g->in;  ...  in->f5e = 1;      /* adds r0, r4, #4 / adds r0, #0x5e */
```

Only the third spelling is two adds. `&g->in` is a value in its own right
with its own definition point, so the allocator materialises it once and
the field offset is a separate constant add on top; the other two are a
single constant-folded displacement from the base pointer.

The tell that this is the right reading and not a scheduling accident: the
two adds are SEPARATED by an unrelated `movs r1, #1`. The compiler
scheduled the constant load into the gap between the base address and the
field offset, which it can only do when they are two independent
computations.

The same shape appears at 0x02027186 in the same family (`adds r0, r1, #4;
adds r0, #0x5e; strb`), reached from a different function, which says the
original source spelled the +4 object as a member everywhere in the file,
not as an ad-hoc offset at one call site.

Note the ordering constraint that comes with it: the base pointer is loaded
from the global BEFORE the call and kept in the callee-saved r4. Re-reading
the global after the call gives `ldr r1, [pc]; ldr r0, [r1]` in the wrong
place; binding it to a local ahead of the call is what pins it.
