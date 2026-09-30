# A guard load that folds into its dying base register is not a source shape

summary: a load whose result is tested against 0 and then never used again
(`if (g->task != 0) f(0);`) is written in the image as `ldr rN, [r0, #off]` /
`cmp rN, #0`, with `rN` a register other than the base.  Every spelling of the
guard tried compiles the load into the base register it is loading through
(`ldr r0, [r0, #off]` / `cmp r0, #0`), and the residue is exactly the register
nibble of those two instructions.  The tie is between the `tagMEMUSB *` base
virtual register and the loaded value, and no source shape reaches the image
form; record the residue instead of chasing it.

Found in: src/pending/ov_sdk/ov016_func_021D0CEC.c (0x021D0CEC)

The image (ARM, 1.1p1 -O4,p), the `task` guard after `WM_End`:

    ldr   r4, [pc, #0x40]        ; &g
    ldr   r0, [r4]               ; g
    add   r0, r0, #0x1000
    ldr   r1, [r0, #0xb90]       ; g->task
    cmp   r1, #0
    beq   #0x21d0d94
    mov   r0, #0
    bl    #0x21d7744             ; DWCi_TSKlDeleteEx

`if (g->task != 0) DWCi_TSKlDeleteEx(0);` gives `ldr r0, [r0, #0xb90]` /
`cmp r0, #0` and is otherwise byte-identical: 220 bytes compiled, 9 of 9
relocations resolved, 2 concrete bytes differ, both register nibbles
(+0094 and +0098).  The neighbouring `end` guard in the same function does keep
a fresh register (`ldrb r1, [r0, #0xb94]` / `cmp r1, #2`), so the difference is
not that these guards are written differently -- it is that there `r0` is still
live for the compare's other operand only, while at `task` the base dies at the
load and the allocator has already reused it.

28 spellings were measured and every one of them leaves the same two bytes:
condition form (bare `if`, `!= 0`, `== 0` with an empty else, `0 != x`,
`!= (void *)0`, ternary in the condition, ternary as the statement, `&& 1`,
`x ? 1 : 0`, braced and unbraced); member type (`int`, `unsigned int`,
`unsigned long`, `void *`, non-volatile and volatile, reached through a
`volatile M *`); access form (`g->task`, `*(unsigned long *)&g->task`,
`*(void **)&g->task`, `((volatile unsigned long *)&g->task)[0]`,
`(char *)g + 0x1B90`); local-variable shapes (a second local at function scope,
the block-scope local, and reusing the existing local for the task value); and
a pointer local bound to `g` or to `&g->task`.  `const` on the read-only
extern (`M * const g`) is not a fix either -- it rewrites the whole function
rather than the guard.

Two useful negatives, since both look like the obvious lever: the guard load
does not become the image form by naming a temporary, and it does not become it
by widening the load to 32 bits.  What the image does with the value
(`cmp` only, result discarded) is already reproduced, so the residue is purely
register allocation of a dead base.

When a lane's residue is confined to the register nibbles of one guard load and
its compare, and the rest of the extent reproduces exactly, the right move is
to name it as an allocator tie in the blocker and stop: it is bounded (2 bytes
of 190 concrete), and the attempt budget is better spent on other lanes.  Write
the residue down; do not let the header claim MATCH, and do not create a shard.