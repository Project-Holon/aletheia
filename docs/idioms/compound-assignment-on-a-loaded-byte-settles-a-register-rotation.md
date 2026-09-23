# Compound assignment on a byte already loaded settles a register rotation

summary: `a[p] += k` after `val = a[p]` compiles to the same instructions as `a[p] = (u8)(val + k)`
(the add runs on val's register, no second load), but it numbers the values differently, and that
alone can move a three-register rotation that no declaration order, scope, type or permuter run moves.

Found in: src/matched/func_020172D8.c (0x020172D8)

The mcss.c routine reads `u8 val = a0[p];`, tests one nibble of it, and when the test passes writes
back `val + 0x50` (or `val + 5`). The image is

```
ldrb r0, [r2, r4]      val
adds r3, r0, #0
ands r3, r7            v = val & 0xf0
...
adds r0, #0x50
strb r0, [r2, r4]
```

Spelled `a0[p] = (u8)(val + 0x50);` every instruction is right but a0, the inner counter and the
first loaded byte rotate through r2/r1/r3 (47 bytes out). Block and function scope, enum counters,
const on the table, array and record spellings, and permuter hill and anneal with `--types` were all
flat across waves 12 to 15. Spelled `a0[p] += 0x50;` (and `+= 5` in the other arm) the compiler
still reuses val's load, so the instruction stream is the same, and the allocation is the image's:
EXACT with no other change.

When every instruction of a read-modify-write is right and only the registers rotate, try the
compound form of the store before sweeping declarations.
