# A cross-jumped tail reloads the base member, not the arm's hoisted pointer

summary: When a local pointer is hoisted before an if/else-if chain for the
field accesses inside the arms, an arm whose argument expression follows a call
must name the *base member* again, not the local pointer; otherwise the pointer
is kept live across the call (callee-saved) and the whole function's register
allocation drifts.

Found in: src/matched/ov175_func_021E02F0.c (0x021E02F0)

The original loads `o->f124` once, before the `o->f0` chain, into a
caller-saved register, and each arm's field accesses use it. But the two arms
that end in a call write the call's pointer argument as `o->f124 + o->f4`, not
`n + o->f4`. That is not a stylistic tic: the call is an extern with unknown side
effects, so the compiler cannot prove `o->f124` is unchanged across it and must
emit a fresh `ldr r2, [r6, #0x124]` in the cross-jumped tail. The local `n` is
dead there (its last use is the arm's own field increments), so it stays in the
caller-saved register the hoist put it in.

Writing the arm argument as `(char *)n + o->f4` instead makes `n` live across the
call, so the compiler promotes it to a callee-saved register (and pushes one more
register); the prologue, every shared-tail offset and the total size all change,
while the field semantics are identical.

C that reproduces it:

```c
int f0 = o->f0;
Node *n = o->f124;          /* hoisted, caller-saved */
if (f0 == 2) {
    n->h24++;
    n->w38 += 8;
} else if (f0 == 3) {
    n->h26++;
    n->w3c += 8;
    o->h8++;
    func((char *)o->f124 + o->f4, o->h8);   /* base member, not n */
} else if (f0 == 4) {
    n->h28++;
    n->w40 += 8;
    o->h8++;
    func((char *)o->f124 + o->f4, o->h8);
}
func((char *)o->f124 + o->f120, (short)a);
```

The plausible wrong C is the same body with the two call arguments written as
`(char *)n + o->f4`; it compiles to 260 bytes against the original's 264, with the
local promoted to a callee-saved register.
