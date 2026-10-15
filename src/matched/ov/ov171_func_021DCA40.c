/*
 * function: DENDOU_VIEW_ExitBgs
 * address: 0x021DCA40
 * packet: pkt_ov171_021DCA40
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned),BG_SYS_SetSubPlaneVisible(unsigned,unsigned);
extern void BG_SYS_FreeLayerBuf(unsigned),BG_SYS_Delete(void);
void DENDOU_VIEW_ExitBgs(void){BG_SYS_SetMainPlaneVisible(15,0);BG_SYS_SetSubPlaneVisible(3,0);BG_SYS_FreeLayerBuf(5);BG_SYS_FreeLayerBuf(4);BG_SYS_FreeLayerBuf(3);BG_SYS_FreeLayerBuf(2);BG_SYS_FreeLayerBuf(1);BG_SYS_FreeLayerBuf(0);BG_SYS_Delete();}
