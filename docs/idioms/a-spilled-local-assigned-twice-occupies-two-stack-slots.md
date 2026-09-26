# A spilled local assigned twice occupies two stack slots, later value lower

summary: when a narrow local is spilled and its value is overwritten before the
first value dies, mwcc gives each definition its own stack slot and puts the
first definition at the *higher* address; naming the two values as separate
locals reproduces the original slot order.

Found in: src/matched/ov198_func_0220D090.c (0x0220D090); also fixes the twin
0x0220D218.

Body.

`func_0220D090` computes a width twice into the same `u16`:

```c
w = func_0201D304(t, cfg, 0);        /* value A */
w = (func_02045738(handle) << 3) - w; /* value B, reads A */
func_0201C724(..., w, ...);          /* B */
```

The original spills both values, with A at `[sp,#0x14]` and B at `[sp,#0x10]`
-- A higher than B. Writing it as one variable, mwcc instead emitted B at
`[sp,#0x14]` and A at `[sp,#0x10]` (the source order), a two-slot swap and a
hard `DIFF` even though every other instruction matched.

Splitting the value into two locals in that order reproduces the original:

```c
u16 w0;
u16 w2;
...
w0 = func_0201D304(t, cfg, 0);
w2 = (func_02045738(handle) << 3) - w0;
func_0201C724(..., w2, ...);
```

`w0` (declared first) lands at the higher slot, `w2` (declared second) at the
lower one, consistent with `local-declaration-order-is-stack-order.md`: the
later declaration is at the lower stack address. The two definitions of a
single assigned-twice variable are not ordered that way, so a spilled
overwritten value has to be split by hand if its slot order matters.

Note this only bites when the value is actually spilled; in the sibling
`if`-arm of the same function the same two values stayed in a register and a
single `u16 w` was correct. Reach for the split only when the diff is a pair of
swapped `[sp,#...]` stores with everything else already byte-equal.
