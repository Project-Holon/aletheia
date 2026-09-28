# arm9_el_game: the two former EL_LinkFileEx rows

Lane: arm9_el_game. Packet pkt_020312CC (unit 13, two ARM functions, 80 code bytes).

The SDK catalog correction (c8a8b796) moved 0x020312CC and 0x020312F8 from SDK
EL_LinkFileEx to game code. Both are three-argument forwarders that load the
object pointer from g_02146990 and call into the procsys.c neighbourhood:

- func_020312CC -> func_020314F4(g_02146990, a1, a2, a3)
- func_020312F8 -> sub_020314DC(g_02146990, a1, a2, a3)

Plain C, compiler dsi/1.1p1 -O4,p, c99, ARM, same as the neighbours
(func_020312B4, func_02031324). Both EXACT on the first attempt, every
relocation resolved (func_020314F4 and sub_020314DC by manifest, g_02146990 by
literal witness). The push {r4, lr} and register shuffle come from the compiler
unaided; no idiom needed.

## Files

- src/matched/arm9/func_020312CC.c (new)
- src/matched/arm9/func_020312F8.c (new)
- layout/matched/arm9/pkt_020312CC.json (new shard; manifest --verify --force: 1 rewritten, second pass 0 rewritten)
- layout/worklist.json (refreshed)
- docs/sessions/2026-09-28/reports/arm9_el_game.md (this report)

## Worklist summary

Before (after --refresh, pre-match):

    packets                       1
    coverage by bytes         99.9800%  (400630 / 400710 game code bytes)
    packet status            open=1

After:

    packets                       0
    coverage by bytes        100.0000%  (400710 / 400710 game code bytes)
