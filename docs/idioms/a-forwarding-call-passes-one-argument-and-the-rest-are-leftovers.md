# A call that leaves the incoming argument registers alone is a one-argument call, not a four-argument one

summary: a `bl` at the top of a function with nothing between it and the
prologue looks like it forwards all four parameters, and usually it forwards
only the first; declaring the extra parameters keeps the caller's own arguments
live across the call and reallocates every callee-saved register in the
function, which reads as a scheduling problem twenty instructions later.

Found in: `src/pending/unit_0200B67C.c` (0x0200B67C, 0x0200B6E0), against
`src/matched/unit_0200C9EC.c` (0x0200CA1C)

`func_0200B6E0` opens by saving its parameters and then calling an extern:

```
0200B6E0  push {r3, r4, r5, r6, r7, lr}
0200B6E2  sub  sp, #8
0200B6E4  ldr  r6, [sp, #0x24]    /* the sixth parameter */
0200B6E6  adds r5, r0, #0
0200B6E8  adds r4, r1, #0
0200B6EA  str  r2, [sp, #4]
0200B6EC  adds r7, r3, #0
0200B6EE  bl   func_02012EBC      /* r0..r3 still hold a, b, c, d */
```

Nothing between the prologue and the `bl` touches `r1`, `r2` or `r3`, so the
call site is indistinguishable from `func_02012EBC(a, b, c, d)` and that is the
obvious way to write it. It is wrong, and the evidence is elsewhere in the
image: `src/matched/unit_0200C9EC.c` matched `func_0200CA1C` as
`func_0200CA10(func_02012EBC(a))` with a one-parameter prototype, and that
function's bytes leave no room for a second argument.

The cost of getting it wrong is not at the call. With four declared parameters
`b` is live from the entry, so it competes for a callee-saved register with the
locals of the arm that runs much later; the two sub-record pointers then share
registers with `b` instead of with `a`, and seven bytes spread over five
instructions at offsets 0x84 to 0x94 come out with every register interchanged.
The call itself is byte-identical either way.

Measured on this unit, holding everything else fixed:

```
one parameter,  q assigned before r    ->  0 concrete bytes wrong
four parameters, q assigned before r   -> 24 concrete bytes wrong
```

The reverse reading, and it is worth reaching for before spending an hour on
register allocation: **a call whose arguments are all already in place tells you
nothing about how many it takes.** Look for the same extern called from a
function that has to set the registers up, or for a matched file that already
declares it. A four-argument call that really is one sets at least one of `r1`
to `r3`, because the caller's own parameters are almost never in the callee's
order.

The tail-call case is the same collision seen from the other side:
`docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md` records that
`ldr r3, [pc]` / `bx r3` spends `r3` and so caps the call at three arguments.
There the arity is readable from the bytes; here it is not, and the only
honest source of it is another call site.
