/*
 * function: EVENT_RECOVERY_RunBalls
 * address:  0x021C0844
 * packet:   pkt_ov021_021C0844
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *   EVENT_RECOVERY_PlaceBall  0x021C09B0  thumb  ov021
 *   EVENT_RECOVERY_SetBallsStep  0x021C09A8  thumb  ov021
 *   EVENT_RECOVERY_StartBallsAnime  0x021C0A10  thumb  ov021
 *   EVENT_RECOVERY_FinishBalls  0x021C0A48  thumb  ov021
 *   EVENT_RECOVERY_AreBallsIdle  0x021C0A70  thumb  ov021
 *   EVENT_RECOVERY_DeleteBalls  0x021C0988  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELD_SOUND_SYSTEM_StartPushAndPlayTask  0x02029830  thumb
 *   FIELD_SOUND_SYSTEM_StartPopAndWaitTask  0x02029620  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 */
#include "../include/Obj00707.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void EVENT_RECOVERY_PlaceBall(u8 *p);
extern void EVENT_RECOVERY_SetBallsStep(u8 *p, int *st, int v);
extern void EVENT_RECOVERY_StartBallsAnime(u8 *p);
extern void EVENT_RECOVERY_FinishBalls(u8 *p);
extern int EVENT_RECOVERY_AreBallsIdle(u8 *p);
extern void EVENT_RECOVERY_DeleteBalls(u8 *p);
struct Evt;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *FIELD_SOUND_SYSTEM_StartPushAndPlayTask(void *a, u32 b);
extern void *FIELD_SOUND_SYSTEM_StartPopAndWaitTask(void *a, u32 b, u32 c);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

int EVENT_RECOVERY_RunBalls(u32 a, int *st, u8 *p)
{
    switch (*st) {
    case 0:
        if ((int)((struct Obj00707 *)p)->f16 % 15 == 0) {
            EVENT_RECOVERY_PlaceBall(p);
            if (p[0x14] <= p[0x15]) {
                EVENT_RECOVERY_SetBallsStep(p, st, 1);
            }
        }
        break;
    case 1:
        if (((struct Obj00707 *)p)->f16 > 10) {
            EVENT_RECOVERY_StartBallsAnime(p);
            GAME_EVENT_CallEvent((struct Evt *)a, FIELD_SOUND_SYSTEM_StartPushAndPlayTask(FIELDMAP_GetGameSystem((void *)(((struct Obj00707 *)p)->f4)), 0x514));
            EVENT_RECOVERY_SetBallsStep(p, st, 2);
        }
        break;
    case 2:
        if (EVENT_RECOVERY_AreBallsIdle(p) != 0) {
            EVENT_RECOVERY_FinishBalls(p);
            EVENT_RECOVERY_SetBallsStep(p, st, 3);
        }
        break;
    case 3:
        GAME_EVENT_CallEvent((struct Evt *)a, FIELD_SOUND_SYSTEM_StartPopAndWaitTask(FIELDMAP_GetGameSystem((void *)(((struct Obj00707 *)p)->f4)), 0, 6));
        EVENT_RECOVERY_SetBallsStep(p, st, 4);
        break;
    case 4:
        EVENT_RECOVERY_DeleteBalls(p);
        return 1;
    }
    ((struct Obj00707 *)p)->f16 = ((struct Obj00707 *)p)->f16 + 1;
    return 0;
}
