/*
 * function: BTL_POKEPARAM_GetRealMoveId
 * address: 0x021D54D0
 * packet: pkt_ov093_021D54D0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u32 BTL_POKEPARAM_GetRealMoveId(u8 *p, u8 i) { return *(u16 *)((u32)p + i * 14 + 0x104); }
