# A tail call's pool word is issued before the write of its last argument, and no C moves it

summary: for a one-section `bx ip` tail call this front end emits the pool
load naming the callee after every argument instruction, while the original
issues it in the slot just before the last argument write, so a bare wrapper
comes out with the two instructions transposed and eight bytes of diff.

Found in: near miss on 0x02072A88 (`pkt_02072A44`) and 0x02072E7C
(`pkt_02072C40`); the filed case 0x02076B8C (`pkt_02076B8C`, single
instruction, no argument to schedule around) is unaffected.

The two cheapest instances are one-liners whose whole body is a call:

```c
void func_02072A88(u32 *p) { func_02072974(1 << *p); }
void func_02072E7C(u32 *p) { func_02073438(*p); }
```

```
0x02072A88  ORIGINAL                            COMPILED
            ldr r0, [r0]                        ldr r0, [r0]
            mov r1, #1                          mov r1, #1
            ldr ip, [pc, #4]   <-- here         lsl r0, r1, r0
            lsl r0, r1, r0                      ldr ip, [pc]
            bx  ip                              bx  ip
            .word 0x02072974                    .word 0x02072974

0x02072E7C  ORIGINAL                            COMPILED
            ldr ip, [pc, #4]   <-- here         ldr r0, [r0]
            ldr r0, [r0]                        ldr ip, [pc]
            bx  ip                              bx  ip
            .word 0x02073438                    .word 0x02073438
```

In both cases every argument instruction is right and the relocation resolves
through the ordinary `label` class; the two instructions are simply in the
other order, and the file is a same-size `DIFF`, never a `MATCH`, so it cannot
be parked.

Spellings that were measured on 0x02072A88 and all leave the pool load last:
the void form, a `return` form with the callee declared to return `u32`, the
argument bound to a named local first, and `1u` instead of `1`. The same
schedule gap reappears with the pool load between a `mov` and an `lsl` in
0x02072E7C, so it is not a property of one instruction.

Practical consequence: a bare tail-call wrapper is worth one compile to see
whether its schedule happens to line up, but if the diff is only this
transposition do not iterate - there is no source shape to move it, and the
same file with the pool load in the original's slot is one instruction of
`-O4,p` scheduling away.
