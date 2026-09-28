# Overlay SDK lanes, 2026-09-28

Eight lanes match the open overlay SDK rows, by library and by size band. Read
`docs/LANES.md` and `docs/sessions/2026-09-28/arm9sdk_brief.md` first; everything in the
ARM9 brief applies here (hard rules, status copied from the verify output, the asm rule),
with the overlay differences below.

## Scope

- Overlay SDK rows only. Another developer owns overlay game code: never write, move or
  rename anything under `src/*/ov/`, and never match a game row, even as a callee.
- Your rows: `python tools/sdkobj.py --open --region ovNNN --limit 5000` for each overlay
  (ov009, ov013, ov014, ov015, ov016, ov024, ov048, ov095, ov107, ov114, ov172, ov175),
  filtered to your libraries and to the current size band. Smallest rows first, one
  vendor object at a time.
- Bands: pass 1 is rows under 256 bytes; pass 2 is 256 to 1023; pass 3 is 1024 and up.
  Do not start a larger band in the same pass.

## Files

- Source: `src/matched/ov_sdk/ovNNN_func_XXXXXXXX.c` (pending: `src/pending/ov_sdk/`).
  The C function is `func_XXXXXXXX` unless the vendor name is needed; the file name
  always carries the overlay prefix (docs/sessions/2026-09-27/tree_brief.md addendum 3).
- Shard: `layout/matched/ovNNN/pkt_ovNNN_XXXXXXXX.json` via
  `python tools/match.py manifest --verify --force --shard ovNNN/pkt_ovNNN_XXXXXXXX`.
  Always `--force`. The header `packet:` must name that shard.
- Overlays share address windows: give every callee in another overlay a region hint on
  its `symbols:` line, and every callee in the same overlay its own `ovNNN` token.
- Existing pending drafts in your territory were written from objects by earlier lanes of
  this project and may be continued.

## Evidence

A reference attests only through the existing classes (matched, label, literal, string,
sole-ref, runtime, sdk, linker, template). An SDK callee attests as `sdk` only if its
catalog row exists; a removed false-positive row is not evidence. If a callee cannot be
attested honestly, the function stays MATCH in pending; report it, do not invent.

## Report

`docs/sessions/2026-09-28/reports/<lane>.md`: per function region, address, verdict,
bytes; the exact file and shard list; near misses with residue; name disagreements; asm
bodies with their evidence line; what the next pass should take. Keep under about 150k
context; stop and report when you pass it.
