/*
 * function: POKETRADE_SAVE_ResetClactAndBeginEvent
 * address:  0x021DFDA0
 * packet:   pkt_ov119_021DFDA0
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   POKETRADE_2D_InitClactSystemSub  0x021E3E60  thumb  ov119
 *   CLACT_CreateUnit  0x0204B100  arm
 *   POKETRADE_SAVE_PopBgmFadeIn60  0x021DFD3C  thumb  ov119
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_PROC_StepBeginWipeOut  0x021D9434  thumb  ov119
 *   POKETRADE_SAVE_CreateMessageResources  0x021E10D8  thumb  ov119
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   POKETRADE_SAVE_StepEventMessage1  0x021DFE48  thumb  ov119
 *
 * Slot-state teardown/rebuild, dispatched on *(p+0x118c): 5 and 6 run the
 * shared +8 slot teardown and hand POKETRADE_PROC_SetStep either POKETRADE_PROC_StepBeginWipeOut or
 * NULL; the default path increments the +0x11f8 byte and hands
 * POKETRADE_SAVE_StepEventMessage1. Target of func_021D6C78's ABS32 callback argument (ov119).
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00906.h"
#include "../include/Obj22751.h"
#include "../include/Obj22752.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void POKETRADE_2D_InitClactSystemSub(void *);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void POKETRADE_SAVE_PopBgmFadeIn60(void *);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_PROC_StepBeginWipeOut(void *p);
extern void POKETRADE_SAVE_CreateMessageResources(char *p);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_FadeOutBgm(u32 a);
extern void POKETRADE_SAVE_StepEventMessage1(char *p);

void POKETRADE_SAVE_ResetClactAndBeginEvent(void *p)
{
    u8 *b = p;
    int st;

    CLACT_DeleteUnit(((struct Obj00906 *)b)->f9C4);
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemSub(p);
    ((struct Obj00906 *)b)->f9C4 = CLACT_CreateUnit(0x154, 0, ((struct Obj00906 *)b)->f5F4);
    st = ((struct Obj00906 *)b)->f118C;
    if (st == 5) {
        POKETRADE_SAVE_PopBgmFadeIn60(p);
        ((struct Obj22751 *)(*(int * *)&((struct Obj00906 *)b)->f8))->f8 = 3;
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepBeginWipeOut);
    } else if (st == 6) {
        POKETRADE_SAVE_PopBgmFadeIn60(p);
        ((struct Obj22752 *)(*(int * *)&((struct Obj00906 *)b)->f8))->f8 = 3;
        POKETRADE_PROC_SetStep(p, 0);
    } else {
        POKETRADE_SAVE_CreateMessageResources(p);
        GFL_USE_SetBgmPlayerParam((void *)1);
        GFL_USE_PushBgm();
        (((struct Obj00906 *)b)->f11F8)++;
        GFL_USE_FadeOutBgm(6);
        ((struct Obj00906 *)b)->fF2C = 0;
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepEventMessage1);
    }
}
