# Merge lane brief (src/game restructure)

Repo: <home>/OneDrive/Documents/aletheia. A byte-matching C decompilation of
Pokemon Black (DS), compiler mwccarm dsi/1.1p1. `src/matched/` holds one function per
file, every one verified byte-exact; it is the frozen record: NEVER edit anything under
`src/matched/`, `layout/`, `asm/`, `tools/` or `docs/`.

`src/game/<region>/` is the new tree: the original source files (translation units, TUs)
rebuilt by tools/restructure.py. For each TU it wrote:
- `<tu>.c` when the whole TU merged and verified, or
- `<tu>_p01.c`, `<tu>_p02.c`, ... : merged parts that verified, in address order, and
- a folder `<tu>/` with the member files that could not be merged into a part, plus
  `MERGE.md` listing the blockers (which member ranges failed and why).

Your job, for each TU you are given: make the TU as close to ONE file as you can, every
file still byte-exact.

How:
1. Read `src/game/<region>/<tu>/MERGE.md`, the part files and the folder's member files.
2. Typical blockers and fixes:
   - a global declared with two types by different members (`void *` vs `struct X *`):
     give it one declaration (prefer the specific struct type) and add casts in the code
     that used the other view, only if the bytes stay the same;
   - a function prototype that differs between members: use the one the function's
     definition has (grep `src/matched` for the definition), add casts at calls;
   - two different local structs with one name: the tool renamed them `Name_ADDR`; if they
     describe the same object, unify them into one;
   - a macro defined two ways: rename one;
   - "c99=DIFF": merging changes the code (shared strings, inlining of a static helper):
     leave those members as separate files, note it in MERGE.md.
3. Merge step by step: append the next member's code to the part before it (or merge two
   adjacent parts), keep one copy of each type and declaration, and verify the result:
     python tools/match.py tu --src <file> --addr 0x<first function address> --region <region> --thumb --lang c99
   (use --arm instead of --thumb for ARM files; see the `isa:` and `lang:` header lines;
   drop --lang c99 if the header lang is empty). The result must say EXACT (or MATCH).
   Keep the merged header comment format (function list, address = first function, symbols).
4. When a member is merged, delete its copy from the folder. When the folder is empty
   except MERGE.md, delete the folder. Rename the final single file to `<tu>.c` if it
   covers the whole TU; otherwise keep `_pNN` names in address order (renumber so there
   are no gaps).
5. Update MERGE.md with what is left and why, or delete it with the folder.

Rules:
- Plausible human C only: no fixed-address casts, no volatile without reason, no tricks.
- Never change bytes: every file you write must verify EXACT/MATCH before you move on.
- Stage nothing in git, commit nothing; the integrator does that.
- Keep your context under 150k tokens: read targeted line ranges.
- No em dashes and no emoji in files.

Report: per TU, files before and after (parts + singles), what you fixed, what is left.

Lessons from earlier lanes (use them):
- Compilers `../1.2/sp2` and `../2.0/...` emit a file's functions LAST TO FIRST: in a merged
  file of such members, list the functions in descending address order.
- `-O4,p` and `-O4,p -proc arm946e` are the same settings (arm946e is the default).
- A UTF-8 byte order mark at the start of a member hides its header; strip it.
- The fastest method: a greedy pass that merges the next part or member into the
  running file with `tools/restructure.py`'s `merge()` and keeps it when `match.run_tu`
  says EXACT. You may copy tools/restructure.py into the scratchpad and run a patched
  copy, but do not edit tools/.
- Globals viewed through different local structs in different members are the main
  blocker. Only unify them when the members' field offsets agree; otherwise leave the
  boundary and describe it in MERGE.md (a later struct pass handles it).
