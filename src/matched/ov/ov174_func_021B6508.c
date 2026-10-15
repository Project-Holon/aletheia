/*
 * function: LOCAL_TVT_SYS_ExitSystem
 * address: 0x021B6508
 * packet: pkt_ov174_021B6508
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
extern void CLACT_ExitSystem(void),BG_SYS_FreeLayerBuf(unsigned),BMP_WIN_Exit(void),BG_SYS_Delete(void);
void LOCAL_TVT_SYS_ExitSystem(unsigned char *p) {CLACT_ExitSystem();BG_SYS_FreeLayerBuf(7);BG_SYS_FreeLayerBuf(3);BG_SYS_FreeLayerBuf(2);BG_SYS_FreeLayerBuf(1);BG_SYS_FreeLayerBuf(0);BMP_WIN_Exit();BG_SYS_Delete();}
