/*
 * function: PMS_SELECT_GRAPHIC_DeleteScene
 * address: 0x021C16B0
 * packet: pkt_ov110_021C16B0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 re-read at 021C16D6 and 021C16E0.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   PMS_SELECT_GRAPHIC_ExitSceneActors 0x021C181C thumb ov110
 *   PMS_SELECT_GRAPHIC_ExitSceneBgs 0x021C1798 thumb ov110
 *   func_0201DD68 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj22415.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void PMS_SELECT_GRAPHIC_ExitSceneActors(void **p);
extern void PMS_SELECT_GRAPHIC_ExitSceneBgs(void *);
extern void func_0201DD68(void);
extern void MI_CpuFill8(void *,int,unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void PMS_SELECT_GRAPHIC_DeleteScene(u8 *p) {
    func_02030EAC(((struct Obj22415 *)p)->fC);
    PMS_SELECT_GRAPHIC_ExitSceneActors((void **)(p+4));
    PMS_SELECT_GRAPHIC_ExitSceneBgs(p);
    func_0201DD68();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p,0,16);
    func_020307B0(p);
}
