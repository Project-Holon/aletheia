/*
 * function: BTL_CALC_GetFightersPerSide
 * address: 0x021D7F00
 * packet: pkt_ov093_021D7F00
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u32 BTL_CALC_GetFightersPerSide(u32 n) { switch(n) { case 0:return 1; case 1:return 2; case 2:return 3; case 3:return 1; default:return 1; } }
