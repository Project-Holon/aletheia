# Overlay merge lane: standard instructions

Read MERGE_LANE.md in this folder first (brief plus the lessons at the end) and follow it.

Your TU list is mlo/ov_laneNNN.txt (NNN = your lane number), one line per TU as
"<region> <tu>": parts src/game/<region>/<tu>_pNN.c, folder src/game/<region>/<tu>/.
Use --region <region> in every check.

Tools
- Use the CURRENT tools/restructure.py merge(): it has all parser fixes (comments
  with # or ', struct-pointer last parameters, same-line items, #define placement,
  comment-free own prototypes). Older scratch copies (rs16.py and others) still have
  those bugs; if you reuse a driver, point it at tools/restructure.py.
- Greedy drivers: scratchpad/ol006/ (go.py region-aware greedy and apply, dg.py merge
  diagnostic, vf.py verify), scratchpad/ol007/ (bnd.py per-boundary verdicts, err.sh
  compile errors with source lines), scratchpad/ol005/ (pd5.py/td5.py prototype and
  struct diffs), scratchpad/ol003/un3.py (struct unifier by offset, verifies, reverts).
- Copy what you use into scratchpad/olNNN/ and give every temp file a name unique to
  you (include olNNN). Other lanes work in the same region folders.

Method that works best
1. Greedy pass over each TU.
2. For the blockers: build ONE canonical struct block per object from all members'
   views (offsets checked against every view; see scratchpad/ol006/normsl.py,
   normsb.py), apply it to every part, give each function one prototype (its
   definition's), then greedy again.
3. Rewrite stand-in or goto-style functions (int a0.. parameters, machine one-liners)
   into typed plain C when they stay byte-exact.

Rules
- Only write your own TUs' files. Re-verify all your files before reporting.
- A folder member moved up into the region folder must get ../../matched/ includes.
- Run python tools/gamecheck.py --region <region> and fix doubled or missing
  functions inside your TUs.
- A gap no function covers (often a 12-byte linker veneer) is a file boundary.
- Never merge across a change of compiler or flags. One copy of duplicate static
  inline helpers. No function-pointer casts to paper over two prototypes.
- Keep MERGE.md up to date while blockers remain.
- One compile at a time (low RAM). Stop deep work when context nears 130k.
- Nothing staged or committed. No em dashes, no emoji.

Report: per TU files before and after, what you fixed, what is left and why.

Extra lessons (from later lanes)
- A false "c99=DIFF" often comes from stale symbol-header rows: two members list one
  static name at different addresses. tools/restructure.py now prefers the member that
  defines the name; scratchpad/ol013/g13.py drops such rows before merging.
- Never leave a background job running when you hand back: finish and verify first.
- Readability first: when a global is viewed two ways, unify toward the real struct
  (named fields), never toward u8 * with offset arithmetic. If the struct view cannot
  be byte-exact, leave the boundary and note it in MERGE.md.
- Do not delete a TU folder's MERGE.md while blockers remain; it is the work list.
- Best driver so far: scratchpad/ol020/go20.py with hzlib20.py (greedy merge plus a
  harmonizer: casts call arguments to the merged prototype, fixes void-versus-value
  returns, keeps only verified merges). Start with it.
- A few bytes of code that no function covers (a lone bx lr) between parts: list the
  address in MERGE.md under "unmatched code"; it is a file boundary for now.
- The repo is inside OneDrive: retry a write that fails on a sync lock, re-verify.
- Use scratchpad/ol024/hzlib20.py instead of ol020/hzlib20.py: the ol020 copy treats
  `return f(a, b);` as a declaration and never casts those call arguments.
- A function defined with N parameters but called with fewer elsewhere in the TU: an
  old-style (K&R) definition is acceptable only if it stays byte-exact; otherwise leave
  the boundary and list it in MERGE.md.
- Block-scope function declarations inside bodies hide prototype conflicts: hoist them
  to file level first (scratchpad/ol027/hoist27.py). scratchpad/ol027/mm27.py finds the
  function where a merged build first differs; dd27.sh shows the differing rows.
- The greedy driver deletes the TU folder with its MERGE.md: recreate MERGE.md for every
  TU still split, and renumber parts without gaps (p01, p02, ...; header file: line too).
- Run each driver only once at a time; one lane ran its batch twice and the runs collided.
- A false "ISA conflict": a symbol row with trailing prose, or a comment line shaped like
  a symbol row, ends the header's symbols: block early. Reword the comment line.
- The merge tool's automatic renaming of same-named local structs can change code size;
  rename them uniquely by hand when a merge gives an unexplained DIFF.
- Callers pass more arguments than the definition takes: add unused trailing parameters
  to the definition if it stays EXACT (lane 028).
- Hidden setters close most uncovered-code gaps in ov093/ov094: the 12-byte block
  `movs r1,#N; str r1,[r0]; ldr r0,[pc]; bx lr` + pool word is
  `int *func_X(int *p) { *p = N; return d_Y; }` with `extern int d_Y[];` and a
  `d_Y data ovNNN a4` symbols row. Lane 034 injected 86 with scratchpad/ol034/inject34.py
  (standing approval for seeding hidden functions). Write other small uncovered leaves the
  same way when they verify; check scratchpad/gapmatch/<region>/ for ready EXACT drafts
  first. List every hidden function you add in your report.
- scratchpad/ol036/canon36.py is a template for one canonical struct from many views (closed 46 groups in btlv_effvm).
- scratchpad/ol041/unif41.py: one struct per base name from all views by offset (run once per TU only).
- tools/restructure.py now reads header symbol rows with any indent (one-space rows were
  dropped before and gave false ISA conflicts). Multi-declarator externs
  (`extern void a(..), b(..);`) are still not read as prototypes: split them first
  (scratchpad/ol039/split39.py). go-drivers leave ../../../matched/ includes in files moved
  up: fix them to ../../matched/.
- scratchpad/ol040/ac40.py casts pointer arguments on 'illegal implicit conversion' lines to the canonical prototype; ren40.py renames duplicated generic typedefs (Work, Info, Args) per part before merging. Lane 040 closed 7 of 8 TUs with them.
- A merged function that grows 2-4 bytes is usually a new narrowing: a u32 local or parameter now passed to a callee whose prototype (seen in the merged file) takes u16/u8. Fix the local or parameter type, not the prototype (r2_04 closed three TUs this way). A stand-in like a + b*10 hides a struct array: write it as pointer arithmetic on a typed row struct.
- pair40.py writes its merge file even when the merge fails: install only on EXACT/MATCH (scratchpad/u01/ti.sh). tools/restructure.py mishandles K&R definitions with multi-line bodies (eats the next prototype): prefer an unused trailing parameter or an unprototyped extern over a K&R definition.
- Round 3 (2026-10-08): when a TU ends as ONE file, name it <tu>.c (not <tu>_p01.c),
  set the header `file:` line, and delete the TU folder with its MERGE.md. Lanes r2_17,
  r2_20 and r2_23 did this. tools/gamepromote.py does it too.
- Do not rename clashing generic typedefs per part (Work_vC8CC, Work_vCFD8) as the final
  answer: that is readability debt. Build one canonical struct by offset (canon36.py,
  r209/canon195.py). Use per-part renames only as a temporary step, and say so.
- A return type you invent so the bytes fit (for example making an extern return
  unsigned int) must be listed in the report as a guess.
- Re-run tools/match.py by hand on every final file before reporting, and set each
  header `status:` to that verdict.
- Wide caller, narrow callee (r3 lanes closed about 10 TUs this way): first try making
  the CALLER's own parameter or local narrow (u16 heap, short delta, u8 index). Then no
  narrowing is emitted at the call and one prototype serves both parts.
- Many "unmatched code" gaps are plain C: 12-byte stubs `ldr r3; movs r1,#k; bx r3`
  are `return g(a, k);`, empty leaves are `void f(void) {}`. Write them, verify, inject.
- Round 4: many remaining boundaries are already proven real (compiler/flags change,
  veneer, ARM/Thumb). If MERGE.md says so, confirm from the headers and move on: no
  compiles spent on them. Spend the budget on struct unification (one canonical struct
  per object, named fields, by offset) and on writing uncovered code as hidden functions.
- The greedy drivers keep the old header status: after any merge, re-run match.py and set
  `status:` to the real verdict. A prose line in the header shaped like a symbol row
  ends the symbols block and turns EXACT into MATCH: reword it.
- Task callbacks written as raw addresses ((void *)0x02014489): use the function name
  (func_02014488) when it stays EXACT.
- Big uncovered gaps between parts (hundreds of bytes, one push/pop) are unmatched
  functions, not boundaries: report the address range so it can be matched.
- Callee defined later with u8/u16 parameters, called earlier without narrowing: the original had NO declaration in view (implicit call). If the file's lang allows implicit declarations, try deleting every declaration of that function before the call (the merge tool hoists one: remove it by hand after merging). An unprototyped extern followed by a prototyped narrow definition is rejected by mwcc.
