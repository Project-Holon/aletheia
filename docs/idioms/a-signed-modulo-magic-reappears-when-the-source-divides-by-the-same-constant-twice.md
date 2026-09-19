# The signed `% K` magic appears twice when the source scales by 0xFFFF and divides by K again

summary: A pool magic that looks like a source constant is the compiler's own
division-by-constant magic; it is emitted only for a signed dividend, and when
the same magic shows up a second time the source divides by the same constant
twice. `>> 4` and `/ 16` on the quotient are different code.

Found in: src/matched/func_0203F684.c (0x0203F684), src/matched/func_0203F6D8.c
(0x0203F6D8)

The original body (76 bytes of code plus two shared pool words):

```
push {r3, lr}
ldr  ip, [pc, #0x40]      ; 0xB60BB7
lsr  r1, r0, #0x1f        ; sign word
smull r2, lr, ip, r0
add  lr, r0, lr
add  lr, r1, lr, asr #8
mov  r3, #0x168           ; 360
smull r1, r2, r3, lr
sub  lr, r0, r1
rsb  r1, lr, lr, lsl #16  ; * 0xFFFF
smull r0, r2, ip, r1
add  r2, r1, r2
lsr  r0, r1, #0x1f
add  r2, r0, r2, asr #8
asr  r1, r2, #4
lsl  r1, r1, #2
ldrsh r0, [r0, r1]
```

0xB60BB7 is not a constant the source writes: it is this compiler's magic for
division by 360 in the `+ dividend, asr #8` form, and it appears twice because
the expression divides by 360 twice:

```c
s16 func_0203F684(int x)
{
    return tbl_020A1B38[2 * ((((x % 360) * 0xFFFF) / 360) >> 4)];
}
```

Three plausible spellings that produce different code and cost time:

- `unsigned x` (or a `u32` cast on the argument): the compiler switches to
  `umull` against 0x6C16C16D and the whole function is a diff.  The sign word
  `lsr r1, r0, #0x1f`, the `add ... asr #8` close and `smull` (not `umull`)
  are the tells that the dividend is signed.
- `/ 16` for the trailing scale: compiles to an exactness-corrected sequence
  (`asr r0, r2, #3` then `add r0, r2, r0, lsr #28`) instead of one
  `asr r1, r2, #4`, four instructions longer.
- a `struct { s16 a; s16 b; }` table for the odd field: the original's odd
  index emits `lsl r0, r0, #1 / add r1, r0, #1 / lsl r1, r1, #1`, which is an
  index into a flat `s16[]` of interleaved pairs (`2 * i` and `2 * i + 1`),
  not a struct field access.
