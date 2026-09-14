# A random number below N is the high word of a 64 bit multiply, and a `movs rN, #0` next to the call is that product's high half

summary: this codebase never writes `rand() % n` or `rand() >> k`; it writes
`(u64)rand() * n >> 32`, so a draw below a constant power of two is an inlined
`lsrs` / `movs #0` / `lsls` / `orrs` quartet whose *result* is the register the
`orrs` accumulates into, and a draw below a variable is a `_ull_mul` call whose
answer is r1 rather than r0.  Reading the quartet as a plain shift gives the
same value and a different register allocation, and reading the `movs r1, #0`
as an argument invents a parameter that is not there.

Found in: `src/matched/unit_0201B100.c` (0x0201B188),
`src/pending/unit_0201B7A0.c` (0x0201B7F4), and the three draws of
`docs/notes/sub_0201B038.c.txt` (0x0201B044, 0x0201B088, 0x0201B0C0)

Four draws in one packet, and none of them is spelled the obvious way.

**The constant power of two case.**  0x0201B7F4 wants a coin flip:

```
blx  func_0203F0A8       /* the 32 bit draw */
movs r1, #0
lsrs r0, r0, #0x1f
lsls r1, r1, #1
orrs r1, r0              /* the answer is in r1 */
movs r0, #1
tst  r0, r1
```

That is the inline expansion of a 64 bit multiply by 2 followed by `>> 32`:
the high half of the product is `(lo >> 31) | (hi << 1)`, and `hi` is the zero
the cast to `u64` put there.  The source is

```c
if (((u32)(((u64)func_0203F0A8() * 2) >> 32) & 1) == 0) {
```

The algebraically equal `(u64)func_0203F0A8() >> 31` compiles to the same four
instructions with r1 and r2 interchanged, because then the accumulator is the
low half rather than the high one
(`docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md`);
and the plain 32 bit `func_0203F0A8() >> 31` is a single `lsrs` and three
instructions short.  0x0201B044 is the same shape with `* 0x10000`, giving
`lsrs #0x10` / `lsls #0x10`, and 0x0201B0C0 with `* 0x100`, giving `lsrs #0x18`
/ `lsls #8`.

**The variable case.**  0x0201B188 wants one chance in three:

```
blx  func_0203F0A8
movs r1, #0             /* the draw's high half */
movs r2, #3             /* the bound's low half */
movs r3, #0             /* the bound's high half */
blx  _ull_mul
cmp  r1, #0             /* the answer is r1, the product's high word */
```

`_ull_mul` at 0x0209C054 takes r0:r1 and r2:r3 and returns r0:r1, so the
quotient-shaped answer is **r1** and not r0.  Reading `movs r1, #0` as a second
argument to `func_0203F0A8` or `cmp r1, #0` as a test of some other value both
send the search a long way off.  The source is

```c
if ((u32)((u64)func_0203F0A8() * 3 >> 32) != 0) {
    return;
}
```

**The helper is inlined, guard and all.**  Where the bound is a variable the
original also carries a `cmp rN, #0` in front of the multiply and skips it when
the bound is zero, keeping the raw draw:

```c
slot = func_0203F0A8();
if (n != 0) {
    slot = (u32)(((u64)slot * n) >> 32);
}
```

That guard is not something the compiler adds: with `n` zero the product is
zero, so the two paths differ and the test has to be in the source.  It is the
body of a small "random below n" helper that mwccarm inlined, which is why the
same three instructions appear around every variable-bound draw in the region.

The reverse reading, and it is the useful one: **a `movs rN, #0` immediately
before or after a call whose result is then shifted is the high half of a 64
bit value, not an argument and not a flag**, and the multiplier tells you the
range of the draw.  `* 2` is a coin flip, `* 0x100` a byte, `* 0x10000` a
halfword, and a variable multiplier is "below n".
