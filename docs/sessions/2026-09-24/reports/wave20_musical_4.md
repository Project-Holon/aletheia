# Wave 20, lane musical_4 (20B)

0x0200CA98 (musical_dist_save.c, Thumb, 1.1p1): DIFF, 114 -> 89 out, 392/392
(asm 2060 for v19 -> 800). Not closed; no file in src/matched, no shard to verify.

What moved it, from v19 (no u8 cnt):
1. `long o` in the form loop (not row1): row1 coalesces with the first p
   reload and the second `ldr [sp]` returns (size 392). 331 -> 113.
2. `j = 0;` before the cnt load, `for (; j < cnt; j++)`: form loop exact. 108.
3. `i = 0;` as the first tail statement (`for (; i < 4; i++)`): k's zero is
   live across y before scheduling, so y takes r4 as in the image. 103.
4. `long off` plus the loop mask inline (`*q &= bit ^ 0xFF`, no nm local):
   off after base, nm hoisted into r4, k r3. 89.
Everything from +0x00 to +0xBC is byte-exact. Residue: one r0/r1/r2 rotation
from +0xBE (image base r1, off r0, 0xFF chain/row/sel r2; compiled base r2,
off r1, chain r0), which also cross-jumps the `mov r0, lr` of the two sel!=0
arms.

Measurements: 25 (two sweeps of 40 and 120 counted once each), all in the note.
Flat: long x/m/y/bit, y declared first, `y &= 7`, separate k, decl order of
tail locals, off unnamed (110), inverted sel guard (151, blocks reorder).

Permuter (anneal 2000 --types, seed 3801): rejected. Every accepted
candidate has unresolved=1 against the baseline's 2 (mutations merge the two
Table literals into one pool entry) and the scorer ranks that above bytes, so
it climbed to 284 out. Integrator: permuter.py's ranking should not reward
fewer unresolved relocations when the image has both literals.

Files written: docs/notes/pkt_0200CA98.c.txt (dated wave-20 section, best
source, 25 measurements, register map); this report.
Seeds: none noticed.
