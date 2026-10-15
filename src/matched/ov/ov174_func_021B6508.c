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
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
extern void CLACT_ExitSystem(void),func_020403F4(unsigned),BMP_WIN_Exit(void),BG_SYS_Delete(void);
void LOCAL_TVT_SYS_ExitSystem(unsigned char *p) {CLACT_ExitSystem();func_020403F4(7);func_020403F4(3);func_020403F4(2);func_020403F4(1);func_020403F4(0);BMP_WIN_Exit();BG_SYS_Delete();}
