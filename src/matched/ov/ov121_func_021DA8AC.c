/*
 * function: MYSTERY_UTIL_IsTaskDone
 * address: 0x021DA8AC
 * packet: pkt_ov121_021DA8AC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int MYSTERY_UTIL_IsTaskDone(u32 *p) { return p[1]; }
