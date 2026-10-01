# A derived wide local keeps the update before its first call

summary: when a wide parameter sum used by two later calls is updated in its callee-saved register before the first call, bind the sum to a fresh wide local; assigning back into the parameter can compute the first argument in a scratch register and delay the home-register update until the second use.

Found in: `src/matched/ov/ov210_func_021BF7B0.c` (0x021BF7B0), `src/matched/ov/ov210_func_021BFA14.c` (0x021BFA14), Thumb dsi/1.1p1 -O4,p.

The original adds 12 or 20 into r4, passes its signed low halfword in r3, calls another helper, then again narrows r4 for the next call. With `y += 20;`, the compiler instead copies r4 into r3, adds 20 there for the first call, and postpones `adds r4,#20` until after the intervening helper. A named wide local restores the earlier update and both narrowing sites:

```c
int coord;
/* after the first helper call */
coord = y + 20;
func_021BEE38(p, 11, 0x8c, coord, 1);
func_021BEDF0(p, 13, 1);
func_021BEE38(p, 13, 0x8c, coord, 1);
```

021BFA14 with parameter reassignment compiled 106 bytes with 52 concrete bytes differing. A short parameter compiled 102 bytes but narrowed once into r4 and removed the second narrowing pair, leaving 29 concrete bytes different; an unsigned wide parameter retained the original 52-byte diff. The wide local compiled 102 bytes EXACT*, with two bytes of alignment padding outside the function.

021BF7B0 also binds the derived index to a wide `index` local. Its parameter-update spelling compiled 114 bytes with 68 concrete bytes differing; named `index` and `coord` locals compiled 108 bytes EXACT. This is a lifetime and scheduling distinction, not a general instruction to replace reused parameters: some functions require parameter reuse to preserve their register homes.
