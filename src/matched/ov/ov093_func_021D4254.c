/*
 * function: func_021D4254
 * address: 0x021D4254
 * packet: pkt_ov093_021D4254
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   func_021D4A6C 0x021D4A6C thumb ov093
 *   func_020307B0 0x020307B0 arm
 */
extern void *d_021F3B88;
extern void func_021D4A6C(void);
extern void func_020307B0(void *);
void func_021D4254(void) { if(d_021F3B88) { func_021D4A6C(); func_020307B0(d_021F3B88); } }
