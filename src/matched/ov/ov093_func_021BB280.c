/*
 * function: BTL_SERVER_StepSelectEnding
 * address:  0x021BB280
 * packet:   pkt_ov093_021BB280
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B917C  0x021B917C  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   BTL_MAIN_GetCompetitor  0x021B86B8  thumb  ov093
 *   BTL_MAIN_GetWinBgm  0x021B86DC  thumb  ov093
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   BTL_SERVER_SetHandler  0x021BABEC  thumb  ov093
 *   BTL_SERVER_StepWaitEnd  0x021BB320  thumb  ov093
 *   BTL_SERVER_StepSendWildWin  0x021BB368  thumb  ov093
 *   BTL_SERVER_StepSendWildLoseOrDraw  0x021BB3B0  thumb  ov093
 *   BTL_SERVER_StepSendCommResult  0x021BB3F8  thumb  ov093
 *   BTL_SERVER_StepSendTrainerResult  0x021BB43C  thumb  ov093
 *   BTL_SERVER_StepSendSubwayResult  0x021BB484  thumb  ov093
 */
#include "../include/Obj05188.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021B917C(char *p);
extern u8 func_021B8FF4(u8 *);
extern void *BTL_MAIN_GetCompetitor(void ***);
extern u16 BTL_MAIN_GetWinBgm(void **);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
extern void BTL_SERVER_SetHandler(int *p, void *f);
extern int BTL_SERVER_StepWaitEnd(u8 *, int *);
extern int BTL_SERVER_StepSendWildWin(u8 *, int *);
extern int BTL_SERVER_StepSendWildLoseOrDraw(u8 *, int *);
extern int BTL_SERVER_StepSendCommResult(u8 *, int *);
extern int BTL_SERVER_StepSendTrainerResult(u8 *, int *);
extern int BTL_SERVER_StepSendSubwayResult(u8 *, int *);

int BTL_SERVER_StepSelectEnding(u8 *p)
{
    int r5 = func_021B917C((char *)(*(u8 * *)&((struct Obj05188 *)p)->fC));

    ((struct Obj05188 *)p)->fAA = r5;
    ((struct Obj05188 *)p)->fA8 = func_021B8FF4(*(u8 * *)&((struct Obj05188 *)p)->fC);

    switch ((int)BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj05188 *)p)->fC)) {
    case 1:
        BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepSendTrainerResult);
        break;
    case 2:
        BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepSendSubwayResult);
        break;
    case 3:
        BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepSendCommResult);
        break;
    case 0:
        if (r5 == 1) {
            BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepSendWildWin);
        } else if (r5 == 0 || r5 == 2) {
            BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepSendWildLoseOrDraw);
        } else {
            BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepWaitEnd);
        }
        break;
    default:
        if (r5 == 1) {
            GFL_USE_CancelChangeAndPlayBgm(BTL_MAIN_GetWinBgm(*(void ** *)&((struct Obj05188 *)p)->fC), 0xffff);
        }
        BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepWaitEnd);
        break;
    }
    return 0;
}
