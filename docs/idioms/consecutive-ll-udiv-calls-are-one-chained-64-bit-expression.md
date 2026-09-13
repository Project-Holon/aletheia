# Two `blx` to the 64 bit division helper in a row are one chained expression, because it returns in the register pair it takes

summary: `_ll_udiv` takes the dividend in r0:r1 and returns it in r0:r1, so a
second call that sets only r2:r3 is `a / b / c` on a 64 bit value and not two
separate divisions; the `asrs r3, r2, #0x1f` in front of each is the sign
extension an `int` operand costs on the way to the 64 bit type.

Found in: `src/matched/unit_020067E0.c` (0x02006844)

```
ldrh r0, [r4, #2]
movs r1, #0x7f            /* the high word of the dividend */
str  r0, [r5, #0xc]
ldrh r2, [r4, #2]
ldr  r0, pool             /* 0xD87F8000, the low word */
asrs r3, r2, #0x1f
blx  0x0209C00C
ldrh r2, [r4, #4]
asrs r3, r2, #0x1f
blx  0x0209C00C
str  r0, [r5, #0x20]
```

The second call sets up only r2 and r3, which looks at first like a call with
an uninitialised argument. It is not: r0 and r1 hold the first call's result,
and the helper's contract is r0:r1 in, r0:r1 out. So the eleven instructions
are one expression,

```c
e->unk20 = (u32)(0x7FD87F8000ULL / wave->unk02 / wave->unk04);
```

and `str r0, [r5, #0x20]` is the truncation of the 64 bit result to the u32
field. Written as two separate divisions with a `u32` temporary in between the
compiler emits a `movs r1, #0` to rebuild the high word before the second call
and the function is four instructions longer.

Two details are worth having.

**The constant has no pool word of its own for the high half.** 0x7FD87F8000 is
split into a `ldr` of 0xD87F8000 and a `movs r1, #0x7f`, so a `movs` of a small
number sitting next to a pool word load may be the top half of a 64 bit
literal rather than an argument. Here the value is 16756991 * 0x8000, and
16756991 is half the DS system clock, so the expression is a sample rate
conversion; reading the `movs r1, #0x7f` as an argument sends the search after
a two argument function that does not exist.

**The `asrs rN, rM, #0x1f` is a conversion, not arithmetic.** The divisor is a
`u16` struct field, which promotes to `int`, and converting an `int` to the
unsigned 64 bit type of the dividend sign-extends. So the `asrs` says the
operand's declared type is signed and 32 bits wide or narrower; a `u32` divisor
would be `movs rN, #0` instead, and that is a one instruction difference that
pins the field's declaration.

The neighbouring helpers make the family easy to recognise once seen:
0x0209C00C and 0x0209C018 differ only in a `mov r4, #0` against `mov r4, #1`
and are the quotient and remainder entries of the same routine, 0x0209C054 is
`umull` plus two `mla` and is the 64 bit multiply, and 0x0209C074 is the 64 bit
shift. None of them is in `layout/symbols_sdk.txt`, because they are compiler
runtime and not SDK, so each is pinned in the `symbols:` block exactly as
`docs/idioms/runtime-helper-reloc.md` pins `_u32_div_f`.
