/*
 * function: ITEMMENU_TaskStartFadeIn
 * address:  0x021B8640
 * packet:   pkt_ov070_021B8640
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskWaitFadeIn  0x021B8688  thumb  ov070
 */
#include "../include/Obj00002.h"

struct PrintSys;
extern unsigned int PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
typedef unsigned int   u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskWaitFadeIn(int p);

void ITEMMENU_TaskStartFadeIn(int p)
{
    if (PRINTSYS_QUE_IsFinished((const struct PrintSys *)(*(int *)&((struct Obj00002 *)p)->f50C))) {
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, ((struct Obj00002 *)p)->f544);
        GFL_USE_PlaySeDefaultVolume(0x79F);
        ITEMMENU_SetTask((char *)p, (int)ITEMMENU_TaskWaitFadeIn);
    }
}
