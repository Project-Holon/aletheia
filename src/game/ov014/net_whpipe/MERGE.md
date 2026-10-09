# net_whpipe (ov014)

Round 4 (r4_ov05): 7 parts to 4. One canonical typedef struct W (Ent ent[16], u16 age[16], flag) is now shared by the former p02, p03, p04 (merged, new p02) and p06 (new p04); G_W.h is no longer included. The hidden function func_02177B0C (the 32-byte uncovered block 0x02177B0C..0x02177B2C, writes byte +0xCEC and halfword +0xC6A of the object) closed the old p06|p07 boundary.

Remaining boundaries:
- p01|p02: four linker veneers at 0x0217725C..0x0217727C (real file boundary).
- p02|p03 and p03|p04: the new p03 (func_021777FC, former p05) only matches when g_021797A4 is declared `u8 *`. A struct W *, and even a void * with a cast, moves the register allocation (w and e swap, DIFF). The other parts need the struct W * view.