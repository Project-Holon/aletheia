/*
 * function: EVENT_FIELDMAP_CONTROL_RunSeasonFadeInWithCallback
 * address:  0x021BF0E4
 * packet:   pkt_ov021_021BF0E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EL_SCOREBOARD_StartOnFieldWithCallback  0x021877A8  thumb  ov020
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 */
#include "../include/Obj05067.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Evt;
extern void *EL_SCOREBOARD_StartOnFieldWithCallback(int a, int b, u8 c, u8 d, int e, int f);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

int EVENT_FIELDMAP_CONTROL_RunSeasonFadeInWithCallback(u32 p0, int *st, u8 *q)
{
    u32 a = ((struct Obj05067 *)q)->f0;
    u32 b = ((struct Obj05067 *)q)->f4;

    switch (*st) {
    case 0: {
        u32 r = (u32)EL_SCOREBOARD_StartOnFieldWithCallback(a, b, q[0x20], q[0x21], ((struct Obj05067 *)q)->f24, ((struct Obj05067 *)q)->f28);
        GAME_EVENT_CallEvent((struct Evt *)p0, (struct Evt **)r);
        *st = *st + 1;
        break;
    }
    case 1:
        return 1;
    }
    return 0;
}
