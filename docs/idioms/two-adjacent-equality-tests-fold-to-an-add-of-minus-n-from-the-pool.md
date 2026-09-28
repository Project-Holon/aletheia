# Two adjacent equality tests on a u16 fold to a pooled 0xFFFE add, not `subs #2`

summary: `x == 2 || x == 3` on a u16 compiles to `ldr rN, =0xFFFE; adds rN, x, rN; lsls/lsrs #16; cmp rN, #1; bhi` (and is hoisted out of a loop into a spill slot); the hand-folded `(u16)(x - 2) <= 1` gives `subs rN, x, #2` instead, and `x >= 2 && x <= 3` keeps two compares.

Found in: src/matched/ov/ov010_func_02162970.c (0x02162970)

The trigger scan tests `type` against 2..3 in one switch arm. The image computes
`(u16)(type + 0xFFFE)` once before the loop (the 0xFFFE sits in the literal pool)
and compares the spilled value with 1 in the arm. Only the or-of-equalities
spelling (or a literal `+ 0xFFFE` / `+ (u16)-2`) reproduces the pooled constant;
any explicit subtraction of 2 is emitted as `subs #2` and is 186 bytes out after
the pool shift.
