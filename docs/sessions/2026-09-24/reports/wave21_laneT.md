# Wave 21, lane T: ov230's own decryptor in the pipeline (region `ov230d`)

Owner-approved tools change. The design follows the `twl` / arm9i_dec.bin pattern.

## What was built

- **tools/ovcrypt.py** is a new stdlib-only module. Its docstring gives the scheme and the evidence, in the style of modcrypt.py. It replays ov230's static-initialiser decryptor on a copy of extract/overlays_dec/y9_0230.bin. I reimplemented it from my own reading of loc_02188A48, func_02188A0C and the entry thunks in asm/overlays/ov230.s. The decryptor code [0x021889E4, 0x02188B48) must match a recorded SHA-1. END, KEY, DELTA and BIAS are read from the decryptor's own pool words and `sub #imm` immediates. Each table address is computed from its entry thunk's immediates (orr/adds/bne to the decryptor). For func_02188408 that address is 0x02188414.
  - The whole overlay is refused if any of these checks fails:
    - an initialiser has another shape;
    - a range is not whole words inside ov230;
    - a range overlaps another range, the decryptor, a thunk or a table;
    - a range is unchanged by decryption;
    - a decrypted range is not a clean ARM function.
  - The clean-function check uses a stdlib decoder. A walk from the first word must reach every word and never leave the range: no fall-through and no `b` into the next slot. `bl`/`blx` must land in ov230. There must be no undefined, unconditional-space or non-p15 coprocessor words. The last word must be an unconditional return.
  - Result: 5 initialisers and 28 ranges, all clean. Tables 0, 1 and 3 hold 0x24-byte thunk slots, 18 in total. The table at 0x02188414 holds the six slots 0x021882A0 + n*0x3C. Table 2 holds the dispatcher 0x02188C60 and two helpers, and table 4 holds seven more functions.
  - The second-layer bodies the dispatcher decrypts at call time are not replayed. The view is the state right after the static initialisers ran.
  - The decryptor zeroes its thunk and table words after use. The view keeps them, and check 3 guarantees none of them lies inside a range.
  - My output is byte-identical to H2's independent scratch emulation.
  - CLI: `python3 tools/ovcrypt.py check|write|selftest`. The selftest has 10 cases, all passing: the real image passes, and six mutations are refused (hash, a garbage slot, a slot without a return, a range stretched past its return, a range on its own table, a range outside ov230, a non-thunk initialiser).
- **extract/ov230d.bin** is the derived view. It is written by `ovcrypt.py write`, and delink.py now does the same step as item 5 of its docstring (analyse_ov230d; fatal on a failed check). extract/overlays_dec/y9_0230.bin, asm/overlays/ov230.s and build.py are untouched, so the ROM rebuild keeps the encrypted bytes. build.py never reads the view.
- **tools/disasm.py** has a new `ov230d` subcommand, which writes asm/ov230d/ov230d.s. Seeds are the sinit entries, every checked range start, and function_starts.txt rows for `ov230d` (none added). The decryptor tables are declared data. The listing is refused if extract/ov230d.bin differs from a fresh decryption, or if Capstone does not trace each range as one function of code. Result: 35 functions, 36.9% code.
- **tools/match.py** has a new symbols token `ov230d` and a section "decrypted ov230".
  - A target resolves only if all of these hold:
    1. the token is present;
    2. the address is a range start of the checked view;
    3. extract/ov230d.bin equals the fresh decryption;
    4. asm/ov230d/ov230d.s labels the address with the declared ISA.
  - With an outside branch the class is `label`; without one it is `sole-ref/code`.
  - I chose `ov230d` over reusing `ov230` for the same reason `twl` is a separate token: the plain `ov230` token keeps meaning the ROM listing, so no existing hint changes meaning, and nothing is looked up in the decrypted view on address alone.
  - Converse guard `on_ciphertext()`: a `func_` label in ov230's ROM listing inside a decrypted range is a label on ciphertext. The overlay `label` and `sole-ref/code` rules now refuse it. Today no ROM-listing label lies in a range (the 7 labels are all outside), so the guard changes no verdict.
  - resolve_relocations uses the ov230d label as ISA evidence for ov230d-hinted sites only.
- **Evidence class for ica_anime: sole-ref/code.** The only caller of the three slots image-wide is func_02011D9C, which is the range under test, the same situation as func_0206DC00's twl callees. It is honest because the label sits on real decrypted thunk code: the range the game's own initialiser decrypts and flushes, which is checked to be a whole ARM function, and which Capstone traced. It is not on ciphertext.

## Selftests

- `python3 tools/match.py selftest`: **206 cases, 0 failures**. The original tools gave 192 of 192; 14 cases are new.
- The new cases:
  - the three slots attest as ("sole-ref", "code");
  - refused: an interior address, the wrong ISA, no token, the twl token, and the plain ov230 token;
  - refused: the ov230d hint on func_02188A0C, which is real plain code labelled in the decrypted listing but outside the ranges;
  - refused: a planted label on still-encrypted bytes at 0x02187F00;
  - refused: a planted ROM-listing label on ciphertext at 0x021882A0, by attest, the overlay label rule and the overlay sole-ref/code rule;
  - a slot failing the clean-function check makes ovcrypt refuse, and then nothing is attested;
  - the `ov230d` token parses.
- `python3 tools/ovcrypt.py selftest`: 10 of 10.
- `python3 tools/selfcheck.py`: 2 of 2 PASS.

## ica_anime

- src/pending/func_02011D9C.c: I changed only the three symbols: tokens (ov230 to ov230d) and the header prose (status, a promoted line, and the blocking paragraph replaced). The C is unchanged.
- `match.py one` (dsi/1.1p1 -O4,p, thumb, c99): **EXACT, 272 of 272 bytes, 25 of 25 relocations**. 0x021882A0, 0x02188354 and 0x02188390 are sole-ref x1.
- I moved the file to src/matched/func_02011D9C.c with a plain `mv` (no git). `match.py one` from the new path gives EXACT.
- `manifest --verify --shard pkt_02011D9C`, run twice: EXACT/EXACT with 1 rewritten, then 0 rewritten. layout/matched/arm9/pkt_02011D9C.json lists sole-ref code for 0x021882A0, 0x02188354 and 0x02188390.

## Proof nothing else moved

I ran every re-verify in scratch snapshot roots (copies of src/ and layout/) so that no repo shard other than pkt_02011D9C was rewritten.

- **All shards** (`manifest --verify --shard` for each of 1352 shards, 3774 entries, new tools): 1 status change, 0 tracebacks, 340 rc!=0, 33 rewritten.
  - I re-ran the 33 rewritten or changed shards on a second snapshot with the **original** match.py (git HEAD). The printed verdicts and the resulting shard files are **identical**, so none of these outcomes comes from this change.
  - The one change is **func_0206DC00, EXACT to MATCH**. It happens the same way with the original tools. This container has no asm/twl/twl.s, so the twl sole-ref/code rule has no listing. Regenerating it needs `delink.py` with the DSi key plus `disasm.py twl`. I did not do this because it is outside this lane.
  - The 340 rc!=0 are pre-existing. 339 shards hold EXACT* entries, which `manifest --verify` counts as not EXACT. The other one is pkt_0206DC00.
  - The 33 rewrites are evidence-list refreshes on the current tree, for example sole-ref lines that other lanes' newly matched files now answer through other classes, plus pkt_0206DC00. They are identical with the original tools.
  - ica_anime's shard shows no change in that pass because it had already been written EXACT. Its MATCH to EXACT is the explicit `match.py one` result above.
- **Pending** (`tools/session/promote_fast.py --dry` on the snapshot): the 1 remaining MATCH-class pending file, func_020863E0, verifies MATCH (22 of 23). Its header says EXACT. The original tools give the same MATCH 22 of 23, so this is pre-existing and not a change.

## Files touched

- New: tools/ovcrypt.py.
- Edited: tools/disasm.py (ov230d region/subcommand, listing path), tools/delink.py (step 5 hook), tools/match.py (ov230d section, token, guard, selftests), tools/session/README.md.
- ica_anime: src/pending/func_02011D9C.c moved to src/matched/func_02011D9C.c, layout/matched/arm9/pkt_02011D9C.json, and an appended section in docs/notes/pkt_02011D9C.c.txt.
- Docs: docs/NOTES.md (new section "Overlay 230's own decryptor"), docs/HANDOFF.md (tooling line), and this report.
- Derived and gitignored: extract/ov230d.bin, asm/ov230d/ov230d.s, asm/ov230d/inst_index.txt.
- No git writes. I did not run build.py or wave.py.
