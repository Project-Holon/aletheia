/*
 * function: BTL_CALC_ActionSetForcedSkip
 * address: 0x021D8444
 * packet: pkt_ov093_021D8444
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
void BTL_CALC_ActionSetForcedSkip(u32 *p) { *p = (*p & ~15) | 7; }
