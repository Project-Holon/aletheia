# White per-function tracking

Black keeps one record per matched function in `layout/matched/<region>/`. White builds from the
same `src/game` files, so it gets the same kind of record in a separate tree:
`layout/matched_white/<region>.json`, one file per region. A record holds names, addresses, sizes and a
status. It holds no game bytes.

Make or refresh the tree with `python tools/whitetrack.py` (`--summary` prints the figures only,
`--check` fails when the files are out of date). Run `python tools/whitelink.py` and
`python tools/gamelink.py arm9_main itcm --version white` first: the tool reads their output in
`build/gamelink/*_white`.

## Record

| Field | Meaning |
| --- | --- |
| `name`, `black_address` | The Black record. |
| `white_address` | The same function in White (`docs/restructure/white_diff.tsv`; `tools/white_map.py` for a function with no row). |
| `size` | Bytes of the White function. A secure-area SVC thunk is 4 bytes. |
| `diff` | `same`, `constant`, `shifted`, `differs` (real code change), `mapped` (no row in the diff table). |
| `source` | The `src/game` file with the function, found the way `tools/gamecheck.py` finds it: the address in a `func_` name, the name (renamed functions, SDK names, unit members), a header row, or the file that holds an alternate entry or inner label. Empty for a linker veneer. |
| `kind` | `linker veneer` on a veneer record (see below). |
| `version_switch` | The file uses `VERSION` or a named constant of `src/game/version.h`. |
| `status` | See below. |

## Status

| Status | Meaning |
| --- | --- |
| `EXACT` | The function's bytes in the White link of its region equal White's image at `white_address`. The link compiles the `src/game` file with the White define (`match.compile_tu`, `-d VERSION=2`, address literals remapped) and the White address map. |
| `STANDALONE`, `IMAGE` | The tool can still give these (a function with no `src/game` file, or one whose bytes lie in image data of the link). No record has them today. |
| `UNAVAILABLE` | A region with no White link. None today: the DSi block is linked by `tools/twllink.py --version=white` and compared with the decrypted White DSi image (modcrypt with the key from the environment). |
| `DIFF`, `NOT_LINKED`, `NO_TWIN` | Failures. The current tree has none. |

## Real code differences

The diff table marks 72 functions `differs`. All 72 are `EXACT`. 58 of
them live in files with a version switch (`PM_VERSION_ID`, `PM_VERSION_BIT`, `PM_VERSION_MASK`,
`PM_VERSION_LEGEND_SPECIES`, `MSG_PROFANITY_NOTICE`, or a local `#if VERSION == VERSION_WHITE`).
The other 14 are alignment artefacts of the diff table: the source is the same in both games and the
bytes move because a neighbour, a literal pool or an address constant moved. The same source
produces both images, which is the proof.

## Linker veneers

A veneer (an 8 or 16 byte jump stub the linker adds) has no source line. Its record is `EXACT` with
`kind: linker veneer` when the White image holds a veneer of the same form at the White address and
its target word is the White twin of the Black veneer's target. 76 records are veneers.

## Where the figures come from

Run `tools/whitelink.py`, `tools/gamelink.py arm9_main itcm --version white` and
`tools/twllink.py --version=white`, then `tools/whitetrack.py`. Current figures: 35,669 functions,
all `EXACT` (the DSi block included, its 341 functions), and `progress/report_white.json` is at 100%.

Per-function White tracking lives in `docs/WHITE_TRACKING.md`, `tools/whitetrack.py`,
`layout/matched_white/` and `progress/report_white.json`.

## Progress figures

`python tools/progress_report.py --version white` writes `progress/report_white.json` (the Black units
with White addresses and White verdicts). A function counts as matched when its record is `EXACT`. A unit is complete when its Black verdict is
complete and every function of it is matched in White.
