# sdk9f_misc: ARM9 SDK final lane, mixed rows

Territory: six arm9 SDK rows (libos os_mutex/os_entropy/os_pxi, libspi tp.o, libdwcac
close.o, libdwcbm dwc_backup.o). Result: 5 filed EXACT (512 bytes), 1 left in pending
(DIFF 62, unchanged). No `.c` or `.h` under `sdk/` was opened; all work came from
`tools/sdkobj.py`, `match.py show/one/--diff`, the permuter and reading `tools/match.py`
(the evidence rules, not edited).

## Verdicts

Every `status:` is copied from `manifest --verify --force --shard arm9/pkt_<ADDR>`; each
shard was then verified again with a plain `--verify`, which rewrote 0.

| address | symbol (object) | bytes | verdict | compiler |
|---|---|---|---|---|
| 0x02084A28 | OS_IsResetOccurred (os_pxi.o) | 16 | EXACT | dsi/1.1p1 (stamp 1024) |
| 0x0208AF08 | TP_GetLatestIndexInAuto (tp.o) | 16 | EXACT | dsi/1.1p1 (stamp 1024) |
| 0x0205B2F8 | CloseSocket (close.o, static) | 68 | EXACT | dsi/1.1p1 (stamp 1025; also EXACT under 1.2, 1.1p1 recorded) |
| 0x02086164 | OSi_UnlockMutexCore (os_mutex.o) | 216 | EXACT | dsi/1.1p1 (stamp 1024) |
| 0x02088168 | OS_GetLowEntropyData (os_entropy.o) | 204 | EXACT | dsi/1.1p1 (stamp 1024) |
| 0x02058904 | DWCi_BACKUPlConvWifiInfo (dwc_backup.o) | 192 | DIFF 62, pending, not rewritten | |

## Files and shards

- New matched: `src/matched/arm9_sdk/func_02084A28.c`, `func_0208AF08.c`, `func_0205B2F8.c`,
  `func_02086164.c`, `func_02088168.c`
- New shards: `layout/matched/arm9/pkt_02084A28.json`, `pkt_0208AF08.json`, `pkt_0205B2F8.json`,
  `pkt_02086164.json`, `pkt_02088168.json`
- Pending removed (each replaced by my own draft from the object, now matched):
  `src/pending/arm9_sdk/func_0205B2F8.c`, `func_02086164.c`, `func_02088168.c`.
  Disclosure: I printed the old `func_0205B2F8.c` once while checking its status line before
  writing mine. The 68-byte function is a direct reading of the object listing and my file is
  my own; its C is the obvious one and matches the old draft's body.
- Untouched: `src/pending/arm9_sdk/func_02058904.c` (previous lane's 62-byte draft; I did not
  beat it with an honest spelling).
- Scratch: `scratchpad/sdk9f_misc/`.

No asm bodies.

## What closed each one

- **OS_IsResetOccurred / TP_GetLatestIndexInAuto**: one-line getters. They reuse the object
  preludes of their matched neighbours (`OsPxiBss g_02150FC8` from OSi_CommonCallback,
  `TpBss g_02152FA4` from TP_GetLatestRawPointInAuto), so the shape is uniform per object.
  The catalog rename from the GX names (sdk9w2_catalog) is confirmed: sdkobj locates both
  members with 0 concrete mismatches.
- **CloseSocket**: code was already identical. SOCLiConfigPtr (0x021A1CD8) now resolves
  under the **existing** overlay `sole-ref/data` rule with an `ov009` hint on its
  `symbols:` line (`SOCLiConfigPtr 0x021A1CD8 data ov009`). No rule was added or bent:
  - The address lies in two overlay windows, ov009 and ov021, and both listings hold data
    there. Without a hint the rule refuses as ambiguous, which is why the earlier lane saw
    MATCH.
  - With the hint, `_hint_contested()` is false: ov021 has no object start at 0x021A1CD8 and
    **no** pool word referring to it.
  - ov009 has **13** pool words naming 0x021A1CD8 outside the compared range (0x0215CAE0 ...
    0x0215EE8C). The callees SOCL_CalmDown/SOC_Cleanup are ov009-window labels, and the
    matched `ov009_func_0215CD3C` dereferences the same word as a config pointer.
  - Evidence recorded in the shard: `sole-ref data:0x021A1CD8`.
- **OSi_UnlockMutexCore**: the reload is an availability asymmetry, not control flow. The
  STD/W case reads the count through its address,
  `mutex->count = (s32)(OSi_GetMutexType(mutex) | ((*(u32 *)&mutex->count - 1) & OSi_MUTEX_COUNT_MASK));`,
  and the R case uses the plain `OSi_DecreaseMutexCount(mutex)`. The address-taken read is
  not CSE'd with the switch value, so the STD/W copy reloads into r0. mwcc then tail-merges
  the two copies, which leaves the `ldr r0,[r6,#0xc]; b next`. A `volatile` read gives the
  same bytes, and so do `((u32 *)mutex)[3]` and `*(s32 *)&`; using the & form in **both**
  cases gives 9 bytes. Two further fixes were needed:
  - the unlock path clears the type, not the count (`OSi_SetMutexType(mutex, 0)`, which is
    the `bic`);
  - `unlocked` is declared before `currentThread` (DWARF order: e, then unlocked). This puts
    unlocked in r1 and the thread in r2.
- **OS_GetLowEntropyData**: three levers.
  - An `OSSystemWork *w` base local that DWARF does not list. Assigning
    `macAddress = w->macAddress` inside the VCOUNT block, *before* the OS_GetTickLo call,
    makes mwcc load 0x02FFFC00 into r4 before the call and keep it across (125 to 85
    bytes).
  - The halfword at 0x02FFFFA8 is read as an absolute address (`*(u16 *)0x02FFFFA8`), not as
    a field of `w`. mwcc gives it its own base, the `add r1, r4, #0x3a8` (85 to 4).
  - The buffer[5] operands are swapped: `((u32)w->h394 << 16) ^ w->w390` (4 to 0).

  OSi_TickCounter resolves `sole-ref`.

## Near miss left in pending: 0x02058904 DWCi_BACKUPlConvWifiInfo (62)

I wrote my own draft from the object and reached the same 62. What I tried, beyond the
previous lanes' lists:

- **TU statics.** `.bss` statics with Address emitted (tentative, initialised, or touched by
  a helper function) give 131. mwcc addresses Wifi[5] from Wifi's own base. The Address+9
  base appears only through the overlay struct.
- **Shift computed first.** A block-local `next = tmp >> 5` computed before the byte, or a
  `u32 lo` copy taken before the shift, gives 62 and 61. The scheduler, not the IR order,
  decides.
- **Aliasing store (the most informative result).** Writing the bytes through an
  out-of-bounds cast off a separate `extern u32 Address` (`((u8 *)&Address)[9]`, file
  `wy1.c`) makes mwcc treat the byte store as possibly aliasing `tmp`. Combined with
  shift-first, this reproduces the object's middle block:
  - the shift goes to ip/lr;
  - both tmp stores come after the `strb`.

  It breaks the rest: `info->pass` is reloaded after the Wifi[10] store, the literal load
  still comes first, and a separate Address literal appears. Total 125. The same cast through
  the overlay struct does not alias (62). Hypothesis for the next pass: in the original, the
  Wifi[5] store (only) is one mwcc cannot disambiguate from `tmp`, while the Wifi[10]/[11]
  stores are disambiguated from `*info`.
- **Compiler.** dsi/1.2, 1.2p1 and 1.3 give the same counts as 1.1p1 for every variant.
- **Permuter.** Seeds 14201/14202 (macros broke the parser; rerun macro-free as `wq.c`),
  14203 (8,000, anneal), 14204 (8,000, anneal) and 14205 (6,000, random). Nothing
  semantics-preserving. 14203's "48" truncates tmp to u8 and was discarded.

## Catalog / DWARF notes

- 0x02084A28 and 0x0208AF08: the catalog renames are right (0 mismatches against os_pxi.o
  and tp.o).
- CloseSocket's DWARF gives only `result`. SOCLiConfigPtr and the SOC callees have no DWARF
  in close.o. SOCLiConfigPtr is ov009 data.
- OS_GetLowEntropyData's DWARF lists only `macAddress`. The `w` base local is not a DWARF
  local; the bytes are identical.
- Other shards that reference these addresses as evidence (`pkt_0205B1E4` names 0x0205B2F8,
  `pkt_02086078` names 0x02086164, ITCM `pkt_01FF8414` names 0x02084A28) are unaffected.
  They may now also have a `matched` witness.

## Next pass

- Only 0x02058904 remains. Start from the aliasing result above (`scratchpad/sdk9f_misc/wy1.c`).
  Find a spelling where the Wifi[5] store alone is not disambiguated from `&tmp`, and keep
  the literal pool {Wifi, Address(.bss+0), Wifi+6, Wifi+0xC}. Unused permuter seeds: 14206
  to 14299.
