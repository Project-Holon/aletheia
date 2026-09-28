# Tree lane brief (2026-09-27)

Read docs/LANES.md (the lane brief: picking work, per candidate steps, write set) and
docs/AGENT-BRIEF.md once. Then read the idiom index in docs/MATCHING.md in full before
the first measurement: it is the ranked lever list, and most residues seen so far are
covered there. No em dashes, no emoji. Do not commit or push. Never edit tools/ or
layout/ (except the one tool your brief names). Work in a scratchpad subdirectory named
after your lane. If tools/match.py fails to parse, another lane is saving it: wait a
minute and retry.

## Strategy: one call tree, top down then bottom up

1. Take the root named in your brief (or the biggest open function in your territory).
   Confirm it is a real function: `lane.py` flags `phantom?`; also check the extent is
   not a pool or data run swallowed by a stale label. If it is not real, take the next.
2. Walk its callees (`match.py show`, every bl/blx and pool-word code pointer). A callee
   already covered by a shard, in ARM9, or in the SDK tables is a witness already: do
   not descend. Descend into open callees recursively until you reach open leaves.
   Write the tree down in your scratch dir before matching anything.
3. Match bottom up: leaves first, then their callers, up to the root. File every
   function the moment it verifies (EXACT/EXACT* to src/matched plus
   `match.py manifest --verify --shard <pkt>` twice, second pass rewrites nothing;
   MATCH to src/pending with the blocker named). Each closed callee becomes a
   `matched` witness for its caller.
4. Cap: about 40 open functions per tree. If the tree is bigger, finish the subtree you
   are in, file it, and report the rest as the next lane's list.
5. Method per function: apply idioms in index order; derive every parameter width and
   arity from the callee's own matched body, never the call site. For anything over
   about 300 bytes that stays more than a few bytes out after the obvious levers, write
   a fresh draft from the image rather than iterating (this closed __dec2num, musical,
   both palanm functions and 0x0206F4C8 after long lever stalls). Pins other than
   dsi/1.1p1 need a documented tell (docs/FRONTEND-PINS.md). Permuter
   (tools/permuter.py, relocation-guarded) at most once per function, after hand work.
6. Near misses that will not close: best source and every measurement in
   docs/notes/<pkt>.c.txt under a dated marker. One idiom file per new lever that
   closed something (format in docs/idioms/README.md; do not regenerate the index).

## Report

Under 300 words, to the integrator and to docs/sessions/2026-09-27/reports/<lane>.md:
the tree (root and how many functions), per function the verdict and what closed it,
files written, shards verified, the unfinished remainder as a list for the next lane,
seeds (unlabelled starts with a witness site), anything the integrator must do.

## Addendum after the first set

- Overlay GAME lanes: skip any root or callee that has a row in layout/symbols_sdk.txt
  (DWC, GameSpy, crypto, NHTTP and so on). Those belong to the overlay SDK lane, and two
  lanes writing the same file is a collision. SDK callees already attest through the
  `sdk` class; treat them as witnesses. `python tools/sdkobj.py --open --region ovNNN`
  lists open SDK rows if you need to check.
- `lane.py`'s biggest candidates are often phantoms (code-pointer tables or rodata under a
  stale label whose first word decodes as a push). Check before descending.
- tools/sdkobj.py exists: for any SDK callee it prints the vendor object with named
  relocations and DWARF prototypes, which gives exact callee arity and widths.

## Addendum 2 (2026-09-28): new source layout and scope

- The source tree is now partitioned by region and kind (docs/source-tree-rework.md):
  `src/matched/{arm9,arm9_sdk,itcm_sdk,ov,ov_sdk,twl,twl_sdk}` and the same under
  `src/pending/`. Overlay game files go in `ov/`, overlay SDK files in `ov_sdk/`. The folder
  is the classification: `python tools/sdkclass.py --where 0xADDR ovNNN` tells you which
  one an address belongs to. Follow docs/LANES.md for the exact paths.
- A separate session owns the ARM9 SDK (`arm9_sdk/`). Lanes of this session work
  overlays and overlay SDK only; do not write under arm9_sdk, and do not match ARM9 SDK
  rows even when they are callees (they attest through the `sdk` class).
- Uncommitted leftovers from a lane cut by the session limit may already be in the tree
  under the new folders: check `git status` for your territory first and salvage per
  docs/sessions/2026-09-27/relaunch_note.md.

## Addendum 3: naming standard (2026-09-28)

A function's identity is its address. Names follow one rule so every tool can resolve them:

- Game functions are named by their listing label, `func_XXXXXXXX`; no `ovNNN_` prefix, no `sub_` or `unit_` forms, inside the C and in the shard `name` field.
- SDK functions keep their vendor symbol name (from `tools/sdkobj.py` or `sdkclass.py --where`).
- Every overlay source file is named `ovNNN_<name>.c` (for example `src/matched/ov/ov135_func_021F7F9C.c`), because overlays sharing a window share addresses.
- The shard `kind` field matches the folder: `ov/` is game, `ov_sdk/` is sdk.
- An address counts only once it is a code label in its own overlay's listing. If the listing shows your function as `.word` data, seed it in `layout/function_starts.txt` with a witness comment and regenerate that listing before filing; report every seed.

The census of existing mismatches is `docs/sessions/2026-09-27/namecensus.tsv`; a dedicated lane fixes those, so do not rename committed files outside your own work.
