# A case guard whose return sits after the case body wraps the body

summary: in a Thumb switch arm, a `beq` from the arm's first test to a separate
`add sp; movs r0,#0; pop` block placed after the arm's body is `if (x != v) { body; break; } return 0;`,
not `if (x == v) return 0; body;` (that form puts the return inline, right after a `bne`).

Found in: src/matched/ov/ov227_func_021B963C.c (0x021B963C), cases 1 and 2.

The same function also showed two smaller shapes:

- `movs r1,#0; cmp r0,#1; bne; movs r1,#1; cmp r1,#0; beq` is a flag written in steps:
  `ok = 0; if (g->f24 == 1) ok = 1; if (ok) { ... }`. A static inline `return v == 1;` folds away.
- `cmp fl,#0; beq L; movs r0,#0; b J; L: movs r0,#1; J: str` is `if (fl) f = 0; else f = 1;`.
  The ternaries `fl ? 0 : 1`, `fl == 0 ? 1 : 0` and `!fl` all give the inverted `bne` layout.
- A zero flag stored to its stack slot between the `ldrh` of a stack argument and the call setup was
  written as `fl = 0;` after the call statement in the source, not before it.
