# An if/else that stores to the same target in both arms keeps a `b` to the next instruction

summary: `bpl L; rsbs r1,r1,#0; b next; L: next: str r1,[..]` (a branch to the very next
instruction) is `if (c) p[3] = -step; else p[3] = step;`; a negate-in-place followed by
one store (`if (c) step = -step; p[3] = step;`) or the `?:` form compiles without the `b`.

Found in: src/matched/ov/ov043_func_021F398C.c (0x021F398C)

Original tail of the function: `subs r2,r3,r2; bpl +4; rsbs r1,r1,#0; b .+2; str r1,[r0,#0xc]`.
The compiler cross-jumps the two identical stores but keeps the `b` that ended the
then-arm, so the else arm is empty. Tried without success: negate a local then store
(`step = -step`), the ternary, an empty `else {}`, `else { step = step; }`, `d >= 0`
polarity with the negation in the else arm (that flips `bpl` to `bmi` and moves the
`rsbs`). Only the store written in each arm, negated arm first, gives EXACT.
