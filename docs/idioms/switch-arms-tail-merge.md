# What both arms of a switch do is emitted once, and the default jumps over it

summary: an assignment made by every case of a switch is tail-merged into a
single block the default case branches past, so writing it after the switch
instead moves one branch target and reallocates every register in the function.

Found in: `src/matched/unit_0200A3FC.c` (0x0200A4B8, 0x0200A50C)

Two functions in that unit begin with a two-case switch over a kind that is
only ever 0 or 1, and neither has a `default:`. The original:

```
        cmp  r1, #0
        beq  .case0
        cmp  r1, #1
        beq  .case1
        b    .body            /* the default: falls past the merge block */
.case0: movs r6, #0xda
        lsls r6, r6, #2       /* size = 0x368 */
        b    .merge
.case1: ldr  r6, =0xA94       /* size = 0xA94 */
.merge: subs r0, r6, #4       /* h = base + size - 4, from BOTH arms */
        adds r4, r5, r0
.body:  ...
```

`.merge` is the tail of the two case bodies, cross-jumped into one copy. The
default path branches to `.body`, *past* it, which means the pointer is
uninitialised when the kind is neither 0 nor 1: exactly what the C says, since
the switch has no default and the local is never assigned on that path.

So the source has the pointer computation inside each arm:

```c
switch (kind) {
case 0:
    size = 0x368;
    h = (struct Hdr *)((u8 *)base + (size - 4));
    break;
case 1:
    size = 0xA94;
    h = (struct Hdr *)((u8 *)base + (size - 4));
    break;
}
```

Hoisting it out of the switch, which is the obvious way to write it and the
way that does not repeat itself, gives the compiler the same merged block but
makes the default branch *to* it rather than past it. That is one halfword,
and it looks like a trivial fix. It is not: with the computation after the
switch the pointer is live on the default path too, the register pressure
changes, and both functions come out with `base`, `size` and `h` in different
registers throughout. Twenty-five bytes differ in a 84-byte function and every
one of them is a register number.

The reverse reading is the useful one. A `b` at the end of the dispatch chain
that lands *after* a block both arms fall into says that block is inside the
arms in the source, and that the variable it writes is genuinely undefined on
the default path.
