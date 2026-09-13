# A tail call is always `ldr r3, [pc, #n]` and `bx r3`, even to the next function in the same file

summary: one PROGBITS section per function means the compiler cannot encode
a displacement to any other function, so a tail call materialises the
target's address through an ABS32 pool word and `bx`; a four to eight byte
function with no prologue at all is that and nothing else.

Found in: src/matched/unit_02005DAC.c (0x02005DF8), src/matched/unit_02005C3C.c (0x02005C3C)

`sub_02005DF8` is twelve bytes and calls `sub_02005E04`, which begins twelve
bytes later in the same translation unit:

```
ldr  r3, [pc, #4]     ; 0x02005E05
movs r1, #0x7f
bx   r3
.byte c0 46           ; alignment
.word 0x02005E05
```

There is no `b` and no `bl`. docs/MATCHING.md's "TU granularity" section
records that mwccarm emits one section per function; the consequence here is
that the compiler has no displacement to encode even for its own immediate
neighbour, so it spends four bytes of literal pool and lets the linker fill
the address in. The Thumb bit in the pool word is the linker's too, which is
why the same construct reads `0x02005E05` for a Thumb target and
`0x0203508C` for an ARM one: `bx` switches instruction set on the low bit and
the compiler never has to know which.

Recognising it matters in three ways.

**It is a call, not data.** A run of `48 xx 4B yy ... 18 47` followed by two
or three words is a whole function. `disasm.py` will not label it, because
its prologue sweep only recognises a function that saves `lr` and a tail call
saves nothing, so these turn up as `.word` blobs in the generated listing.
Four of the fifteen functions of `src/matched/unit_020079BC.c` and
`unit_02007AC8.c` are this shape, as are `sub_02005C18`, `sub_020062D8` and
`sub_020062EC`.

**Writing `return f(x);` is enough.** No attribute, no `goto`; at `-O4,p`
this compiler takes the tail call whenever the callee's arguments are already
in place and nothing is live across it. A statement followed by a plain
`return` does the same for a `void` function.

**It changes what a unit has to contain.** The pool word is an `R_ARM_ABS32`
against the callee, so it needs the same attestation as any other reference.
When the caller and the callee are in one byte range the site is `local` and
costs no image evidence at all; split them and the callee needs a branch to
it from somewhere outside the range, which a single-caller helper does not
have. That is why `sub_020062D8` and `sub_020062EC` cannot be matched apart
from `sub_02006300`.
