# A branch to a branch after a two-part test is a nested if with the call in all three arms

summary: when a 0/1 argument chosen by `a && b` compiles in the image to a `b` that lands on another `b` (the inner else hopping to the outer else), with the shared first argument loaded above each conditional branch, the source is a nested if/else whose three arms each call the function; `a && b` in one if/else, a ternary, a flag local or the test inside the argument list all thread the hop away and load the argument after the join.

Found in: src/pending/ov010_func_02160018.c (0x02160018, state 12)

The image (Thumb, 1.1p1 -O4,p):

    cmp   r7, #0
    ldr   r0, [r4, #4]      ; w->f04, hoisted above the branch
    bne   FC
    bl    func_020120F4     ; ... func_02012B28(...)
    cmp   r0, #1
    ldr   r0, [r4, #4]      ; reloaded, hoisted again
    bne   FA
    movs  r1, #1
    b     FE
FA: b     FC                ; the hop
FC: movs  r1, #0
FE: bl    func_021606DC

The C that reproduces it, with the result in a local that the next call
consumes:

    if (i == 0) {
        if (func_02012B28(func_020127A4(func_020120F4(w->f04))) == 1)
            t = func_021606DC(w->f04, 1);
        else
            t = func_021606DC(w->f04, 0);
    } else {
        t = func_021606DC(w->f04, 0);
    }
    func_02012374(evt, t);

The three calls are cross-jumped into one `bl` with only `r1` set per arm,
and the two identical else arms leave the unthreaded `b FA -> b FC` hop.
`if (i == 0 && f(...) == 1) t = g(p, 1); else t = g(p, 0);` gives the same
bytes except that the `w->f04` loads sit in the arms instead of above the
branches (5 instructions out); the ternary, a `u32 x` flag local and
`g(p, i == 0 && f(...) == 1)` all fold to a 576-byte function. Writing the
tail call (`func_02012374(evt, t)`) once after the local, rather than in
each arm, is also what lets the neighbouring state jump into the shared
`adds r0, r6, #0; bl func_02012374` tail. Related:
docs/idioms/a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.md.
