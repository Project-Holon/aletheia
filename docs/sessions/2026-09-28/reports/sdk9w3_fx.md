# sdk9w3_fx: ARM9 SDK wave 3, libfx / libgx / libcrypto leftovers

Worked from `tools/sdkobj.py`, `tools/match.py show/one` and `tools/permuter.py` only. No file under
`sdk/` was opened. Objects: fx_vec.o, fx_cp.o, g2.o, rc4.o, all stamp 4.0.0.1024 (dsi/1.1p1), flags
`-O4,p`, lang `c99`. Permuter seeds used: 13606 to 13615.

## Verdicts

| address | symbol (object) | bytes | verdict | residue |
|---|---|---|---|---|
| 0x0202FAB4 | CRYPTO_RC4Init (rc4.o) | 128 | EXACT (manifest), matched | none |
| 0x0207D59C | G2x_SetBGyAffine_ (g2.o) | 160 | EXACT* (manifest), matched | none (EXACT* because the listing extent is 188 bytes) |
| 0x0207C8D0 | FX_SqrtAsync (fx_cp.o) | 52 | DIFF 10 B (was 31), pending | r1/r2 swap only |
| 0x0207CDB8 | VEC_Fx16Normalize (fx_vec.o) | 300 | DIFF 19 B, pending | one instruction scheduled early |
| 0x0207CCA4 | VEC_Normalize (fx_vec.o) | 276 | DIFF 24 B, pending | one instruction scheduled early |

## Files and shards written

- `src/matched/arm9_sdk/func_0202FAB4.c`, shard `layout/matched/arm9/pkt_0202FAB4.json` (new).
  Verified with `manifest --verify --shard arm9/pkt_0202FAB4` twice; the second pass rewrote 0.
- `src/matched/arm9_sdk/func_0207D59C.c`, shard `layout/matched/arm9/pkt_0207D59C.json` (new).
  Verified twice; the second pass rewrote 0.
- Deleted `src/pending/arm9_sdk/func_0202FAB4.c` and `src/pending/arm9_sdk/func_0207D59C.c` (this
  session's drafts, superseded by the matched files).
- `src/pending/arm9_sdk/func_0207C8D0.c`: new body (pointer-phi shape, below), notes rewritten.
- `src/pending/arm9_sdk/func_0207CDB8.c`, `func_0207CCA4.c`: code unchanged, a "Pass 3" sentence
  appended to `notes:`.
- No tools, docs/MATCHING.md or other shard touched.

## What closed

**CRYPTO_RC4Init.** The key-index wrap goes before the swap:
`tmp = d[i]; id2 = (u8)(id2 + (tmp + key[id1])); id1++; if (id1 == (u8)key_len) id1 = 0;
d[i] = d[id2]; d[id2] = tmp;`. With the wrap after the swap (every earlier pass) the colouring rotates
d, id1, id2, tmp and the mask. `id2 = 0;` before `id1 = 0;` is also part of the match. The
instructions are the same either way: the image schedules the compare ahead of the stores regardless,
so the diff never showed the statement order.

**G2x_SetBGyAffine_.** Order: both matrix stores first, then `dx`, `dy`, then `y2 = ...`, then the x row
folded straight into the `[2]` store, then `[3] = y2 >> 4`. Computing y2 before the x row is what
changes the colouring (dx leaves x1's register, and the two sums accumulate into centerX's and centerY's
registers). Reusing `x1` for the x row, or `centerX = ...` computed after y2, is also EXACT, but the
filed version needs no parameter reuse and matches DWARF (locals dx, dy, y2 only).

Both are the same lesson: a pure register rotation that declaration order does not move can be the
order of two independent statements in the source, even when the image's instruction order is the
same for both source orders. This may deserve an idiom entry (the integrator's call).

## Near misses

**FX_SqrtAsync 0x0207C8D0, 31 to 10 bytes.** The image shape (base loaded once before the `cmp`, both
arms predicated with 4 instructions each, one unconditional `str r0, [r1, #0xc]` after the join) needs
a pointer assigned in both arms and the high word stored through it at the join:

    volatile CPSqrtRegs *p;
    if (x > 0) { p = reg_CP_SQRT; reg_CP_SQRT->cnt = 1; reg_CP_SQRT->param_lo = 0; }
    else       { p = reg_CP_SQRT; reg_CP_SQRT->cnt = 1; reg_CP_SQRT->param_lo = 0; x = 0; }
    p->param_hi = (u32)x;

What is left is a swap: base in r2 and gt-arm constants in r1, where the image has them the other way
round. DWARF lists no local for FX_SqrtAsync, so `p` is not a final answer. The same 10 bytes come from
a form with no named local: an inline `SqBeg()` that does the cnt/lo stores and returns the base, then
`(x > 0 ? SqBeg() : (x = 0, SqBeg()))->hi = (u32)x;`. Things that did not close the swap: a shared `u32 h`
instead of `x = 0`, p assigned first/middle/last in each arm, the arm stores through p or the constant,
gt/le order (le-first gives 22), a u16/u32/integer-address phi, `x = x` in the gt arm, and permuter
seeds 13607, 13608, 13610, 13615. Without the pointer phi (a shared `h` or `x = 0` with the constant
address at the join), the join reloads its own base and the gt arm is not predicated (64 to 68 bytes).
A u64 local or u32-half inlines are worse (52 to 80 bytes). Returning x (permuter find, not usable
because DWARF says void) predicates both arms fully, so the void function's early `bxgt` is what the
join store prevents.

**VEC_Fx16Normalize 0x0207CDB8, 19 bytes.** Only one instruction is out of place: `smulbb r3, r3, r3`
(z*z) is issued right after `mov r2, #0` in our build, and after `adds r6, r7, r6` in the image.
Everything else, including the divider/multiply interleave and base r5, already matches in the draft.
Putting DIVCNT/NUMER before the sum (the suggested start) makes it worse (29 to 57 bytes, base moves to
r2), whether NUMER is written as u64 or as halves and at whichever of the four sum positions. Also flat:
sum through inline helpers (square, dot product with one or two pointers, accumulating or single
expression), s64/long/int casts, z-first order, other dsi compilers (1.1 to 1.6sp2 all give 19), `-proc`
models, and permuter seeds 13606 and 13613 (random mode).

**VEC_Normalize 0x0207CCA4, 24 bytes.** Also one instruction: `lsl r2, r7, #2` (high word of t<<2) is
issued before the DIVCNT store in our build and after the DENOM-low store in the image. Flat: `t <<= 2`,
`t * 4`, `(u64)t << 2`, two shifts, the shift at each position between the divider and sqrt stores,
divider setup before the sum, all 8 u32-half combinations for NUMER/DENOM/SQRT_PARAM, dot-product
inlines, other dsi compilers, and permuter seeds 13612 and 13614. `-opt noschedule` also gives the same
bytes for both functions, so these two may not be scheduling residues at all.

## Catalog / DWARF notes

- G2x_SetBGyAffine_: DWARF has no x2 local; the matched C folds the x row into its store, consistent
  with that.
- FX_SqrtAsync: DWARF lists no locals, and the best shape needs a phi pointer (see above).

## asm bodies

None.

## Next pass

- FX_SqrtAsync: start from the pending pointer-phi body. Only the base/constant register choice is left.
  Try making the join's base a compiler temp other ways (an inline taking the pointer as a parameter
  at the join, a struct copy), or statement-order changes like the two that closed RC4/G2x.
- The two Normalize functions: both residues are one ALU instruction the image issues later than we do.
  Source reordering inside the block has not moved them, and `-opt noschedule` shows no difference, so
  the next step may be to ask whether the vendor build used an option that 1.1p1 at `-O4,p` does not
  reproduce, instead of more C spellings.
- Unused seeds: 13616 to 13699.
