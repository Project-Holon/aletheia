# Cleanup and renaming pass: plan and the reasons behind it

Goal from the user: src/game must read like the source the developers worked
on, one .c per original file, and still build the ROM byte for byte. Matching
is done; this pass makes the code readable. It changes no byte.

## Why one pass, file by file
The user's point: never go over the same code twice. A lane that cleans a file
already reads all of it, so the same lane also merges its structs, removes its
stand-ins and names its functions. Doing structs first and names later would
mean reading every file twice.

Inside a file, the order is fixed:
1. Read the whole file first (every function, every type, every extern).
2. Settle the structs: one struct per object, built by offset from all its
   views; plain names; a shared header per region when several files use the
   object. The lane decides the groups and names; tools/structunify.py only
   executes those decisions and checks them; small files are edited by hand.
3. Remove the stand-ins (docs/restructure/CLEANUP_BRIEF.md item 5).
4. Name the functions last, because the struct and field names are the best
   evidence for what a function does.

Names that other files use go into a shared table, and one tool applies them
tree-wide (tools/sdkrename.py does this for SDK names already; game names use
the same mechanism). A lane never edits callers in other files by hand.

Functions that look like they belong to another original file are only flagged
in a shared table (file, function, suspected home, evidence). Nobody moves them
during this pass; the certain ones are moved afterwards in one step.

## Naming standard (docs/NAMING.md)
- Game functions: `MODULE_VerbObject`, module = the file name in upper case
  (FIELD_EFFECT_Init). SDK and library names stay the real ones.
- Names derived from the game's assert strings come first.
- tools/autoname.py proposes a name and a confidence for every game function
  (asserts, __FILE__ anchors, SDK calls, proc tables, call graph). Lanes confirm
  or fix the proposal instead of inventing names.

## The original was written by people
It is sometimes redundant: two struct views or two names for one object, a
value set twice, a copy in a second local. Keep a duplicate when the bytes or
the literal pool need it, and say so in a comment.

## Every change stays byte-exact
Each file is checked after each step (`python tools/gameverify.py --file F`).
A cleaner form that changes bytes is not used; the reason goes in a comment.
