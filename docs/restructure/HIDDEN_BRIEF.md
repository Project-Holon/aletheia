# Hidden-function lane brief

The regenerated listings and lane BT4's triage found real functions that no
file defines yet (most are small leaves: getters, setters, tail calls, SVC
stubs). Each now has a row in layout/function_starts.txt and a func_ label in
the listings. Your lane matches its list and files each function. Read
docs/restructure/FINISH_BRIEF.md, docs/restructure/ASM2C_BRIEF.md and
docs/restructure/REGMM_BRIEF.md (levers, compiler builds, human-written code).

## Per function
1. Read the listing (asm/...) and the evidence comment of its function_starts
   row (who calls it or holds its address).
2. Check first whether a src/game file already defines it under another name
   (grep the address and the SDK name in layout/symbols_sdk.json); if so, only
   file it (step 4).
3. Write it as C (EXACT). Use the SDK name when layout/symbols_sdk.json has
   one. A function the original wrote in asm (the BIOS `svc N; bx lr` stubs in
   the arm9 secure area) stays an asm body with the line
   `/* hand-written in the original: <reason> */`.
4. File it:
   - put the C into the src/game file whose address range covers it, in
     address order (the covering file is the one whose function list brackets
     the address; a gap between two files goes at the end of the earlier one
     only if that file's next function would follow it; else report it);
   - write a src/matched file for it in the folder its neighbours use;
   - `python tools/gameverify.py --file F` EXACT for the src/game file;
     `python tools/match.py one ...` EXACT for the src/matched file.
5. Do NOT run `match.py manifest` (the integrator does it once).

## Rules
Only touch the files your list needs. No permuter, sweeps or brute force.
`volatile` only for hardware or shared memory. Never open SDK source. No git
stash/checkout/reset/mv; nothing staged or committed. No em dashes or emoji.
Keep context under 150k; stop near 130k and report.

## Report
Per function: name, file, verdict (EXACT / kept asm with reason / not
closed with bytes differing and the remaining difference). Files touched.
