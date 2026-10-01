# A threshold chain pools one base constant and derives every sibling by `sub`

summary: a descending run of `if (err >= Tn) id = ...;` comparisons does not put
each `Tn` in the literal pool. 1.1p1 pools **one** base (the first threshold of
the run) and derives every later one in place with `sub rT, rBase, #delta`, so
the machine shows a single `ldr` followed by many `sub`/`cmp` pairs. The deltas
are therefore NOT enough to recover the source: if you guess the base wrong but
keep the deltas, every instruction still reads correctly and only the four-byte
pool word (and the whole register rotation it feeds) is off.

Found in: src/pending/ov_sdk/ov016_func_021C7D80.c (0x021C7D80), from a 479-byte
DIFF to 19 bytes.

The `-50xxx` run of `drawMessage` is:

```c
else if (-49999 <= err) id = 0;
else if (-50002 <= err) id = 7;
else if (-50003 <= err) id = 5;
else if (-50098 <= err) id = 0;
else if (-50099 <= err) { if (prm == 2) id = 5; else id = 7; }
else if (-51999 <= err) id = 0;        /* base2 - 0x7d0 */
```

The image pools only `-49999` (`ldr r0, [pc, #0x254]`) and then:

```
  sub r2, r0, #3      ; -50002
  sub r2, r0, #4      ; -50003
  sub r2, r0, #0x63   ; -50098
  sub r2, r0, #0x64   ; -50099
  ...
  sub r0, r0, #0x7d0  ; -51999  (reuses the still-live base, no new pool word)
```

The previous draft had the base as `-50063` (all deltas identical, so every
`sub #3/#4/#0x63/#0x64` was right) and wrote the `-51999` arm as a runtime
`prm - 2000`; that is what produced a `ldr r1, [sp, #0x18]` / `sub` for a slot
that should have been a pure constant, and it forced the `err` web out of `r1`
into `r0`, flipping the whole 479-byte body.

Method: read the pooled value at the `ldr`'s own PC-relative target (`addr+8 +
imm`), trust it as the base, and express every sibling as that base minus the
printed delta. Do not back-solve the base from a sibling whose delta "looks
nice" - the base is the one word the linker relocates and the deltas ride on a
register that stays live across the run.
