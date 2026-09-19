# The complement of a loop value is one hoisted `mvn` when spelled as `^ 0xFFFFFFFF`

summary: `x = ~v;` inside a loop rematerialises `mvn r1, r0` at every
iteration, while `x = v ^ 0xFFFFFFFF;` makes mwccarm keep the sentinel in a
register and emit `eor` against it -- one extra instruction outside the loop
but a byte-for-byte different loop body.

Found in: `src/matched/func_02046300.c` (0x02046300)

The loop of the original is

```
0204633c  e3e04000  mvn  r4, #0          ; the sentinel, hoisted out of the loop
...
02046348  e0201004  eor  r1, r0, r4      ; ~v
02046354  e0060001  and  r0, r6, r1      ; mask1 & ~v
```

and the same C with `~v` gives

```
0204634c  e2701000  rsbs ...             ; (nothing: the mvn is *inside*)
0204634c  e1e01000  mvn  r1, r0          ; per iteration
02046354  e0060000  and  r0, r6, r0      ; and reuses r0 for the mask
```

which is one instruction shorter overall but places the loop's instructions in
different registers, so every following byte differs. Both spellings are 32-bit
complement of an unsigned value and compile to the same *semantics*; only the
`^` form is strength-reduced as a two-operand operation whose other operand is
a loop-invariant constant, and therefore hoisted.

Tried and *not* enough: `~v` with `v` as `u32`, `s32`, or an intermediate; a
named `u32 nv = ~v;` local; `nv = v ^ 0xFFFFFFFF;` in a local. The local forms
change nothing at all -- the compiler re-materialises the `mvn` regardless --
so the operator spelling itself is the lever.

This is the second time a per-iteration constant has been hoisted only when the
expression is written one particular way; the mirror-image finding is
`a-literal-multiply-then-divide-is-the-signed-scale-idiom.md`, where the wrong
spelling *loses* a hoisted correction sequence for the same reason.
