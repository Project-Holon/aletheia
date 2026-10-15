/*
 * function: ZUKAN_SEARCH_SCREEN_DeleteBg
 * address: 0x021BC43C
 * packet: pkt_ov211_021BC43C
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned),BG_SYS_SetSubPlaneVisible(unsigned,unsigned),BG_SYS_FreeLayerBuf(unsigned),BG_SYS_Delete(void);
void ZUKAN_SEARCH_SCREEN_DeleteBg(void){BG_SYS_SetMainPlaneVisible(14,0);BG_SYS_SetSubPlaneVisible(10,0);BG_SYS_FreeLayerBuf(5);BG_SYS_FreeLayerBuf(7);BG_SYS_FreeLayerBuf(2);BG_SYS_FreeLayerBuf(1);BG_SYS_FreeLayerBuf(3);BG_SYS_Delete();}
