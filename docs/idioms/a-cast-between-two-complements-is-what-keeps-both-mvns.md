# A cast between two complements is what keeps both `mvn`s

summary: `~(u32)~x` compiles to two live `mvn`s while `~n` with `n = ~x`, the
inline-helper form and every arithmetic rewrite (`x ^ -1`, `-x - 1`,
`0xffffffff - x`) all fold back to `x`; the intervening cast is the only thing
that stops the double-negation fold, and the statement boundary that puts the
first `mvn` before the surrounding `orr` is a separate lever.

Found in: `src/matched/func_0204CBB0.c` (0x0204CBB0)

The cell-actor record publisher ends with four bitfield moves, and the first of
them carries three instructions that compute nothing:

```
0204CC6C  and r2, r0, #0xff        m
0204CC70  mvn r0, r2               ~m
0204CC74  orr r1, r1, r2           v | m
0204CC78  mvn r0, r0               ~~m, which is m again
0204CC7C  and r0, r1, r0           (v | m) & m, which is m again
0204CC80  str r0, [r4, #0x84]
```

so the store's value is just `m`, and any C that says so loses twelve bytes.
mwccarm folds the redundancy out of every direct spelling: `(v | m) & m`
collapses by absorption, and `n = ~m; ... & ~n` collapses because `n` is
copy-propagated into its single use before the fold runs, as do
`~(m ^ 0xffffffffu)`, `~(0u - m - 1u)`, `& (0xffffffffu - n)`, a `static inline`
helper holding either half of the expression, and a second dead use of `n` to
try to defeat the propagation. Making the value `int` rather than `u32` does
not help either.

What survives is a cast between the two complements, because the conversion
node sits between them and the folder does not look through it:

```c
u8  m = e->f_08;          /* the redundant and #0xff is the u8 narrowing */
int n = ~m;               /* mvn */
v = r->unk_84 | m;        /* orr */
r->unk_84 = v & ~(u32)n;  /* mvn, and */
```

Writing it as one expression, `(r->unk_84 | m) & ~(u32)~m`, keeps both `mvn`s
but schedules them adjacent, `mvn; mvn; orr; and`. The original interleaves the
`orr` between them, and that ordering comes from the statement boundaries: the
complement, the disjunction and the conjunction each have to be their own
statement for the scheduler to lay them out in that order.
