/*
 * function: MB_SEQ_FreeBgs
 * address: 0x021C5714
 * packet: pkt_ov136_021C5714
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MB_SEQ_FreeBgs 0x021C5714 thumb
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
typedef unsigned int u32;
extern void BG_SYS_FreeLayerBuf(u32 bgId);
extern void BG_SYS_Delete(void);

void MB_SEQ_FreeBgs(void *a0)
{
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_Delete();
}
