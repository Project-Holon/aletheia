/*
 * function: MONOLITH_TOOL_STATS_FreeBackgrounds
 * address: 0x021B8ABC
 * packet: pkt_ov071_021B8ABC
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 */

typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_FreeLayerBuf(unsigned int);
void MONOLITH_TOOL_STATS_FreeBackgrounds(void) { func_02040588(4,0); func_02040588(6,0); BG_SYS_FreeLayerBuf(4); BG_SYS_FreeLayerBuf(6); }
