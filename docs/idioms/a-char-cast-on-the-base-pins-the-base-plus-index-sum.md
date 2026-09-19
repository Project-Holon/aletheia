# A redundant `char *` cast on the base pins the base-plus-index sum below the guard

summary: a `base + i * K` address that the front end otherwise schedules ABOVE
the guard branch (`ldr base` / `ldr v,[base,off]` / `add tmp,base,off` /
`cmp v,#0` / `beq`, 7 instructions where 6 belong) is scheduled inside the
guarded block once the same access spells the base through a `char *` cast -
unsigned/`u8 *` arithmetic and `char *` arithmetic are two different DAG nodes
to the scheduler, and only the second leaves the sum where the original has
it.

Found in: `src/matched/func_0204F1A0.c` (0x0204F1A0)

The function indexes a 0x28-byte record array hanging off `o->f04`, tests the
record's first word and, when set, hands two of its fields to two indirect
callbacks. With the field typed `u8 *` and every access written
`*(u32 *)(o->f04 + off + 0x20)`, the compiler computes `base + off` BEFORE the
guard test, in the register the load then uses:

```
  +0010  ldr r1, [r5, #4]        | ldr r2, [r5, #4]
  +0014  ldr r0, [r1, r4]        | ldr r0, [r2, r4]
  +0018  add r2, r1, r4          | cmp r0, #0            <- the sum is hoisted
  +001C  cmp r0, #0              | beq  ...
  +0020  beq  ...                | ldr r1, [pc, #0x40]
  +0024  ldr r1, [pc, #0x40]     | add r0, r2, r4
  +0028  ldr r0, [r2, #0x20]     | ldr r0, [r0, #0x20]
```

The instruction count is identical, only the placement differs, so the residue
is 18 bytes of DIFF that no operand reordering fixes. Spelling the three
accesses inside the body through `(char *)` - and only those, the guard stays
`o->f04 + off` - reproduces the original exactly:

```c
    if (*(u32 *)(a0->f04 + off) != 0) {
        g_020A8144(*(u32 *)((char *)a0->f04 + off + 0x20));
        g_020A814C(*(u32 *)((char *)a0->f04 + off + 0x24));
        *(u32 *)((char *)a0->f04 + off) = 0;
    }
    *(u32 *)((char *)a0->f04 + off + 0x14) = 5;
```

Two traps around it:

* the cast belongs on the BODY accesses only. Casting the guard too (all four
  accesses through `char *`) hoists the sum again - 18 bytes of DIFF, back
  where it started. The guard's own node is what the scheduler is comparing
  the body's node against;
* `u8 *` and `char *` are the same machine type, so the cast is free at every
  other level: it changes no load, no store and no immediate, only which node
  the address sum belongs to.

The general rule: when the only difference is a `base + index` sum sitting one
slot too early (a hoisted `add` above a guard that consumes the same sum), look
for a comparison `cmp`/`beq` between the load and the sum, and re-spell the
LATER uses through a differently-qualified pointer type.
