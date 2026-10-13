/*
 * function: REPORT_ExitBgs
 * address: 0x021F01F8
 * packet: pkt_ov034_021F01F8
 * region: ov034
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_020403F4 0x020403F4 arm
 */
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(u32 i);
void REPORT_ExitBgs(void) { func_02040588(6,0); func_02040588(5,0); func_02040588(4,0); func_020403F4(6); func_020403F4(5); func_020403F4(4); }
