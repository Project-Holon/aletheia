# Wave 17 standing brief (near-miss lanes)

Repo: this repository (aletheia). Windows; run python through Bash. `python tools/env.py` resolves
the toolchain. Read docs/AGENT-BRIEF.md once (the manual), then docs/MATCHING.md's idiom index and
docs/FRONTEND-PINS.md's last twenty rows. Never edit layout/, tools/, asm/, or another lane's files.
Do not commit or push. Foreground commands only. Keep your context small: read only the notes,
family header and listing extract for the function you are on.

Every function in your scope is a documented near miss: byte-correct in shape, a few bytes out
because the compiler chose a different register or instruction order. Each has a docs/notes file
(`docs/notes/<pkt or name>.c.txt`) with the best source under a best-source marker and a list of
levers already tried. Read that list first and do not repeat it.

Procedure per function:
1. `python tools/match.py show --addr A` and the note. Write down what the image does that the best
   source does not (which value lives in which register, which store comes first).
2. Form a hypothesis about the source spelling that would make 1.1p1 -O4,p do the same. Levers that
   closed functions in waves 14 to 16, in yield order: `const` on read-only pointer parameters and
   read-only extern tables; callee arity and parameter widths read from the callee's own body (never
   from the call site); a call written out in both arms of a branch; SDK enum parameter types passed
   into SDK inlines; enum-typed locals; declaration order and function-scope vs block-scope; compound
   assignment; narrow (u16/s16) parameters; a dead stack parameter reused for a local's address;
   initialised local arrays; identify the library shape first (NNS G2D/G3D, MSL, fdlibm) and then try
   the ../2.0/sp2 pin only when a documented tell is present (kept branches, kept constants, pool
   reloads at every call).
3. Measure each hypothesis once with `match.py one`. Record every measurement in the note (bytes out,
   what changed). Stop on a function after your untried levers are exhausted or after 12 measurements;
   the permuter (tools/permuter.py) is allowed once per function, at most 800 compiles, only after the
   hand levers.
4. On EXACT or EXACT*: file in src/matched with the exact verdict in the header, then
   `python tools/match.py manifest --verify --shard <pkt>` twice (the second pass must rewrite nothing).
   On MATCH: file in src/pending with the blocking class named. Otherwise leave the improved best
   source in the note under a new dated best-source marker.
5. A new lever that closed something gets one idiom file in docs/idioms/ (format in
   docs/idioms/README.md); do not regenerate the index.

Report (under 300 words) to the integrator: per address, before -> after bytes out, verdict, what
moved it; files written; shards verified; seeds (unlabelled starts you noticed, with the witness
site); anything an integrator must do. Write the same report to
docs/sessions/2026-09-23/reports/wave17_<lane>.md.
