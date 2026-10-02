# A cast local-array read hoists its base to entry; a pointer local CSEs the call argument too

summary: when a stack array's base sits in a callee-saved register set at function entry (ahead of
a parameter spill) yet one call still takes a fresh `add rN, sp, #k` for the same array, the reads
go through a no-op cast, `((int *)ids)[i]`, not through a `p = ids` pointer local. The cast keeps the
element address from folding into sp-relative form, so the compiler hoists the base to entry and
reloads the element after each call; the plain `ids` call argument is a separate expression and is
not commoned into the hoisted register.

Found in: src/matched/ov/ov094_func_021FB91C.c (0x021FB91C, Thumb)

The image:

```
adds r4, r0, #0
add  r6, sp, #0x10      ; base hoisted to entry, before the spill
str  r1, [sp]           ; spill of the second parameter
...
add  r2, sp, #0x10      ; case 4: func_021FCA04(s, 0x10, ids), fresh
...
ldr  r1, [r6, r7]       ; final loop, element reloaded after each call
```

A `int *p = ids;` local (any declaration order, initialiser or statement, `&ids[0]`, `(int *)&ids`,
a u32/char-spelled p, a struct wrapper, a reused parameter) gives the same body but puts the spill
first and copies the case 4 argument from r6 (`adds r2, r6, #0`), 6 bytes out. Plain `ids[i]` reads
fold into `add r0, sp, #0x10` per use and hold the element across the call (286 bytes out). Only the
reads in the loop that needs the hoisted base take the cast; the writes in the other loops can stay
`ids[n] = i`.
