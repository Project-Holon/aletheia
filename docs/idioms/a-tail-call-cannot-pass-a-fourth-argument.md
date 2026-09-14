# A tail call has only three argument registers, because r3 is the branch target

summary: `ldr r3, [pc, #n]; bx r3` spends r3 on the callee's address, so a
tail call can pass at most r0 to r2; the same call written with a fourth
argument becomes `push {r3, lr}; blx; pop {r3, pc}` and is eight bytes longer,
and a function that tail-calls a four-parameter callee is therefore evidence
that *this* translation unit declared it with three.

Found in: `src/matched/unit_0200B448.c` (0x0200B490, 0x0200B4B8), against
`src/matched/unit_0200B938.c` (0x0200B938) and
`src/matched/unit_0200B900.c` (0x0200B900)

`docs/idioms/tail-call-is-a-pool-word-and-bx.md` records that a Thumb tail
call materialises the callee's address through an `R_ARM_ABS32` pool word and
branches to it with `bx`. The register it branches through is r3, and r3 is
also the fourth argument register, so the two uses collide.

`func_0200B938` and `func_0200B490` compute the same checksum over the same
record and hand it to the same callee. The first keeps its result and is a
`bl`:

```
ldrh r3, [r0, r1]     /* v */
...
adds r2, r3, r2       /* v + ((v ^ 0xFFFF) << 16) */
bl   func_0200B900    /* r3 is still v: four arguments */
```

The second is a tail call, and the `ldrh` that produced v in r3 is overwritten
before the branch:

```
ldrh r3, [r0, r1]     /* v */
...
adds r2, r3, r2
ldr  r3, [pc, #0xc]   /* ... and now r3 is func_0200B900's address */
bx   r3               /* three arguments */
```

Nothing is lost, because `func_0200B900` ignores its arguments: its whole body
is a call to an ARM routine with no argument set-up at all. But the C has to
say so. Declaring the four-parameter prototype in the tail-calling file and
passing four arguments gives

```
push {r3, lr}
...
blx  func_0200B900
pop  {r3, pc}
```

which is four instructions and eight bytes more, and no spelling of the call
recovers the `bx` form while a fourth argument is live.

So the two files declare the same function differently, with three parameters
in one and four in the other, and both are right: C has no cross-translation-
unit prototype check, and the image records exactly this. The reverse reading
is the useful one: **a `ldr r3, [pc]` / `bx r3` tail call is a call of at most
three arguments**, whatever the callee's other callers pass, and an otherwise
byte-perfect function that is eight bytes long where the original is sixteen
has one argument too many rather than a scheduling problem.

The same collision explains a second detail in `func_0200B490`. With no
register to spare, the length 0x17DC cannot be held next to the offset
0x18A0 that the halfword load needs, so the file spends a pool word on 0x18A0
and reaches 0x17DC as `subs r1, #0xc4`; `func_0200B938`, which has r6 free,
spends no pool word for either.
