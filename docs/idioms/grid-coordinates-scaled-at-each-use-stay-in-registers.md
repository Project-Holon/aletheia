# Grid coordinates scaled at each use stay in registers

summary: Name only the unscaled grid coordinates and write the scaling and the `p + i * 4` pointer
at each use. Named scaled locals make mwcc spill them instead of the pointer.

## Shape

A loop computes a column and a row from the index, scales them, and passes the scaled values
to calls. A pointer `p + i * 4` is also live across the first calls. The image keeps the scaled
row and column in callee-saved registers and spills the pointer:

```
adds  r7, r1, #0
muls  r7, r0, r7      ; (i % 4) * 6 in r7
...
lsls  r5, r0, #4      ; (i / 4) << 4 in r5
...
adds  r0, r0, r1
str   r0, [sp, #0x14] ; p + i*4 spilled
```

The draft with named scaled locals (`y = (i % 4) * 6; x = i / 4 << 4; q = p + i * 4;`)
spills one of the named locals and keeps q in a register. Declaration order, types and
`y *= 6` do not change this.

## Source

Name only the unscaled coordinates. Write the scaling at each use, and write the pointer
inline at each use:

```c
y = i % 4;
x = i / 4;
*(void **)(p + i * 4 + 0x8F8) = f(7, (x << 4) + 4, y * 6 + 1, ...);
g(*(void **)(p + i * 4 + 0x8F8));
for (j = 0; j < 2; j++)
    h(5, (x << 4) + 1 + j * 12, y * 6 + 1, ...);
```

`y * 6` and `x << 4` become CSE temps. The pointer `p + i * 4` is a CSE temp too. The colouring
then keeps the two scaled temps in registers and spills the pointer temp, and the slot order
(pointer lowest) matches the image.

## Seen in

ov099 func_021C1D1C (wave D9r, 284 bytes to EXACT).
