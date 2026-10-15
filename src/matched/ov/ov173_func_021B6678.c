/*
 * function: POKE_SUMMARY_MAIN_ExitDisplay
 * address: 0x021B6678
 * packet: pkt_ov173_021B6678
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B66A8 reads and 021B66AE writes hardware halfword.
 * symbols:
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
typedef unsigned int   u32;
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_FreeLayerBuf(unsigned int);
extern void BG_SYS_Delete(void);
void POKE_SUMMARY_MAIN_ExitDisplay(void)
{
    BG_SYS_SetSubPlaneVisible(29, 0);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    *(volatile unsigned short *)0x04000304 |= 0x8000;
    BG_SYS_Delete();
}
