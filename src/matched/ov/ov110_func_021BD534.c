/*
 * function: PMS_INPUT_ProcMain
 * address: 0x021BD534
 * packet: pkt_ov110_021BD534
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: unlabelled substantial switch leaf at 0x021BD578, excluded.
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetCont 0x0203630C arm
 *   KEY_GetRepeat 0x0203633C arm
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   func_02030D28 0x02030D28 arm
 */
#include "../include/Obj05294.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern unsigned int KEY_GetRepeat(void);
typedef signed int     s32;
struct Ctx;
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
extern void func_02030D28(struct Ctx *c);
int PMS_INPUT_ProcMain(void *a,int b,int c,u8 *p) {
    int result;
    int x;
    x=KEY_GetTrg(); ((struct Obj05294 *)p)->f34=x;
    x=KEY_GetCont(); ((struct Obj05294 *)p)->f36=x;
    x=KEY_GetRepeat(); ((struct Obj05294 *)p)->f38=x;
    BUTTON_MAN_UpdateSlots(((struct Obj05294 *)p)->f44);
    if (*(void (**)(u8 *,void *))(p+0x30)) {
        (*(void (**)(u8 *,void *))(p+0x30))(p,p+0x2c);
        result=0;
    } else result=(*(int (**)(u8 *,void *))(p+0x24))(p,p+0x20);
    func_02030D28(((struct Obj05294 *)p)->f7C);
    return result;
}
