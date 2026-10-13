# Asm-to-C lane brief

Goal from the user: src/game must read like the developers' own source and
build the ROM. Some functions in src/game (and their src/matched copies) are
`asm` bodies: compiler output copied as instructions. The developers wrote
these in C. Your lane turns each listed function into C that compiles to the
same bytes (EXACT). Read docs/restructure/FINISH_BRIEF.md (rules, levers) and
docs/restructure/REGMM_BRIEF.md (levers that closed this week's near misses).

## Which functions
Your prompt lists files and functions with a triage verdict (COMPILED or
UNSURE) from instruction patterns only. Check each one first:
- Keep it as asm only if the original was plausibly hand-written: mrs/msr,
  mcr/mrc, swi, ldm/stm block loops, a known SDK asm routine, register use
  mwccarm never makes. Then add one line above it:
  `/* hand-written in the original: <reason> */` and move on.
- Otherwise write C. Tail-call thunks (`ldr ip,=f; bx ip`) and short leaf
  functions are C too: `T f(args) { [return] g(args); }`.

## How
1. Read the asm body and the neighbours in the same file (types, callers).
2. Grep docs/idioms for the shapes you see before compiling.
3. Write the C in the src/game unit file in place of the asm body, using the
   file's existing types. Prototypes follow definitions.
4. Check one function: `python tools/match.py tu --src F --addr A --region R
   --diff` (or `one`), then the file: `python tools/gameverify.py --file F`.
5. Put the same C into the function's src/matched file (replace the asm body,
   keep the header, status EXACT).
6. Do NOT run `match.py manifest` (shards are shared; the integrator runs it).

If a function will not close after a fair try (several stated hypotheses with
tools/mwccdbg evidence), leave the asm in place and report the exact
remaining difference. Do not leave a file broken: every file you touch must
verify EXACT at the end.


## The original was written by people
It is sometimes poorly optimised and does needless work: duplicated
variables, a value copied into a second local, a value recomputed or read
twice, two structs (or two names) for one object, dead stores, odd types.
Try such redundant forms before calling a function stuck. A form is a
stand-in only when no person would have a reason to write it (a cast or
statement whose only effect is to steer the compiler).

## Compiler build
If a function stays off across every C spelling, try the other compiler
builds first (`--cc ../2.0/sp2`, `--cc ../1.2/sp3`): NitroSystem and some
library objects were built with them (REGMM_BRIEF lever 6).

## Rules
Only touch the files your prompt names. No permuter, sweeps or brute force.
No function-pointer casts to hide arity. `volatile` only for hardware or
shared memory. Never open sdk/. No git stash/checkout/reset/mv; nothing
staged or committed. No em dashes or emoji. Scratch in the dir your prompt
names. Keep context under 150k: targeted reads; stop near 130k and report.

## Report
Per function: C / kept asm (reason) / not closed (bytes differing / size and
the remaining difference). Files touched. Guesses (names, types).
