# A post-increment used as a value spends a register copy and recomputes the field's offset

summary: `return p->f++;` and `n = p->f; p->f = n + 1; return n;` are not the
same code: the post-increment copies the loaded byte into a second register
before adding one and then rebuilds the address offset it had a moment ago, so
it is two instructions and four bytes longer than the spelled out version that
looks like its definition.

Found in: `src/matched/unit_02012924.c` (0x020129FC)

`func_020129FC` hands out the next value of a counter, and the whole of it is a
guard and a post-increment. The original:

```
020129FC  push {r3, r4}
020129FE  ldr  r2, [pc, #0x20]      /* 0x1C9 */
02012A00  ldrb r1, [r0, r2]
02012A02  cmp  r1, #0
02012A04  beq  .zero
02012A06  subs r1, r2, #1           /* 0x1C8, off the pool constant */
02012A08  ldrb r4, [r0, r1]
02012A0A  adds r1, r4, #0           /* the copy */
02012A0C  adds r3, r1, #1
02012A0E  subs r1, r2, #1           /* ... and 0x1C8 again */
02012A10  strb r3, [r0, r1]
02012A12  adds r0, r4, #0
02012A14  pop  {r3, r4}
02012A16  bx   lr
.zero:
02012A18  movs r0, #0
```

The spelling that reads like the semantics,

```c
n = p->unk1C8;
p->unk1C8 = n + 1;
return n;
```

drops both: `adds r3, r4, #1` goes straight off the loaded register and the
offset stays in `r1`, so the function is 36 bytes against the original's 40 and
23 concrete bytes differ, most of them because everything after the `beq` has
shifted by four. Written as

```c
if (p->unk1C9 != 0) {
    return p->unk1C8++;
}
return 0;
```

it is EXACT.

What the compiler is doing is lowering `p->f++` as "materialise the old value,
then evaluate the store", rather than as "load, add, store, return the load".
The old value is already in a register and the copy is dead, and the address
offset is live across the copy and gets rebuilt rather than kept; neither
survives to `-O4,p`'s peephole. So the two extra instructions are the visible
signature of the operator and not of the types or of the guard.

The reverse reading is the useful one, and it is mechanical: a read-modify-write
on a field whose loaded value is **copied to another register before the add**,
with the field's offset computed twice on either side of that copy, is a
post-increment or post-decrement used as a value. The same field incremented
from a register the function already holds, with one offset computation, is the
spelled out assignment. Two instructions apart, and nothing else in the
function moves.

This is the value-expression counterpart of
`docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md`,
which covers `p->f += k` as a statement: there the tell is a second `ldrb`,
here it is a register copy, and in both cases the tidier looking C is the wrong
one.
