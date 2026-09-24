# permuter.py: relocation and truncation ranking guard

Bug (reported by wave20_musical_4, wave19_swaps_long, wave19_bgwinfrm_anime): Score.key()
ranked a candidate above the baseline whenever it had fewer unresolved relocation sites
than the baseline (even when the drop came from merging two pool literals into one, not
from resolving one for real), and whenever it happened to land in a better RANK tier
(EXACT/MATCH/DIFF/SIZE) despite being far more truncated than the baseline.

Fix: Score now carries `nsites` (total relocation sites on the compile, not just the
unresolved ones). Score.key() reads three new class-level baseline anchors
(BASE_RESOLVED, BASE_NSITES, BASE_SIZEDIFF), set once per run from the regenerated
baseline's own Score by `set_reloc_guard_baseline()` (called from both `search()` and
`search_hill()` right after the baseline compile):

- `reloc_pen`: 10**6 per relocation site resolved fewer than the baseline, plus 10**6 per
  site-count mismatch against the baseline (catches the merged-literal case, where the
  image itself has two literals and a lower site count is never legitimate).
- `size_pen`: 10**5 per byte that a candidate's `|size - tsize|` exceeds the baseline's own
  `|size - tsize|` by.

Both penalties are prepended to the sort key (before RANK), so a violator sorts strictly
worse than the baseline regardless of RANK tier or bytes-out; a compliant candidate (the
baseline included) gets 0/0 and is ranked exactly as before. `--no-reloc-guard` sets
Score.GUARD = False and restores the pre-fix ranking unconditionally.

## Testing

Unit-level (isolated Score construction, no compiler):
- Baseline DIFF, 2 resolved relocation sites; candidate that merges them into 1 (same
  bytes-out win): guard pushes it to key `(2000000, 0, ...)`, strictly worse than the
  baseline's `(0, 0, ...)`. Without the guard it outranks the baseline as before.
- Baseline SIZE status 4 bytes short of the target extent; candidate MATCH status but 28
  bytes short: guard pushes it to `(0, 2400000, 1, ...)`, worse than the baseline's
  `(0, 0, 3, ...)`. Without the guard the candidate's lower RANK (1 < 3) let it outrank the
  baseline despite being far more truncated, reproducing the wave19_bgwinfrm_anime report.

Integration: ran the permuter (mode anneal, --types, --thumb) on the wave-20 musical_4
best source for func_0200CA98 (extracted from docs/notes/pkt_0200CA98.c.txt, 392/392
target, 89 concrete bytes out baseline) at budget 300 seed 9001 and budget 2000 seed 3801
(the seed the wave-20 note used for its "rejected" anneal run). In both runs every
accepted candidate's key stayed pinned at the baseline; `cur`/`best` never regressed
below the baseline's resolved-relocation count or size match over the full budget.

No existing self-check script was found in the repo for this tool (tools/permuter.py has
no `--selftest`/test harness); testing was done via the unit-level Score checks above plus
the live anneal runs.
