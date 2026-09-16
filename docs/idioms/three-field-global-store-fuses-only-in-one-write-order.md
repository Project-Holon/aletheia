# Three field stores fuse into one `stm` in only one source order, and it is not field order

summary: a run of `str` into consecutive words of one global fuses into a
single `stm` only when the parameter that is already in its argument register
is written first and the two that need a `mov` are written last; any other
order leaves the first store stranded as a separate `str` and costs four
bytes.

Found in: `docs/notes/func_02066934.c.txt` (0x02066934), the store-fusion half
of that near miss

The original opens

```
02066934  push {r3, r4, r5, r6, r7, lr}
02066938  ldr  r3, [pc, #0x54]      ; &gUnk_02148B20
0206693C  movs r6, r1               ; n     (flags for the n == 0 return)
02066940  mov  r7, r0               ; recs
02066944  mov  r5, #0               ; i = 0
02066948  stm  r3, {r2, r6, r7}     ; cb, n, recs in one instruction
0206694C  popeq {r3, r4, r5, r6, r7, pc}
```

three words at +0x00/+0x04/+0x08 of one global, written from r2 (the third
parameter, untouched in its argument register), r6 and r7 (copies of the
second and first parameters, which the loop below also uses).

## The tell

The compile is the right length minus four, and the prologue reads

```
movs r6, r1
str  r2, [r3]
mov  r7, r0
mov  r4, #0
stmib r3, {r6, r7}
```

Two of the three did fuse. The one that did not is exactly the one whose
value needed no `mov`.

## Why

mwccarm fuses adjacent stores at selection time, before scheduling, and it
emits each value's `mov` immediately before the store that consumes it. A
value that is already in a register has no `mov`, so its `str` is emitted the
moment the base address is live, which is *before* the two `mov`s: the three
stores are no longer adjacent and only the last two can merge. Writing that
field first in the source puts its `str` at the head of the run, where the
other two stores' setup instructions have already been hoisted out of the way
by the loop that also needs r6 and r7, and all three become adjacent.

For 0x02066934 exactly one of the six orders reproduces the `stm`:

```c
gUnk_02148B20.cb    = cb;      /* +0x00, the parameter still in r2 */
gUnk_02148B20.recs  = recs;    /* +0x08 */
gUnk_02148B20.count = n;       /* +0x04 */
```

`cb, count, recs` (the field order) and `count, recs, cb` both give
`str r2, [r3]` plus `stmib r3, {r6, r7}`; `count, cb, recs` gives
`stm r3, {r2, r6}` plus a stranded `str`; `recs, cb, count` strands the
`str r7, [r3, #8]` instead; `recs, count, cb` fuses all three but emits the
two `mov`s in the wrong order.

## Not the aggregate path

The `ldm`/`stm` pair of
`docs/idioms/aggregate-assignment-is-ldm-stm.md` is a different mechanism and
the wrong tool here. A named local struct filled field by field and then
assigned (`gUnk_02148B20 = b;`) does reach `stm r3, {r0, r1, r2}`, but only
after `sub sp, sp, #0xc`, three stack stores and an `ldm` back out: 40 bytes
of round trip for an instruction the plain stores give for free. A compound
literal is the same lowering. When the source values are already in registers
and the destination is a global, the fusion you want is the peephole one, and
the only knob is the order you write the fields in.
