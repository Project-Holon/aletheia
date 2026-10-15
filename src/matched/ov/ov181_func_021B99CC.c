/*
 * function: STAFF_ROLL_TeardownBackgrounds
 * address: 0x021B99CC
 * packet: pkt_ov181_021B99CC
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 0x021B99F6.
 * symbols:
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned),BG_SYS_SetSubPlaneVisible(unsigned,unsigned),BG_SYS_FreeLayerBuf(unsigned),BG_SYS_Delete(void);
void STAFF_ROLL_TeardownBackgrounds(void){BG_SYS_SetMainPlaneVisible(2,0);BG_SYS_SetSubPlaneVisible(2,0);BG_SYS_FreeLayerBuf(5);BG_SYS_FreeLayerBuf(3);BG_SYS_FreeLayerBuf(1);BG_SYS_Delete();}
