# A call-argument difference written as a local's initialiser takes a free argument register for the constant

summary: `movs r1, #K; lsls r1, #n; subs r2, r0, r1` right after a call, feeding
the third argument of the next call, is `int v = f(...) - K; g(a, b, v);`;
writing `g(a, b, f(...) - K)` (or `v = f(...); g(a, b, v - K)`) builds the
constant in r2 and copies the call result to r3 first, two bytes longer.

Found in: `src/matched/ov/ov021_func_02187F00.c` (0x02187F00).

The difference is where the subtraction sits in the source, not its types:
`unsigned`, `short`, `+ -K`, `-K + v`, `(K' << 12)`, a cast, and a split
`v -= K` statement all produce the longer sequence. Only folding the
subtraction into the declaration's initialiser reproduced the original.
