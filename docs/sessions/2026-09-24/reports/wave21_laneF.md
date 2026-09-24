# Wave 21, lane F: 0x0201DB20 and 0x0209128C

Both stay DIFF under dsi/1.1p1 -O4,p. No source filed and no shard written. Every figure
below comes from `tools/match.py one` (or the permuter, which scores through
`match.run_one`).

## 0x0201DB20 (printsys, character-map search): DIFF 15, 154/156

- I measured 38 new hand spellings from the wave 15 source. None goes below 15:
  - switch versus if-chain
  - a result local
  - method and begin locals
  - goto loops
  - m as a dead parameter
  - inline Search and Scan helpers
  - mapInfo declared three ways
  - joined chain-step webs
  - the dying-local lever: pNext or the offset computed in hi or lo
- Diagnostics show that m is coloured after lo and hi under every spelling, including when
  its webs are joined and when it is a parameter. hi and lo follow declaration order between
  themselves. The image colours m, lo, hi.
- Permuter: earlier runs chased the 156-byte listing extent. A scratch wrapper, which does
  not edit tools/, pinned the extent at 154. With that in place:
  - anneal 1000 `--types`: best 154/15
  - hill `--types` (204 single mutations): best 154/15
  - anneal 1500 from the lo-first (18) source: best 154/15
- Best bytes-out: 15. The wave 15 source is unchanged.

## 0x0209128C: DIFF 1 under 1.1p1

- I measured 12 new 1.1p1 spellings: a volatile global, pointer and function-pointer
  parameters, a local pointer to the global, an array global, `v & 1`, an inline setter
  through a pointer, a do/while macro, a short parameter and an explicit return.
- 11 of them give 28/1. The function-pointer form gives 32/22. Every one emits a plain
  `mov r1, #1`.
- Per the standing ruling, I made no front-end argument.

## Compiles

About 52 hand compiles plus about 2700 permuter compiles. The permuter is batched and ran for
about 4 minutes in total.

## Files touched

- docs/notes/sub_0201DB20.c.txt: a dated section appended
- docs/notes/func_0209128C.c.txt: a dated section appended
- this report

Scratch files are in /tmp/aletheia_laneF.
