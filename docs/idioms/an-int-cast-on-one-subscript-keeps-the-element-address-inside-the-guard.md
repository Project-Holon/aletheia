# An `(int)` cast on one subscript keeps the element address inside the guard

summary: when a loop reads `tbl[i].id` into a local, guards on it, and only then forms `&tbl[i]` for the guarded body, 1.1p1 CSEs the two subscripts and hoists `adds rE, rBase, rOff` above the `cmp`; the original computes it after the branch. Writing the guard's read as `tbl[(int)i].id` (with `u32 i`) makes the two subscripts different expressions, so the element address is built inside the guarded block and the function matches.

Found in: src/matched/ov195_func_02205A34.c (0x02205A34), src/matched/ov195_func_02205AC0.c (0x02205AC0)

Original, per iteration of a 6-entry table of 0x2c-byte records:

```
movs r0, #0x2c ; muls r0, r4, r0 ; ldr r5, [r7, r0] ; cmp r5, #4 ; blo next
adds r6, r7, r0          <- element address, after the branch
```

With `u32 v = tbl[i].id; if (v >= 4) { Entry *e = &tbl[i]; ... }` the compiler
emits `adds r6, r7, r0` between the `ldr` and the `cmp`: three instructions
permuted, same size. Struct-member spellings, a `continue` guard and an inline
helper taking `&tbl[i]` all keep or worsen the hoist. `tbl[(int)i].id` for the
read (the body still uses `&tbl[i]`) is the only change needed; found by
`tools/permuter.py` (seed 6401) after hand work stalled.
