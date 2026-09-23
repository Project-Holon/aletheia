# Session helpers (2026-09-22 to 2026-09-23)

Copied from the orchestrator's scratchpad at the end of the run so the wave loop in
docs/HANDOFF.md section 2 can be repeated on another machine. They assume the repo root as the
working directory; edit the absolute scratchpad path at the top of foldin.sh and commitset.sh.

- foldin.sh: worklist refresh, pending re-verify (promote_fast.py --dry), reproduced figure
  (pending_pct.py), split build, ROM build with sha1, treemaps, and the sharded/unsharded split of
  untracked src/matched files.
- commitset.sh "<label>" <prev exact> <prev repro>: README figure, stage sharded sources and shards,
  docs and pending, commit with both figures and deltas, push. Refuses to run with empty figures.
- remaining.py: open functions per upper-half pseudo-family (pseudo_families.json), sizes, ISA, state.
- families.py: the same for anchored families (layout/file_anchors.txt).
- pseudo_families.py: regenerates pseudo_families.json from adjacency and shared callees/data.
- promote_fast.py / pending_pct.py: fresh 6-way verdicts of src/pending and the reproduced figure.
- pseudo_remaining.txt: the upper-half list at the end of wave 13.

On a fresh machine the listings under asm/ do not exist (gitignored): run
`python tools/disasm.py arm9 --split` and `python tools/disasm.py overlay --all`
from the repo root before any helper here works. The helpers locate the repo
from their own path; no hardcoded checkout path.

Portable fold-in and commit (Windows, macOS, Linux): `python tools/session/wave.py foldin`
then `python tools/session/wave.py commit "<label>" <prev_exact> <prev_repro>`; same steps as
foldin.sh and commitset.sh, repo-relative, no scratchpad.
