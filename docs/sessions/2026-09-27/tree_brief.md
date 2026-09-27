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
