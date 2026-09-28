# A signed index under an unsigned bound keeps `i + k` out of a callee-saved register

summary: when a loop passes `i + k` to several calls and the image recomputes it
before each call (`adds r1, r4, #0` / `adds r1, #k`) while still testing the bound
with `blo`, the index is an `int` compared against an unsigned literal (`i < 8u`);
an `unsigned` index makes mwcc CSE `i + k` into a callee-saved register, which
pushes a live value to a stack slot and grows the frame by 4 bytes.

Found in: src/matched/ov/ov170_func_021ED1C8.c (0x021ED1C8)

The second loop of the window-10 frame builder calls four window functions with
the same `j + 0x58`:

```
021ED2AC  adds r1, r4, #0
021ED2AE  adds r0, r5, #0
021ED2B0  adds r1, #0x58      <- recomputed before every call
...
021ED2D0  adds r4, r4, #1
021ED2D2  cmp  r4, #8
021ED2D4  blo  #0x21ed27e     <- unsigned test
```

Measured under dsi/1.1p1 -O4,p:

- `unsigned j; ... j < 8`: `j + 0x58` is held in r7, the count that the original
  keeps in r7 is spilled, the frame is `sub sp, #0x2c` instead of `#0x28`, and
  `push` loses r3. 94 bytes differ.
- `int j; ... j < 8`: register allocation is the original's, but both loop tests
  are `blt`. 2 bytes differ.
- `int j; ... j < 8u` (or `(unsigned)j < 8`): EXACT.

The sibling src/matched/ov/ov170_func_021ED594.c has the same loop with an
`unsigned short` index; there the narrowing does the same job.
