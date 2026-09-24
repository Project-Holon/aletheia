# Wave 20, lane wipe_oam (20D)

## 0x0202350C (wipe_sub.c): 4 -> 4, DIFF
The registers already match. The residue is only an order tie: `movs r0, #0`
and `ldrb r2, [r4, #0xb]` are swapped at +0x22. The allocation levers cannot
reach it because every way of writing the zero (named u32, u8 or unsigned long,
assigned first, used twice, initialised at declaration) is constant-propagated
before codegen, so the zero never gets its own web. Also measured: u8 k8/kb
(4), the stores written through index or pointer so they depend on each other
(4), and kb passed to the call (36). A sweep of the f40/f44 store positions (42
compiles) did no better than 4. The permuter (anneal 800, seed 4201) found
nothing. 12 hand measurements.

## 0x0202627C (bmp_oam.c): 10 -> 10, DIFF
This was measured on the 19Q alternative source (w first). All of these gave
10: the named zero used two to four times (it propagates); cb as unsigned long;
cb block-scoped; the inverted guard. Assigning cb late or last made it worse
(14, 24). Sweeps: the four reads in all 24 orders under four type mixes gave a
best of 10 in each, and the five stores in all 120 orders gave a best of 10.
The permuter (hill 800, seed 4202) stayed at 10. 14 measurements.

## Finding
In both functions the value that needs to move is a constant. mwcc propagates
a named zero local, so the levers that give a variable a longer or shorter web
have nothing to act on. Changing how the constant is materialised would need a
non-constant spelling, and none was found that stays byte-correct.

## Files written
- docs/notes/func_0202350C.c.txt (wave 20 section, best source unchanged)
- docs/notes/pkt_0202627C.c.txt (wave 20 section, best source unchanged)
- this report

No shards were verified (nothing closed). No new idioms. Seeds used: 4201 and
4202. Integrator: nothing to do.
