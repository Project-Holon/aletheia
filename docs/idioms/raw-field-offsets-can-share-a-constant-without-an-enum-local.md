# Raw field offsets can share a constant without an enum local

summary: a far offset held across calls does not always require an enum local; raw field offsets can share the compiler's constant, while a named enum gives the offset a different register or hoists a pointer sum and adds a spill.

Found in: src/matched/ov/ov210_func_021BE8B8.c (0x021BE8B8), src/matched/ov/ov210_func_021BE44C.c (0x021BE44C).

With `dsi/1.1p1 -O4,p --thumb`, both functions became EXACT after removing the named enum offset and writing the fields at their literal offsets. This is a case to test before applying `an-enum-typed-offset-local-keeps-the-far-offset-in-a-callee-saved-register.md`; that enum lever is needed by its own examples, not by every retained constant.

In 021BE8B8, the offset is used for a descriptor load and a later flush:

```c
clear(get(*(Descriptor **)(p + 0x1b4)), 0);
draw(p, 13, message, 48, 0, 0x3c40, 2);
flush(p + 0x1b4);
```

The original and raw-offset compile retain 0x1B4 in r6, the object in r5, and the shared zero in r4. An enum offset local instead put the offset in r4 and zero in r6: 64 bytes in both forms, six concrete bytes different. The raw spelling fixed all six without reordering statements or changing prototypes.

In 021BE44C, raw offsets 0x1D0 (bank), 0x1CC (font), 0x14C (window base), and 0x1DC (print system) share r4=0x1D0. The compiler derives the font with `subs r0,r4,#4`, derives the window with `subs r0,#0x84`, and advances r4 by 0xC for the print-system load. A named enum offset used in those expressions instead hoisted `p+offset` into r4, retained the enum in r6, spilled x, grew the local allocation from 20 to 24 bytes, and added an alignment word to the push. Both code ranges were 80 bytes, but 60 concrete bytes differed. Literal field offsets reproduced the original frame and register allocation.

The conclusion is local to these measured shapes: first establish whether the compiler already shares literal offsets. Introduce an enum when a concrete diff demonstrates that the raw spelling rematerializes constants that the original retains.
