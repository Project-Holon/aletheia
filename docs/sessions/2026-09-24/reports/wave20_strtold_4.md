# Wave 20, lane 20A (strtold_4)

## 0x02094B8C, MSL __strtold (ARM, 3864 bytes)

62 -> 36 concrete bytes out, DIFF (size exact). Not closed; MATCH-capped
anyway by __double_huge and two anonymous pool words.

What moved it: the tail's uch as its own block-scope variable declared at
the top of the hex block, before `double hexresult;` and p
(`unsigned char hch;`, every tail use renamed). That colours it before p:
p r4, uch r3 in the first part, the shift loop's bound r3, the overflow
constant r3 and the whole swap loop now match. Declaring the same variable
after p gives 75, so the block declaration position is the lever.

Direction 1 (dead initialiser or `x = x;` on uch, later start for p) did
not help: every dead def on uch compiles byte-identical to the base, and
moving p's start costs 183 to 382. The permuter (anneal, --types, 2000,
seed 3901, --focus p,uch) found nothing under 62.

Still open (36 bytes, all in the second tail loop): the image has ui r2,
chindex r3, uch r5; the source gives chindex r2, uch r3, ui r5. Block-scope
ui or chindex, and the for-init order, were flat or worse.

19 hand measurements plus one permuter run (cap 20). All of them are in
docs/notes/pkt_02094B8C.c.txt under the 2026-09-24 wave 20 lane 20A
marker. The best source follows it, and re-extracting it measures 36.

Files written: docs/notes/pkt_02094B8C.c.txt (appended),
this report. No src/ files, no shards, no idiom file (not closed).

Seeds: none noticed.

Integrator: nothing to do beyond reading the note. For a next lane: start
from the 36 source, and work only on the second loop's ui/chindex order.
Untried: a loop-spanning dead def on the second loop's ui, a block-scope
ui declared between hch and hexresult, and `chindex = 12;` as its own
statement before the for.
