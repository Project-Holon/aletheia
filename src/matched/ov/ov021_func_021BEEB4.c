/*
 * function: EVENT_FIELDMAP_CONTROL_RunFadeIn
 * address:  0x021BEEB4
 * packet:   pkt_ov021_021BEEB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes  0x021BF564  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_ResetBgAffine  0x021BF584  thumb  ov021
 */
#include "../include/Obj06060.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern void EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes(u32 a);
extern void EVENT_FIELDMAP_CONTROL_ResetBgAffine(u8 *a0);

int EVENT_FIELDMAP_CONTROL_RunFadeIn(u32 p0, int *st, u8 *q)
{
    switch (*st) {
    case 0:
        if (((struct Obj06060 *)q)->f18 != 0) {
            EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes(((struct Obj06060 *)q)->f4);
            EVENT_FIELDMAP_CONTROL_ResetBgAffine((u8 *)(((struct Obj06060 *)q)->f4));
        }
        FADE_Start(((struct Obj06060 *)q)->fC, 0x10, 0, -1);
        *st = *st + 1;
        break;
    case 1:
        if (((struct Obj06060 *)q)->f14 == 1)
            return 1;
        if (FADE_IsActive() == 0)
            return 1;
        break;
    }
    return 0;
}
