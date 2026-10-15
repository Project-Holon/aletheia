/*
 * function: MYSTERY_UTIL_MarkTaskDone
 * address: 0x021DA8B8
 * packet: pkt_ov121_021DA8B8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void MYSTERY_UTIL_MarkTaskDone(u32 *p) { p[1]=1; }
