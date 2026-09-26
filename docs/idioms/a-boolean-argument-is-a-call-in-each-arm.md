# A 0/1 argument passed to a call is the call written in each arm, not a value

summary: When the original materialises a boolean argument for a call as
`tst; beq .set1; movs r0,#0; b .end; .set1: movs r0,#1; .end: bl`, no value
expression reproduces it. `(x & 3) == 0`, `(x & 3) == 0 ? 1 : 0`, `!(x & 3)`,
an if/else assigning both polarities to a local, and a two-case switch with a
call in each case all compile to the mirror `tst; bne .set0; movs r0,#1; b
.end; .set0: movs r0,#0` — mwccarm canonicalises the value's true arm as the
fall-through. The original orientation only comes back when the **call** is
written in each arm and the optimiser tail-merges it:

```c
if ((func_020362DC() & 3) != 0)
    func_020355D8(0);     /* beq .set1; movs r0,#0; b; .set1: movs r0,#1 */
else
    func_020355D8(1);
```

Found in: `src/matched/ov195_func_0220546C.c` (0x0220546C, ov195). The same
argument idiom is parked at DIFF in `src/pending/ov195_func_022053E8.c`, where
the call already ends in a shared `return` and the value form was used; the
register-allocation blocker there is separate, but the argument orientation is
this one.

Tell: a 3-byte diff confined to `beq`/`bne` and the two `movs r0,#imm` either
side of it, same total size. Do not keep permuting the comparison; move the
call into both arms.
