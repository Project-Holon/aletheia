# A compound assignment on a field flips the register pair of the guard above it

summary: `p->f14 = p->f14 + 1;` and `p->f14 += 1;` compile to identical
increment instructions, but the first form lands the two u16 loads of the
*preceding* guard in the opposite r0/r1 pair and moves the `adds` that follows
them, which is four concrete bytes in a four-instruction window; when an
otherwise byte-perfect function is off by a handful of bytes inside its guard,
try the compound spelling of a later store on the same field.

Found in: `src/matched/func_0202BFF0.c` (0x0202BFF0)

The body is a two-gauge update: a guard `if (o->f12 <= o->f14) return;`, the
counter bump, then two arms that each push `127.0f * (o->f14 / o->f12)` (the
second with `1.0f + `) through five MSL soft-float calls.

With the counter written as a plain assignment,

```c
if (o->f12 <= o->f14) {
    return;
}
id = o->fxe;
o->f14 = o->f14 + 1;
```

every one of the 128 bytes matched except four, all in the guard:

```
original                        with `= o->f14 + 1`
ldrh r1, [r5, #0x12]            ldrh r1, [r5, #0x14]
ldrh r0, [r5, #0x14]            ldrh r0, [r5, #0x12]
cmp  r1, r0                     cmp  r0, r1
...                             ...
adds r0, r0, #1                 adds r0, r1, #1
```

The two arms, the five library calls, the pool words and the frame (r4 for
the gauge id, r5 for the object, r6 for the float temporary) were all already
right, and the two spellings of the bump compile to the same `adds` once the
operands are coloured - so the source shape that changes is not the increment
but the allocator's *whole-function* colouring, which the front end computes
after it has seen the assignment form of the store.  Writing

```c
o->f14 += 1;
```

reproduces the original's assignment and the guard's pair with it; nothing
else in the function changes.

Two things that make this worth checking first when a guard is the only
residue.  The guard is at the very top of the function and its two loads are
the first two instructions that need a temporary, so they sit at the head of
whatever colouring the rest of the body induces - which is why a change
sixteen instructions further down can move them.  And the two forms really do
reach the backend as different trees (`a = a + k` is an add whose result is
stored, `a += k` a read-modify-write of the field), so this is not the
scheduler reshuffling equal inputs: it is the allocator seeing a different
body.
