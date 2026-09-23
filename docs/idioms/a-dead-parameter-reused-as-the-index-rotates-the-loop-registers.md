# A dead parameter reused as the index rotates the loop registers

summary: When a byte index or cursor lands in the register of a parameter that is dead by then, the source reassigned that parameter (`start = start / 8;` or `start = idx + 1;`) rather than declaring a fresh local. A fresh local gets a new colour and rotates every register of the following loop (index, counter, constant) by one, a same-width permutation that no declaration order, type sweep or permuter run moves.

Found in: src/matched/sub_020343C0.c (0x020343C0), src/matched/func_0203422C.c (0x0203422C), areaman.c, ARM

The tell is the instruction that defines the index writing over a parameter
register: `asr r1, r1, #3` in 0x020343C0 (start/8 into start's own r1) and
`add r1, r0, #1` in 0x0203422C (the cursor past the head byte into start's
r1). Both functions had stood at DIFF 44 and 17 for four waves with the
index / loop counter / tail (or zero) in r3 / r2 / r1 against the image's
r1 / r3 / r2. Writing

```c
start = start / 8;          /* 0x020343C0: start is the byte index from here on */
...
start = idx + 1;            /* 0x0203422C: start is the fill cursor from here on */
while (nfull-- != 0) { p->bits[start] = 0; start++; }
```

gives the image's allocation byte for byte; `u32 idx = start / 8;` with
`idx++` (or a second index local j) gives the rotation. In 0x020343C0 the
lever also flipped the then-arm zero order back to the natural
`nfull = 0; tail = 0;` (the earlier `tail = 0;` first order had only been
the permuter compensating for the wrong index colour). This is the
register-parameter sibling of
docs/idioms/a-dead-stack-parameter-reassigned-to-a-locals-address-keeps-a-callee-saved-register.md.
