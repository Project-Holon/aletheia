/*
 * function: EVENT_FIELDMAP_CONTROL_RunFadeOut
 * address:  0x021BEE74
 * packet:   pkt_ov021_021BEE74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 */
#include "../include/Obj12906.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);

int EVENT_FIELDMAP_CONTROL_RunFadeOut(u32 p0, int *st, u8 *q)
{
    switch (*st) {
    case 0:
        FADE_Start(((struct Obj12906 *)q)->fC, 0, 0x10, 0x10 - 0x11);
        *st = *st + 1;
        break;
    case 1:
        if (((struct Obj12906 *)q)->f14 == 1)
            return 1;
        if (FADE_IsActive() == 0)
            return 1;
        break;
    }
    return 0;
}
