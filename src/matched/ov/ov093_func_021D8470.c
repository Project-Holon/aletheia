/*
 * function: BTL_CALC_ActionSetRecordError
 * address: 0x021D8470
 * packet: pkt_ov093_021D8470
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void BTL_CALC_ActionSetRecordError(u32 *p) { *p = ((*p & ~15) | 9) & 15; }
