# sdk9w2_cardfs report (libcard, libfs, libctrdg; arm9 SDK rows, second pass)

All work from `tools/sdkobj.py`, `match.py show/one`, the idiom index and the permuter; no file under `sdk/` was opened. The first pass's object-derived drafts were continued; `CARDi_RequestStreamCommandCore.c` (0x02076540) was not read and not attempted.

## Filed (status copied from `manifest --verify`; second pass rewrote 0 for every shard)

| address | symbol | bytes | status | shard | how |
|---|---|---|---|---|---|
| 0x02075ED4 | CARDi_LockResource | 120 | EXACT | arm9/pkt_02075ED4 | `-O4,p` spelling found: `while ((p->lock_owner != -3) ? 1 : 0)` |
| 0x020774C0 | CARD_TerminateForPulledOut | 88 | EXACT | arm9/pkt_020774C0 | C unchanged; the callee 0x027315A8 is now witnessed by the `matched` class through `layout/matched/twl/pkt_027315A8.json` (another lane's uncommitted twl_sdk file) |
| 0x0207AAF8 | FSi_ReadDummyCallback (static) | 8 | EXACT | arm9/pkt_0207AAF8 | new file, `return 4;` |
| 0x0207AB00 | FSi_WriteDummyCallback (static) | 8 | EXACT | arm9/pkt_0207AB00 | new file, `return 4;` |
| 0x0207AB10 | FSi_InitRomArchive | 340 | EXACT | arm9/pkt_0207AB10 | promoted from pending MATCH; both dummy callbacks now attest (`matched`) |
| 0x020911D4 | CTRDGi_DummyCallback (static) | 4 | EXACT | arm9/pkt_020911D4 | new file, empty body |
| 0x020911A0 | CTRDG_DummyInit | 52 | EXACT* | arm9/pkt_020911A0 | promoted from pending MATCH; CTRDGi_DummyCallback attests (`matched`) |

Total 620 bytes. Files written: `src/matched/arm9_sdk/func_{02075ED4,020774C0,0207AAF8,0207AB00,0207AB10,020911D4,020911A0}.c` and `layout/matched/arm9/pkt_{same}.json`. The pending files for 0x02075ED4, 0x020774C0, 0x0207AB10, 0x020911A0 were moved out of `src/pending/arm9_sdk/` (plain `mv`, no git).

0x020774C0 depends on `src/matched/twl_sdk/func_027315A8.c` / `layout/matched/twl/pkt_027315A8.json` from another lane: if that entry is dropped, this row falls back to MATCH (C unchanged).

## Pending (updated notes)

| address | verdict | residue |
|---|---|---|
| 0x02076E4C CARDi_ReadRomWithCPU | DIFF (280/284 bytes) | loop entry fixed with the same ternary lever (`while ((length > 0) ? 1 : 0)`), stack slots fixed (declare `retval` before `cachedPage`, matching the DWARF reverse order), clamp fixed (`if (length <= n) n = length;` gives `cmp r8,r7; movls`), `ptr` declared before `pos` fixes r5/r6. Left: the image copies n (r7) to r0 for the `length < n` test (`mov r0,r7; cmp r8,r0`) where every spelling tried folds to `cmp r8,#0x200` (4 bytes short); the inner poll loop takes r1-r3 where ours takes r0-r2. Tried: n at function scope / assigned per arm / inline predicate / casts / ternary on the test; permuter seeds 13401-13403 (seed 13401's best reads the volatile MCCNT1 twice, not value-preserving, rejected). |
| 0x02078D34 FS_LoadOverlayInfo | MATCH | ABS32 to SDK_OVERLAY_NUMBER (0xED) unwitnessed. Evidence that exists: 0xED = 237 = `layout.json` `counts.overlays`. No attest class covers an overlay count, and the only pool word holding 0xED (0x02078EA8) is this function's own. No witness invented. |
| 0x0207902C FS_StartOverlay | MATCH | ABS32 to SDK_LTDAUTOLOAD_LTDMAIN_START (0x02700000) and SDK_LTDAUTOLOAD_LTDMAIN_BSS_END (0x02735B40) unwitnessed. Evidence that exists: `layout.json` twl `ram_start` = 0x02700000 and `bss_end` = 0x02735B40; the matched asm body OS_GetInitArenaLo also holds 0x02735B40 as a pool word at 0x02086740, but main.s prints that run as unlabelled `.word`, so the `literal` class does not index it. A tools-side rule (twl layout bounds, or indexing pool words of matched asm bodies) would be needed; not attempted (tools/ is off limits). |

## Territory items not done

- 0x02076540 CARDi_RequestStreamCommandCore (408 B): not attempted (context budget). The old pending `CARDi_RequestStreamCommandCore.c` is untouched and unread.

## Card lane's earlier edits to tracked files: keep both

`src/matched/arm9_sdk/cardi_dmareaddone.c` (0x02077084) and `cardi_initresourcelock.c` (0x0207608C) were modified in the working tree (SDK names, DWARF CARDiCommon layout, `sdk:` line). Verified with `match.py one`, `-O4,p`: both working-tree versions are EXACT; both HEAD versions are DIFF (HEAD `cardi_initresourcelock.c` is 18 bytes out, the same zero/base register swap the first pass reported). HEAD's `pkt_02060000.json` did not list either; the working-tree `pkt_02060000.json` re-adds both as EXACT. Keep the edits (not reverted; `pkt_02060000` is not my shard, so I did not run `manifest --verify` on it).

Follow-ups for the integrator:
- 0x02077084 is claimed by two shards with different names: `pkt_02077084` (`func_02077084.c`, committed) and `pkt_02060000` (`cardi_dmareaddone.c`). `manifest --check` does not flag it because the names differ. Byte-identical sources; drop one.
- 0x0207608C is now EXACT via `cardi_initresourcelock.c`, so the tracked `src/pending/arm9_sdk/func_0207608C.c` (DIFF) is stale and can be deleted (the lever was `CARDiCommon *p = (CARDiCommon *)&cardi_common;` plus the full struct).

## Classification note

The three statics (0x0207AAF8, 0x0207AB00, 0x020911D4) are not in `tools/sdkclass.py`'s union (it places catalog and archive symbols, and statics have no catalog row), so the derived category would be `arm9` (game), the way `func_0207AB08` (FSi_OverrideRomArchive) sits in `src/matched/arm9/`. I filed them under `arm9_sdk` as the brief asked; the object evidence is the callers' relocations (`FSi_ReadDummyCallback`, `FSi_WriteDummyCallback` in fs_proc_rom.o, `CTRDGi_DummyCallback` in ctrdg_proc.o). `tools/migrate_src.py` would move them to `arm9/` if re-run.

## Shape note (worth an idiom entry)

A `while` whose condition is written `(cond) ? 1 : 0` is rotated without the peeled entry test at `-O4,p`: mwcc emits the constant setup, a `b` to the bottom test and a single back edge, the shape `-O4,s` gives for a plain `while`. A plain `while (cond)` gets the peeled guard, and `for(;;){if(!cond)break;}` gets a top-tested loop. It fixed CARDi_LockResource outright and the loop entry of CARDi_ReadRomWithCPU. A `static inline BOOL f(const T *p) { return (c) ? 1 : 0; }` predicate gives the same result. Related to the first pass's FSi_ExecuteSyncCommand `&&` finding: a condition the compiler will not duplicate. (Side check: every placed card_common.o function is EXACT under both -O4,p and -O4,s, and card_rom.o's CARDi_RefreshRom is DIFF under -O4,s, so -O4,p stays the flag.)

## Catalog / DWARF names

No catalog rows exist for 0x0207AAF8, 0x0207AB00 or 0x020911D4; the names come from the callers' relocations. 0x027315A8 is PMi_ExecutePostExitCallbackList by relocation; it is also called from 0x02087C10.

## asm bodies

None.

## Next pass

- 0x02076540 CARDi_RequestStreamCommandCore (write fresh from the object).
- 0x02076E4C: the `mov r0,r7; cmp r8,r0` copy (see idiom a-constant-compared-from-a-register-is-a-variable-assigned-in-another-arm) and inner-loop colouring.
- 0x02078D34 / 0x0207902C: need a tools-side decision on linker-absolute symbols.

Permuter seeds used: 13401 to 13403.
