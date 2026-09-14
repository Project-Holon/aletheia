# A post-decrement in the loop condition splits the compare from the subtract

summary: `while (n-- != 0)` compiles to a `cmp n, #0` and a flagless
`sub n, n, #1` with the branch reading the compare, while the equivalent
`while (n != 0) { ...; n--; }` folds both into one `subs`; they are the same
loop with the same trip count, but the post-decrement form is two instructions
and eight bytes longer, once at the rotated entry test and once per body.

Found in: `src/matched/sub_020343C0.c` (0x020343C0), `docs/notes/sub_020343C0.c.txt`

The bitmap fill loop in the area manager runs a counted number of 0xFF bytes
out and the original spells it

```
020344a4  cmp r3, #0              /* the test reads the pre-decrement value */
020344a8  strb ip, [r4]
020344ac  add r1, r1, #1
020344b0  sub r3, r3, #1          /* no S bit: the flags above still stand */
020344b4  beq .tail
020344b8  mov ip, #0xff
020344bc  add r4, r0, r1
020344c0  cmp r3, #0
020344c4  strb ip, [r4, #0xc]
020344c8  add r1, r1, #1
020344cc  sub r3, r3, #1
020344d0  bne .body
```

Note that the peeled first iteration and the loop body carry the same
`cmp`/`sub` pair, and that the branch at the bottom is a long way from the
`sub` that changes the counter. That separation is the tell. The C is

```c
while (nfull-- != 0) {
    p->bits[idx] = 0xFF;
    idx++;
}
```

The obvious rewrite, decrementing inside the body,

```c
while (nfull != 0) {
    p->bits[idx] = 0xFF;
    idx++;
    nfull--;
}
```

folds the compare into the subtract in both places, and the function shrinks
from 256 bytes to 248:

```
020344a4  cmp r1, #0
020344a8  add r5, r5, #1
020344ac  beq .tail
020344b0  mov ip, #0xff
020344b4  add r3, r0, r5
020344b8  strb ip, [r3, #0xc]
020344bc  add r5, r5, #1
020344c0  subs r1, r1, #1         /* one instruction fewer in the dependence */
020344c4  bne .body
```

Eight bytes is small enough that on a 250 byte function it reads as "two
instructions missing somewhere", and because everything from the loop onward
shifts by the same amount the diff looks like a register allocation problem
rather than a statement-form problem. The rule is simple in both directions: a `subs`
on the counter immediately before the back edge is the decrement written in
the body, and a bare `sub` with a separate earlier `cmp` is the post-decrement
written in the condition.
