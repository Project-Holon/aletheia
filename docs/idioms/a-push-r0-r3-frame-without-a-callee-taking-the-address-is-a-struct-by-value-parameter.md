# A `push {r0-r3}` frame whose home slot is only read is a by-value struct parameter

summary: when a function opens with `push {r0, r1, r2, r3}` and an `add rN, sp, #K` base is used only to load (`ldr r1, [r7]`), never passed to a callee as the whole slot's address, the parameter is a small struct passed by value, not a scalar whose address is taken.

Found in: `src/matched/ov/ov093_func_021C3C60.c` (0x021C3C60, third parameter a one-word struct), `src/matched/ov/ov093_func_021C4104.c` (0x021C4104, fifth and sixth parameters are one 8-byte struct `{int a; u8 b;}`; it does pass the field addresses `&s` and `&s.b`, so there the struct shows in the +0/+4 field layout, not in the absence of an address).

`address-of-a-register-parameter-is-a-push-of-all-four.md` covers a scalar whose
address goes to a callee. Here the address is never handed out:

```
021C3C60  push {r0, r1, r2, r3}
021C3C62  push {r3, r4, r5, r6, r7, lr}
021C3C64  add  r7, sp, #0x20          <- base of the 3rd parameter's home slot
021C3C6A  ldr  r1, [r7]               <- passed to the callee by value
021C3C7C  ldr  r3, [sp, #0x20]        <- s.x read directly
```

A scalar `int c` with `int *q = &c;` never reproduces it: mwcc forwards `*q`
back to `c` and emits `ldr r1, [sp, #0x20]` first, with the `add r7` late (six
concrete bytes wrong in every combination of `*q` and `c` tried). Declaring the
parameter as `typedef struct { int x; } S;` and passing the struct itself to the
callee (`extern int f(int a, S c)`), with `c.x` where the scalar is wanted,
is EXACT*.

For the 8-byte case the fields sit at `+0` and `+4` of the base: an `ldrb`
through `add r0, sp, #0x38` with offset 4 (Thumb has no SP-relative `ldrb`)
and `&s` / `&s.b` passed as `add r2, sp, #0x38` / `add r3, sp, #0x3c`.
