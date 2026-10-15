/*
 * function: BEACON_VIEW_FreeBackgrounds
 * address:  0x021F2BD4
 * packet:   pkt_ov032_021F2BD4
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_FreeBackgrounds 0x021F2BD4 thumb
 *   func_02040588 0x02040588 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 */

typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_FreeLayerBuf(unsigned);

void BEACON_VIEW_FreeBackgrounds(char *p)
{
    unsigned short z = 0;

    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
    *(volatile unsigned short *)0x04001050 = z;
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(7);
}
