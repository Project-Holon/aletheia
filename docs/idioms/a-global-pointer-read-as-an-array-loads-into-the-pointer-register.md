# A global pointer declared as an array loads into the pointer's own register, and `*g` does not

summary: for a relocation that is a global pointer to one word,
`extern u32 g[];` read as `g[0]` makes mwccarm destroy the pointer register
with the load and schedule the load before the argument saves, while
`extern u32 *g;` read as `*g` picks a fresh destination register and delays
the load until one is free; the two spellings emit the same instruction count
in a different order, and only one of them is the original.

Found in: `src/matched/func_020337B8.c` (0x020337B8, lane r2b-1)

The original opens

```
020337B8  push {r3, r4, r5, r6, r7, lr}
020337BC  ldr  r3, [pc, #0xa0]      /* r3 = &g_020A789C */
020337C0  mov  r5, r0
020337C4  ldr  r3, [r3]             /* r3 = *g, the pointer register dies here */
020337C8  mov  r4, r1
020337CC  mov  r7, r2
020337D0  cmp  r3, #1
020337D4  bne  #0x203385c
```

so the load of the pointee is the second instruction of the body and it
overwrites the register that held the address.  Measured on this function,
holding the body fixed:

```
extern u32 *g;  if (*g == 1) { ... }       180 bytes on the first try only if
                                           the load lands in r1 after `mov r4, r1`,
                                           and both `if (*g == 1)` and
                                           `u32 st = *g; if (st == 1)` gave
                                           184 bytes with the pointer kept alive
extern u32  g[]; if (g[0] == 1) { ... }    180 bytes, prologue byte for byte
                                           identical to the original
```

The lever generalises because a one-word global pointer is exactly what the
generated listings make indirection look like, and the two spellings are the
same address and the same dereference: only the register the address dies in
changes, and with it the whole function's scheduling.  Reach for the array
spelling before searching for a different guard shape.

Related: `docs/idioms/declaration-order-decides-which-register-a-local-gets.md`
is the same class of finding one level down (a register number, not a
schedule), and `docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md`
records the argument-scheduling half.

This file is not yet in the index in `docs/AGENT-BRIEF.md`: regenerate it with
`python tools/match.py idioms` (integrator's step, do not hand-edit the index).
