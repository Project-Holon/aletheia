/*
 * function: func_021BD534
 * address: 0x021BD534
 * packet: pkt_ov110_021BD534
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: unlabelled substantial switch leaf at 0x021BD578, excluded.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 *   func_0203633C 0x0203633C arm
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   func_02030D28 0x02030D28 arm
 */
#include "../include/Obj05294.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern unsigned int func_0203633C(void);
typedef signed int     s32;
struct Ctx;
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
extern void func_02030D28(struct Ctx *c);
int func_021BD534(void *a,int b,int c,u8 *p) {
    int result;
    int x;
    x=func_020362DC(); ((struct Obj05294 *)p)->f34=x;
    x=func_0203630C(); ((struct Obj05294 *)p)->f36=x;
    x=func_0203633C(); ((struct Obj05294 *)p)->f38=x;
    BUTTON_MAN_UpdateSlots(((struct Obj05294 *)p)->f44);
    if (*(void (**)(u8 *,void *))(p+0x30)) {
        (*(void (**)(u8 *,void *))(p+0x30))(p,p+0x2c);
        result=0;
    } else result=(*(int (**)(u8 *,void *))(p+0x24))(p,p+0x20);
    func_02030D28(((struct Obj05294 *)p)->f7C);
    return result;
}
