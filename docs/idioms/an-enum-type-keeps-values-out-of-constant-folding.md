# An enum type keeps a value out of mwcc's early folding: SDK enum parameters and enum loop counters

summary: with `-enum int`, a value typed as an enum is not folded or
substituted the way an `int` is.  An enum loop counter keeps the unfolded
`cmp; bge` entry guard with a plain increment (no `int` or narrow type gives
both), and an inline whose parameters are the SDK's enum types materialises
its arguments into temporaries, right to left, before the body runs.

Found in: src/matched/func_02010DF4.c (0x02010DF4), src/matched/func_02010DCC.c
(0x02010DCC), src/matched/sub_0200FEBC.c (0x0200FEBC)

Loop counter.  The image opens a thirteen-slot loop with a guard the compiler
could have folded:

```
movs r4, #0
cmp  r4, #0xd       <- 0 < 13, not folded
bge  exit
...
adds r4, r4, #1     <- plain increment, no lsls/lsrs pair
cmp  r4, #0xd
blt  loop
```

`int i` folds the guard (28 bytes against 32); `s8`/`u8`/`s16` keep it but
add a truncation pair to the increment.  Declaring the counter as an enum
(`typedef enum { SLOT_0, SLOT_MAX = 13 } Slot; Slot i;`) gives both halves and
is exact.  1050 permuter compiles never found it, because the permuter's
`type` mutation only cycles integer types.

Inline parameters.  sub_0200FEBC calls the SDK's G2_SetBG1Control with five
bitfield reads of a saved control word.  With `int` parameters the inliner
substitutes each extraction straight into the expression after the
`reg_G2_BG1CNT` read (43 bytes out).  With the SDK's own parameter types
(GXBGScrSizeText, GXBGColorMode, GXBGScrBase, GXBGCharBase, GXBGExtPltt) every
argument is extracted first, last argument first, and the register is read
last, which is what the image does.  The same inline with `int` parameters is
still exact where its arguments are plain register fields (sub_0200FD38), so
a correct SDK inline written with the wrong parameter types can hide here.

So: when a residue is an unfolded test or an argument evaluation order that no
statement ordering moves, check whether the original typed the value as an
enum.
