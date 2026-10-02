# Per-channel shift statements on u8 locals interleave the colour chains

summary: when an RGB555 loop body in the image computes the four channel
chains (extract, truncate, shift, truncate, place) interleaved across r0-r3,
the source halves each u8 channel in its own statement (`b = b >> 1;`) after
all four extractions. Casts inline in the packing expression
(`(u8)(b >> 1) << 10`) or `b >>= 1` serialise the chains (one channel after
another through r0); the order of the shift statements decides which
truncation the scheduler puts early.

Found in: src/matched/ov/ov021_func_021C30D4.c (0x021C30D4, ov021, Thumb)

The image (darken every colour of LCDC bank 0x06860000) has the b chain in r2,
g in r0, r in r1 and a in r3, with their `lsls #0x18 / lsrs #0x18`
truncations and the `lsls #0x17 / lsrs #0x18` halvings interleaved, and the
`& 1` mask of `a` hoisted into r7 out of the loop. Measured on the same body:

* `*p = (a << 15) | ((u8)(b >> 1) << 10) | ((u8)(g >> 1) << 5) | (u8)(r >> 1);`
  with the four u8 locals: chains serialised, loop registers rotated (60 bytes);
  the 24 operand orders of that OR: 46 to 69 bytes, never interleaved.
* `b >>= 1; g >>= 1; r >>= 1;`: the halving folds into `lsrs #0x19` (79 bytes).
* `b = b >> 1; g = g >> 1; r = r >> 1;` then
  `*p = (a << 15) | (b << 10) | (g << 5) | r;`: interleaved (40 bytes);
  ordering the three statements b, g, r gives the image byte for byte (the
  other five orders: 15 to 40 bytes).

```c
u16 c = *p;
u8 b = (c >> 10) & 0x1F;
u8 g = (c >> 5) & 0x1F;
u8 r = c & 0x1F;
u8 a = (c >> 15) & 1;

b = b >> 1;
g = g >> 1;
r = r >> 1;
*p = (a << 15) | (b << 10) | (g << 5) | r;
```
