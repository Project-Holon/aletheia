# A temporary reused across lerps keeps each sum before the calls, quotient first

summary: three `from + (to - from) * t / 4096` values computed before three
setter calls, each final `adds` with the quotient on the left (`adds r7, r1,
r0`), the first two sums held in callee-saved registers and only the last sum
done at its call: one shared local `v` reassigned per component
(`v = to - from; v = v * t / 4096; x = v + from;`). Inline lerp helpers put
`from` on the left of every add and nothing in their spelling moves it.

Found in: `src/matched/ov/ov021_func_021ABABC.c` (0x021ABABC, ov021)

The tells, all in one function:

```
muls  r3, r2, r3        ; diff * t
asrs  r1, r3, #0xb      ; signed / 4096
...
adds  r7, r1, r0        ; quotient + from, kept in r7 for the first call
...
adds  r1, r4, r5        ; the last sum, done right before its call
bl    func_0218ED58
```

An inline `Lerp(a, b, t)` (any spelling: `a + q`, `q + a`, compound `a +=`,
casts, pointer parameters, a macro, a local for the quotient) always gave
`adds rd, from, q`: the inline parameter is a named object and goes left.
Naming the quotient in a fresh local per component puts it left but lets mwcc
forward-substitute each sum into its call. Reusing ONE local for every
component does both: it is named (left slot), and its redefinition before the
next call blocks the forward substitution of x and y; z, after which `v` is
not redefined, is substituted into its call exactly as in the image.

The difference for each component also needs its own local before the
multiply (`v = to - from;` then `v * t`) to get `adds r3, r1, #0; muls r3,
r2, r3` and the 64-bit form `(s64)v * t` to pass the difference in r0:r1.

Related: `commutative-operand-order-names-the-temporary.md`,
`a-const-parameter-hoists-field-loads-above-a-call-result-store-into-an-address-taken-local.md`
(the const on p in the same function places the `str` of t after the loads).
