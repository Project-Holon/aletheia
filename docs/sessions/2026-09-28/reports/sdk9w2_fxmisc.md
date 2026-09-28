# sdk9w2_fxmisc: ARM9 SDK wave 2, libfx / libgx / libcrypto / libmath / crt0 leftovers

Work from `tools/sdkobj.py`, `tools/match.py show/one` and `tools/permuter.py` only; no file under
`sdk/` was opened. Objects checked: fx_vec.o, fx_cp.o, g2.o, rc4.o, dgt_sha1.o, crt0.HYB.TWL.o, all
stamp 4.0.0.1024 (dsi/1.1p1), flags `-O4,p`, lang `c99`. Permuter seeds used: 13601 to 13605.

## Verdicts

| address | symbol (object) | bytes | verdict | residue |
|---|---|---|---|---|
| 0x0202FAB4 | CRYPTO_RC4Init (rc4.o) | 128 | DIFF (38 B), pending | register allocation only |
| 0x0207C8D0 | FX_SqrtAsync (fx_cp.o) | 52 | DIFF (31 B), pending | if-conversion shape |
| 0x0207CCA4 | VEC_Normalize (fx_vec.o) | 276 | DIFF (24 B), pending | scheduling only |
| 0x0207CDB8 | VEC_Fx16Normalize (fx_vec.o) | 300 | DIFF (19 B), pending | scheduling only |
| 0x0207D59C | G2x_SetBGyAffine_ (g2.o) | 160 | DIFF (38 B), pending | register allocation only |
| 0x020816FC | MATH_CalcHMACSHA1 (dgt_sha1.o) | 148 | MATCH, pending (unchanged) | one wildcarded pool word |
| 0x02004BB4 | INITi_DoAutoload (crt0.HYB.TWL.o) | 412 | MATCH, pending (unchanged) | one wildcarded PC24 site |

No function closed this pass. No matched file and no shard written; `manifest --verify` was not run
(nothing to verify).

## Files written

- `src/pending/arm9_sdk/func_0202FAB4.c`: fresh draft from rc4.o. The pending file that existed
  there (from commit 353641bf, not this session's) was overwritten without being read.
- `src/pending/arm9_sdk/func_0207C8D0.c`, `func_0207CCA4.c`, `func_0207CDB8.c`, `func_0207D59C.c`:
  sdk9_gxfx drafts, code unchanged, a "Pass 2" sentence appended to each `notes:` line.
- No shard, nothing under `src/matched/`, no tools or layout change.

## Near misses

**CRYPTO_RC4Init 0x0202FAB4.** Best C (in the pending file): clamp, zero `i`/`j`, `d = context->s`,
identity loop, then `tmp = d[i]; id2 = (u8)(id2 + (tmp + key[id1])); id1++; swap;
if (id1 == (u8)key_len) id1 = 0;`. The `(tmp + key) + id2` grouping and the explicit `(u8)key_len`
reproduce every instruction and its order. What is left is the colouring: the image keeps `d` in lr
(DWARF agrees: d r14) and puts the mask of key_len in a fresh register (r3), with the constant 0 taking
key_len's old r2. This C coalesces the mask into r2 and gives d r4. These all failed to move it: 120
declaration orders, 96 combinations of key cast, sum grouping, increment/compare spelling and clamp
position, a no-code self-assignment, `id1 = id2 = 0` chains, and permuter seeds 13601 and 13602.

**FX_SqrtAsync 0x0207C8D0.** The image has two predicated 4-instruction arms (`cnt=1; low=0`),
followed by one unconditional `str r0, [r1, #0xc]` where r0 is x (gt) or 0 (le). So the high-word store
was merged at the join before if-conversion. Every spelling I tried leaves a 5-instruction gt arm that
ends in `strgt; bxgt lr`: gt-first, le-first, a ternary argument, an early return, direct register writes,
the param stored as two u32 halves, and `x = 0` reassignment. Permuter seed 13603 was flat.

**VEC_Normalize 0x0207CCA4 / VEC_Fx16Normalize 0x0207CDB8.** One fix did not close both. New
evidence: in Fx16Normalize, writing DIVCNT and NUMER *before* the sum reproduces the image's
interleave of multiplies and divider stores (smulbb z after the first adds). That moves the I/O base
to r2 instead of r5, though, so the image probably had the divider setup ahead of the sum in its IR
but with a different register order. For VEC_Normalize that ordering does not move the `lsl r2, r7, #2`.
Also flat: split setters (control / imm64 / denom), u32 halves for DENOM or SQRT_PARAM, s64 setter
params, direct register writes, `-O4,s` / `-O3,p` / `-O2,p` / `-O4` (all 24 bytes), and permuter
seeds 13604 and 13605.

**G2x_SetBGyAffine_ 0x0207D59C.** DWARF lists only `dx, dy, y2` (no x2). The image keeps dx in ip,
not coalesced with x1's register; the C coalesces it, and the whole middle block rotates. I tried x2
folded into the store, x1 or centerX reused as x2, 288 combinations of declaration order, dx/dy
order, compute-before/after the matrix stores and x/y order, self-assignments at four points, an
inline GX_FX32_FX16, and int vs long locals. All give the same 26-line rotation.

## The two MATCH rows: exact evidence (no tools or layout changed)

**MATH_CalcHMACSHA1 0x020816FC.** Byte-correct except the pool word at +0x84 (0x02081780). In
dgt_sha1.o that word is an ABS32 relocation to `@12151`. This is a *local data* symbol of 28 bytes, the
compiler-generated initializer template for the local `struct MATHiHMACFuncs hash2funcs` ([fb+8]). The
function copies it onto the stack with `ldm lr!, {r0-r3}; stm ip!, {r0-r3}; ldm lr, {r0-r2}; stm ip,
{r0-r2}` (16 + 12 = 28 bytes). The image value is 0x020A5CB8 (g_020A5CB8). Our compile emits its own
anonymous `@NNN` template, which is local to the translation unit and has no name the `symbols:` block
can pin to 0x020A5CB8. The site therefore stays wildcarded. The four other relocations (MATHi_CalcHMAC,
MATH_SHA1Init/Update/GetHash) resolve. Closing it needs match.py to accept an address for a
compiler-generated initializer (for example, map the compiled object's anonymous data symbol that is
the ABS32 target of this site to a declared address).

**INITi_DoAutoload 0x02004BB4.** The unresolved site is +0x188, `b _start_AutoloadDoneCallback`,
target 0x02004EA8. Corrected facts:
- 0x02004EA8 is **not** the start of a 64-byte extent. `match.py show` prints a 0x40-byte window only
  because `target_extent()` finds no listing start there (the size defaults to 0x40). The asm has
  `loc_02004EA8:` (a `loc_`, not a `func_` label). Nothing overlaps INITi_IsRunOnTwl (0x02004EB4).
- 0x02004EA8, 0x02004EAC and 0x02004EB0 are three consecutive 4-byte `bx lr` stubs. crt0.HYB.TWL.o has
  exactly three 4-byte global functions that no row places: `_start_AutoloadDoneCallback`,
  `NitroStartUp` and `OSi_ReferSymbol`. 0x02004EAC is already labelled `func_02004EAC`; 0x02004EB0 has
  no label.
- The only branch to 0x02004EA8 is inside DoAutoload itself, so the `label` class (which needs a caller
  elsewhere) can never witness it.

Exact split that closes it: in `asm/arm9/src/000_02004000.s`, emit `func_02004EA8` (4 bytes,
0x02004EA8..0x02004EAC, ARM) in place of `loc_02004EA8`. That makes it a traced function start, which
the `sole-ref/code` class accepts. Either of these would also work, with no disasm change:
- a `layout/symbols_sdk.json` row `_start_AutoloadDoneCallback 0x02004EA8 arm` (the `sdk` class);
- an EXACT manifest entry covering 0x02004EA8 (the `matched` class). `void func_02004EA8(void) {}`
  compiles to `bx lr` and `match.py one` reports EXACT at 0x02004EA8.

I did not file that stub, because it is not a catalogued SDK row. It is the integrator's call.

## Catalog / DWARF notes

- G2x_SetBGyAffine_: DWARF has no `x2` local, only `dx, dy, y2` (reverse listing `y2, dy, dx`).
- crt0.HYB.TWL.o: `_start_AutoloadDoneCallback`, `NitroStartUp` and `OSi_ReferSymbol` (4 B each) are
  missing from symbols_sdk.json. They are almost certainly the three `bx lr` words at
  0x02004EA8/0x02004EAC/0x02004EB0 (order not established from the object).

## Next pass

- FX_SqrtAsync: look for a spelling whose IR has a single high-word store at the join (a phi of x and 0)
  while cnt/low stay in both arms. Candidates: an inline with a local temp, a `do {} while (0)` macro
  body, or a u64 local that the inliner hides from DWARF.
- VEC_Fx16Normalize: start from "DIVCNT+NUMER before the sum" and fix the base-register colouring (the
  base in r5, constants in r2); then apply the same thing to VEC_Normalize.
- RC4Init, G2x_SetBGyAffine_: pure colouring. The next ideas are a block-scope temp for `(u8)key_len`
  (rejected here because DWARF shows no such local, but an inlined helper would hide it) and, for G2x,
  an inline helper computing one affine row.
- HMACSHA1 and DoAutoload need the tool or disasm changes above, not C.
- Unused seeds: 13606 to 13699.
