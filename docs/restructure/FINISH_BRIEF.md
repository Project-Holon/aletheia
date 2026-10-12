# Finish lane brief (last restructure and matching work)

Repo: <home>/OneDrive/Documents/aletheia. Goal: every src/game
function EXACT, every TU one file where the original was one file, before the
structural cleanup goes on. Read docs/restructure/REPORT.md (levers, state)
and your TU's MERGE.md first.

## Levers that closed TUs and functions
1. Linker veneers come from the image (match.py); never write them as asm;
   calls name the real target. Tail-call stubs (8-byte Thumb, 12-byte ARM)
   are code: `T f(args) { [return] g(args); }`.
2. Hidden functions in gaps: write them as typed C.
3. One struct per object by offset; shared headers per region.
4. Wide caller, narrow callee: change the CALLER's own variable type (u8,
   u16) so no narrowing is emitted; prototypes follow definitions.
5. Callers pass more args than the definition takes: unused trailing
   parameter or an unprototyped extern; never a function-pointer cast.
6. ARM and Thumb in one file: `#pragma thumb off/on` around the other ISA's
   functions and their declarations.
7. Compiler/settings boundaries are often not real: retag test once.
8. Struct size and const change alias analysis (a large const table moves
   scheduling): try the real storage class and size.
9. tools/mwccdbg (regalloc replay fixed 2026-10-12, scheduler, alias, CSE):
   find the IR fact that differs, then the human C that produces it. Each
   try tests a stated hypothesis.

## Tools
- Merge parts: `python tools/tumerge.py REGION TU [--pair I J] [--apply]`.
- Verify one file: `python tools/gameverify.py --file F`; per function:
  `python tools/match.py one ...` / `tu --src F --addr A --region R --diff`.
- Header symbols: `python tools/gamesyms.py --file F --apply`.
- Presence: `python tools/gamecheck.py --region R` (0 missing, 0 doubled).
- Filing a newly matched or hidden function: label in
  layout/function_starts.txt if missing, a src/matched file, a shard via the
  match.py manifest commands, `manifest --verify --force` twice,
  `manifest --check` clean.

## Rules
Only touch your own files. No permuter, brute force or sweeps. `volatile`
only for hardware or shared memory. No function-pointer casts to hide arity.
Never open files under sdk/. Never commit or write game data (ROM bytes) into
a source file; generated data goes under build/ (gitignored). No git
stash/checkout/reset/mv; nothing staged or committed. No em dashes or emoji.
Scratch in the dir your prompt names; temp files in src/game start with `_`
and carry your lane name. Keep context under 150k; stop near 130k and report.

## Report
Parts before -> after, functions matched, what closed it, the exact blocker
for anything left, stand-ins left (file, function, why), guesses.
