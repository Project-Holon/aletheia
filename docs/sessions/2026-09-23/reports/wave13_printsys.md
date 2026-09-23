# Wave 13: printsys / pms_draw / palanm / blink_palanm lane

## Result: 4 exact filings (3 target functions + 1 unlabelled leaf), about 790 code bytes

| addr | family | verdict | file | packet |
| --- | --- | --- | --- | --- |
| 0x0201C4E4 | printsys | EXACT (456 code + pool) | src/matched/func_0201C4E4.c | pkt_0201C4E4 |
| 0x02021C20 | palanm | EXACT (136) | src/matched/func_02021C20.c | pkt_02021C20 |
| 0x0202EA40 | blink_palanm | EXACT* (196; the extent runs long) | src/matched/func_0202EA40.c | pkt_0202EA40 |
| 0x0202EB04 | blink_palanm | EXACT (6-byte leaf, witness) | src/matched/func_0202EB04.c | pkt_0202EA40 |

All filings use 1.1p1. `manifest --verify` passed for pkt_0201C4E4, pkt_02021C20 and pkt_0202EA40 (the pkt_0202EA40 shard holds 2 entries). Nothing was committed.

### What closed them
- **func_0201C4E4:** the shape of the inline ring-wrap helper. The named-local form `u16 r = o; if (r >= ps->unk04) r = 0; return r;` is EXACT. The early-return form is 5 bytes out, because it truncates in place and the size load moves between the two shifts.
- **func_0202EA40:** two causes.
  - The listing extent was wrong. 0x0202EB04 is a separate leaf (`p->h10 = 0`), so the real size is 196, not 204. With a scratch wrapper that gives the permuter the right size, it pointed at the fixes: `u16` pixel locals, and the pack written as `(r << 10) | (bl | (g << 5))`. The compiler evaluates first the operand that is ORed last.
- **func_02021C20:** the same shape carried over.
  - Use `u16 a; u16 t;` locals.
  - Write the channel extractions inline instead of binding them to locals.
  - Pack as `r | ((b << 10) | (g << 5))`.
  - The old reading (int pixel, sb/sg/sr locals) was stuck at 69.

## Still DIFF (appended note sections, each with a best-source marker and the permuter's best line)
| addr | best | where the gap is |
| --- | --- | --- |
| 0x0201C7D0 | 2 bytes (sp2) | Compiler split, see below |
| 0x0201D768 | 66 (was 72 or 61 with volatile scaffolding) | The only caller narrows the length, so the parameter is `u16 len`. With that, the plain source is 92/92 with no volatile. What remains is the head/counter spill tie. |
| 0x0201C8BC | 17 | The base register for the byte stores; about 35 new spellings |
| 0x0202DD24 | 8 | Spill-slot order. The image keeps `dst` as a named local; every compile treats it as a late temp. |
| 0x0202E1F0 | 369 at 400/412 | Frame layout read slot by slot: the two arms of the second loop have separate p0/p1 slots, `&ws` stays in r7, `n` is spilled. Not closed. |
| 0x0202173C, 0x02021848 | 33 each | The permuter finally got a correct-size run (scratch wrapper around match.target_extent, tools/ untouched). Plateau at 33 is now a real negative. Passing a 7th argument to func_020219C4 is refuted. |
| 0x0202ED00 | 6 | Aggregate copy evaluates source before destination. A wrong-direction probe proves this is the whole residue. |
| 0x0202EB9C | 15 (sp2; 1.1p1 44 and 4 bytes short) | 1.1p1 merges the two func_0202ED00 calls into one, sp2 does not. What remains is a register rotation plus one jump the image leaves unthreaded. |

## For the owner: a compiler question
Three functions each show one 1.1p1 trait and one sp2 trait at the same time, so neither pinned compiler can produce them:
- **0x0201C7D0:**
  - The stacked u16 read is based at the incoming-argument block, as 1.1p1 does. sp2 bases every such read at sp+8; I checked this by compiling the EXACT sub_0201C724 under sp2.
  - The call scheduling and the scratch-address reloads are sp2's.
- **0x0202EB9C:** the two calls stay separate, as in sp2, but one jump is left unthreaded, as in 1.1p1.
- **0x0202E1F0:** the parameter homing matches sp2, but the c1 read base matches 1.1p1.

An intermediate 2.0 build (base or sp1*) is the natural thing to test. Per your rules I did NOT run it.

## Integrator: seed
- 0x0202EB04 (thumb): an unlabelled 6-byte leaf after func_0202EA40's pool word. It is filed EXACT as src/matched/func_0202EB04.c, and it is why func_0202EA40 reads EXACT*.
- 0x0202173C and 0x02021848 (thumb, the `push {r0-r3}` entries) still read as 2-byte extents in the listing. This is repeated from the earlier notes.

## Files touched
- **New sources:** src/matched/func_0201C4E4.c, func_02021C20.c, func_0202EA40.c, func_0202EB04.c
- **Shards:** layout/matched/arm9/pkt_0201C4E4.json, pkt_02021C20.json, pkt_0202EA40.json
- **Notes (appended):** pkt_0201C7D0, func_0201D768.diff, pkt_0201C8BC, sub_0201C4E4, pkt_0202DD24, pkt_0202E1F0, func_0202173C, func_02021C20, pkt_0202EA40, pkt_0202ED00, pkt_0202EB9C
- **Family headers:** printsys.h, palanm.h, blink_palanm.h, pms_draw.h
- **Scratch tool:** scratchpad/w13/permuter_extent_wrapper.py (it overrides the listing extent without touching tools/)
