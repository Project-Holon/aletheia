# A product kept in its parameter multiplies in place

summary: a Thumb `muls r1, r0, r1` straight into a parameter register, with
no `adds r2, rX, #0` copy before it, is a compound assignment into the
parameter that the rest of the function keeps reusing (`a *= b; ... a >>= 12;
a++; return a;`). A separate product local gets a fresh register and a copy.

Found in: src/matched/ov/ov093_func_021D7B10.c (0x021D7B10)

The original rounds a 20.12 product:

```
muls r1, r0, r1      ; product in place
ldr  r0, =0xfff
adds r2, r1, #0      ; fraction is a copy
ands r2, r0
lsrs r0, r1, #0xc    ; shift is the last use of the product
...
```

With `u32 v = a * b;` (or `b *= a` and then a new local for the result)
mwcc always emitted `adds r2, r0, #0; muls r2, r1, r2`, and the fraction and
the product shared r2. Operand order, mask/shift order, ternaries, inline
helpers and `/`/`%` did not move it. Writing

```c
u32 f;
a *= b;
f = a & 0xfff;
a >>= 12;
if (f > 0x800) a++;
return a;
```

keeps one web (parameter, product, shifted result) and gives EXACT.
