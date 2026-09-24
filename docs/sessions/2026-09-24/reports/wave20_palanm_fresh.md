# wave 20, lane palanm_fresh

0x0202173C (palanm.c, 268 bytes, Thumb): DIFF 33 -> EXACT (1.1p1 -O4,p).
0x02021848 (twin, 232 bytes, Thumb): DIFF 33 -> EXACT (1.1p1 -O4,p).
Both EXACT with and without the SDK include path. 9 measurements, no permuter.

What moved it: a fresh draft written from the listing, with every parameter
width read from func_020219C4's own matched body. The draft with `s32 step`
reproduced the old 33; changing only `step` to s16 closed the twin, and the
same spelling closed 0x0202173C first try. The signature is
`int f(PalAnmObj *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx)`
with the prototype `func_020219C4(void *, u16, s32, u8, u8, u16)`. u16 and s8
step give the same bytes. The two halves had each been measured before, but
never together: narrow `step` with a u32 prototype was 34, and narrow b, c, d
with a u32 prototype was 236. The narrow home store only leads the prologue
when the stack parameters and the callee prototype are narrow as well.

Files written:
- src/matched/func_0202173C.c (EXACT, packet pkt_0202173C)
- src/matched/func_02021848.c (EXACT, packet pkt_0202173C)
- layout/matched/arm9/pkt_0202173C.json (written by manifest --verify)
- docs/notes/func_0202173C.c.txt (wave 20 section)
- docs/idioms/narrow-stack-parameters-and-callee-prototype-free-the-narrow-home-store.md

Shards verified: pkt_0202173C, twice (1 rewritten, then 0).

Seeds: none new.

Integrator: the old shard layout/matched/arm9/pkt_0202173E.json (func_02021930
only) still carries the packet's old cut name; check whether it should be
merged into pkt_0202173C. docs/families/palanm.h still describes the pair as
DIFF 33 (the wave 13 ADDED block) and gives func_020219C4 a seven-parameter
prototype: callers need the six-parameter one. Its `a_big` and b_x
comments still hold. The same lever may be worth trying on other
spilled-r3 prologue rows. Nothing committed.
