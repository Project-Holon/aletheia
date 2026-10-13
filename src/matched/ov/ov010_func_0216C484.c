/*
 * function: NAMEIN_SETUP_RunPartyPickEvent
 * address:  0x0216C484
 * packet:   pkt_ov010_0216C484
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj02353.h"

typedef unsigned char  u8;
struct Evt;
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int FIELD_STATUS_CreateFieldCloseEvent(int, int);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02082D44(void *, void *, int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

int NAMEIN_SETUP_RunPartyPickEvent(int a, int *st, int *o)
{
    int x = o[0];
    switch (*st) {
    case 0:
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)x, o[1], 0, 0));
        (*st)++;
        break;
    case 1:
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent(x, o[1]));
        (*st)++;
        break;
    case 2:
        GAME_EVENT_CallEvent((struct Evt *)a, func_02014910((char *)x, o[1], (int)((char *)o + 0x30), (int)((char *)o + 8)));
        (*st)++;
        break;
    case 3:
        GAME_EVENT_CallEvent((struct Evt *)a, FIELD_STATUS_CreateFieldOpenEvent((void *)x));
        (*st)++;
        break;
    case 4:
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)x, o[1], 0, 0, 1, 0, 0));
        func_02082D44((char *)o + 0x79, ((struct Obj02353 *)o)->fD0, 6);
        **(short * *)&((struct Obj02353 *)o)->fCC = o[0x6c / 4];
        **(short * *)&((struct Obj02353 *)o)->fC8 = o[0x70 / 4];
        func_020307B0((void *)o[0x44 / 4]);
        (*st)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}
