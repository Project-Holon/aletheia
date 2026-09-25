# Declaring a narrow pointer gives ldrsh/ldrh; a widening load plus a narrowing cast gives the shift pair

summary: when the original sign- or zero-extends a 16-bit field with an
`ldr`/`ldrh` followed by a matching `lsls`/`asrs` (or `lsls`/`lsrs`) pair, the
source loaded a wider type and cast it down, not a `s16 *`/`u16 *` dereference.

Found in: src/matched/func_021BE360.c (0x021BE360)

The original of `func_021BE360` reads a signed halfword argument:

```
ldr  r0, [r2]          ; a 32-bit load, not ldrsh
movs r1, #0x1d
lsls r0, r0, #0x10
asrs r0, r0, #0x10     ; (s16) of the low half
movs r2, #1
bl   func_02023F60
```

The obvious C is a narrow pointer:

```c
extern void func_02023F60(int, u32, u32);
u32 func_021BE360(u32 a, u32 b, s16 *c)
{
    func_02023F60(*c, 0x1d, 1);   /* emits ldrsh r0, [r2, r0] */
    return 1;
}
```

`ldrsh` is the only signedness evidence `ldrsh-register-offset-is-signedness.md`
talks about, but here it is the *wrong* tell: `*c` through an `s16 *` compiles
to `ldrsh r0, [r2, r0]` (a zero register supplies the index), and `u16 *c`
would give `ldrh`. Neither matches. The bytes say the width came from a cast:

```c
u32 func_021BE360(u32 a, u32 b, u32 *c)
{
    func_02023F60((s16)*c, 0x1d, 1);  /* ldr + lsls #16 + asrs #16 */
    return 1;
}
```

The equal-amount shift pair is the 16-bit narrowing cast
(`shift-pair-with-no-matching-type-is-a-bitfield.md`); the load stays 32-bit
because the cast is on the value, not on the lvalue. So before reading a shift
pair back as a field type, check whether a plain narrow-pointer dereference
would have produced `ldrsh`/`ldrh` instead — if it would, the source names the
wide type and casts.
