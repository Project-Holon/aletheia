# A `return 0;` shares its register with an earlier `= 0` store, keeping r0 out of the rotation

summary: when a function both stores the literal `0` into a field and returns
`0`, the compiler materialises one zero in r0 and keeps it live all the way to
the epilogue, so r0 is not handed out as scratch to any expression in between;
drop the `return 0;` (or make the function `void`) and the whole tail shifts
down into r0/r1, a register-number diff on every instruction that reads like a
scheduler accident and is not one.

Found in: `src/matched/ov175_func_021E0098.c` (0x021E0098)

The function byte-swaps a block of fields in place, sets one 16-bit field to
zero, and returns zero. The original materialises the zero early:

```
021E00EC  ldr  r0, [r4, #0x1c]
021E00F0  mov  r0, #0
...
021E00FC  lsl  r3, ip, #0x18
...
021E015C  strh r0, [r4, #0x2a]      /* the = 0 store */
...
```

and then every later swap works in `r1`/`r2`/`r3`/`ip`, never touching r0:

```
021E0160  ldrh r1, [r4, #0x24]
021E0164  asr  r2, r1, #8
...
```

The store position is not the tell. If the source orders the statements
`f20 = bs(f20); f22 = bs(f22); f2a = 0; f24 = bs(f24); ...` the zero store
still lands where it does above; what changes the output is the *return*. The
same body compiled with `void` as the return type produces identical code up to
the store, then

```
021E00C8  ldrh r0, [r4, #0x24]
021E00CC  asr  r1, r0, #8
021E00D0  lsl  r0, r0, #8
...
```

r0 becomes the field register the moment it is free, and every instruction
after the `strh r0, [r4, #0x2a]` differs by a register number. Declaring the
function `int` and ending it with `return 0;` reproduces the original exactly:
the return value is the *same* constant the field store used, so its live range
extends to `pop {..., pc}` and the allocator reserves r0 for the whole tail.

The specific zero is not required, only that the return value and the stored
constant are the same literal; a function that returns a non-zero constant it
also stored would pin whatever register held it the same way. Conversely, if a
function's epilogue is `pop {r4, ..., pc}` with no `mov r0, #k`, the C has no
`return` and r0 is fair game, so a register diff that only appears *after* the
first shared constant is worth re-reading as a missing return value before it
is treated as a scheduling difference.
