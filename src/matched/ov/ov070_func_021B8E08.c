/*
 * function: ITEMMENU_TaskReturnFromQuantity
 * address:  0x021B8E08
 * packet:   pkt_ov070_021B8E08
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_HideQuantityWindows  0x021B7DD0  thumb  ov070
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   ITEMMENU_UpdateSideButtons  0x021BB3F4  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   ITEMMENU_SetCursorActive  0x021B80C4  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskReturnToListFromQuantity  0x021B7CD0  thumb  ov070
 */
#include "../include/Obj00002.h"

extern void ITEMMENU_HideQuantityWindows(unsigned char *p);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
typedef unsigned char  u8;
extern void ITEMMENU_UpdateSideButtons(int p, int mode);
extern u8 func_020355C4(void);
extern void ITEMMENU_SetCursorActive(struct Obj *o, int flag);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskReturnToListFromQuantity(struct Obj *o);

void ITEMMENU_TaskReturnFromQuantity(unsigned char *p)
{
    int f;
    ITEMMENU_HideQuantityWindows(p);
    CLACT_SetActorAutoAnim((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    ITEMMENU_UpdateSideButtons((int)p, 1);
    f = 1;
    if (func_020355C4()) {
        f = 0;
    }
    ITEMMENU_SetCursorActive((struct Obj *)p, f);
    ITEMMENU_SetTask((char *)p, (int)ITEMMENU_TaskReturnToListFromQuantity);
}
