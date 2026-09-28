# worklist_interior: credit SDK interior labels from the parent's compared range

Lane worklist_interior, 2026-09-28. Implements the change proposed in `sdk9f_last.md`
(owner-approved). Tools touched: `tools/match.py`, `tools/worklist.py`. No source under
`src/` was edited.

## Summary lines

| | before | after |
|---|---|---|
| SDK excluded | 1119 fn, 129800 B | 1119 fn, 129800 B |
| matched SDK | 1105 fn, 127548 B | 1119 fn, 129800 B |
| matched so far (game) | 4500 fn, 400710 B | unchanged |
| coverage by bytes | 100.0000% (400710 / 400710) | unchanged |
| sole-ref share | 48776 B, 189 fn | unchanged |

The "before" line is the committed `layout/worklist.json`, which predates the refresh for
the two whole functions of sdk9f_last (+2 fn, +916 B). The interior credit adds the other
12 fn, 1336 B. `worklist.py --summary` differs from before in that one line only.
`tools/ovstats.py` output is identical before and after. (`ovstats.py` has no `totals`
argument, so the check compared the default output.)

Credited labels: MI_CpuCopy+0xA4/+0xEC/+0x184/+0x21C, MI_CpuMove+0xBC/+0x104/+0x1A0/+0x23C,
OS_SPrintf+0x4, STD_TSScanf+0x4, STD_TSPrintf+0x4, STD_TSNPrintf+0x4.

## Diff summary

`tools/match.py`
- New `next_listing_label(addr, region)`: the first listing label strictly after `addr`.
  It uses the sorted label set from `scan_listing()` and caches it per region.
- `entry_from_source()`: for a verified, non-unit, non-runtime entry, it writes
  `compared_bytes = r.size` (the length `run_one()` compared) only when
  `addr + r.size > next_listing_label(addr)`. Nothing else in the entry changed.
- Selftest: six new cases under "sdk interior". Positive cases: an EXACT parent covers the
  label, and an EXACT* parent covers the label. Negative cases: the compared range stops at
  the label, `compared_bytes` is missing, the parent is unverified, and the parent is MATCH.
  All pass.

`tools/worklist.py`
- New `sdk_interior_parent(extents, addr)`, which returns `(start, end, name)`.
  `sdk_interior()` now calls it and returns the same string as before.
- `cover_from_entries()`: the record for an entry's own address also carries its `status`
  and its `compared_bytes` when present.
- `classify()`, interior branch: with no entry at the label itself, it credits
  `matched_name = "<parent>+0xOFF"` and sets `matched_interior = True`, but only when the
  parent start has an EXACT/EXACT* entry and `start + compared_bytes > label`. Anything else
  stays open. The SDK-matched totals count these through the existing
  `cls == "sdk" and matched_name` rule, the same way as other matched SDK functions.

### One deviation from the literal proposal

The proposal's condition was `r.size > (r.target_size or r.size)`. It fires for only one of
the six parents. `target_extent()` returns None when the address is not a listing label.
Five parents (0x02082EA4, 0x02084F40, 0x0208CF34, 0x0208D7E0, 0x0208D80C) are not labels,
because disasm.py put the label on a later instruction. So the implementation compares
against the next listing label after the address. For a labelled address that is the same
number as `target_size`. This is the "runs past the next listing label" rule the report
states in prose.

## Shards changed

Forced verifies (`manifest --verify --force --shard`) were run on the parent shards only. A
second pass of each rewrote 0.

| shard | change |
|---|---|
| arm9/pkt_02082EA4 | MI_CpuCopy: `compared_bytes: 752`; kind game -> sdk |
| arm9/pkt_02083194 | MI_CpuMove: `compared_bytes: 788`; kind game -> sdk |
| arm9/pkt_02084F44 | OS_SPrintf 0x02084F40: `compared_bytes: 40`; kind game -> sdk (func_02084F68 unchanged) |
| arm9/pkt_02087AE4 | STD_TSPrintf: `compared_bytes: 44`; "OS_SNPrintf" 0x0208D80C: `compared_bytes: 40`; "OS_SPrintf" 0x0208CF34 entry added with `compared_bytes: 40`; kind game -> sdk on func_02087AE4, func_02087FBC, func_0208B8B0, and on the two entries above |
| arm9/pkt_0208CF34 | deleted (see below) |

Two side effects of the forced verify were not part of the brief. Both come from the current
tree, not from the new code:

- **kind game -> sdk.** These sources live under `src/matched/arm9_sdk/`, and the current
  `entry_from_source()` files that directory as kind sdk. The committed shards still said
  game. Worklist figures do not move: every one of these addresses is a strong SDK row, so it
  was classified sdk either way. Across the tree, about 1216 entries in 711 shards still carry
  a kind that differs from what a forced verify would write. That drift was already there and
  is left alone.
- **0x0208CF34 moved shards.** The header of `func_0208CF34.c` has always said
  `packet: pkt_02087AE4`, but its committed entry sat in `pkt_0208CF34.json`. No source maps
  to that shard, so `--shard arm9/pkt_0208CF34` is refused ("no such shard"). Verifying
  pkt_02087AE4 wrote the entry where the header puts it. That left the old shard as a stale
  duplicate, so I deleted `layout/matched/arm9/pkt_0208CF34.json`. `manifest --check` was
  "clean" even while both copies existed, because its duplicate key includes `kind`
  (game vs sdk). That is a gap in the check.

## Other shards

A dry run (a scratch script calling `entry_from_source(verify=True)`, no writes) recompiled
every entry that could gain the field: 3419 entries, the EXACT* ones plus the ones at
unlabelled addresses. The field appears for 13 of them. Six are the parents above. The
other seven would gain the field only on a future forced verify of their shards. No shard of
theirs was rewritten here:

- arm9/func_0202822C (4)
- arm9_sdk/func_02050790 (16)
- arm9_sdk/func_02051630 (16)
- arm9_sdk/func_02059A44 (24)
- ov175_func_021D7E18 (2796, EXACT*)
- ov009_func_0217EF00 (80)
- ov009_func_021956F8 (88)

All 3419 still verify EXACT/EXACT*. An entry whose compared bytes stop at or before the next
label records nothing, so every other shard stays byte for byte identical.

## Checks

- `python tools/match.py selftest --quick`: 265 cases (including the 6 new ones), 0 failures.
- `python tools/match.py manifest --check`: clean (8429 shard files, no duplicates, no
  unread json).
- `python tools/worklist.py --refresh`, then `--summary`: see the table above.
- `python tools/build.py --split --pack`, then `tools/ndsrom.py build extract --override
  build/pack` (the rebuild tools/session/wave.py runs): sha1
  26ad0b9967aa279c4a266ee69f52b9b2332399a5.

## Files for the integrator to stage

`tools/match.py`, `tools/worklist.py`, `layout/worklist.json`,
`layout/matched/arm9/pkt_02082EA4.json`, `layout/matched/arm9/pkt_02083194.json`,
`layout/matched/arm9/pkt_02084F44.json`, `layout/matched/arm9/pkt_02087AE4.json`, the
deletion of `layout/matched/arm9/pkt_0208CF34.json`, and this report.
