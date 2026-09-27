# tree_ov018 (ov018, ov021, ov107)

## Trees

- ov018, root func_02182AA4: 14 functions, 13 EXACT and 1 MATCH. The root is real, but its code is only 0xB0 bytes. Its listing extent of 2528 bytes also covers rodata from 0x02182B54 to 0x02183484.
- ov021, root func_021B88DC (2184 B): all 13 callees were already witnesses. 0x021B854C (an old pending DIFF) is now EXACT\*. It closed with one `arg4 < arg6 && arg4 >= 0` goto guard in front of a plain if/else, and with arg6 reassigned instead of an `m` copy. The root is capped as a near miss (see below).
- ov107: the named root 0x021F4EFC is MBi_ChildCallback (an SDK row), so I skipped it. I took 0x021EFFB0 instead (1580 B, a 26-state machine): 26 functions, all EXACT. That includes 10 unlabelled Thumb accessors in the run 0x021F1060..0x021F116C plus 0x021F11BC. The root was byte-correct on the first draft and resolved once those leaves were filed.

## Files

- src/matched: ov018_func_* (13), ov107_func_* (26), ov021_func_021B854C.c (moved from src/pending/func_021B854C.c).
- src/pending/ov018_func_0217FE38.c: MATCH.
- docs/notes/pkt_ov021_021B88DC.c.txt.

Shards: pkt_ov018_*, pkt_ov107_*, pkt_ov021_021B854C. Each was verified twice and the second pass rewrote nothing. `manifest --check` is clean.

## Near miss

func_021B88DC: control flow matches, and the normalised op stream agrees on 988 of 993 instructions. What remains is register allocation. The original keeps `end` (p->f10) in r7 with a 0x6c frame; every draft spills it. The best draft is 1919 bytes out at 2190/2184. The permuter was run once (seed 7401), best 2015.

## Seeds / integrator

- ov011 0x02175368: an unlabelled leaf, called from 0x0217FE62. It is the only thing blocking func_0217FE38.
- ov107 unlabelled starts, now EXACT: 0x021F1060, 1110, 1118, 1120, 1134, 1148, 115C, 1164, 116C, 11BC. The witness is 0x021EFFB0.
- ov107 still unlabelled and unmatched: the accessors 0x021F1064 and 0x021F10D4..0x021F110C (8), plus 0x021F1174. 0x021F1230 is a callback reached from the pointer table at 0x021F6C7C.

## Next lane

func_021B88DC allocation only. ov018, ov021 (bands >= 512 B) and ov107 have more roots.
