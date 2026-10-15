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
 *   func_020403F4 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
typedef unsigned int u32;extern void BMP_WIN_Exit(void);extern void func_020403F4(u32);extern void BG_SYS_Delete(void);
void GURU2_MAIN_ExitBg(char *p){BMP_WIN_Exit();func_020403F4(1);func_020403F4(2);func_020403F4(3);func_020403F4(6);func_020403F4(7);BG_SYS_Delete();}
