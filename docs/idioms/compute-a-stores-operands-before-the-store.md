# Compute a store's operands before the store, not after

summary: armcc hoists independent arithmetic above a store, but it will not
hoist the store above the arithmetic.  When the original writes a literal
first and derives the bytes that follow from it, spell the C as
`compute operands; store; store derived`; storing first and computing after
produces the same value but a different byte order.

Found in: src/matched/ov114_func_021BA2D0.c (0x021BA2D0)

The function percent-encodes one byte: it writes `'%'` at `dst[0]` and two
hex digits at `dst[1]`, `dst[2]`.  The original is

```
        asr   r2, r1, #4          ; hi = c >> 4
        and   r3, r2, #0xf        ; hi &= 0xf
        mov   r2, #0x25
        strb  r2, [r0]            ; *dst = '%'
        cmp   r3, #0xa
        addlt r2, r3, #0x30       ; hi digit
        addge r2, r3, #0x37
        and   r1, r1, #0xf        ; lo = c & 0xf
        cmp   r1, #0xa
        addlt r1, r1, #0x30       ; lo digit
        addge r1, r1, #0x37
        strb  r2, [r0, #1]
        strb  r1, [r0, #2]
```

The tempting spelling puts the store first:

```c
    *dst = '%';
    hi = (c >> 4) & 0xf;
    dst[1] = hi < 10 ? hi + '0' : hi + '7';
    lo = c & 0xf;
    dst[2] = lo < 10 ? lo + '0' : lo + '7';
```

That still computes the same digits, but the compiler sinks the `'%'` store
to the very end, yields a different scratch-register assignment, and drifts
by dozens of bytes.  The spelling the original wants computes both operands
first and only then stores:

```c
    hi = (c >> 4) & 0xf;
    lo = c & 0xf;
    *dst = '%';
    dst[1] = hi < 10 ? hi + '0' : hi + '7';
    dst[2] = lo < 10 ? lo + '0' : lo + '7';
```
