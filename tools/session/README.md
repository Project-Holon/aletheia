# Session helpers

The wave loop of docs/HANDOFF.md section 2, as plain Python (stdlib only). Every helper locates
the repo from its own path, so it runs from any working directory, and each one can also be
imported (`main()` is only called under `__main__`). Toolchains, the interpreter and the scratch
directory come from `tools/env.py`; nothing here is specific to Windows, macOS or Linux.

## Usage (Windows, macOS, Linux)

```
python tools/session/wave.py foldin
python tools/session/wave.py commit "<label>" <prev_exact> <prev_repro>
python tools/session/promote_fast.py [--dry]
python tools/session/pending_pct.py
python tools/session/remaining.py
python tools/session/families.py [out.txt]
python tools/session/pseudo_families.py
```

Use whatever name starts Python 3 on the machine (`python`, `python3` or `py -3`); the helpers
start their child tools with the same interpreter.

- wave.py foldin: worklist refresh, pending re-verify (promote_fast.py --dry), exact and
  reproduced figures (pending_pct.py), split build and pack, ROM build with its sha1 line,
  coverage maps, then the INCLUDE (sharded) and HOLD (unsharded) lists of untracked
  src/matched files and any untracked layout files.
- wave.py commit: README figure, stages README, shards, docs, pending and the sharded untracked
  sources, commits with both figures and their deltas, pushes. Refuses to run when the figures
  cannot be read. Note that it stages with `git add -u`, so any tracked file modified in the
  working tree at that moment goes into the commit.
- promote_fast.py: fresh 6-way verdicts of src/pending; without --dry, moves EXACT files to
  src/matched and re-verifies the touched shards.
- pending_pct.py: exact and reproduced coverage, counting only pending files with a fresh verdict.
- remaining.py: open functions per upper-half pseudo-family (pseudo_families.json).
- families.py: the same for anchored families (layout/file_anchors.txt).
- pseudo_families.py: regenerates pseudo_families.json here (the text table goes to the scratch
  directory; OUT_JSON / OUT_TXT override both).
- pseudo_remaining.txt: the upper-half list at the end of wave 13.

promote_fast.py writes `pending_verdicts.json` to the scratch directory and pending_pct.py reads
it from there: `ALETHEIA_SCRATCH` if set, else `<system temp>/aletheia`. `python tools/env.py`
prints the resolved path.

On a fresh checkout the listings under asm/ do not exist (gitignored): run
`python tools/disasm.py arm9 --split` and `python tools/disasm.py overlay --all` once from the
repo root before any helper here works.

Optional DSi step (region `twl`, the DSi-mode block of arm9i.bin): arm9i is
modcrypted, so its listing needs the DSi AES key-scrambler constant as a
16-byte file the user supplies and keeps outside the repo (a DSi ARM9 BIOS
dump does not contain it). Set `ALETHEIA_DSI_KEY` to its path (or pass
`--dsi-key`) and run `python tools/delink.py`, then
`python tools/disasm.py twl`. The file is never committed (`*.key` and
BIOS-like names are gitignored). Without it the region is skipped and
everything else is unchanged.
