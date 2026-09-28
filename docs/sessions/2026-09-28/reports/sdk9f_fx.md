# sdk9f_fx: ARM9 SDK final lane, libfx leftovers and two catalog scan rows

Worked from `tools/sdkobj.py`, `tools/match.py show/one`, `tools/permuter.py`, and the vendor objects
extracted into `scratchpad/sdk9f_fx/` with binutils (`readelf`, `objdump --dwarf`, `nm`). No file under
`sdk/` was opened. Objects: fx_vec.o, fx_cp.o, fx_mtx44.o, g3x.o, all stamp 4.0.0.1024 (dsi/1.1p1).
Permuter seeds used: 14101, 14102 (both flat, before the fix below).

## Verdicts

| address | symbol (object) | bytes | verdict |
|---|---|---|---|
| 0x0207C8D0 | FX_SqrtAsync (fx_cp.o) | 52 | EXACT (manifest), matched |
| 0x0207CDB8 | VEC_Fx16Normalize (fx_vec.o) | 300 | EXACT (manifest), matched |
| 0x0207CCA4 | VEC_Normalize (fx_vec.o) | 276 | EXACT (manifest), matched |
| 0x0207BDEC | MTX_Copy44To33_ (fx_mtx44.o) | 40 | false positive, not matched: catalog removal |
| 0x0207DD3C | SBServerSetPublicAddr (sb_server.o) | 12 | false positive, not matched: catalog removal |

## What closed all three: the 64-bit CP registers are not volatile

The answer to "do the object's build options differ" is no: the object's `.comment` is the bare
4.0.0.1024 stamp with no option records, every matched sibling in fx_vec.o and fx_cp.o uses `-O4,p`,
and `-proc` (all 32 values), `-O1` to `-O4`, `#pragma scheduling off`, `#pragma peephole off` and a
dozen `opt_*` pragmas give the same bytes. (`-opt noschedule` is not an option of this compiler; it is
silently ignored, which is why it "gave the same bytes". `#pragma scheduling off` is also a no-op here.)

The difference was in the register declarations. Every draft (and every matched file in the repo)
declares the 64-bit coprocessor registers as `*(volatile u64 *)`. With the SQRT_PARAM register as a
plain `*(u64 *)` lvalue both Normalize functions are EXACT with their existing bodies, and FX_SqrtAsync
is EXACT with the plain body (`if (x > 0) CP_SetSqrt64((u64)x << 32); else CP_SetSqrt64(0);`):

- Normalize pair: a volatile 64-bit store is part of the volatile ordering chain, which changes the
  list scheduler's priorities for the first block (z*z in Fx16Normalize, the `t<<2` high word in
  VEC_Normalize). A sweep of all 32 volatile/non-volatile combinations over SQRT_PARAM, NUMER, DENOM,
  SQRTCNT and DIVCNT closes both functions exactly when SQRT_PARAM is non-volatile and both 16-bit
  CNT registers stay volatile; NUMER/DENOM do not matter either way.
- FX_SqrtAsync: with a non-volatile 64-bit store the two arms' final `str r0, [r1, #0xc]` stores
  are cross-jumped into one, which is the image's shape; with a volatile store the compiler duplicates
  the return instead. The DWARF line table (fx_cp.c 223 cmp, 225 gt arm, 229 base load plus le arm
  plus the shared store, 231 `bx lr`) matches this plain if/else exactly, and no local is needed,
  consistent with DWARF listing none.

The filed files declare NUMER, DENOM, RESULT and SQRT_PARAM all as plain `u64` (consistent with one
64-bit register typedef being non-volatile); that set is also EXACT for all three. CNT and 32-bit
result registers stay volatile. Other matched files still say `volatile u64`; it made no difference
for them. This is probably worth an idiom entry for the integrator: for a residue that looks like
scheduling or a missing cross-jump around CP/DMA 64-bit registers, try the 64-bit register as non-volatile.

## Scan rows: both false positives (report for catalog removal)

- **0x0207DD3C SBServerSetPublicAddr** (sdk_class.json row `0207DD3C`, libdwcgsserverbrowsing,
  sb_server.o, 12 bytes). The bytes `str r1, [r0]; strh r2, [r0, #4]; bx lr` are the last three
  instructions of G3X_SetClearColor, which starts at 0x0207DD24 and is 40 bytes (0x0207DD24 to
  0x0207DD4C, its literal 0x04000350 at 0x0207DD48). The g3x.o object's G3X_SetClearColor has the same
  instructions at +0x18..+0x20. Nothing starts at 0x0207DD3C; the row should be removed.
- **0x0207BDEC MTX_Copy44To33_** (sdk_class.json row `0207BDEC`, fx_mtx44.o, 40 bytes). The object's
  MTX_Copy44To33_ (three `ldm r0!, {r2, r3, ip}; add r0, r0, #4; stm r1!, {r2, r3, ip}` blocks and
  `bx lr`) is byte-identical to the last three blocks of MTX_Copy44To43_, which the catalog places at
  0x0207BDE0 with 52 bytes (four blocks, 0x0207BDE0 to 0x0207BE14) and which is already matched
  (`src/matched/arm9_sdk/func_0207BDE0.c`, EXACT). So 0x0207BDEC is inside Copy44To43_ and
  MTX_Copy44To33_ is not linked at that address; the row should be removed. (It would have qualified for
  an asm body on the evidence: fixed-register ldm/stm copy, one line per instruction in the line table,
  no DW_TAG_variable; not written, since the placement is false.)

## Files and shards written

- `src/matched/arm9_sdk/func_0207C8D0.c`, shard `layout/matched/arm9/pkt_0207C8D0.json` (new)
- `src/matched/arm9_sdk/func_0207CDB8.c`, shard `layout/matched/arm9/pkt_0207CDB8.json` (new)
- `src/matched/arm9_sdk/func_0207CCA4.c`, shard `layout/matched/arm9/pkt_0207CCA4.json` (new)
- Each verified with `manifest --verify --force --shard arm9/pkt_XXXXXXXX`: EXACT, then run twice more
  after the header status was set; both later passes rewrote 0. Header `status:` copied from that output.
- The matched files are written fresh from the object (not copied from the pending drafts).
- Deleted the superseded pending drafts `src/pending/arm9_sdk/func_0207C8D0.c`, `func_0207CDB8.c`,
  `func_0207CCA4.c` (tracked files; the integrator should stage the deletions).
- No tools, docs/MATCHING.md or other shard touched. Scratch in `scratchpad/sdk9f_fx/`.

## asm bodies

None.

## Next pass

Territory closed. Catalog: drop rows 0x0207BDEC and 0x0207DD3C from `layout/sdk_class.json`. Optional:
re-check other open near misses that store 64-bit CP (or other 64-bit I/O) registers with the
non-volatile declaration. Unused seeds: 14103 to 14199.
