/*
 * function: HALL_OF_FAME_ExitBackgrounds
 * address: 0x021B6340
 * packet: pkt_ov180_021B6340
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void BG_SYS_FreeLayerBuf(u32);
void HALL_OF_FAME_ExitBackgrounds(void) {BG_SYS_SetMainPlaneVisible(8,0);BG_SYS_SetSubPlaneVisible(8,0);BG_SYS_FreeLayerBuf(7);BG_SYS_FreeLayerBuf(3);}
