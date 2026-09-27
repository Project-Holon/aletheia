# Runtime lane, second pass: all 34 rows reproduced, none filed

The first pass's scratchpad (converters.c, compares.c, misc.c) was gone at
the start of this session (session scratchpad dirs are ephemeral), so all
21 of its rows were re-transcribed from scratch alongside the 13 that were
left undone, using the same asm-block form and the same mwccarm dialect
quirks it documented (stmdb/ldmia for push/pop, `mov{cond}{s} rd, rn,
<shift> rm` for standalone lsl/lsr/asr/ror/rrx, `<op><cond><s>` order,
cpsr/cpsr_flg for mrs/msr). To handle the volume reliably, disassembly was
regenerated mechanically from extract/arm9_dec.bin with a small capstone
script (translate + auto-label + cross-file symbol resolution), then
hand-fixed only where the tool flagged a real error; every function was
re-verified with `match.py one` before being trusted.

All 34 layout/runtime_arm9.txt rows are now reproduced EXACT/EXACT*, ~10948
bytes, in 12 files under src/pending/runtime2/ (see its README there):
converters.c (9 fns, 732B), compares.c (10 fns, 1296B), misc.c (2 fns,
80B), ll_divmod.c (520B), s32_div_f.c (1008B), double_arith_body.c (412B),
fmul.c (480B), fsub_fadd.c (1204B), dadd_dsub.c (1764B), dmul.c (1128B),
fdiv.c (976B), ddiv.c (1348B). Interconnected clusters (branches into
another entry's interior) are one merged asm function per file; two
functions carry an in-body data table as `dcd` (dmul's 264B normalisation
table, fdiv/ddiv's 256B reciprocal-seed tables, which straddle function
extents exactly as docs/notes says).

**Not filed to the manifest -- worklist leak confirmed.** Before filing,
I checked how tools/worklist.py classifies a matched entry at a
runtime_arm9.txt address. Baseline (`worklist.py --summary`): `runtime
excluded 34 (8964 bytes)`, `matched so far 4506 (401976 bytes)`, `open 0`,
coverage 100.0000%. tools/match.py's manifest schema has only
`MATCHED_KINDS = ("game", "game_unit", "sdk_calibration")` -- no kind for
hand-written runtime library code. Filing any of these functions as kind
"game" makes worklist.py's classifier compute `proven_game = True` at that
address (kind in game/game_unit, address not in symbols_sdk.txt), and the
classification order is written as a chain of `elif ... and not
proven_game`, so the `elif addr in runtime` branch never fires -- the row
falls through to `elif addr in matched` instead and counts as ordinary
game code. I verified this by extracting the exact classifier snippet
(tools/worklist.py lines ~748-786) and running it standalone against a
synthetic matched entry at 0x0209BE4C: result was `matched`, not
`runtime`. I did not write a real manifest shard to layout/matched/ to
prove this on the live tree (shared resource, other lanes active there,
and the sandbox denied a write there); the standalone extraction uses the
real code path unmodified so the result stands. Per instructions, I
stopped filing and left all files in src/pending/runtime2/ with a header
note per file plus a directory README distinguishing this from that
directory's normal MATCH-cap convention (these are already EXACT, so the
normal graduation trigger would misfire).

**For the integrator:** the fix is either (a) a new manifest kind for
hand-written runtime library code that worklist.py's classifier is taught
to still resolve to "runtime", or (b) change the `proven_game` guard on
the `elif addr in runtime` branch so a layout/runtime_arm9.txt address
always classifies "runtime" regardless of manifest kind. Either requires
editing tools/worklist.py and/or tools/match.py, which this lane was told
not to touch. Once fixed, every file in src/pending/runtime2/ re-verifies
with the same `match.py one` command in its header and can move straight
to src/matched/ with a manifest shard per packet id already named in each
header.

No layout/runtime_arm9.txt changes were made. No manifest or
src/matched/ writes were made. No commits.
