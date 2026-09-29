# A copy of the loop counter made before the loop label is a stored zero, not the counter

summary: when a short store loop opens with `adds r1, rI, #0` one instruction before the loop label and stores r1 on every pass, the loop stores the constant 0 (`p->w[i] = 0;`), not `i`; mwcc reuses the counter's zero-initialised register for the constant and hoists the copy out of the loop. Read where the backward branch lands before deciding what the loop stores.

Found in: src/matched/ov/ov054_func_021F37B4.c (0x021F37B4), src/matched/ov/ov055_func_021F3E84.c (0x021F3E84)

Both functions end with a two-pass loop over a small array field:

```
021F385A  adds r1, r4, #0      <- before the label: r4 is still 0
021F385C  lsls r0, r4, #2      <- loop label (blt #0x21f385c)
021F385E  adds r0, r5, r0
021F3860  adds r4, r4, #1
021F3862  str  r1, [r0, #0x10]
021F3864  cmp  r4, #2
021F3866  blt  #0x21f385c
```

Read as a straight line it looks like "copy i, increment, store the copy",
and two earlier lanes wrote `o->w[i] = i;` and tried `for`, `while`, `++i`,
a `t = i` temporary and a pointer walk. All of them store r4 inside the loop
and stay a few bytes out. The branch target is the `lsls`, so the copy runs
once, while the counter is still 0, and every pass stores that zero:

```c
for (i = 0; i < 2; i++)
    o->w[i] = 0;
```

is EXACT in both (the ov055 one stores halfwords with `strh`). No extra
local is needed: mwcc spots that the constant equals the counter's initial
value and copies it rather than writing `movs r1, #0`.
