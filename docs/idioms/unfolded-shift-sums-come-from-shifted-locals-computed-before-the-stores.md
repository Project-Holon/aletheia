# Unfolded shift sums come from shifted locals computed before the stores

summary: when the image keeps `(a << 12) + (b << 12)` as two shifts and an add
(not `(a + b) << 12`), and one shifted value is stored late from a third
register, the source holds each `pos << 12` in a local, computes both locals
before any of the stores, and declares the second local first. Any spelling
where both shifts sit in one expression tree (plain statements, inline
helpers with int parameters, nested helpers, casts, `* 0x1000`) folds the sum.

Found in: src/matched/ov/ov021_func_021A1784.c (0x021A1784, ov021, Thumb)

The image stores two fx32 ranges: `f10 = fC << 12; f14 = f10 + (w0 << 12);`
and the same for f18/f1C from in->f10 and in->w2. It loads w0 before the
previous `out->f8` store, keeps `fC << 12` in r2 and stores it to f10 only
after the second pair's loads. Measured on the same body:

* reading the field back (`out->f14 = out->f10 + (in->w0 << 12)`): unfolded,
  but fC loads first and every store follows its compute (21 bytes off).
* an inline `SetRange(fx32 *d, fx32 pos, fx32 size)` called with
  `in->fC << 12, in->w0 << 12`: unfolded, loads interleave with the shifts.
* the same helper taking int fields and shifting inside, nested or not: folds.
* locals `x`, `y` with each pair's statements kept together: unfolded, x lands
  in r0 and f10 is stored early.
* both locals first, then the four stores in order, with `y` declared before
  `x`: EXACT. Declared `x` then `y`: still off (x in r0).

```c
fx32 y;
fx32 x;
...
x = in->fC << 12;
y = in->f10 << 12;
out->f10 = x;
out->f14 = x + (in->w0 << 12);
out->f18 = y;
out->f1C = y + (in->w2 << 12);
```
