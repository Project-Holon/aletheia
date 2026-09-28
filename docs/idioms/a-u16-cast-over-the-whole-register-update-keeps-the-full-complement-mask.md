# A u16 cast over a whole register update keeps the full 32 bit complement mask, a compound `&=` narrows it

summary: `reg = (u16)((reg & ~0x8000) | (sel << 15))` (the SDK's
GX_SetDispSelect shape, with sel 0) pools the mask as 0xFFFF7FFF, while
`reg &= ~0x8000` and `reg &= 0xFFFF7FFF` on the same `volatile u16` pool
0x00007FFF; the instructions are identical and only the pool word differs.

Found in: src/matched/ov111_func_021C7208.c (0x021C7208)

The original clears bit 15 of POWCNT (0x04000304):

```
ldr  r2, =0x04000304
ldr  r0, =0xFFFF7FFF
ldrh r1, [r2]
ands r0, r1
strh r0, [r2]
```

Both `*(volatile u16 *)0x04000304 &= ~0x8000;` and the same with the literal
0xFFFF7FFF compile to the same five instructions with a pool word of
0x00007FFF, so the function is 2 bytes out in the literal pool only. mwcc
narrows the constant of a compound assignment to the destination width. The
SDK inline

```c
reg_GX_POWCNT = (u16)((reg_GX_POWCNT & ~REG_GX_POWCNT_DSEL_MASK) |
                      (sel << REG_GX_POWCNT_DSEL_SHIFT));
```

folds `| (0 << 15)` away but keeps the `&` at int width, so the pool word stays
0xFFFF7FFF. A 2 byte pool-only residue on a hardware register update is the
tell that the source was an SDK inline (or a hand-written cast over the whole
expression), not a compound assignment. 0x021C76A4 is written in the same shape
(G3X_AlphaBlend on 0x04000060, mask 0xFFFFCFFF, OR 0x8) and is EXACT.
