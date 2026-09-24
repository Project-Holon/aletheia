# Wave 21, lane D4: 0x02048744 (g3d_util.c, 468 bytes)

**Verdict: EXACT** (`match.py one`: 468/468 bytes, 9 of 9 relocations resolved, dsi/1.1p1,
`--arm`). Filed as `src/matched/func_02048744.c`. `manifest --verify --shard pkt_02048330`
was run twice. The first run rewrote the shard, and the second rewrote nothing. All 5
entries are EXACT.

## The lever

The fix uses `int i, j` (the int base, 18 bytes out: i r8, objTbl/j sb) with the outer
increment spelled as a null-based pointer step:

    for (i = 0; i < objCount; i = (int)((char *)0 + i + 1)) {

The emitted code is the same `add sb, sb, #1`. The difference is in the colouring order:
i's loop-carried definition now reaches the allocator as a pointer temporary, not as an
in-place integer add, so i is coloured last. That gives res r7, objTbl/j r8 and i sb, which
is the ranking `short i` produced (lead 1), without the 8 bytes of sign extension.
`(u8 *)0` is also EXACT. These spellings stay at 18: `(int)((char *)i + 1)`,
`(int)(char *)(i + 1)`, `(int)((u8 *)0 + (i + 1))`, `(int)&((u8 *)0)[i + 1]`,
`(int)((u8 *)i + 1)` and `(int)((long long)i + 1)`. On the long base, every variant stays
at 14.

## Merges (lead 3), measured first

Each merge was measured on the long base, the int base and short i with int j:
- **Inert (14/18/45):** mdl reused for rnd, and mdl or tex reused for `a`.
- **Moves the whole r4-r6 set (46/39/88):** tex reused for anm.
- **Worse:** A+F (49/42/91), A+G (472 bytes) and D+C (as D).

None of the merges gives the image ranking. Lead 4 (`n = i + 1; i = n;`) had already been
measured by D2 and D3 on both bases (18/14), so it was not repeated. The full readouts are
in `docs/notes/pkt_02048330.c.txt`, section "2026-09-24, wave 21 (lane D4)".

## Files

- `src/matched/func_02048744.c` (new, EXACT, house header)
- `layout/matched/arm9/pkt_02048330.json` (written by `manifest --verify` only)
- `docs/notes/pkt_02048330.c.txt` (appended the lane D4 section)
- `docs/sessions/2026-09-24/reports/wave21_laneD4.md` (this report)

This took about 45 compiles, with scratch files in /tmp/aletheia_laneD4/w (`log.txt`). No
outside decompilation or reconstruction was consulted. Suggested for the integrator: an
idiom file on "a null-based pointer step re-ranks a loop counter's web". It was not written
here because this lane's write set is limited to the target's files.
