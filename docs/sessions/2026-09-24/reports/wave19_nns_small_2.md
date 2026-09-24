# Wave 19, lane nns_small_2 (19J)

Per address, bytes out before -> after, verdict, what moved it:

- 0x020681E4 (GetCharIndex1D, ../2.0/sp2): 10 -> 0, EXACT. The long type and the order sweeps did not move it: 9 type combinations, 1440 block orders and 84 function-scope placements all gave 18. What closed it: compute log_w in place IN the dying h-shift local `sh` (`if (w >= 8) sh = 3; else { sh = w; asm { clz sh, sh } sh = 31 - sh; }`), with log_h in a fresh local. Any placement with log_w in sh matches.
- 0x0206F4C8 (../2.0/sp2p2): 7 -> 2 with no volatile. The s16 y pair is now `a = ((V2s *)p)[i0].y; p = (u8 *)((V2s *)p + j); b = ((V2s *)p)->y;`. The j element address forms in p's dying register. Left: the wave-8 `adds` operand order. The 720-order sweep and the permuter gave 2 as well. The best source is in the note.
- 0x02071104: 6, unchanged (long ss/tt in 8 combinations, tt-first order, permuter).
- 0x02069BA0: 6, unchanged (long on each local, 120-order sweep with long shortfall, dying-local reuse for the 8, permuter).
- 0x0202350C: 12, unchanged (long a4/a5, u32 as unsigned long, 120 assignment orders, permuter best 15).
- 0x0202627C: 10, unchanged (cb or flag read into the dying sub/rec, 72-compile order sweep with long a/b, permuter).
- 0x02011688: 26, unchanged (long n/idx on the three shapes, goto-fail shape, permuter rejected).

Files written:
- src/matched/func_020681E4.c (EXACT)
- layout/matched/arm9/pkt_02067FE4.json (rewritten by manifest --verify)
- docs/idioms/a-result-computed-in-a-dying-local-takes-that-locals-register.md
- notes: pkt_02067FE4, pkt_0206F4C8, pkt_02071104, func_02069BA0, func_0202350C, pkt_0202627C, pkt_02011688 (each with a "2026-09-24, wave 19 (lane nns_small_2)" section)

Shards verified: pkt_02067FE4, manifest --verify twice (1 rewritten, then 0). A third pass after the integrator's commit also rewrote 0.

Seeds used: 2951 to 2956. No unlabelled starts noticed.

Integrator: f134252 already contains the 0x020681E4 source, shard and idiom. Only the note sections and this report are uncommitted. For 0x0206F4C8, try the same dying-local reuse on the s32 x blend's second key.
