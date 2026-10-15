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
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 */
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_FreeLayerBuf(u32 i);
void REPORT_ExitBgs(void) { func_02040588(6,0); func_02040588(5,0); func_02040588(4,0); BG_SYS_FreeLayerBuf(6); BG_SYS_FreeLayerBuf(5); BG_SYS_FreeLayerBuf(4); }
