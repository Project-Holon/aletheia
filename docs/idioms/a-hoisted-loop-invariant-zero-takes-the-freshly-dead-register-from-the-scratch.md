# A hoisted loop-invariant zero can steal the freshly-dead register the loop scratch wants, and no source shape moves it

summary: when loop 1's index dies and loop 2 needs two short-lived values -- a
loop-invariant constant (here the `k = 0` reset) and the arithmetic scratch --
the image may give the freshly-dead index register to the *scratch* and the
other free register to the constant, while dsi/1.1p1 does the reverse. This is
a genuine allocator tie that the usual rotation levers do not reach: it is not
declaration order, statement order, a named zero, the `for` initialiser, an
enum-typed zero, `const`, or the compound form.

Found in: `src/pending/ov_sdk/ov009_func_02163E40.c` (0x02163E40, ov009, ARM,
CPSi_rc4_init, arc4.o), residue 12 B.

The function is RC4 KSA: loop 1 fills `m[i] = i` with the index in r3; loop 2
needs `i` again (r7), `j` (r5), `k` (r6), `m` (r4), the loaded byte `m_i` (lr),
its `key[k]` partner (ip), and two more values out of {r0, r3}: the saved k-zero
for `if (k >= len) k = 0`, and the scratch that carries `(k+1)&0xff`,
`m_i + key[k]`, `j + ...` and the `m[j]` load. The image is

```
+0030  mov r0, r6     /* Z = k (the reset zero)      */
+003C  add r3, r6, #1 /* scratch = k + 1             */
...
+005C  movge r6, r0
+0060  strb r3, [r4, r7]
```

so the image hands the register freed by loop 1's index (r3) to the **scratch**,
and keeps the constant in r0. dsi/1.1p1 does the exact reverse: `mov r3, r6`
for the constant and r0 for the whole scratch chain. The two are the only free
registers, so this is a four-register same-width permutation of the S/Z pair
and it is worth 12 concrete bytes.

What does **not** move it (each compiled at 120 B): declaration order of every
local permutation that keeps `m_i,m` first (the order that already fixes
`m=r4, m_i=lr`), `j=k=0` vs `k=0;j=k;` vs `k=0;j=0;`, moving `k=0` or `j=0` or
both into loop 2's `for` initialiser, `for (i = k; ...)`, a named `zero` local
spelled as a **copy** of the first zero (`zero = k;`) in three declaration
slots, an `enum { KZERO = 0 }`, `const unsigned char *key`, an assignment-in-
condition `if ((k = (k+1)&0xff) >= len)`, `k &= 0`, `k = k & 0`, and
`a-no-code-self-assignment` at the loop head. Two reorders are actively worse:
loading `key[k]` into a hoisted `kk` and resetting before the sum (19 B), and
moving the reset after the swap stores (26 B).

The plausible reading is that the hoisted constant's web is coloured before the
scratch's in dsi, so it takes the most-recently-dead register; in the image it is
coloured after. The general lesson is a boundary on the rotation idioms: when
the residue is exactly "the loop-invariant constant vs the loop scratch, both
in the only two free registers", stop sweeping declaration/statement order and
park it -- the rotation-family idioms
(`statement-order-of-scratch-temporaries-decides-their-registers`,
`declaration-order-decides-which-register-a-local-gets`,
`a-transfer-of-a-loop-variable-across-phases-changes-the-allocation`) all
require the source to own a value the allocator is choosing between, and a
compiler-generated hoist is not such a value.
