/*
 * function: ITEMMENU_TaskReopenListFromQuantity
 * address: 0x021B8DCC
 * packet: pkt_ov070_021B8DCC
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ITEMMENU_HideQuantityWindows 0x021B7DD0 thumb ov070
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   ITEMMENU_UpdateSideButtons 0x021BB3F4 thumb ov070
 *   func_020355C4 0x020355C4 arm
 *   ITEMMENU_SetCursorActive 0x021B80C4 thumb ov070
 *   ITEMMENU_ReturnToBagMain 0x021B8AF4 thumb ov070
 */
#include "../include/Obj00002.h"
extern void ITEMMENU_HideQuantityWindows(unsigned char *p);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *object, unsigned int flag);
extern void ITEMMENU_UpdateSideButtons(int p, int mode);
typedef unsigned char  u8;
extern u8 func_020355C4(void);
extern void ITEMMENU_SetCursorActive(struct Obj *o, int flag);
extern void ITEMMENU_ReturnToBagMain(void *p);
void ITEMMENU_TaskReopenListFromQuantity(char *p)
{
    int flag;
    ITEMMENU_HideQuantityWindows((unsigned char *)p);
    CLACT_SetActorAutoAnim((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    ITEMMENU_UpdateSideButtons((int)p, 1);
    flag = 1;
    if (func_020355C4())
        flag = 0;
    ITEMMENU_SetCursorActive((struct Obj *)p, flag);
    ITEMMENU_ReturnToBagMain(p);
}
