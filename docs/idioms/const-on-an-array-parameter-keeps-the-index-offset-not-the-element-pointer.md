# const on an array parameter keeps the index offset in a register, not the element pointer

summary: a loop over `s[i]` whose original keeps `s` and `i * sizeof *s` in
callee-saved registers, spills `i`, and re-adds `s + off` at each use (with
`ldr rX, [s, off]` for the field at offset 0) is a `const T *s` parameter; a
plain `T *s` makes the compiler CSE `&s[i]` into one register and spill `s`.

Found in: `src/matched/ov/ov021_func_0218B974.c` (0x0218B974), and the same
lever on its callee `src/matched/ov/ov021_func_0218BA04.c` (0x0218BA04).

Original shape, per iteration:

```
ldr  r0, [sp, #8]      ; i is spilled
lsls r6, r0, #4        ; off = i * 16, kept across the calls
adds r2, r5, r6        ; &s[i] for a call argument
...
adds r2, r5, r6        ; recomputed after the call
ldrb r1, [r2, #0xf]
...
ldr  r1, [r5, r6]      ; s[i].x as base + index
```

With `Src *s` the same C keeps `r5 = &s[i]` for the whole body, spills `s`
and `n`, and keeps `i` in a register: about 110 bytes differ and declaration
order, pointer arithmetic and inline helpers do not move it. Declaring the
parameter (and the callee prototype taking it) `const Src *s` gives the
original allocation unchanged otherwise.

In the callee 0x0218BA04 (one call, then three field copies into a stack
record with the third negated), the same `const` moved the copy of the last
parameter into r3 down next to the `bl` and put the stores in the original
y, x, -z order; six assignment orders of an inline setter did not.
