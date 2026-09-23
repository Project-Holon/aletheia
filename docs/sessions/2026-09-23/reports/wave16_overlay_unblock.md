# Wave 16: overlay unblock lane

Overlay functions filed EXACT (13 functions, 186 bytes; all unlabelled leaves or thunks the listings emit as data words):
- ov010 pkt_02167358: 0x02167358 (20), 0x0216736C (20), 0x02167380 (20): record-field accessors, table 0x02171F5C (sole-ref/self)
- ov010: 0x0215E334 (8), 0x02159BBC (8): Thumb thunks to ENV_SetResourceSet 0x020307B0; 0x021647E8 (8): pool-word tail call to func_0216481C; 0x02161EEC (20): fill ten u16 with 0xFFFF
- ov009 pkt_02156B70: 0x02156B70 (28): s16 at +0x782 of the bss block 0x021A8264, or 0
- ov228 pkt_021DFC20: 0x021DFDB8 (8, ENV_SetResourceSet thunk), 0x021DFE90 (8), 0x021DFE98 (18), 0x021DFEAC (4)
- ov021 pkt_02188BD8: 0x02188BD8 (16)
Parked MATCH in src/pending: ov010 0x0215FA34 and 0x0215FA44 (16 each, id-0x14 tail calls into sub_02034AC4 / sub_02034A5C). The pooled absolute 0x14 has no witness: `literal` indexes ARM9 pool_ words only.

Pending files promoted (overlay hint added, now `matched, overlay`): func_0200E488, sub_0200E3A4, sub_0200E3E8 (EXACT*), sub_0200F698, func_02012704 (EXACT*), func_0202C794.
A concurrent actor promoted func_0200A358, func_0200A3D0, func_0200A848 on these same overlay shards while I was working (shards EXACT).

Still blocked:
- func_0201450C, sub_02014488: 0x0215FA44 (0x02188BD8 now resolves); func_020145CC: 0x0215FA34. Both need the seeds below.
- ov-id literal walls (small pooled absolute ids, no witness): func_0200F17C (also 0x0215536C ov009, 0x02177020 ov014, 0x021798D4 ov015; not attempted because the ids cap it anyway), func_0200F234, func_02010AC4 and func_02010C34 (also ov021 data 0x021D6338/0x021D654C), func_020120C0, func_02014878, func_020274C8, func_0202F9F8 (also 0x021B68D8), sub_02009800.
  Tool note: 0x72 and 0x0E sit at 0x0200F228/0x0200F22C in func_0200F17C's pool as unlabelled continuation words, so the pool index misses them. Otherwise 0200F17C and 0200F234 would witness each other.
- func_0202B84C: ARM9 data 0x0209FF8C. func_0206DC00: TWL-only 0x027300F0/0x0272FEF4 plus the unlabelled arm9 leaf 0x0206DBF4 (no matched source).
- func_020336A4, func_020863E0: headers say EXACT, fresh verdict MATCH (addr_020A789C / g_02151264 have no symbols: line). Not overlay work.
- func_02004490, func_02004632, func_020051D8, unit_0200530C, unit_020113F0 read EXACT/EXACT* fresh but carry CCERR/DIFF headers (asm stubs, units). Not overlay work. The 16 DIFF files are out of scope.

Seeds for the integrator:
- overlay_010 0x0215FA34 thumb: bl from arm9 0x020145F0 (func_020145CC); witness src/pending/func_0215FA34.c (MATCH, bytes right)
- overlay_010 0x0215FA44 thumb: bl from arm9 0x02014546 (func_0201450C) and 0x020144CE (sub_02014488); witness src/pending/func_0215FA44.c
  With these labels, sole-ref/code (overlay) should carry all three callers (the 0x02167394 precedent).
- No ARM9 seeds. The EXACT* followers of 0x0200E488, 0x0200E3A4, 0x0200E3E8 and 0x02012704 predate this wave.
- Pre-existing: pkt_0200F17C has two entries at 0x0200F2D4 (func_0200F2D4 and sub_0200F2D4).

Shards verified twice, all EXACT/EXACT*: ov010 pkt_02167358, pkt_0215E334, pkt_02159BBC, pkt_021647E8, pkt_02161EEC; ov009 pkt_02156B70; ov228 pkt_021DFC20; ov021 pkt_02188BD8; arm9 pkt_0200E488, pkt_0200E3A4, pkt_0200E3E8, pkt_0200F17C, pkt_020124F4, pkt_0202C794.
Nothing committed. New files: 13 src/matched/func_02*.c (overlay), src/pending/func_0215FA34.c and func_0215FA44.c, 8 shards.
