# A named row index in a struct array keeps the base add before the column shift

summary: a 12-byte row lookup that emits `muls`, then adds the object base before shifting the column, can require both a two-dimensional struct member and a named row-index local; raw byte arithmetic or an inline `1 - row` lets the column shift run first and swaps the scratch registers.

Found in: src/matched/ov/ov119_func_021DE1B4.c (0x021DE1B4), src/matched/ov/ov119_func_021DE518.c (0x021DE518).

Both functions divide a selected slot by three and use its remainder as the column. The object pointers begin at +0xFD8 and have two rows of three words. The matched spelling is:

```c
typedef struct { char pad[0xfd8]; int obj[2][3]; } State;
int col = index % 3;
int row = index / 3;
int other = 1 - row;
int obj = p->obj[other][col];
```

The original computes `other * 12`, adds `p`, then computes `col * 4` and adds it. In 021DE1B4, raw `*(int *)(p + other * 12 + col * 4 + 0xfd8)` gave eight concrete byte differences, including the quotient spill trading places with the subtraction. The struct member with the named `other` gives EXACT.

In 021DE518, using `p->obj[1-row][col]` still gave twelve concrete byte differences: constant one lived in r1 instead of r0, the multiply used r0 instead of r1, and the column shift preceded the object-base addition. Binding `other = 1-row` before `p->obj[other][col]` gives EXACT. Changing the function's pointer type or the selected-index local to u16 alone did not change those twelve bytes.

This complements the existing flat-versus-two-dimensional-array idiom: `muls #12` establishes the row shape, while the named row expression constrains its scheduling.
