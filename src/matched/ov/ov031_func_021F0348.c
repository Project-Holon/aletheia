/*
 * function: UNION_SUBDISP_ExitBgs
 * address: 0x021F0348
 * packet: pkt_ov031_021F0348
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   func_02040588 0x02040588 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 */
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_FreeLayerBuf(unsigned int);
void UNION_SUBDISP_ExitBgs(void *p)
{
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(7);
}
