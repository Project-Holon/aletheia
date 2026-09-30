# A data-pair load hoisted into named locals before a clamp keeps the image's order

summary: when a call's arguments are two `u16` lookups into different tables plus a
clamp on the fourth argument, 1.1p1 issues the `&locals` add and the clamp `cmp`
*ahead* of the pair of `ldrh` and pairs each pool load with its own `ldrh`
(base, use, base, use); binding both lookups to named locals **before** the clamp
statement makes the compiler pool both bases first, issue both `ldrh` together and
sink the `&locals` add to just before its store, which is the image's schedule.

Found in: src/matched/ov_sdk/ov016_func_021D1868.c (0x021D1868)

The tail of `window.o`'s `disp` draws one rectangle and therefore calls
`func_021D5FF4(x, y0, x + w, y1, &r)`, where `x` is `g_021DA9FE[type].x` and `w` is
`g_021DAA16[type][0]`, and `y1` has just been clamped by `if (y1 > 0xc0) y1 = 0xc0;`.

Written inline, the two lookups share a pool base per operand and the guard's `cmp`
lands between them; the drafted body is size-exact but sixteen instructions from the
`&r` add on are reordered and one register pair is swapped:

```c
if (y1 > 0xc0)
    y1 = 0xc0;
func_021D5FF4(g_021DA9FE[g_021DE658->type].x, y0,
              g_021DA9FE[g_021DE658->type].x + g_021DAA16[g_021DE658->type][0], y1, &r);
```

```
  +0128 image ldr r4, [pc, #0x44]   | ours lsl r5, r0, #2
  +0134 image ldr r2, [pc, #0x4c]   | ours ldr r2, [pc, #0x38]
  +0138 image ldrh r0, [r4, r5]     | ours cmp r3, #0xc0
  +0144 image add r4, sp, #4        | ours movgt r3, #0xc0
  +014c image add r2, r0, r2        | ours ldrh r2, [r2, r5]
```

Two named locals, assigned *before* the clamp statement (the assignment order does
not matter, only that the clamp statement is textually after them), reproduce the
image byte for byte:

```c
    u16 x1, x2;
    ...
    x1 = g_021DA9FE[g_021DE658->type].x;
    x2 = g_021DAA16[g_021DE658->type][0];
    if (y1 > 0xc0)
        y1 = 0xc0;
    func_021D5FF4(x1, y0, x1 + x2, y1, &r);
```

Measured on 0x021D1868 (dsi/1.1p1, arm, c99, `-O4,p`, 396 bytes): inline 32 concrete
bytes off; the same two locals inside a `{ }` block after the clamp 32; a single
`u16` local used for argument 1 only 400 bytes (SIZE, the second lookup is no longer
CSE'd into the same expression); the form above EXACT.

The tell is the same one as
`a-constant-pair-pools-the-one-used-first-and-only-pointer-math-defeats-the-fold.md`,
one level up: two pool words a small distance apart, and a guard or an address
temporary that the image schedules *between* them rather than ahead of both. When the
register pairing of the two bases is the only difference and the guard `cmp` is on the
wrong side of the loads, this is the lever, not a pin.
