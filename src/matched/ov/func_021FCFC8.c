/*
 * function: WORLDTRADE_LIST_ExitBgPlanes
 * address:  0x021FCFC8
 * packet:   pkt_021FCFC8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_Delete_03F4  0x020403F4  arm

 *
 * Poke channel 1 then channel 2.
 */

typedef unsigned int   u32;
extern void BG_SYS_Delete_03F4(u32 i);

void WORLDTRADE_LIST_ExitBgPlanes(void)
{
    BG_SYS_Delete_03F4(1);
    BG_SYS_Delete_03F4(2);
}
