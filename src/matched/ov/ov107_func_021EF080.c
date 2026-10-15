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
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
#include "../include/Obj00979.h"
struct Bank;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void BG_SYS_FreeLayerBuf(unsigned);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
void MB_COMM_SYS_ExitDisplay(char *p) {
 CLACT_DeleteActor(((struct Obj00979 *)p)->f7C);
 CLACT_DeleteUnit(((struct Obj00979 *)p)->f6C);
 CLACT_ExitSystem();
 BG_SYS_FreeLayerBuf(0);BG_SYS_FreeLayerBuf(1);BG_SYS_FreeLayerBuf(2);BG_SYS_FreeLayerBuf(3);
 BG_SYS_FreeLayerBuf(7);BG_SYS_FreeLayerBuf(6);BG_SYS_FreeLayerBuf(5);BG_SYS_FreeLayerBuf(4);
 BMP_WIN_Exit();BG_SYS_Delete();
}
