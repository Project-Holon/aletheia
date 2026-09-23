# Wave 14 lane: wih_dwc.c, bmp_menuwork.c, bmp_menu.c

EXACT 8 (+3 unlabelled followers) / MATCH 4 / DIFF 1, from 11 open rows.

- wih_dwc.c: EXACT 0x0201045C (MI_CpuCopy8 takes 3 args), unit_02010848 (followers 0x02010848, 0x02010864, 0x02010884). MATCH (src/pending, every concrete byte right, each blocked only on an unlabelled ov014 callee): 0x02010360, 0x020103E4, 0x0201058C (0x40-byte out struct for func_0205D01C), 0x020107FC (wrapping if).
- bmp_menuwork.c: EXACT 0x0201F81C (the loop stores zero, not the index).
- bmp_menu.c: EXACT 0x0201F93C (the allocator's heap parameter is `int`, found by permuter hill), unit_0201FC5C = 0x0201FC5C + 0x0201FD18 + 0x0201FD54 (0x0209C0A4 is _s32_div_f, quotient plus remainder; +0x0B is unsigned 4:2:2 bitfields; print-util inline). DIFF 0x0201FDA0.

Near miss: 0x0201FDA0, 2 bytes. The prologue has `str r3,[sp,#0x14]` and `adds r5,r0,#0` swapped. The best source and the levers tried are appended to docs/notes/pkt_0201FC5C.c.txt: parameter types from the callers, permuter hill 800 and anneal 2000 --types (no gain), and the compilers 1.2, sp2 and sp2p2.

Seeds (integrator, layout/function_starts.txt):
- ov014 0x0217963C thumb. Witness: bl at arm9 0x020103B6 and 0x020103FE. Unblocks 0x02010360 and 0x020103E4 (they witness each other).
- ov014 0x02177B80 thumb. Witness: bl at arm9 0x0201081A. Unblocks 0x020107FC (sole-ref/code).
- ov014 0x02178098 thumb. Witness: bl at arm9 0x020105E8. Unblocks 0x0201058C.
- arm9 0x02010848, 0x02010864, 0x02010884 thumb. Witness: src/matched/unit_02010848.c.

Shards verified (twice; pkt_0201F93C three times until 0 rewritten): pkt_0201045C, pkt_020107FC, pkt_0201F81C, pkt_0201F93C, pkt_0201FC5C.

New family headers: docs/families/wih_dwc.h, bmp_menuwork.h, bmp_menu.h.
