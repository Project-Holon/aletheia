# Removing `const` from a read-only parameter sinks a grouped load below a store

summary: the inverse of
`a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer`.
When a parameter is already declared `const T *` and the only residue is that
*our* build issues a grouped load (an `ldm`) above a store while the original
issues it below, the qualifier is the cause: with `const` the front end treats
the load as unable to alias the store and hoists it.  Drop the `const` and the
load sinks to the original's slot, with everything after it recolouring.

Found in: `src/pending/ov_sdk/ov114_func_021CC674.c` (0x021CC674,
`CRYPTOi__BN_gen_exp_string`, crypto_bobj1.o, 408 B; 39 -> 27 concrete bytes).

The original loads `e->d` / `e->top` in one `ldm` *after* two byte stores into
the `str` parameter:

```
strb r4, [r7, r0]        ; str[n] = 0
strb r4, [r1, #-1]       ; p[-1] = 0
ldm sb, {r2, r3}         ; d = e->d; top = e->top
```

With `const BIGNUM *e` this build hoisted the `ldm` above both stores and the
whole dependent tail shifted (39 bytes).  Making `e` a plain `BIGNUM *`
restored the sink and the tail, 39 -> 27 bytes; the store/load do not actually
alias, so the qualifier is purely a scheduler hint and the parameter being
read-only does not require it.

Read the two idioms together: `const` is a scheduling lever, not a correctness
one, so choose it by which side of the store the original's grouped load sits
on, in either direction.
