/*
 * function: func_021D4270
 * address: 0x021D4270
 * packet: pkt_ov093_021D4270
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   func_0200FB24 0x0200FB24 thumb
 */
extern void *d_021F3B88;
typedef unsigned int   u32;
extern u32 func_0200FB24(void);
int func_021D4270(void) { if(d_021F3B88) { if(func_0200FB24()) return 1; return 0; } return 0; }
