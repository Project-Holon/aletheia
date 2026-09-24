# Wave 20 lane 20J (strtold_5)

## 0x02094B8C (MSL __strtold, ARM, 3864 bytes)

36 -> 36 bytes out, DIFF (size exact). No gain; the lane 20A best source stays the best.
MATCH-capped at exact bytes as before (__double_huge, two anonymous pool words).

20 hand measurements plus one permuter run, all recorded in docs/notes/pkt_02094B8C.c.txt under
"2026-09-24, wave 20 (lane 20J, strtold_5)".

Finding: the second tail loop's triple (ui r2, chindex r3, uch r5) can be made exact. Declare
fresh block-scope `unsigned long ui2; unsigned long ch2;` before `unsigned char hch;` in the hex
block, in that order, and use them only in the second loop. That gives 39, and the whole residue
is then a p against r4/r5 swap: image p r4, first-part chindex and loop uch r5; ours is the
reverse. Of the six U/C/H orders, only U C H fixes the loop (39, 47, 62, 62, 62, 54). Sharing
ui2/ch2 with the first part puts back the 20A colouring byte for byte. Nested blocks around the
loop give 75. `chindex = 12;` as a separate statement changes nothing. Moving hexresult or the
first part's chindex does not move p.

Permuter: anneal, 1500 compiles, seed 4701, --focus ui,chindex,hch, from the 20A best with
#defines joined: 36, no gain.

Next for an integrator/lane: start from source 1 (U C H hr p, 39) and try levers on p only (dead
def of p spanning the tail, p function-scope, pointer recomputed at the swap loop), or run the
permuter on source 1 with --focus p,hch.

Files written: docs/notes/pkt_02094B8C.c.txt (appended), this report. No src/ files, no shards
verified. Seeds: none noticed.
