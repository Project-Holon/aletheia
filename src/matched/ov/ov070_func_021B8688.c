/*
 * function: ITEMMENU_TaskWaitFadeIn
 * address:  0x021B8688
 * packet:   pkt_ov070_021B8688
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   ITEMMENU_MoveActorToPoint  0x021BB690  thumb  ov070
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   ITEMMENU_ReturnToBagMain  0x021B8AF4  thumb  ov070
 */
#include "../include/Obj20670.h"

typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
extern int ITEMMENU_MoveActorToPoint(const char *p);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *, unsigned int);
extern void ITEMMENU_ReturnToBagMain(void *p);

void ITEMMENU_TaskWaitFadeIn(int p)
{
    int a = WIPE_SYS_EndCheck();
    int b = ITEMMENU_MoveActorToPoint((const char *)p);
    if (a == 1 && b == 0) {
        CLACT_SetActorAutoAnim((struct Obj *)((struct Obj20670 *)p)->f6A8, 1);
        ITEMMENU_ReturnToBagMain((void *)p);
    }
}
