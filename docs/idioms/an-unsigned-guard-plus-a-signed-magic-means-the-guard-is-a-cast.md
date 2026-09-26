# An unsigned guard plus a signed multiply means the guard is a cast, not the variable type

summary: `movhs` (unsigned compare) next to `smull` with a negative magic
constant is the tell: the source guards with an unsigned cast but does the
arithmetic in a signed type, so `u32 x; if (x >= K)` compiles to a different
(`umull`-based) sequence five bytes shorter.

Found in: src/matched/func_0203F734.c (0x0203F734)

`func_0203F734` is an unlabelled ARM leaf that returns
`floor(x * 0xFFFF / 360)` for `x < 360` and 0 otherwise:

```
0203F734  cmp  r0, #0x168
0203F738  movhs r0, #0
0203F73C  bxhs lr
0203F740  ldr  r1, [pc, #0x1c]     ; 0xB60B60B7, the signed /360 magic
0203F744  rsb  r2, r0, r0, lsl #16 ; r2 = x * 0xFFFF
0203F748  smull r0, r3, r1, r2     ; signed 64-bit product
0203F74C  add  r3, r2, r3
0203F750  lsr  r0, r2, #0x1f
0203F754  add  r3, r0, r3, asr #8
0203F758  lsl  r0, r3, #0x10
0203F75C  lsr  r0, r0, #0x10
0203F760  bx   lr
0203F764  .word 0xB60B60B7
```

The obvious C is an all-unsigned one:

```c
u16 func_0203F734(u32 x)
{
    if (x >= 0x168) return 0;
    return (u16)(x * 0xFFFF / 0x168);
}
```

That compiles the same guard (`cmp`/`movhs`/`bxhs`, the comparison really is
unsigned) but the body becomes `umull` with the **unsigned** /360 magic and a
five-instruction correction, 48 bytes instead of the original 52:

```
umull r0, r1, r2, r1
sub   r0, r2, r1
add   r1, r1, r0, lsr #1
lsl   r0, r1, #8
lsr   r0, r0, #0x10
```

What produces the signed `smull` sequence is keeping the arithmetic in a signed
type while the guard casts:

```c
u16 func_0203F734(int x)
{
    if ((u32)x >= 0x168) return 0;
    return (u16)(x * 0xFFFF / 0x168);
}
```

The `(u32)` in the guard is load-bearing twice: it emits `movhs`/`bxhs`, and it
stops mwcc from proving `x * 0xFFFF` non-negative and switching to the unsigned
divide. The tell to read in the listing is `movhs` (unsigned predicate) sitting
directly above an `smull` whose multiplier is a negative constant such as
0xB60B60B7: the variable is signed, the guard is not.
