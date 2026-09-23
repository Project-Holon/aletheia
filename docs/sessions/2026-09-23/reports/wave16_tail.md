# Wave 16 tail lane report
50 functions EXACT (all shards verified twice), 9 DIFF recorded with notes, 0 new MATCH parks.

| family | EXACT | DIFF / skipped |
|---|---|---|
| mystery_data | 0x0200AD6C; 0x0200A848, 0x0200A3D0, 0x0200A358 promoted (overlay callees now matched) | none open |
| overlay witnesses | ov010 0x02161EEC; ov228 0x021DFDB8, 0x021DFE90, 0x021DFE98, 0x021DFEAC (shard ov228/pkt_021DFC20, shared with another lane that wrote the same four leaves at the same minute) | |
| game_comm | unit_020263D8: 0x020263D8, 0x02026400, 0x0202640C (bitfield flags, store order) | 0x0202627C DIFF 10 (one swapped pair in case 5) |
| pmsi_param | 0x02024230 (u16 phase; the table is FX_SinCosTable_ 0x020A1B38, never 0x02021B38) | 0x020246C8 DIFF 1 (jump threading) |
| actor_tool | 0x020253D4 (int cursor, 2x16 slot array) | 0x02025360 DIFF 57 (permuter flat) |
| save_control | 0x02006F20 (enum counter plus `i = 0; if (i < N) { flags = ..; do .. while }`) | |
| battle_rec | unit_0200BFA4 + follower 0x0200C054 (u64 locals, minutes first, mode 2 adds the delta) | |
| screentex | 0x0202E688 (FX_SinIdx/FX_CosIdx inside the MTX_Perspective inline) | |
| btl_setup / wipe / iss_3ds_sys | | 0x02013528 DIFF 6 (const tried); 0x0202271C DIFF 1 under every 2.0 build (duplicate pool word, not pinned); 0x0202BB68/BBB0 not re-run (no new lever) |
| iss_switch | 0x0202C794 was promoted by the integrator before I reached it | |
| vm | unit_020113F0: 0x020113F0, 0x02011400 (2D table subscripts, sole-ref/self) | |
| ringtone_sys | 0x02029FD0, 0x02029FE4, 0x0202A084 (tbl[state][event]; case 1 written out apart from case 3) | |
| zonedata | 0x02013D74 (one disjunction) | 0x020141A8 DIFF 47 (live 1 plus derived -1) |
| boot (before first anchor) | unit_020051D8 (+ thunk 0x02005204), unit_0200530C, 0x02004490, 0x02004632 (SVC stubs) | 6 ARM `ldr pc` veneers are not C |
| iss_sys / iss_dungeon_sys / iss_city_sys | 0x0202B84C (0x0209FF8C is Data_0209FF88+4); 0x0202B374 (volatile items, guarded do/while, count copy); 0x0202AB5C | |
| game_event / field_sound_system / vman | 0x02012380 (switch, case 0x21 empty); 0x02028BDC (callee arity); 0x02034558 (height stored per arm, re-read) | |
| pms_word | 0x02024938 (2D table, symbol+1 pool word); 0x020247A8 (declaration order) | |
| beacon_status | unit_02027634: loader plus 12 id getters 0x02027694..0x020276C0 | |
| iss_switch_sys / wipe_sub / billboard / game_beacon | | 0x0202C148 DIFF 17; 0x0202350C DIFF 23 -> 13 (const cfg); 0x0204EEC8 not improved; 0x020274C8 MATCH* wall |

Shards written and verified twice: arm9 pkt_0200AD6C, pkt_0200A848, pkt_0200A358, pkt_0200A3D0, pkt_020263D8, pkt_02024230, pkt_02025360, pkt_02006F20, pkt_0200BFA4, pkt_0202E688, pkt_020113F0, pkt_02029FD0, pkt_02029FE4, pkt_0202A084, pkt_02013D74, pkt_020051D8, pkt_0202B84C, pkt_0202B374, pkt_02012380, pkt_02028BDC, pkt_02024938, pkt_020247A8, pkt_02027634, pkt_0202AB5C, pkt_02034558, pkt_02004490; ov010 pkt_02161EEC; ov228 pkt_021DFC20.

Family headers written: docs/families/game_comm.h, actor_tool.h, screentex.h; pmsi_param.h updated. DIFF notes appended for every DIFF row above.

## Integrator: seed
- arm9: 0x02026400 (unit_020263D8), 0x0200C054 (unit_0200BFA4), 0x02005204 (unit_020051D8), 0x02011400 (unit_020113F0), 0x02027694..0x020276C0 step 4 (unit_02027634), 0x0200AD6C and 0x0202AB5C (single files).
- ov010 0x02161EEC; ov228 0x021DFDB8, 0x021DFE90, 0x021DFE98, 0x021DFEAC.
- Extent only, no source yet: 0x0200AD78 (follower of 0x0200AD6C), 0x020141DC (leaves after 0x020141A8; the 92-byte extent skews the permuter).

## Layout and tool items
- 0x020507A4 is a phantom row: the function starts at 0x020507A0 and is already EXACT (func_020507A0.c).
- ARM `ldr pc, [pc, #-4]` veneers counted as open: 0x02005B6C, 0x02006D3C, 0x020053E4, 0x02005420, 0x02005428, 0x02005454.
- No evidence class for absolute overlay-id symbols (0xE7, 0x73, 0xBB, 0x0D, 0x09): this blocks 0x020274C8, 0x02010AC4, 0x02010C34, 0x02009800 whatever the C.
- Other lanes' pending files duplicate a matched address: 0x020336A4, 0x0204AC18, 0x0206380C, 0x0206A17C.
