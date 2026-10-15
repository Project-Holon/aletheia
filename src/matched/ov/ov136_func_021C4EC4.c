/*
 * function: MAILVIEW_FreeBgs
 * address:  0x021C4EC4
 * packet:   pkt_ov136_021C4EC4
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MAILVIEW_FreeBgs 0x021C4EC4 thumb
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 */
typedef unsigned int   u32;
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BG_SYS_SetLcdSwap(u32 swap);
void MAILVIEW_FreeBgs(void *p)
{
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_SetLcdSwap(1);
}
