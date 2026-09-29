# A flag ternary over enum constants keeps the bne-to-one polarity

summary: `cmp rN, #0; bne L1; movs r0, #0; b end; L1: movs r0, #1` (zero on the
fall-through) for a 0/1 local is `flag = e == 0 ? B_FALSE : B_TRUE;` with enum
constants. Every int-constant spelling (`e != 0`, `!!e`, `e == 0 ? 0 : 1`,
`if (e == 0) flag = 0; else flag = 1;`) is folded to a boolean first and comes
out `beq L0; movs #1; b; L0: movs #0`. A flag built this way and tested at
once (`...; cmp r0, #0; bne skip`) is `f = e == 0 ? B_TRUE : B_FALSE; if (f == B_FALSE)`.

Found in: src/matched/ov/ov071_func_021B6F54.c (0x021B6F54),
src/matched/ov/ov071_func_021BA1FC.c (0x021BA1FC), src/matched/ov/ov071_func_021B8EE8.c
(0x021B8EE8) (the flag-then-tested shape below)

Measured on that function with everything else fixed (u16 flag, `const int *d`):
eleven int-constant spellings, as ternaries, if/else in both arm orders and
relational forms, and with `int` or `unsigned` operands, all gave the same
3-byte polarity diff. `switch` and `flag = 0; if (e) flag = 1;` change the size.
With `typedef enum { B_FALSE, B_TRUE } Bool;` and the flag still a `u16` local,
the ternary `e == 0 ? B_FALSE : B_TRUE` is EXACT. With the local itself typed
`Bool`, the diff grows to 20 bytes, because the flag loses the u16 narrowing
that the image schedules between the loads.

The enum constants are what matter. A plain int ternary is recognised as a
boolean and re-emitted in the compiler's own order. With enum constants the
two arms stay as written, zero first. This matches
`an-enum-type-keeps-values-out-of-constant-folding.md`.

This is not the same as the if/else-with-stores shape
(`ov195_func_02205C74`: `if (o->f08 == 0) o->f48 = 0; else o->f48 = 1;`), where
the arms store to memory and keep their polarity with int constants.

## The flag built and then tested

0x021BA1FC and 0x021B8EE8 build the 0/1 value and test it at once:

```
ldrb r0, [r5, #0x10]
cmp  r0, #0
bne  L
movs r0, #1
b    M
L: movs r0, #0
M: cmp  r0, #0
bne  skip
movs r0, #1          ; busy = 1
str  r0, [sp, #4]
skip:
```

Every int spelling folds the whole materialisation into one `cmp; beq`, 12
bytes short: `if ((e[0x10] == 0) == 0)`, an `int f = e[0x10] == 0;` local tested
with `f == 0`, the int ternary `e[0x10] == 0 ? 1 : 0`, the double boolean
`(f != 0) == 0`, and a `static inline` predicate. The enum-constant ternary
reproduces it, with the local typed `int` or `Bool`:

```c
f = e[0x10] == 0 ? B_TRUE : B_FALSE;
if (f == B_FALSE) {
    busy = 1;
}
```
