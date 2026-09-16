# A `const` header pointer moves the loop-closing test's load to the top of the body

summary: when a counted loop's bound is a struct field that is still reloaded
every iteration, whether the reload sits above or below the body's stores says
whether the pointer is `const`; the `const` form also costs one extra
callee-saved register.

Found in: `src/matched/unit_02048BC4.c` (0x02048BC4)

`docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md` covers the case
where `const` removes a reload. This is the case where it does not: the field is
reloaded every iteration either way, and the only difference is *where*.

## The tell

The loop bound is a field of a pointer parameter, and the body stores through a
different pointer. Without `const` the closing test's load has to follow the
stores, because the stores may alias it:

```
    ...body stores...
    ldrb r3, [r4, #4]       @ s->count
    cmp  r1, r3
    blt  top
```

With `const` the same load schedules at the top of the body, above the stores,
and stays live across them:

```
    mul  r5, r1, r2
    ldr  r6, [r4]           @ s->recs
    ldrb r3, [r4, #4]       @ s->count, hoisted
    ...body stores...
    cmp  r1, r3
    ...more stores...
    blt  top
```

mwcc does no loop-invariant motion on loads, so `const` never lifts the reload
out of the loop altogether; it only lets it cross the stores inside one
iteration. That is why the original still looks, at a glance, like
non-`const` code.

## The register that gives it away

Holding the bound live across the whole body costs one more callee-saved
register. In the worked case that turned `push {r3, r4, r5, r6, lr}` plus a
`sub sp, sp, #4` (five registers, 20 bytes, so the frame needs four more bytes
of padding and the outgoing fifth argument needs its own slot) into
`push {r3, r4, r5, r6, r7, lr}` with no `sub` at all, because six registers are
24 bytes and the pushed r3 slot doubles as the outgoing argument area.

So the prologue is the cheap check: a function whose outgoing stack argument
goes to `[sp]` with no `sub sp` has one more callee-saved register live than
the obvious C gives it, and a loop bound that could be `const` is the first
place to look.

## Rule

Write the read-only header pointer `const` when the closing test's field load
appears above the body's stores. Do not spray `const` on the pointers that are
written through, and do not add it to a source pointer whose loads must stay in
source order: in `src/matched/unit_02048C58.c` the same keyword on
`func_02048CA4`'s source argument hoists all three halfword loads ahead of the
stores and is thirteen bytes wrong.
