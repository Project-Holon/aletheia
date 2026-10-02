# A field saved by reading it back from the vector keeps the dead store and moves the zero ahead of the copy

summary: when a vector field is stored, then overwritten with 0, and restored later from a callee-saved register, write the save as a read of the vector (`a.y = p->y; y = a.y; a.y = 0;`), not as a separate load (`y = p->y; a.y = y;`). The read keeps the first store alive even with the zero store right after it, and lets the zero sit before a following struct copy, which is what sets the register colouring.

Found in: src/matched/ov/ov021_func_021AB908.c (0x021AB908)

The image stores y, then 0, to the same slot, and restores y later:

```
021AB924  ldr  r7, [r5, #0x14]   <- y
021AB928  ldm  r4!, {r0, r1}     <- b = *q
021AB930  str  r7, [sp, #0x24]   <- a.y = y   (dead store, kept)
021AB934  movs r6, #0            <- zero, also the high word of every 0x800LL rounding add
021AB93C  str  r6, [sp, #0x24]   <- a.y = 0
...
021AB95A  str  r7, [sp, #0x24]   <- a.y = y   (restore)
021AB9D8  adds r1, r7, #0        <- final a.y reload turned into a move from r7
```

Earlier lanes wrote `y = p->y; a.y = y; b = *q; a.y = 0;`: same schedule but
y r6, zero r4, table base r7 (22 bytes). Moving `a.y = 0` before the copy gave
the right colouring (the zero then interferes with q, so it cannot take r4)
but mwcc dropped the dead `a.y = y` store. Reading y back from the vector

```c
a.x = p->x;
a.y = p->y;
a.z = p->z;
y = a.y;
a.y = 0;
b = *q;
b.y = 0;
```

keeps both stores and the zero before the copy: EXACT, with and without
`--lang c99`. The `adds r1, r7, #0` at the end is a late load-to-move rewrite:
it only appears when y's register survives to the end, so it is a symptom of
the colouring, not a separate statement to model.
