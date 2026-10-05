# Write the consumer in each arm: more join shapes

Seen in wave D6 lane 08 (2026-10-05), ov099. Six drafts that earlier lanes left as
"allocator walls" closed EXACT with one change each: the value that merges at a join
was removed, and its consumer (the call or the store) was written in each arm.
Tail merging rebuilds the single join block of the image, and the register order
of the long-lived values then follows the image.

This extends rule 2 of `two-long-lived-values-in-each-others-registers.md`.

## Shapes

| image shape | draft (DIFF) | closing source |
|---|---|---|
| `adds r0,p,#0xE4; b J; adds r0,p,#0xE0; J: ldr r0,[r0]; ... bl f` | `q = a ? p + 0xE4 : p + 0xE0; f(*q, ...)` | `if (a) f(*(u32 *)(p + 0xE4), ...); else f(*(u32 *)(p + 0xE0), ...);` (021BA978) |
| two switch cases branch to one call (`bl g; b T` / `ldr r0,[r0]; T: ... bl f`) | `a = g(..); goto tail; ... a = x; tail: f(a, ...)` | the call and the following store written in each case (021BD1A4) |
| `movs r1,#0x97; b J; movs r1,#0x90; J: subs r0,#9; strb r1,[r5,r0]` | `r = 0x97; goto store; ... store: p[o - 9] = r;` with an enum offset local | each case writes its own literal stores: `*(u8 *)(p + 0x1353) = 0x97; *(int *)(p + 0x1CC) = 0x8A;` (021BCE30, 021BCDB0) |
| `movs r7,#0x41; b J; movs r7,#0x11; J: ... lsls r7,r7,#6` | `flags = c ? 0x41 : 0x11;` and `flags << 6` at each use | `if (c) flags = 0x41; else flags = 0x11; flags <<= 6;` (021BBEB4) |
| `ldr r2,=d_X` in each arm, one shared store after the join | `g = d_X;` in each arm, `g[0x1C] = ...` after the join | the global written at each use, every store in each arm (021BB954) |

## Notes

- In 021BCE30 the enum offset local (wave D3 lever) was a false lead. With the stores
  in each arm, plain literals 0x135C and 0x1353 compile to the shared
  `ldr r0,=0x135C; ... subs r0,#9` by themselves.
- In 021BBEB4 the ternary and the if/else give different code only together with the
  separate `flags <<= 6` statement; each change alone leaves the spill set unchanged.
- Not closed by this: ov099 021B95A0 (heap/offset swap, no join in the source).
