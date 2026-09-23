# Wave 17, lane 17D (tail): report

Per address, bytes out before -> after:

- 0x0203422C areaman: 17 -> EXACT. The fill cursor is the parameter reused, `start = idx + 1;` (new idiom).
- 0x020343C0 areaman: 44 -> EXACT. Same lever, `start = start / 8;`, with the zeros in natural order. Needed a symbols line for Areaman_TailMask 0x020A0495.
- 0x0202BB68 / 0x0202BBB0 iss_3ds_sys: 37 / 36 -> tu-EXACT as unit_0202BB68. The lever was callee arity: the clamp helpers take (obj, index, cap), so v is their third argument.
- 0x0202C148: 17 -> EXACT. The lever was a u16 heapId parameter.
- 0x020141A8: 47 -> EXACT. I re-measured on the real 52-byte extent, and the s16 -1 field is enough.
- 0x02091284: filed as an `asm void` veneer (word 0x02731920). EXACT.
- 0x02025360 actor_tool: 57 -> 21 (DIFF). Uses the struct, a fill base recomputed in the loop body, and `int i, j, end;`. The remaining difference is a rotation of three registers.
- 0x0202350C: 13 -> 12 (DIFF). cfg[8] and cfg[0xb] are now read into locals before the stores.
- Unchanged, with the levers tried recorded in their notes: 0x0202E1F0 at 21, 0x0202627C at 10, 0x020246C8 at 1, 0x0209D7D4 at 43.

Files written:
- src/matched: func_0203422C.c, sub_020343C0.c, unit_0202BB68.c, func_0202C148.c, func_020141A8.c, func_02091284.c.
- docs/idioms/a-dead-parameter-reused-as-the-index-rotates-the-loop-registers.md.
- Notes appended for every function except the veneer.

Shards verified twice: pkt_0203422C (new), pkt_020343C0 (new), pkt_0202BB68, pkt_0202C148, pkt_020141A8, pkt_02091284 (new).

For the integrator:
- docs/families/iss_3ds_sys.h declares func_0202BC48 and sub_0202BC60 with two arguments. The correct form is (obj, index, cap).
- actor_tool.h and areaman.h still list their functions as DIFF.
- Try the u16-heap lever once each on func_0202BEEC and func_02013528.
- tools/match.py was broken mid-edit by another lane for a while; I measured with a HEAD copy in scratch, then verified every shard with the live tool.
- Seeds: none new.
