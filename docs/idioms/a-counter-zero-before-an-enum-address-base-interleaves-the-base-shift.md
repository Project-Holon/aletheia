# Zero a loop counter before assigning an enum address base

summary: a Thumb loop whose enum address base emits `movs; lsls` can place
the counter's zero between them when the counter is assigned before the
base. Assigning the base first leaves its two instructions consecutive.

Found in: `src/matched/ov/ov094_func_022082FC.c` (0x022082FC),
`src/matched/ov/ov094_func_02208420.c` (0x02208420).

An enum local keeps the VRAM constant out of early folding and preserves
the image's operand order, as covered by
`an-enum-type-keeps-values-out-of-constant-folding.md`. It leaves four
concrete bytes different in each of these functions: the zero and shift
are transposed at the loop entry.

```c
enum { VRAM = 0x06400000 } base;
i = 0;
base = VRAM;
for (; i < limit; i++) {
    copy(src, (void *)(buf.w[1] + (base + offset(i))), 32);
}
```

This gives `movs r6,#0x19; movs r4,#0; lsls r6,r6,#22` in 022082FC
and the same sequence using r7 for the base in 02208420. Both are EXACT*
with only two bytes of alignment padding after their bodies. The spelling
`base = VRAM; for (i = 0; ...)` gives `movs; lsls; movs` instead.

Integer literals, unsigned suffixes and pointer casts do not settle both
the enum base's register and the add order. The counter-before-base
assignment is the remaining scheduling lever; no volatile is involved.
