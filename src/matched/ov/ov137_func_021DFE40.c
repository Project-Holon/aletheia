/*
 * function: GURU2_MAIN_ExitBg
 * address: 0x021DFE40
 * packet: pkt_ov137_021DFE40
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
typedef unsigned int u32;extern void BMP_WIN_Exit(void);extern void BG_SYS_FreeLayerBuf(u32);extern void BG_SYS_Delete(void);
void GURU2_MAIN_ExitBg(char *p){BMP_WIN_Exit();BG_SYS_FreeLayerBuf(1);BG_SYS_FreeLayerBuf(2);BG_SYS_FreeLayerBuf(3);BG_SYS_FreeLayerBuf(6);BG_SYS_FreeLayerBuf(7);BG_SYS_Delete();}
