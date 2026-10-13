/*
 * function: FLDEFF_FISHING_SetAnimeSpeed
 * address:  0x021AE01C
 * packet:   pkt_ov021_021AE01C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectWork  0x021AC1E0  thumb  ov021
 */
#include "../include/Obj12798.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int FIELD_EFFECT_GetObjectWork(u32 a);

void FLDEFF_FISHING_SetAnimeSpeed(u32 a, u16 v)
{
    u8 *p;

    if (a != 0) {
        p = (u8 *)FIELD_EFFECT_GetObjectWork(a);
        ((struct Obj12798 *)p)->f6 = 1;
        ((struct Obj12798 *)p)->f4 = v;
    }
}
