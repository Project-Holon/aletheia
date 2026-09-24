# Wave 19, lane 19R mcss_4

No function closed. All three notes got a dated wave-19 lane 19R section that lists every measurement. The best sources are unchanged.

| address | before -> after | verdict | measurements |
|---|---|---|---|
| 0x02016C60 | 29 -> 29 (870/872, 1.1p1) | DIFF | 19 hand, no permuter |
| 0x0209128C | 1 -> 1 (1.1p1) | DIFF | 8 |
| 0x02067080 | 2 -> 2 (704/704, ../2.0/sp2) | DIFF | 12 |

0x02016C60: I tried every untried lever from the brief. Inverted guards on pass 2's entry test (continue: 388; goto: 29; empty then-arm: 29; do/while(0) break: 387). The pointer assigned inside an inverted test and inside the test itself (29). The pass-1 pointer reused, reassigned (29) and not reassigned (750). A dying-local sweep over 24 existing locals (29 at best). const on the record, pointer, a0, a1 and f2c (29, or 771 for a const a0). Compound h2/shift forms (29 to 160). u32 k (29). The pass-2 pointer stays in r0 in every build. A single loop with a pass flag is ruled out by the image: it has two full loop copies with separate invariant slots, and 1.1p1 does not unroll a loop of this size. Nothing moved, so the permuter was not run.

0x0209128C: (a) All matched neighbours are 1.1p1, so there is no sp2 or 1.2 pin to inherit. That covers pkt_020911D8 (020911D8, 020911F0, 02091200, 02091220, 02091230, 0209124C, 0209125C, 020912A8, 02091374, 0209138C, 020913A4), pkt_02091284 (02091284) and the whole 0x02090F18..0x02092F0C run. (b) I measured 8 more 1.1p1 spellings: a u8 `(x != 0)` flag, an inverted guard, a ternary on the narrow flag, and goto arms. Each gives 1 out, or worse at 22 or 27. The ../2.0/sp2 exact build stays unfiled.

0x02067080: I measured the inverted guard on both repeat clamps, the adjust block, the remove-adjustment inline and G2_GetOBJEffect. I also measured a u8 flag and a u8 parameter (4), a plain versus compound clamp, and the dying-local y forms. All give 2 unless noted. dsi/1.2 gives 676 bytes and 560 out. The +0x21C ip-versus-r6 tie is unchanged.

Files written: docs/notes/pkt_02016C60.c.txt, docs/notes/func_0209128C.c.txt, docs/notes/pkt_02066E30.c.txt (appended sections only), and this report. Nothing was filed. No shards needed verifying. No seeds noticed. Permuter seeds 3701..3749 unused.

Integrator: nothing to do.
