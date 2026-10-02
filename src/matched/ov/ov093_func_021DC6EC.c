/*
 * function: func_021DC6EC
 * address: 0x021DC6EC
 * packet: pkt_ov093_021DC6EC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: 12-byte store/return follower after non-C veneer 021DC6DC.
 * symbols:
 *   d_021F0990 0x021F0990 data a4
 */
extern unsigned char d_021F0990[];
void *func_021DC6EC(int *p) { *p = 2; return d_021F0990; }
