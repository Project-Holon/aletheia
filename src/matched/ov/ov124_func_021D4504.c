/*
 * function: CG_HELP_ExitDisplay
 * address: 0x021D4504
 * packet: pkt_ov124_021D4504
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
#include "../include/Obj00991.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void func_020403F4(u32);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
void CG_HELP_ExitDisplay(char *p) {CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj00991 *)p)->f4C);CLACT_ExitSystem();func_020403F4(4);func_020403F4(5);func_020403F4(6);func_020403F4(7);BMP_WIN_Exit();BG_SYS_Delete();}
