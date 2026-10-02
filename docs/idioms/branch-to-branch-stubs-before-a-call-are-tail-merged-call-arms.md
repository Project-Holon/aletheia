# Branch-to-branch stubs before a call are tail-merged call arms

Shape: a nested compare tree (for example a 3-way max) whose leaves are
`adds r0, rX` or nothing, with lone `b` stubs that jump to another `b` or to a
shared `adds r0, r2` block, followed by one constant load and one call whose
result is stored and then immediately reloaded from memory
(`str r0, [r5, #0xc]` ... `ldr r1, [r5, #0xc]`).

Source: every arm of the if/else tree makes the call itself and stores the
result, e.g.

    if (o->a > o->b) {
        if (o->a > o->c) o->m = FX_Div(o->a, 0x4000);
        else             o->m = FX_Div(o->c, 0x4000);
    } else if (o->b > o->c) o->m = FX_Div(o->b, 0x4000);
    else                    o->m = FX_Div(o->c, 0x4000);

The compiler tail-merges the identical `movs r1; blx; str` tails into one
block, which leaves the empty and duplicate arms as branch stubs. Because the
store sits in that merged block, the next statement reloads the field instead
of forwarding it, and the call's constant is not kept live for later reuse.
A local `m` computed by ternaries or if/else and passed to one call gives
`bgt` polarity, a forwarded register and a constant held in a callee-saved
register instead.

Seen: ov021 func_021A1784 (src/pending/ov/ov021_func_021A1784.c).
