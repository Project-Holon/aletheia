# A one-bit field clear is `bics` with `movs #1`, not `ands` with a pool mask

summary: clearing an `unsigned short : 1` field compiles to `ldrh; movs r1,#1;
bics r2,r1; strh`, while the equivalent `*p &= ~1` spends a literal-pool word on
`ands`.

Found in: src/matched/func_021F0B7C.c (0x021F0B7C)

The original is twelve bytes:

```
ldrh r2, [r0]
movs r1, #1
bics r2, r1
strh r2, [r0]
bx lr
```

A one-bit unsigned short bitfield assignment reproduces it exactly:

```c
struct S { unsigned short f0 : 1; };
void f(struct S *p) { p->f0 = 0; }
```

The plausible wrong C, `*p &= (unsigned short)~1;` (or `*p &= ~1;`), instead
materialises the 32-bit mask `0xFFFFFFFE` from the literal pool and uses
`ands r1, r2`, two bytes longer and in a different register:

```
ldrh r2, [r0]
ldr r1, [pc, #8]      ; 0xFFFFFFFE
ands r1, r2
strh r1, [r0]
bx lr
```

When the original has `bics` against a freshly-`movs`d `#1`, the source was a
bitfield clear, not a mask. This is the write-side twin of
`shift-pair-with-no-matching-type-is-a-bitfield.md` (which reads one).
