# A byte count local preserves word spills and reloads

summary: A count returned as `u8` can still occupy a word spill slot. Keeping the local `u8`, rather than widening it to `u32`, can restore an immediate reload of the spilled return value or change its slot order relative to another live integer without adding truncation instructions.

Found in: src/matched/ov/ov093_func_021CF9B4.c (0x021CF9B4), src/matched/ov/ov093_func_021CFE98.c (0x021CFE98)

Both functions save a byte-valued count returned by a callee and compare a
loop index against it across further calls. Under dsi/1.1p1 `-O4,p`, use a
plain byte local with the callee's evidenced byte return type:

```c
u8 n;
n = byte_count(...);
for (i = 0; i < n; i++) {
    /* calls */
}
```

In `func_021CF9B4`, `u32 n` compiled to 270 bytes: it stored the return value
at `[sp, #0xc]` but forwarded `r0` into the initial comparison. `u8 n`
restored the original adjacent `str r0, [sp, #0xc]; ldr r0, [sp, #0xc]`,
giving EXACT at 272 bytes. The reload is a word load, so its width alone
does not reveal the local's type.

In `func_021CFE98`, `u32 n` gave the same 274-byte code length as the body
but exchanged the spill slots of `n` and another local `int k`: `n` used
`[sp, #0xc]` and `k` used `[sp, #8]`. The original used the reverse order.
Changing only `n` to `u8`, with `k` kept `int`, restored all four differing
stores and reloads and gave EXACT*. Swapping their declaration order and
narrowing `k` to `u16` had not changed those slots.

This extends the nonconstant case of the related
[narrow flag local](a-narrow-flag-local-is-spilled-not-constant-propagated.md)
finding. Keep the count's evidenced value range; narrowing a genuinely
wide count is not an equivalent spelling. Neither example needs volatile.
