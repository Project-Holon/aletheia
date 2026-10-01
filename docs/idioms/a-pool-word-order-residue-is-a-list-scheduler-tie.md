# A pool emission order residue is a list-scheduler tie, not a source order

summary: when the only residue is two pool words trading places (the address
a load-but-no-store statement needs versus the immediate a later store needs),
the pool order follows the *scheduled* instruction order, not the source
statement order. Reordering statements, naming locals, `const`, `volatile`,
u32-vs-u64 stores and a second extern name all measure the same residue; the
scheduler hoists the immediate load above an intervening `ldm`/`stm`.

Found in: `src/pending/ov_sdk/ov009_func_021685CC.c` (0x021685CC,
DWCi_GetMathRand32, dsi/1.1p1, ARM)

The image loads the context address for the 64-bit `rand->x = seed` store from
pool word 0x104, and the mul-low immediate from 0x108. 1.1p1 emits the opposite
pool order because it schedules the mul-low load one slot *above* the
`ldm r4`/`stm r0` copy, so the immediate's word is added to the pool first:

```
image                          compiled
ldr r0, [pc]  ; x address      ldr r0, [pc]  ; mul low
ldm r4, {r2,r3}                ldr r1, [pc]  ; x address
stm r0, {r2,r3}                ldm r4, {r2,r3}
ldr r0, [pc]  ; mul low        stm r1, {r2,r3}
ldr r1, [pc]  ; mul high       str r0, [r6,#8]
str r0, [r6,#8]                ldr r1, [pc]  ; mul high
```

Same instruction multiset, same 276 bytes, two pool words transposed (the
relocation site moves from +0x104 to +0x108). Mirroring which extern feeds the
guard and which feeds the x store moves the residue but does not remove it
(19 bytes, now one pool *offset* short as well), which is the tell that the
symbol names are not the lever.

Diagnostic: if every spelling gives the same byte count and the diff window is
exactly two adjacent pool words (one a relocation, one an immediate), it is the
scheduler's pool-emission order and no C shape reaches it. Park with the two
word addresses named, as `docs/notes/func_021685CC.c.txt` does.
