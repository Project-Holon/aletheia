/*
 * function: EVENT_DISAPPEAR_RunSpinZoomEffect
 * address:  0x021C021C
 * packet:   pkt_ov021_021C021C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   EVENT_DISAPPEAR_StartSpinAndEffect  0x021C029C  thumb  ov021
 *   EVENT_DISAPPEAR_StartZoomInAlt  0x021C02F8  thumb  ov021
 *   EVENT_DISAPPEAR_CreateFadeOutAlt  0x021C0374  thumb  ov021
 *   EVENT_DISAPPEAR_EndZoomInAlt  0x021C0360  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 */
#include "../include/Obj05073.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Evt;
extern u32 FIELDMAP_GetTaskManager(u8 *p);
extern void EVENT_DISAPPEAR_StartSpinAndEffect(u8 *p);
extern void EVENT_DISAPPEAR_StartZoomInAlt(u8 *p);
extern int EVENT_DISAPPEAR_CreateFadeOutAlt(u32 *p);
extern int EVENT_DISAPPEAR_EndZoomInAlt(u8 *a);
extern int FIELD_TASK_MANAGER_IsEmpty(u32 a);
extern void func_020061E4(u32 a);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

int EVENT_DISAPPEAR_RunSpinZoomEffect(u32 a, int *st, u8 *p)
{
    int n;

    u32 q;

    q = FIELDMAP_GetTaskManager((u8 *)(((struct Obj05073 *)p)->f4));
    switch (*st) {
    case 0:
        EVENT_DISAPPEAR_StartSpinAndEffect(p);
        EVENT_DISAPPEAR_StartZoomInAlt(p);
        func_020061E4(0x6DF);
        *st = *st + 1;
        break;
    case 1:
        n = ((struct Obj05073 *)p)->f74;
        ((struct Obj05073 *)p)->f74 = n + 1;
        if (n > 0x23) {
            GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_DISAPPEAR_CreateFadeOutAlt((u32 *)p));
            *st = *st + 1;
            break;
        }
    case 2:
        if (FIELD_TASK_MANAGER_IsEmpty(q)) {
            func_020061E4(0x559);
            *st = *st + 1;
        }
        break;
    case 3:
        EVENT_DISAPPEAR_EndZoomInAlt(p);
        return 1;
    }
    return 0;
}
