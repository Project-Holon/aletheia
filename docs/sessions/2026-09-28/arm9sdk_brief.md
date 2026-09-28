# ARM9 SDK lanes, 2026-09-28

Ten lanes finish the ARM9 SDK. Read `docs/LANES.md` first; this brief overrides it where
they differ.

## Hard rules

- Do not open, read, grep or copy any `.c` or `.h` file under `sdk/`. Work only from the
  vendor objects through `python tools/sdkobj.py` (DWARF prototypes, locals, relocations,
  line table), `python tools/match.py show`, and the idiom index (`python tools/match.py
  idioms`, `docs/MATCHING.md`). DWARF file:line metadata may be cited; source text may not.
- Do not salvage, read or extend existing files under `src/pending/arm9_sdk/`: write your
  own draft from the object. If a pending file exists at your address, overwrite it only
  with your own work from the object, and say so in the report.
- ARM9 only, SDK rows only, your territory only. Never write game code, overlays or
  another lane's library.
- No `git add`, `git commit`, `git push`, `git stash`, `git reset`. Do not edit `tools/`,
  `docs/MATCHING.md` or any shard but your own.
- Scratch goes in `scratchpad/<lane>/` (gitignored) or the system temp dir.
- Keep under about 150k context: targeted reads, no whole listings. When you pass the
  budget, stop and report; the next pass continues from your report.

## Territory

Your open rows: `python tools/sdkobj.py --open --region arm9 --limit 2000`, filtered to
your libraries and objects. Work each object together, smallest functions first, so the
object's types are learned once.

## Method

1. `python tools/sdkobj.py 0xADDR --region arm9` for the prototype, locals (listed in
   reverse declaration order), named relocations and the object's `.comment` stamp.
   Stamp 4.0.0.1024 is `dsi/1.1p1`; check each object, do not assume.
2. `python tools/match.py show --addr 0xADDR --region arm9` for the ISA and extent.
3. Write C. Flags `-O4,p`, lang `c99` unless the object says otherwise.
4. Verify:

       python tools/match.py one --src <file> --func func_XXXXXXXX --addr 0xXXXXXXXX \
           --cc 1.1p1 --<arm|thumb> --region arm9 --flags=-O4,p

5. EXACT or EXACT*: file under `src/matched/arm9_sdk/func_XXXXXXXX.c`, then
   `python tools/match.py manifest --verify --shard arm9/pkt_XXXXXXXX` twice; the second
   pass must rewrite 0. Anything else goes to `src/pending/arm9_sdk/` with a notes line.

## Status is copied, never written

The header `status:` is copied from the `manifest --verify` output for that function, not
from `match.py one`, memory or intent. A file under `src/matched/` must have a shard entry
that verifies EXACT or EXACT*. The integrator re-verifies every shard you list; any
mismatch between your report and the shard sends the file back to pending.

## asm bodies

Write C first. An `asm` body is allowed only when both hold:

- the function needs an instruction with no C spelling under this compiler (`mrs`/`msr`
  on CPSR/SPSR, `mcr`/`mrc`, `swi`, a fixed-register `ldm`/`stm` block copy, no-prologue
  code using r12 or the stack outside the ABI, crt0-style code that runs before C), or
  the object shows the function was hand-written (its DWARF subprogram has no
  `DW_TAG_variable` children and no line-table spread consistent with compiled code, or
  it lives in an asm-only object such as gxasm.o);
- the header records which instruction or which object evidence forces it, one line.

An asm body without that line is not EXACT for this project; leave it in pending.

## Header

    /*
     * function: func_XXXXXXXX
     * address:  0xXXXXXXXX
     * packet:   pkt_XXXXXXXX
     * region:   arm9
     * compiler: 1.1p1
     * flags:    -O4,p
     * lang:     c99
     * isa:      arm
     * status:   <copied from manifest --verify>
     *
     * sdk:      <symbol> (<object>)
     *
     * symbols:
     *   ...
     */

## Report

`docs/sessions/2026-09-28/reports/<lane>.md`: per function address, verdict, bytes; the
exact list of files and shards written; near misses with the residue; catalog or DWARF
name disagreements; asm bodies with their evidence line; what the next pass should take.
