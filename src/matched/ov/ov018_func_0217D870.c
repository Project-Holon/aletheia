/*
 * function: INTRUDE_SUBDISP_BgExit
 * address: 0x0217D870
 * packet: pkt_ov018_0217D870
 * region: ov018
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
void INTRUDE_SUBDISP_BgExit(void)
{
    func_02040588(6, 0);
    func_02040588(7, 0);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(7);
}
