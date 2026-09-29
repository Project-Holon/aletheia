# An argument bound through an inline wrapper is set up after the other argument registers

summary: when one argument of a call (a NULL stack argument, a buffer address kept in a callee-saved register) is materialised AFTER the other argument loads in the image but BEFORE them in yours, and every other byte matches, route the call through a `static inline` wrapper that takes that value as a parameter (an SDK inline such as G3_Perspective, or a small `get(s, x, y, buf)` returning buf): the inlined parameter's copy is placed after the other arguments' setup.

Found in: src/matched/ov/ov075_func_021F52D8.c (0x021F52D8), src/matched/ov/ov091_func_021BAFA0.c (0x021BAFA0)

## ov075 0x021F52D8: G3i_PerspectiveW_ through G3_Perspective

```
original                         direct call to func_0207D704
movs r4, #0                      movs r4, #0
ldr  r2, =FX_SinCosTable_        ldr  r2, =FX_SinCosTable_
movs r0, #0xc                    str  r4, [sp, #0xc]     <- mtx = NULL
movs r1, #0xe                    movs r0, #0xc
ldrsh r0, [r2, r0]               movs r1, #0xe
ldrsh r1, [r2, r1]               ldrsh r0, [r2, r0]
ldr  r2, =0x1555                 ldrsh r1, [r2, r1]
str  r4, [sp, #0xc]  <-          ldr  r2, =0x1555
```

The SDK inline fixes it:

```c
static inline void G3_Perspective(int fs, int fc, int aspect, int n, int f, void *mtx)
{
    func_0207D704(fs, fc, aspect, n, f, 0x1000, 1, (int)mtx);  /* G3i_PerspectiveW_ */
}
    G3_Perspective(d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0x1000, 0x400000, 0);
```

Eighteen hand variants of the direct call (parameter widths, a local zero,
`1 << 22`) and a permuter pass left the store where it was.

## ov091 0x021BAFA0: a buffer pointer returned by an inline

Both arms end `adds r0, r4, #0; movs r1, #K; movs r2, #K2; add r5, sp, #N`
and then share `adds r3, r5, #0; bl func_021BB56C`. `p = b1;
func_021BB56C(s, K, K2, p);` and `func_021BB56C(s, K, K2, p = b1)` both put
`add r5, sp, #N` first (16 bytes). The spelling that matches:

```c
static inline s16 *get(u8 *s, int x, int y, s16 *buf)
{
    func_021BB56C(s, x, y, buf);
    return buf;
}
    p = get(s, 0x1a, 0x13, b1);
```

Putting `buf` first in the inline's parameter list gives the same bytes, so
the parameter's position does not matter, only that the value goes through
the inline.
