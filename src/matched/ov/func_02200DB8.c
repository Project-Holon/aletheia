/*
 * function: WORLDTRADE_SERVER_ExitBgPlanes
 * address:  0x02200DB8
 * packet:   pkt_02200DB8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_Delete_03F4  0x020403F4  arm

 *
 * Poke channels 2, 1 and 0 in that order.
 */

typedef unsigned int   u32;
extern void BG_SYS_Delete_03F4(u32 i);

void WORLDTRADE_SERVER_ExitBgPlanes(void)
{
    BG_SYS_Delete_03F4(2);
    BG_SYS_Delete_03F4(1);
    BG_SYS_Delete_03F4(0);
}
