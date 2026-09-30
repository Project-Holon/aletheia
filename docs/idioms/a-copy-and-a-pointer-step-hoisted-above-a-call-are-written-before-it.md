# A copy and a pointer step the image hoists above a call are written before it, and the call's address argument is re-expressed through the copy

summary: when the image defines a local and steps a pointer *above* a call, the
C has those two statements textually before the call and passes the address
argument through the new local; written after the call, this compiler sinks both
statements below it, and the difference cascades into a whole-block register
rotation that no declaration order reaches.

Found in: `src/matched/ov_sdk/ov172_func_021C2B74.c` (0x021C2B74,
SSP_StartJpegEncoder, jpegenc.o)

The thumbnail block sets up a work pointer, steps the caller's buffer past the
work area, and only then resamples into the thumbnail source inside that work
area. The image has all three of those things before the call:

```c
        pThumbWork = wrk;      /* 021C2C0C  mov  r4, r5            */
        wrk += 0x12c00;        /* 021C2C10  add  r5, r5, #0x12c00  */
        func_021C1D8C(src, width, height, pThumbWork + 0x9600, 160, 120, option);
                             /* 021C2C08  add  r3, r5, #0x9600  <- the OLD wrk */
                             /* 021C2C18  bl   0x021c1d8c         */
```

The obvious source order — the call first, then the two statements, which is
what the address arithmetic suggests because the fourth argument wants the
pre-step `wrk` — compiles to the same instruction multiset with both statements
*sunk below* the call, and the block goes 80 concrete bytes out:

```c
        func_021C1D8C(src, width, height, wrk + 0x9600, 160, 120, option);
        pThumbWork = wrk;
        wrk += 0x12c00;
```

```asm
        ldr  r4, [sp, #0x58]   /* the 7th argument temp */
        ...
        add  r3, r5, #0x9600
        str  r4, [sp, #8]
        ldr  sb, [sp, #0x50]
        bl   0x021c1d8c
        mov  r4, r5            /* pThumbWork = wrk, after the call */
        ldr  r0, [sp, #0x50]
        add  r5, r5, #0x12c00  /* wrk += 0x12c00, after the call */
```

The cost is not the two misplaced instructions. It is that the sunk copy frees
`r4` (the local's home) across the call, so the argument-setup temporary takes
`r4` instead of `r9`, and from there every register in the block is a different
colour from the image's. `r4` and `r5` swap roles with `sb`, and the residue
reads as an allocator accident in a block whose statements are all correct.

Moving the two statements before the call and writing the fourth argument as
`pThumbWork + 0x9600` is byte-exact. Note what the compiler then does with that
argument: it re-associates the address back onto the pre-step pointer and emits
`add r3, r5, #0x9600` against `r5`, so the spelling through the copy does not
change which base register the address lands in. That is the tell that the
source form is right — if the argument were read from the stepped `wrk`, the
image's own `add` would be a `sub`.

The same lever in other spellings, all byte-exact here: naming the address in a
local before the two statements, or keeping a second copy of the base pointer
for it. What does not work is hoisting only the copy and leaving the step after
the call (60 bytes out): it is the pair that the image has above the call, and
hoisting one of them leaves the temporary problem in place.

The general form: when a call in the image sits *between* two definitions of
locals that the sink could equally well place after it, read the definitions'
position relative to the call as source order, not as scheduling. This is the
mirror image of
`docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md`,
where the store's position names the local; here the local's position names the
statement order.
