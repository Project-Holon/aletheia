/*
 * function: PMS_INPUT_SubHandleConfirm
 * address: 0x021BF53C
 * packet: pkt_ov110_021BF53C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_VIEW_IsIdle 0x021B9C74 thumb ov110
 *   PMS_INPUT_IsComplete 0x021BF680 thumb ov110
 *   PMS_INPUT_SetExitState 0x021BF6CC thumb ov110
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_VIEW_GetMenuResult 0x021BAC0C thumb ov110
 *   PMSI_PARAM_ClearUnusedWords 0x020245AC thumb
 *   PMSI_PARAM_SetResult 0x020241E0 thumb
 *   PMS_INPUT_SetHandler 0x021BD7A0 thumb ov110
 *   PMS_INPUT_HandleFinish 0x021BF4C4 thumb ov110
 *   PMS_INPUT_ClearSubHandler 0x021BF500 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Handler)(u8 *, void *);
struct T245;
struct T241;
extern int PMS_INPUT_VIEW_IsIdle(unsigned int a);
extern int PMS_INPUT_IsComplete(u8 *);
extern void PMS_INPUT_SetExitState(u8 *, u8, u8);
extern void PMS_INPUT_VIEW_StartTask(u8 *, int);
extern int PMS_INPUT_VIEW_GetMenuResult(u8 *p);
struct T;
extern void PMSI_PARAM_ClearUnusedWords(struct T *p, u32 a1);
extern void PMSI_PARAM_SetResult(struct T *p, u16 *a1, u16 *a2);
extern void PMS_INPUT_SetHandler(u8 *, Handler);
extern int PMS_INPUT_HandleFinish(u8 *p, int *q);
extern void PMS_INPUT_ClearSubHandler(u8 *);
void PMS_INPUT_SubHandleConfirm(u8 *p, u32 *q)
{
    switch (*q) {
    case 0:
        if (PMS_INPUT_VIEW_IsIdle((unsigned int)(((struct Obj00012 *)p)->f14))) {
            if (PMS_INPUT_IsComplete(p)) {
                PMS_INPUT_SetExitState(p + 107, 1, 0);
                ((struct Obj00012 *)p)->f48 = 0;
                PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14, 21);
                *q = 1;
            } else *q = 3;
        }
        break;
    case 1:
        switch (PMS_INPUT_VIEW_GetMenuResult(((struct Obj00012 *)p)->f14)) {
        case 0:
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14, 23);
            *q = 3;
            break;
        case 1:
            if (((struct Obj00012 *)p)->f4 == 2) PMSI_PARAM_ClearUnusedWords((struct T *)(p + 8), 42);
            PMSI_PARAM_SetResult((struct T *)(*(struct T241 * *)&((struct Obj00012 *)p)->f0), (u16 *)(p + 16), (u16 *)(p + 8));
            PMS_INPUT_SetHandler(p, (Handler)PMS_INPUT_HandleFinish);
            *q = 3;
            break;
        }
        break;
    case 2:
        if (((struct Obj00012 *)p)->f34 & 243) *q = 3;
        break;
    case 3:
        if (PMS_INPUT_VIEW_IsIdle((unsigned int)(((struct Obj00012 *)p)->f14))) PMS_INPUT_ClearSubHandler(p);
        break;
    }
}
