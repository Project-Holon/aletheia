# Lane brief

The canonical operating brief for a decompilation lane (a packet agent working
a contiguous run of open functions, or a size band of an overlay). Read
`docs/AGENT-BRIEF.md` for the matching rules and evidence classes; this file is
the short version you get handed with a lane, plus the shared tooling.

## Picking work

Use the one enumerator, never a hand-rolled one:

```
python tools/lane.py --band 128 256 --overlays 0 47      # a size band of overlays
python tools/lane.py --band 0 16 --regions ov021 ov022   # named overlays
```

It reads coverage from every shard, including the nested `functions` of a
`game_unit` entry and the non-`pkt_*.json` shards (the twl region), and skips
addresses already in `src/pending`. It flags `phantom?` on a long extent whose
body has no branch and no `[pc` load: that is a stale `func_` label on a pool
run, not a function, and no C will match it.

For arm9 work, `python tools/worklist.py --targets` ranks open functions by
attestation-weighted fan-in.

## Per candidate

1. `python tools/match.py show --addr 0xADDR --region <ovNNN>` (overlay windows
   overlap, so the region token is essential; it also resolves the ISA).
2. Write C under `src/pending/<category>/` (or `src/matched/<category>/` if
   EXACT) with the house header: function, address, packet, region, compiler,
   flags, isa, status.  **The category is derived, never chosen**: `arm9`,
   `arm9_sdk`, `itcm_sdk`, `ov`, `ov_sdk`, `twl`, `twl_sdk`, picked from the
   header's `region:` plus membership in the tool/sdkclass.py union (run
   `python tools/lane.py` to see where a file belongs).  A source in the wrong
   folder is a classification bug, not a preference.
   **The header `status:` must be the verdict `match.py` actually gave you.**
   Never write `EXACT` on a file that is not EXACT.
3. Verify:
   `python tools/match.py one --src <f> --func <f> --addr 0xADDR --cc dsi/1.1p1 --<arm|thumb> --region <ovNNN> --flags=-O4,p`
   (`tu` for a contiguous EXACT run; `--diff` on DIFF).
4. EXACT/EXACT*: `git mv -k` into `src/matched/<category>/`, set `status:`, then
   `python tools/match.py manifest --verify --shard <pkt>`.
   Name the packet `pkt_<ADDR>`; when an address is claimed by another
   overlapping overlay use `pkt_<ovNNN>_<ADDR>` and `ovNNN_func_<ADDR>.c` so
   two regions never write the same file or shard.
5. MATCH (byte-correct, one relocation wildcarded): run `--suggest-split`; if a
   matchable target unblocks it, match that first. Otherwise leave it in
   `src/pending/<category>` with `status: MATCH` and the blocker named.
6. DIFF: fix the C. Consult `docs/idioms/README.md` when the diff shape matches
   a summary; check `docs/notes/*.c.txt`.

## Write set

Only: `src/pending/<category>/*.c` and `src/matched/<category>/*.c` for your
lane's addresses; their
`layout/matched/<region>/` shards; NEW `docs/idioms/<slug>.md`;
`docs/notes/*.c.txt`. Never touch `tools/`, `docs/MATCHING.md`,
`docs/PARALLEL.md`, `layout/worklist.json`, `layout/function_starts.txt`,
anything under `asm/`, or another lane's files. Never run `manifest` over files
outside your lane (it rewrites shards). No `git add`/`commit`/`push`.

## Before handing back

`python tools/match.py manifest --verify --shard <your pkt>` and
`python tools/match.py manifest --check` (no duplicate entries, no unread
shard). Report: table of (file, address, verdict), totals, and any new idiom.
