# A read-modify-write of the field just stored zero is what emits bic, a plain masked assignment folds away

summary: `p->f = 0; p->f = (p->f & ~mask) | (x & mask);` emits the `bic rD, rZ, #imm` a bitfield clear
shows, because the dead store is forwarded to the second statement as a register value. The obvious
spelling `p->f = x & mask;` folds to a bare `and` (or to nothing) and loses the `bic` and the register
that held the zero.

Found in: open functions `0x020606D0` (packet `pkt_020606A8`) and `0x02060814` (packet `pkt_02060814`)

Both functions open with the same shape, a word or halfword field cleared a bit at a time:

```
020606E0  mov  ip, #0              /* the zero, materialised in a register */
020606E8  bic  r1, ip, #0xff       /* clear the low byte of it */
020606EC  and  r0, r0, #0xff       /* the new value */
020606F0  orr  r2, r1, r0
02060700  str  r2, [r4, #0x20]
```

and

```
02060834  mov  r0, #0
02060838  strh r0, [r4, #0x34]
0206083C  bic  r0, r0, #1          /* clear bit 0 of the value just stored next door */
02060840  strh r0, [r4, #0x36]
```

What produces this is a store followed by a read-modify-write of the field that was just
stored, never a single masked assignment:

```c
p->f20 = 0;                                  /* dead store, forwarded as a register */
p->f20 = (p->f20 & ~0xff) | (a4 & 0xff);     /* mov ip,#0; bic; and; orr; str  -- the shape above */

p->f34 = 0;
p->f36 = p->f34 & ~1;                        /* mov r0,#0; strh; bic r0,r0,#1; strh -- the shape above */
```

What does not work, each compiled and compared:

```c
p->f20 = a4 & 0xff;                 /* one `and`, no bic, no zero register: the store is a constant */
u32 v = 0; p->f20 = v & ~0xff | a4 & 0xff;   /* folded: v is a known zero, so the mask disappears */
p->f36 = 0; p->f36 = p->f36 & 0xfffe;        /* 0xfffe is a 16-bit mask, so mwcc pools the word and
                                                emits `and` instead of the immediate `bic` */
```

Two things follow that are worth knowing before writing the C for this family.

The mask has to be a 32-bit complement to reach `bic` with an immediate. `& ~1` gives
`bic r0, r0, #1`; `& 0xfffe` gives a pool word `0x0000fffe` and an `and`, and on a value mwcc
knows is zero it degrades further to `and r1, r0, #0`, which is a different function.

The zero register is what the two variants differ by, and it is observable. mwcc will not fold a
value it has already assigned to a local or has in flight from a dead store, so the AND-NOT
survives as a real instruction; a zero written directly into the expression is folded at once.

What this does not fix is which register gets the zero. In the residue left on both functions above
the zero is coalesced into a callee-saved register and stays live to the end of the function, where
the original materialises it into a caller-saved register after each call. Both remaining deltas on
those two functions are that one choice plus the scheduling it implies, at identical instruction
count and identical instruction selection.
