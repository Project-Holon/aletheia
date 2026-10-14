/*
 * function: MB_COMM_SYS_ExitDisplay
 * address: 0x021EF080
 * packet: pkt_ov107_021EF080
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding follow the return.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 */
#include "../include/Obj00979.h"
struct Bank;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void func_020403F4(unsigned);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
void MB_COMM_SYS_ExitDisplay(char *p) {
 CLACT_DeleteActor(((struct Obj00979 *)p)->f7C);
 CLACT_DeleteUnit(((struct Obj00979 *)p)->f6C);
 CLACT_ExitSystem();
 func_020403F4(0);func_020403F4(1);func_020403F4(2);func_020403F4(3);
 func_020403F4(7);func_020403F4(6);func_020403F4(5);func_020403F4(4);
 BMP_WIN_Exit();func_0203F9B4();
}
