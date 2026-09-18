# The second term of a two-multiply sum is the one that becomes the `mla`

summary: in `a * k1 + b * k2` the compiler emits `mul` for one product and `mla`
for the other, and which term gets the `mla` follows the *source order* of the
terms - so the same values with the two terms written the other way round lose
the paired load that goes with them.

Found in: `src/matched/func_0203F4FC.c` (0x0203F4FC)

Three words at 0x02146A1C are hours, minutes and seconds, and the function is
seconds since midnight. The original:

```
    ldr ip, [pc]            ; 0x02146A1C
    mov r0, #0xe10          ; 3600
    ldm ip, {r1, r3}        ; r1 = h, r3 = m
    mul r2, r1, r0          ; h * 3600
    mov r0, #0x3c           ; 60
    mla r0, r3, r0, r2      ; m * 60 + that
    ldr r1, [ip, #8]        ; s
    add r0, r1, r0
```

The `ldm` says the source read the first two members as a pair, and the `mul`
takes the *hours* term while the `mla` folds in the *minutes* term. Written the
way the arithmetic reads, `p[0] * 3600 + p[1] * 60 + p[2]`, this compiler does
the opposite - it materialises 60 first, loads the two members one at a time
with `ldr r1, [ip, #4]` / `ldr r3, [ip]`, and produces

```
    mov r0, #0x3c
    mul r2, r1, r0          ; m * 60
    mov r0, #0xe10
    mla r0, r3, r0, r2      ; h * 3600 + that
```

44 bytes against the original's 40, no `ldm`, and a fifth pool word. Simply
writing the minutes term first -

```c
    return p[1] * 60 + p[0] * 3600 + p[2];
```

- reproduces the original exactly: the first-written product becomes the `mul`,
the second becomes the `mla`, and once both members are read before any
arithmetic the compiler pairs them into the `ldm`.

The lesson is the same shape as
`the-accumulator-of-a-commutative-chain-is-its-second-operand.md`, one level
down: for `+` of two plain values the *second* operand is the register the first
is folded into, and here the product written second is the one that gets the
`mla`. When a diff shows two `mul`/`mla` pairs swapped, swap the source terms
before touching anything else - the load shape and the constant order follow it.
