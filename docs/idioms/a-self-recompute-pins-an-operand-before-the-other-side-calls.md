# Assigning an operand to a local and then recomputing into the same local pins it in a register before the other side's call

summary: `x / f()` evaluates the call first and rematerialises `x` out of its
incoming stack slot afterwards; writing `n = x; n = n / f();` forces `x` into a
callee-saved register in the prologue shuffle instead, which is two bytes
longer and shifts the rest of the function.

Found in: src/pending/func_0202208C.c (0x0202208C)

The original opens by moving every parameter it will need out of the way, the
sixth one included, and only then calls the divisor helper:

```
push {r4, r5, r6, r7, lr}
sub  sp, #0x24
ldr  r5, [sp, #0x3c]      ; the sixth parameter, promoted to a callee-saved reg
adds r4, r0, #0
str  r1, [sp, #0x1c]
str  r2, [sp, #0x20]
adds r7, r3, #0
blx  CARD_GetBackupSectorSize
adds r1, r0, #0
adds r0, r5, #0           ; ...and only now is it the dividend
blx  _s32_div_f
```

The obvious C does not produce that:

```c
n = (s32)p6 / (s32)CARD_GetBackupSectorSize();
```

An unmodified parameter that already has a home on the incoming stack is free
to rematerialise, so the compiler schedules the call first and then reloads:

```
blx  CARD_GetBackupSectorSize
adds r1, r0, #0
ldr  r0, [sp, #0x3c]      ; two bytes instead of four, and nothing in r5
blx  _s32_div_f
```

Two bytes shorter, and because the rest of the function keeps the same
instruction sequence, every later offset is shifted by two and the whole body
reads as a diff.

Introducing a separate named local does not help, the copy folds away:

```c
s32 total = (s32)p6;
n = total / (s32)CARD_GetBackupSectorSize();   /* identical to the inline form */
s32 size = (s32)CARD_GetBackupSectorSize();
n = total / size;                              /* also identical */
```

What works is assigning to the local and then recomputing *through the same
local*, so the value is live across the call under its own name:

```c
n = (s32)p6;
n = n / (s32)CARD_GetBackupSectorSize();
```

That is the shape that reproduces `ldr r5, [sp, #0x3c]` in the prologue block
and `adds r0, r5, #0` after the call, and it is what took the function from 149
differing bytes to byte-identical.

The finding is not about division. Any binary operator whose other side is a
call behaves the same way: the compiler will defer a rematerialisable operand
past the call unless a named local's live range crosses it, and the
self-recompute is the cheapest way to say that in C. It is the mirror image of
`docs/idioms/cmp-operand-order-names-the-temporary.md`, where naming the *call
result* is what moves the byte; here it is naming the *other* operand.
