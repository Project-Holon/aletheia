Not MATCH-capped. All 12 files here are byte-exact (EXACT or EXACT*)
hand-written-assembly reproductions of the mwccarm/MSL runtime.a rows in
layout/runtime_arm9.txt (34 rows, ~10948 bytes total, verified individually
with `python tools/match.py one --func <name> --addr <addr> --cc 1.1p1
--arm`). They are parked here for a different reason than the rest of
src/pending/ (see its own README): not a relocation-witness gap, but a
tools/worklist.py classifier gap.

Filing any of these as a manifest entry (kind must be "game" or
"game_unit"; MATCHED_KINDS has no third option for hand-written runtime
library code) makes tools/worklist.py's classifier compute proven_game =
True at these addresses, which short-circuits the `elif addr in runtime`
branch and reclassifies the row "matched" instead of "runtime" -- i.e. it
leaks into the game coverage figure. See docs/sessions/2026-09-27/reports/
runtime_asm_2.md for the full analysis.

Do NOT run these through the normal src/pending graduation path (they will
already show EXACT on a re-verify, which is not the graduation signal
here). They should move to src/matched/ only after the integrator either
adds a manifest kind for hand-written runtime library code, or changes
tools/worklist.py's classifier to treat a layout/runtime_arm9.txt address
as "runtime" regardless of manifest kind.
