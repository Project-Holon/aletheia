# The statement order of four independent scratch temporaries decides which scratch register each lands in

summary: when a function computes several byte temporaries from the same
loaded bytes and the whole body is right except that the scratch registers
(`r1`/`r2`/`r3`/`ip`/`lr`) are permuted, the lever is the *statement order* of
the temporary assignments, not the order of their declarations.  Declaring the
locals in any order is inert; writing the four assignments in the image's
order recolours every load and masked value at once.

Found in: `src/matched/ov_sdk/ov114_func_021C60C8.c` (0x021C60C8, ov114,
DWCi_Ndi_encodeBASE64, dwci_nd.o)

The base64 encoder loads `c[0]`, `c[1]`, `c[2]` and builds four 6-bit indices:

```c
base1 = (unsigned char)(c[0] >> 2);
base0 = ((c[0] << 4) | (c[1] >> 4)) & 0x3f;
base2 = ((c[1] << 2) | (c[2] >> 6)) & 0x3f;
base3 = c[2] & 0x3f;
```

With the four assignments in the obvious dependency order (base1, base2, base3,
base0) the callee-saved set and the tail were already byte-exact, and 39
concrete bytes remained: every `ldrb`/`asr`/`orr`/`and`/`ldrsb` in the compute
block carried a different scratch register.  Permuting the *declarations*
`base0..base3` through all 24 orders changed nothing.  Permuting the four
*assignment statements* through their 24 orders gave EXACT on four of them and
39..117 concrete diffs on the rest — a 3x swing from a pure statement reorder.

Rule: a same-size residue that is confined to the scratch registers of one
dependency-free computation, and that no declaration order moves, is the
**statement order** of that computation.  Sweep it; the compiler assigns a
scratch register per evaluated subexpression in first-use order, and the loads
of the shared source bytes sink or hoist to follow it.

Related: `declaration-order-decides-which-register-a-local-gets.md` is the
callee-saved (long-live-range) half; this is the scratch (short-live-range)
half where declaration order has no effect at all.
