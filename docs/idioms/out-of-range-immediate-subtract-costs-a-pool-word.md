# An 8-bit-immediate-sized subtraction still costs a pool word when the constant is spelled as an unsigned 16-bit add

summary: `x - 0x96` where 0x96 fits an 8-bit subs immediate compiles to `subs`,
but the original instead loads a pool word and adds it; the source spells the
constant as its positive unsigned 16-bit two's-complement form (`x + 0xff6a`),
which mwccarm never folds back down to a subtract regardless of how the
literal is written, because the addend does not fit the 8-bit add-immediate
either.

Found in: src/matched/unit_02013CC8.c (0x02013CE0, 0x02013D00)

`sub_02013CE0` and `sub_02013D00` each reject an id outside a small window by
computing `(u16)(id - k)` for a small `k` (0x96, 0x4b) and comparing the
result against 1 with `bhi`/fallthrough. Writing the obvious
`sub_02013A94(id) - 0x96` compiles to `subs r0, #0x96` (a valid 8-bit
immediate) and is 8 bytes short of the original, which loads
`ldr r1, [pc, #imm]; adds r0, r0, r1` from a pool word holding `0x0000FF6A`.

Rewriting the literal spelling as `+ 0xff6a` (`0x0000FF6A` == `-0x96` mod
2^16, but written as a positive 16-bit constant rather than a negated 8-bit
one) reproduces the pool load exactly. Writing it as `+ 0xffffff6a` (sign
extended to 32 bits) folds straight back to the 8-bit `subs`, because the
compiler still recognises the numeric value as a small negative int; the
16-bit-only spelling is what keeps the constant outside both the 8-bit subs
and 8-bit add immediate ranges and forces the pool.

The general rule: this front end decides pool-versus-immediate from the
literal's value as parsed, not from some canonical reduced form, so a
range-check constant that is genuinely `k` away from a boundary has to be
spelled as the exact word the original's pool holds, not as the algebraically
simplest subtraction.
