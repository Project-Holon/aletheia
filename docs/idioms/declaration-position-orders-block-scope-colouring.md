# A block-scope declaration's position among its neighbours decides a register pair, one slot at a time

summary: inside a nested block, moving one declaration by a single slot among the block's other
locals can swap two registers held by other variables' webs (including function-scope ones);
permutation sweeps that keep the moved local fixed at the end of the list never see it, so
try each insertion point of the mis-coloured local before giving up on declaration order.

Found in: src/pending/func_02094B8C.c (0x02094B8C)

MSL `__strtold`'s hex tail declares, in one else-block, the result double, a byte pointer
over it, a byte scratch and (for the second tail loop only) a fresh index and bit position.
The image keeps the pointer in `r4` and, in `r5`, both the first part's shift count
(`adds r5, r2, #1`) and the byte loaded in the second loop.

With the block written `ui2; ch2; hch; hexresult; p = (unsigned char *)&hexresult;` the
second loop's triple (ui2 r2, ch2 r3, hch r5) is right but the pointer and the r4/r5 pair
are the other way round (39 bytes). Measured positions of `p` against the rest
(1.1p1 -O4,p, concrete bytes out):

```
hexresult ui2 ch2 hch p        39   (p r5, the pair r4)
hexresult ui2 p ch2 hch        47
hexresult p ui2 ch2 hch        77
p at function scope (3 slots)  77   (every slot identical)
hexresult ui2 ch2 p hch         0   (MATCH, capped only by relocation evidence)
```

A lane had swept all six orders of ui2/ch2/hch with `p` fixed last and concluded the
pair could not be moved; the fix was one slot for `p` alone, between ch2 and hch. Dead
defs of `p` (`p = p;` in the loop), a second assignment of `p` before the swap loop
(+4 bytes), and moving `p`'s first def below the shift loop in a nested block all fail.

See also docs/idioms/declaration-order-decides-which-register-a-local-gets.md for the
plain two-local case.
