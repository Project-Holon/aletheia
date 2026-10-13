/*
 * function: ITEMMENU_TaskSelectItemFlash
 * address:  0x021B8B7C
 * packet:   pkt_ov070_021B8B7C
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   ITEMMENU_UpdateSlotActorPosition  0x021BB398  thumb  ov070
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *   BLINK_PALANM_Update  0x0202EA40  thumb
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskSelectItem  0x021B7128  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned int   u32;
struct Obj;
extern void func_020061E4(u32 a);
struct CodeIn;
struct Row;
extern void ITEMMENU_UpdateSlotActorPosition(int p, u32 val);
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);
typedef signed int     s32;
extern s32 BLINK_PALANM_Update(struct Row *p);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskSelectItem(struct Obj *o);

void ITEMMENU_TaskSelectItemFlash(int p)
{
    switch (((struct Obj00002 *)p)->f864) {
    case 0:
        func_020061E4(0x54C);
    case 3:
        ITEMMENU_UpdateSlotActorPosition(p, 0);
        ((struct Obj00002 *)p)->f864 += 1;
        return;
    case 1:
    case 4:
    case 6:
        ((struct Obj00002 *)p)->f866 += 1;
        if (((struct Obj00002 *)p)->f866 == 4) {
            ((struct Obj00002 *)p)->f866 = 0;
            ((struct Obj00002 *)p)->f864 += 1;
        }
        return;
    case 2:
    case 5:
        ITEMMENU_UpdateSlotActorPosition(p, 2);
        ((struct Obj00002 *)p)->f864 += 1;
        return;
    case 7:
        ((struct Obj00002 *)p)->f864 = 0;
        ITEMMENU_UpdateSlotActorPosition(p, 1);
        BLINK_PALANM_ResetPhase((struct CodeIn *)(*(int *)&((struct Obj00002 *)p)->f850));
        BLINK_PALANM_Update((struct Row *)(*(int *)&((struct Obj00002 *)p)->f850));
        ITEMMENU_SetTask((char *)p, (int)ITEMMENU_TaskSelectItem);
        return;
    }
}
