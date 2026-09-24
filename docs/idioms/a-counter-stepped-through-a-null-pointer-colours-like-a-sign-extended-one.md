# A counter stepped through a null pointer colours like a sign-extended one, at no cost

summary: when a loop counter needs a lower allocation priority than the int webs around it (the image gives it a later callee-saved register) and only a sign-extending narrow type (`short i`) reproduces that ranking at the price of the extension instructions, keep `int i` and write the increment as `i = (int)((char *)0 + i + 1);`. It compiles to the same single `add`, but the loop-carried definition reaches the allocator as a pointer temporary, which ranks i the way the narrow type does.

Found in: src/matched/func_02048744.c (0x02048744, g3d_util.c)

The image keeps resIdx in r7, the objTbl/j web in r8 and the outer counter
i in sb.  With `int i` the compile swaps resIdx and i (18 bytes out; 14 with
long locals).  Four wave-21 lanes established:

- registers fall into bands by rank, and only a SIGN-extended narrow
  counter (short, signed char, char i) gives the image's ranking: 476 bytes,
  45 out, every byte right except the extension of the increment; u8/u16
  and union-long counters fall to the long band;
- codeless extra references to i (self-assignments, i*0, i-i, dead
  conditionals, unused inline parameters) are folded before costing;
- routing the increment through a copy does not move it here.

So what ranks i is the kind of expression that defines it each iteration,
not its type or its use count.  A pointer step supplies that without the
extension:

    for (i = 0; i < objCount; i = (int)((char *)0 + i + 1)) {

EXACT under dsi/1.1p1 (468 bytes); `(u8 *)0` is equally EXACT.  Nearby
spellings stay at 18: `(int)((u8 *)0 + (i + 1))`, `(int)&((u8 *)0)[i + 1]`,
`(int)((u8 *)i + 1)`.  On the long base every variant stays at 14.

Tell: a loop counter the image colours below neighbouring int webs, where a
`short` counter gets the registers right but adds `lsl`/`asr` pairs.  Try the
null-pointer step before anything else.  Related:
docs/idioms/an-arithmetic-loop-carried-definition-colours-last-unless-it-goes-through-a-copy.md
(the copy form re-ranks a pointer up; this form re-ranks a counter down).
