# A constant built as movs then adds or subs one is arithmetic on an enum local

summary: when the image builds a known value in two steps, `movs rN, #K`
followed by `adds rN, #1` or `subs rN, #1` (with a `lsls/lsrs #0x18` pair if
the result is narrowed), the source did the arithmetic on an enum-typed local.
Every integer local folds the pair to a single `movs #K+1` / `movs #K-1`.

Found in: src/matched/ov/ov038_func_021F3F40.c (0x021F3F40),
src/matched/ov/ov038_func_021F3DFC.c (0x021F3DFC),
src/matched/ov/ov038_func_021F3B3C.c (0x021F3B3C),
src/matched/ov/ov036_func_021F3980.c (0x021F3980)

Measured under dsi/1.1p1 -O4,p. The three ov038 functions choose a button
slot and pass it as the fourth argument of func_021BE674/700/6CC:

```
movs r0, #2
ldrb r1, [r5, #6]
cmp  r1, #1
bne  skip
adds r0, r0, #1        <- 2 + 1, not folded to 3
lsls r0, r0, #0x18
lsrs r0, r0, #0x18
skip:
```

A `u8 k` or `int k` gives `movs #3` in the taken arm. What is exact is:

```c
typedef enum { K_0 } KType;
KType k;
k = 2;
if (s[6] == 1)
    k = (u8)(k + 1);
```

The callee parameters that receive `k` have to be `int`. A `u16` parameter
adds a second `lsls/lsrs #0x10` pair before each `bl`.

ov036 0x021F3980 builds its shuffle count as `movs r0, #0xf; subs r0, #1`.
The literal `15 - 1` gives `movs #0xe`. An enum `n` with
`n = 15; cnt = n - 1;` keeps the subtraction.

This is the same mechanism as
an-enum-type-keeps-values-out-of-constant-folding.md (mwcc does not
propagate an enum-typed constant). The tell here is different: an unfolded
`movs` followed by `adds` or `subs #1` on a value that is otherwise known.
