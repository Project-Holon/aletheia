# Wave 15 tail lane (16 families, 37 addresses)

EXACT 16 of the lane's addresses plus 1 thunk. MATCH 11 (walls, parked). DIFF 10.
- iss_3ds_sys: EXACT 0x0202B90C, 0x0202BA24, 0x0202BAF4, plus 0x0202BB40 (thunk, not seeded). DIFF 0x0202BB68 (0x0202BBB0 twin not re-run). Levers: an enum counter keeps the unfolded guard; BA24 stores 0, not i.
- wipe: EXACT 0x02022758, 0x02022790, 0x020227CC, 0x02022940. DIFF 0x0202271C (1.1p1 CSE 9 B; sp2 1 B pool dedupe). 0x0209F568..74 are rodata words: declared `data`, they resolve sole-ref/self.
- field_status: MATCH (parked, walls) 0x02014878 (pooled overlay-id words), 0x020145CC, 0x0201450C, 0x02014488.
- iss_city_unit: EXACT 0x0202AFAC, 0x0202AFFC, 0x0202B04C (const u8 *obj, const s32 *pos, const-pointee callees).
- blink_palanm: DIFF 0x0202ED00 (6 B), 0x0202EB9C (15 B sp2).
- iss_switch: EXACT 0x0202C860 (pending promoted, now sole-ref/code). MATCH 0x0202C794.
- symbol_save: MATCH, all 6 parked (overlay walls, GROUP A included).
- save_control: EXACT 0x020070C8 (enum counter plus `goto end`). DIFF 0x02006F20 (MATCH-capped anyway).
- net.c: DIFF 0x0203CBAC (80 B). arc_util: EXACT 0x0204A39C (ARM, not Thumb). double3Ddisp: DIFF 0x0204E914. bgwinfrm: DIFF 0x0202CC70.
- net_handle: EXACT 0x0203A020, net_command: EXACT 0x0203A958 (both closed by `const u8 *` on the message param).
- pokegra: EXACT 0x0202D4A8 (the 2-way shiny local typed as an enum fixes the sp+4/sp+8 spill slots).
- bmp_menu: DIFF 0x0201FDA0 (2 B).
DIFF notes appended: pkt_0202BB68, pkt_0202271C, pkt_0202ED00, pkt_0202EB9C, func_02006F20, pkt_0203CBAC, func_0204E914, func_0202CC70, pkt_0201FC5C.
Headers written: docs/families/{wipe,iss_city_unit,iss_switch,arc_util,double3Ddisp,net_command}.h.
Superseded pending files removed from the tree (not staged): func_02022790.c, func_020227CC.c, func_0202C860.c, func_0204A39C.c.

## Integrator: seed
- 0x0202BB40 thumb, src/matched/func_0202BB40.c (thunk to 0x0202BA24; the witness for 0x0202B90C).
- 0x0202BA60 thumb, the unlabelled 28-byte follower of 0x0202BA24 (no source filed).

## Overlay callees needing evidence (address, overlay)
0x0215FA34 ov010, 0x0215FA44 ov010, 0x02188BD8 ov021 (field_status); 0x021647E8 ov010, a thunk (iss_switch);
0x0216736C, 0x02167380, 0x02167358 ov010; 0x0215536C, 0x02156B70 ov009; 0x02177020 ov014; 0x021798D4 ov015 (symbol_save);
0x021DFC20, 0x021DFE90, 0x021DFE98, 0x021DFDB8 in the ov228 range (save_control 0x02006F20).

## Shards verified (each twice, stable)
pkt_0202B90C, pkt_0202BA24, pkt_0202BAF4, pkt_0202271C, pkt_02022790, pkt_02022940, pkt_0202AFAC,
pkt_0202C860, pkt_020070C8, pkt_0204A39C, pkt_0203A020, pkt_0202D4A8, pkt_0203A958.
New levers worth an idiom: an enum local moves a spill slot (D4A8); a const-pointee read-only parameter frees store/load scheduling (A020, A958, AFAC trio).
