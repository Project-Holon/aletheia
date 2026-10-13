# Cleanup lane brief (src/game, structural pass)

Goal from the user: the src/game files must read like the source the
developers wrote and build the ROM. Byte-exactness is already reached; this
pass removes what the developers did not write, without changing a byte.

Repo: the repository root. Your lane prompt names your
files (a region, or a file range in a region). Read first: this brief,
`docs/restructure/STANDINS.md` (census by kind), and the top of
`docs/restructure/REPORT.md` (levers).

## What to fix, in this order
1. **Per-function struct copies.** Typedefs and structs named after an
   address (`Obj_0204C83C`, `S_021B8460`, `Q_06899E48`, `ObjNNNNN` includes
   from src/matched/include) that describe the same object. Build one struct
   per object by offset from all its views in your files, give it a plain
   name, put it in a shared header for your region when more than one file
   uses it (`src/game/<region>/<name>_types.h`; reuse an existing header if
   one already describes the object), and rewrite every access. Use a script
   for the bulk rewrite (map each view field to the canonical field by
   offset), not hand edits. Named unions where views really overlap.
   Renaming copies (Obj_X -> FooObj17) without merging them is not progress:
   the target is a handful of structs per file, as a developer would have.
   Evidence that views are one object: the same pointer flows between them
   (call, callback registration, a field that points to it), OR, inside one
   file, they are views of the same parameter role (the work/task pointer
   of that file's functions) and their layouts are compatible (no offset with
   two different sizes or kinds). Merge compatible views into the largest
   layout; keep two structs only where offsets really conflict.
   The original was written by people and is sometimes redundant: two
   names or two struct views for one object can be real (twl 027073AC and
   02705E04 need two symbols at one address to match). Keep a duplicate
   when the bytes or the pool layout need it, and say so in a comment.
2. **Raw offsets** `*(T *)((u8 *)p + 0x..)` and `(char *)p + 0x..` where the
   struct is known: write the field. Keep the raw form only when the field
   form changes the bytes (`(p + i*stride) + const` can be the original).
3. **Function-pointer casts** `((T (*)(...))f)(...)` and `(Fn)func_...`:
   give the function or the slot its real type.
4. **Several names for one address** inside your files (`sub_X` and `func_X`,
   `g_X` and a named alias, two externs for one object): keep one name (the
   real one if known, else `func_`/`g_`), drop the extra symbols rows.
5. **Stand-ins** (`/* stand-in */` comments, `volatile` on ordinary RAM data,
   raw-address casts for named objects, asm bodies of compiled code). The
   user decided (2026-10-12) to remove them in this pass, since it reads every
   file anyway. Levers: the other compiler builds (`../2.0/sp2`, `../1.2/sp3`:
   NitroSystem code was built with 2.0), the real struct size, `const` on
   pointees, redundant human forms (a value set twice, a second name for one
   object), and tools/mwccdbg. Keep a stand-in only with the exact reason.
6. Leave alone: names (renaming is a later phase), prototypes shared with
   files outside your list, real `asm` that the developers could have written
   (SDK-style CPU helpers), `volatile` on hardware registers.

## Rules
- Every file you touch stays EXACT (or MATCH if it was MATCH): verify after
  each step with `python tools/gameverify.py --file F` (one file) and run
  `python tools/gamesyms.py --file F --apply` on each file you change. At the
  end: `python tools/gameverify.py --region R` and
  `python tools/gamecheck.py --region R` (0 missing, 0 doubled).
- If a cleaner form changes the bytes, keep the old form, mark it
  `/* stand-in: <why> */`, and list it in your report.
- Only touch your own files and headers you create for your region. If you
  must change a header another region includes, re-verify every includer
  (grep) and say so in the report.
- No permuter, brute force or sweeps. No function-pointer casts to hide
  arity. `volatile` only for hardware or shared memory. Never open files
  under sdk/. No git stash/checkout/reset/mv; nothing staged or committed. No
  em dashes or emoji in files.
- Scratch goes in your scratch dir named in the prompt; copy any script you
  write there, and keep backups there. Temp files in src/game start with `_`
  and carry your lane name; delete them before you report.
- Keep context under 150k: scripts for bulk edits, targeted reads. Stop near
  130k and report.

## Report
Per file or group: what you unified (old names -> new type), counts before
and after (struct copies, raw offsets, casts, duplicate names), stand-ins
left (file, function, why), headers created or changed, any guess.

## Lane mechanics (cleanup and renaming wave)
- Read docs/restructure/RENAMING_PLAN.md first: one pass per file (read all,
  structs, stand-ins, names last); the reasons are the user's.
- Your prompt lists whole files. New shared headers are named after your
  primary file stem, `src/game/<region>/<stem>_types.h`, so two lanes never
  create the same header. `src/matched/include/ObjNNNNN.h` headers are
  read-only: drop the includes from your files, never edit those headers.
- Names: use the proposals in the autoname table (tools/autoname.py output,
  path in your prompt) and confirm or fix each one; `MODULE_VerbObject`, module
  = file name in upper case. A name used by other files goes into
  `rename_map.tsv` in your scratch dir (old, new, address); the integrator
  applies all maps tree-wide with tools/sdkrename.py. Rename inside your own
  files only for file-local (`static`) functions.
- Functions that look misplaced: add a row to `misplaced.tsv` in your scratch
  dir (file, function, suspected home, evidence); do not move them.
- Do not run `match.py manifest`. Verify each file after each step with
  `python tools/gameverify.py --file F`.

## Name everything (user decision, 2026-10-13)
Name every function, type, field, static, local and parameter in your files in
this pass, from how the code uses them (docs/NAMING.md "Name everything in one
pass"). No placeholders (`unkNN`, `fieldNN`, `GetField5C`, `FuncXXXX`,
address suffixes). Only functions that look misplaced keep their name and go
into misplaced.tsv.
