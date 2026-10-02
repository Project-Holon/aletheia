/*
 * function: func_021D4230
 * address: 0x021D4230
 * packet: pkt_ov093_021D4230
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   func_021D4B18 0x021D4B18 thumb ov093
 */
extern void *d_021F3B88;
extern int func_021D4B18(int);
int func_021D4230(void) { int r; if(d_021F3B88) { r=1; if(func_021D4B18(1)==0) r=0; return r; } return 1; }
