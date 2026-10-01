# Unsigned address scaling preserves an index admitted by a signed guard

summary: A signed `index < 3` guard also admits negative full-word values. Spell the following scaled address as unsigned 32-bit multiply/add to preserve the original wrapping `lsl` and address addition; a signed multiply can emit identical bytes while its C has overflow.

Found in: src/matched/ov/ov131_func_021D52D4.c (0x021D52D4), src/matched/ov/ov131_func_021D54A8.c (0x021D54A8).

Both originals keep the comparison signed, then load an element through
`base = p + 0x60; offset = index << 2; ldr [base, offset]`. Neither adds
a lower-bound test. A complete invocation-domain proof is needed before
treating the index as an ordinary nonnegative array subscript.

The direct spelling `*(int *)(p + 0x60 + *(int *)(p + 0x58) * 4)` matched
both functions EXACT, but its signed multiplication can overflow for
negative values that pass the guard. Retain the signed guard and use:

```c
*(int *)((u32)p + 0x60 + (u32)*(int *)(p + 0x58) * 4)
```

With 32-bit `u32`, each integer operation wraps modulo 2^32 before the
target pointer conversion. This preserves every input bit and the original
shift/add address; it introduces no narrowed index, lower-bound guard, or
assumed menu range. Both corrected functions remained EXACT on their first
fixed-flag compile, and their adjacent 892-byte translation unit was EXACT.

This is a semantic distinction that a byte verdict alone cannot establish.
