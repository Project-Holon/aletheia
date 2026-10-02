/*
 * function: func_021D845C
 * address: 0x021D845C
 * packet: pkt_ov093_021D845C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * follower: Two zero alignment bytes.
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
void func_021D845C(u32 *p) { *p = ((*p & ~15) | 8) & 15; }
