# Source tree rework: region/kind folders and a deterministic SDK classifier

## Source layout

`src/matched/` and `src/pending/` are partitioned by region and kind:

    arm9  arm9_sdk  itcm_sdk  ov  ov_sdk  twl  twl_sdk

A file's folder is its classification.  The region comes from the header's
`region:`; the `_sdk` suffix from `tools/sdkclass.py`.

12,483 files moved, 6,949 shard `source:` paths rewritten, 0 collisions,
0 unmapped.  `tools/migrate_src.py` performs the move and the rewrite; every
tool resolves sources through the shard `source:` field, so the tree can be
re-sorted without touching the build.

## SDK classification

`tools/sdkclass.py` scans the linked image with `libmatch.py`'s archive
patterns, then propagates: the linker lays an archive member out contiguously
in one section at the object's own offsets, so one verified function pins the
whole member and its siblings follow at `base + value`.  Output is
`layout/sdk_class.json`.

`symbols_sdk.json` (the catalog) union `sdk_class.json` (the scan) is the SDK
set, consumed by `tools/ovstats.py`, `tools/coveragemap.py` and
`tools/worklist.py`.  Nothing that was SDK stops being SDK.

`kind` is derived, never authored: `match.py` maps each source directory to a
kind through `SRC_DIRS`, and `sdk`/`sdk_unit` are in `MATCHED_KINDS` so SDK
matches count.

`python tools/sdkclass.py --where 0xADDR REGION` prints the kind, folder and
symbol for one address.

## Tools added

| tool | purpose |
|---|---|
| `tools/sdkclass.py` | archive placement scan; `layout/sdk_class.json`; `--where` |
| `tools/migrate_src.py` | sort `src/matched`/`src/pending` into region/kind folders |
| `tools/deadcode_probe.py` | find code in a region reachable only indirectly |
| `tools/twl_probe.py` | the twl-specific form of the above |

## Tools updated

`tools/match.py` (`SRC_DIRS`, `MATCHED_KINDS`, selftest fixtures),
`tools/ovstats.py`, `tools/coveragemap.py`, `tools/worklist.py`,
`tools/datamap.py`, `tools/lane.py`, `tools/sdkobj.py`,
`tools/session/promote_fast.py`, `tools/session/pending_pct.py`,
`tools/session/remaining.py`.

## Docs updated

`README.md` (figures and the source-layout note), `docs/LANES.md`,
`docs/AGENT-BRIEF.md` (category rules and command examples).

## Coverage

| | before | after |
|---|---|---|
| overlay game | 481,416 / 1,903,430 (25.2920%) | 481,084 / 1,902,906 (25.2815%) |
| overlay SDK matched | 82,520 B / 745 fn | 82,852 B / 758 fn |
| overlay SDK total | 473,222 | 473,746 |
| arm9 game | 404,166 / 4,554 fn | 404,080 / 4,548 fn |
| combined game | 38.3768% | 38.3689% |
| twl map | 440 game / 39,012 SDK | 440 game / 39,012 SDK |

Net ~37.3 KB reclassified game -> SDK, dominated by the twl block.

## twl

disasm emits any byte it cannot reach from a seed as data, so code whose only
reference is indirect is absent from the twl denominator.  `twl_probe.py`
collects image pointers into the region and seeds the ones landing on neither
a label nor an SDK symbol.  Every seeded state was rejected: the largest
contributor was an arm9->twl data table with a `+0x10000` stride, traced as
Thumb and emitting Thumb-2 (`and.w`, invalid on ARM9); after dropping those,
the remainder still failed the assembler on invalid ARM (`strdeq r3,r4`, odd
first register to STRD).  No recovered function was confirmed, so the seeding
was reverted.  twl is 204 functions, 39,012 SDK bytes, 440 game bytes; the
game figure is a lower bound.  A validating pass (accept a seed only when its
traced function assembles and is self-consistent) is the way to land it.

## Catalog names

`layout/worklist.json` reports 132 `sdk_conflicts` (addresses where the SDK
catalog and a matched game entry disagree) and there are 16 real-name
disputes, e.g. `GXS_LoadBG0Scr` claimed at nine consecutive addresses whose
bodies are the `GX_LoadBG*Scr` family.  `layout/symbols_sdk.txt` is generated
by `tools/libmatch.py`, so corrections belong in `libmatch.py`'s name
selection (or a corrections table), followed by a re-scan.

## Verification

    manifest --check    clean (6,955 shards, no duplicates, no unread json)
    idioms --check      up to date (328)
    selftest --quick    239 cases, 0 failures
    build --split --pack 243 PASS, 0 FAIL; whole ARM9 image PASS
    ndsrom verify       byte-identical, sha1 26ad0b9967aa279c4a266ee69f52b9b2332399a5
    coveragemap         all three maps regenerated
