# An array of aggregates is laid out low-to-high, so a copy run starting at the frame top needs reversed indices

summary: Eight 32-byte struct copies from a global table that land at
descending stack offsets (`sp+0xec` first, `sp+0xc` last) are not an array
indexed in source order; `T b[8]` always puts `b[0]` at the lowest address, so
the source either used eight separate locals or the array was indexed
high-to-low.

Found in: src/matched/ov120_func_021D6100.c (0x021D6100), src/matched/ov123_func_021D9AE8.c (0x021D9AE8)

The original `func_021D6100` (ov120) copies eight 32-byte `BgTemplate`
records out of the const table at `0x021D89B0` into eight stack slots and
passes each slot to `func_0203FCA0`. The copies run:

```
add r3, sp, #0xec   ; first copy
...
add r3, sp, #0xcc   ; second
...
add r3, sp, #0x0c   ; eighth, lowest
```

Writing the natural loop-shaped C

```c
struct BgTemplate b[8];
b[0] = tbl[0];
func_0203FCA0(0, &b[0], 0);
b[1] = tbl[5];
...
```

compiles the whole function correctly except that every `add r3, sp, #imm`
comes out mirrored: `b[0]` at `sp+0xc` instead of `sp+0xec`. The copies are
`ldm`/`stm` aggregate assignments, and mwcc lays an array out ascending from
its base, `b[0]` lowest. The original's first destination is the *top* of the
frame, so its first-used object cannot be element 0 of an ascending array.

Either of these reproduces it:

```c
b[7] = tbl[0];
func_0203FCA0(0, &b[7], 0);
b[6] = tbl[5];
...
```

or eight separate declarations in the same order (`T t0, t1, ..., t7;`),
since a later declaration is placed at the lower address. Only the stack
offsets change; the register choice and every other byte are unaffected, so
the mismatch shows up as eight concrete `add r3, sp` differences and nothing
else.
