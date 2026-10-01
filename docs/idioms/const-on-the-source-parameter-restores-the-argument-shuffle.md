# `const` on a read-only source parameter restores the vendor's two-scratch argument shuffle

summary: a small forwarder whose only residue is one extra `mov` in the
argument-move sequencer (the vendor parks both pointer arguments in scratch
registers `lr` and `ip`; ours needs only `ip`) goes EXACT when the source
pointer the function reads through is declared `const`, together with a callee
prototype that accepts it. The qualifier changes the front end's parameter
homing, not the load order.

Found in: `src/matched/ov_sdk/ov009_func_0217D8E0.c` (0x0217D8E0, ov009,
`gsLargeIntDiv`, `gslargeint.o`).

The whole function is a four-argument forwarder to a five-argument callee:

```
image:  push {r3, lr}            ours:   push {r3, lr}
        mov  lr, r1                      str  r3, [sp]
        mov  ip, r2                      mov  ip, r1
        str  r3, [sp]                    mov  r3, r2
        ldr  r1, [r0], #4                ldr  r1, [r0], #4
        mov  r2, lr                      mov  r2, ip
        mov  r3, ip                      bl   #0x217d904
        bl   #0x217d904                  pop  {r3, pc}
        pop  {r3, pc}
```

Incoming `r0=src1, r1=divisor, r2=dest, r3=remainder` must become outgoing
`r0=src1->mData, r1=src1->mLength, r2=divisor, r3=dest, [sp]=remainder`. The
vendor's parallel move saves *both* incoming pointers before the stack store;
1.1p1 frees `r3` first and saves only the divisor. Seventeen concrete bytes,
and the vendor DWARF homes the parameters `divisor` to `r14` and `dest` to
`r12`, which reads like an unforceable front-end allocation.

What reaches it is the vendor's own signature:

```c
typedef unsigned int l_word;
typedef int gsi_bool;
typedef struct gsLargeInt_s { l_word mLength; l_word mData[64]; } gsLargeInt_t;

extern gsi_bool func_0217D904(const l_word *src1, l_word length1,
                              const gsLargeInt_t *divisor,
                              gsLargeInt_t *dest, gsLargeInt_t *remainder);

gsi_bool func_0217D8E0(const gsLargeInt_t *src1, const gsLargeInt_t *divisor,
                       gsLargeInt_t *dest, gsLargeInt_t *remainder)
{
    return func_0217D904(src1->mData, src1->mLength, divisor, dest, remainder);
}
```

Both `src1` (`const`) and the callee's first parameter must be `const`; a
non-`const` `src1` (`gsLargeInt_t *src1`) stays at 32 B / 17 bytes. `const` on
`divisor` is not required — `gsLargeInt_t *divisor` is also EXACT — but the
read-through pointer `src1` is the one that matters. This is the same qualifier
`a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md`
and `const-source-pointer-schedules-the-block-load-first.md` use for a load
trading places with a store; here it selects a different parameter homing, so
try `const` on a source pointer before concluding an argument-shuffle residue
is a front-end artefact.
