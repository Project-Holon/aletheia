# A field offset derived from a live base after an if is the stores repeated in each arm

summary: under 1.1p1 -O4,p (Thumb) the image loads a large offset K from the pool before an
if/else (often for a load in the condition), and after the arms join it builds nearby offsets
as `adds rX, rK, #0; subs rX, #d` from the same register instead of a new pool word. The
source writes the stores that follow the join in EACH arm, with literal values. The compiler
derives the nearby offsets from K inside each arm, then tail-merges the identical suffix of
both arms into the join block, so K stays live across the join. A local `int off = K;` does
not do this (the local is folded and a second pool word appears).

Found in: src/matched/ov/ov111_func_021C4E0C.c (0x021C4E0C, ov111, Thumb) and
src/matched/ov/ov197_func_0220BD24.c (0x0220BD24, ov197, Thumb). Related:
a-constant-shifted-in-a-merged-tail-is-a-statement-repeated-in-each-arm.md.

## The tell

```
ldr  r1, =0x305C        ; K, loaded for the condition
ldrh r0, [r4, r1]
cmp  r0, #0
bne  1f
movs r2, #0x20
b    2f
1: movs r2, #0xe0
2: adds r0, r1, #0      ; join block: offsets come from K, not from the pool
subs r0, #0x10
str  r2, [r4, r0]
movs r0, #0x98
subs r1, #0xc
str  r0, [r4, r1]
```

A draft with one store after the if (`v = c ? 0xE0 : 0x20; *(u32 *)(p + 0x304C) = v;`) loads
0x304C as a new pool word, and the pool has one extra entry.

## The source

```c
if (*(u16 *)(p + 0x305C) == 0) {
    *(u32 *)(p + 0x304C) = 0x20;
    *(u32 *)(p + 0x3050) = 0x98;
} else {
    *(u32 *)(p + 0x304C) = 0xE0;
    *(u32 *)(p + 0x3050) = 0x98;
}
```

The part that differs between the arms (the value) stays in each arm; everything after it is
merged. In ov197 0x0220BD24 two whole calls `f(mgr, 11, 0, 0, 5, 5, pal)` and
`f(mgr, 12, ...)` are written in each arm with the literal pal; the image keeps r4 = 0x533
(the condition's base) and reaches the 0x520 field as `r4 - 0x13`, and the two
`str r6, [sp]` / `str r6, [sp, #4]` argument stores stay in each arm.
