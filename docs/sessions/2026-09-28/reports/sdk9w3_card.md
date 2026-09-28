# sdk9w3_card report (libcard, arm9 SDK rows, third pass)

All work comes from `tools/sdkobj.py`, `match.py one/show`, the permuter, and objdump on vendor members pulled out through `sdkobj.member` into `scratchpad/sdk9w3_card/`: the Rom and Debug builds of card_rom.o and card_backup.o, used for the line tables, DWARF and disassembly. I did not open any `.c`/`.h` under `sdk/`. No `git` writes.

## Result

Nothing filed as matched. Both functions reach EXACT only in mwcc's asm mode, and the brief's asm rule does not allow that. Both stay in pending, each with the exact spelling recorded in its notes line.

| address | symbol | bytes | verdict (plain C) | reaches EXACT with |
|---|---|---|---|---|
| 0x02076E4C | CARDi_ReadRomWithCPU (card_rom.o) | 284 | DIFF, 280/284, 165 bytes | plain `while (length > 0)` plus a zero-byte `asm { .align 4 }` before `CARDi_CheckPulledOutCore(...)` or before `CARDi_StartRomPageTransfer(pos)` |
| 0x02076540 | CARDi_RequestStreamCommandCore (card_backup.o, static) | 408 | DIFF, 408/408, 21 bytes (register permutation only) | a zero-byte `asm { .align 4 }` as the last statement, or `#pragma opt_loop_invariants off` |

I checked each "EXACT with" claim with `match.py one` against the exact pending file plus the one-line change. `manifest --verify` was not run because no shard was written.

## Files written

- `src/pending/arm9_sdk/func_02076E4C.c`: continued this session's draft. The body is rewritten to the object-evidenced shape (see below). Status DIFF comes from `match.py one`.
- `src/pending/arm9_sdk/CARDi_RequestStreamCommandCore.c`: overwritten, unread, with a fresh draft written from the object. Status DIFF comes from `match.py one`.
- This report.
- No shards.

## Evidence for the asm-mode reading (for the integrator / idiom owner)

- **CARDi_ReadRomWithCPU, Rom line table.** The `mov r0,r7` copy at +0x64 is attributed to line 372, the line where `n` is declared. The Rom DWARF also places `n` in r0. So `n` is a real copy of a constant temp, which means copy propagation did not run. `#pragma opt_propagation off` reproduces that copy (the ternary version is then 10 bytes out, all poll-loop colouring). Only asm mode also gives the r1-r3 colouring in the poll loop.
- **Other shape facts from the Rom line table and the Debug build, all adopted in the draft:**
  - a `u8 *const cacheBuffer = CARDi_cache_buf;` local at line 367. It is in the Debug DWARF; the Rom DWARF drops it because it was propagated away.
  - `ptr`, `n`, `pos` are declared on lines 371, 372 and 373.
  - the clamp is a MIN ternary.
  - `pos` is computed with `& ~(512 - 1)`. The `mov #0x200; rsb` pair is just how mwcc builds 0xFFFFFE00, and it appears with a literal too.
- **CARDi_RequestStreamCommandCore.** The Debug build has the same locals (req_type, req_mode, retry_count, size, len), the same switch, the same MIN and the same early-exit structure, and the Rom line table (147-222) matches the draft line for line. The Rom version still differs only in how four callee-saved registers are assigned. Declaration order (all 24 permutations), `const` combinations, compound versus explicit assignment, casts, `default:` arms, `return` versus `break` and enum field types all leave the permutation in place. The only thing that closes it is asm mode or `opt_loop_invariants off`.
- **No asm instruction in either function.** Neither the Rom nor the Debug disassembly contains one. The loops lane's rule ("asm reading only when the body shows an asm instruction") therefore keeps both out of matched. Still, two functions from two objects of one library now need the same mode, so something in the libcard TU probably turns it on. The trigger is not yet identified; the loops lane showed that an inlined asm helper folded to dead code does this. This needs a coordinator decision: accept a `/* asm mode: ... */` evidence line, or keep both rows pending.
- **card_rom.o may be C++.** It carries the C++-mangled local static `_ZZ35CARDi_ReadCardWithHashInternalAsyncPvS_mmE14card_hash_info`. Compiling with `--lang c++` changes nothing useful (the ternary becomes a materialised bool, and a plain `while` is peeled). Sibling rows match as c99.

## Near misses and residue

- 0x02076E4C: 165 bytes, 280/284 (the `mov r0,r7` copy and the r1-r3 poll loop). Unchanged from the second pass, now with the explanation above.
- 0x02076540: 21 bytes. Image: buf r4, req_type r5, req_mode r6, size r7. Draft: req_mode r4, size r5, buf r6, req_type r7. With non-const locals the draft becomes req_type r4, req_mode r5, size r6, buf r7: the same values, rotated by one register.
- The `flag` word must be read volatile (`volatile u32 flag` in CARDiCommon). The image re-reads it for the clear, and a cast-only volatile test merges the loads into an `ldm`. For comparison, the matched CARDi_Request uses a volatile cast on its test.

## Catalog / DWARF names

These agree with the catalog. CARDi_RequestStreamCommandCore is `static` in card_backup.o, so its local 0x20 load is `cardi_common.cmd->spec.subsect_size` for request 15 (erase subsector), inlined. The call for request 11 is CARD_GetBackupSectorSize.

## asm bodies

None filed.

## Permuter

- Seeds 13801-13803 on 0x02076E4C: the best candidates re-read MCCNT1, drop the `n` compare or retype `ctrl`. None preserves the function's behaviour; all rejected.
- Seeds 13804-13806 on 0x02076540: the best candidate (12 bytes out) makes the `p->len` compare signed. That changes behaviour; rejected.

## Next pass

- Get a decision on the asm-mode reading. If it is accepted, both rows file EXACT with the one-line change given in each notes line; add the evidence line and run `manifest --verify --force --shard`.
- If it is not accepted, look for the libcard trigger. Compare asm-mode sensitivity across the other open card_rom.o and card_backup.o rows; CARD_InitRomHashContext is on the loops lane's sign list.
