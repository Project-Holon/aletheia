/*
 * function: ITEMMENU_TaskWaitMessageThenList
 * address:  0x021B8F0C
 * packet:   pkt_ov070_021B8F0C
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   ITEMMENU_SetCursorActive  0x021B80C4  thumb  ov070
 *   ITEMMENU_RedrawList  0x021B6138  thumb  ov070
 *   ITEMMENU_ClearMessageWindow  0x021BA9AC  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   ITEMMENU_UpdateSideButtons  0x021BB3F4  thumb  ov070
 *   ITEMMENU_ReturnToBagMain  0x021B8AF4  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned int u32;

extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg();
struct Obj;
extern void ITEMMENU_SetCursorActive(struct Obj *o, int flag);
extern void ITEMMENU_RedrawList(char *p);
extern void ITEMMENU_ClearMessageWindow(char *p);
struct Obj;
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void ITEMMENU_UpdateSideButtons(int p, int mode);
extern void ITEMMENU_ReturnToBagMain(void *p);

void ITEMMENU_TaskWaitMessageThenList(int p)
{
    if (func_020362DC() & 3) {
        ITEMMENU_SetCursorActive((struct Obj *)p, 1);
    } else if (TOUCHPANEL_GetTrg()) {
        ITEMMENU_SetCursorActive((struct Obj *)p, 0);
    } else {
        return;
    }
    ((struct Obj00002 *)p)->f818 = 0xFFFF;
    ITEMMENU_RedrawList((char *)p);
    ITEMMENU_ClearMessageWindow((char *)p);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    ITEMMENU_UpdateSideButtons(p, 1);
    ITEMMENU_ReturnToBagMain((void *)p);
}
