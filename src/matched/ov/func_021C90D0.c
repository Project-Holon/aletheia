/*
 * function: FLDEFF_D06DENKI_FollowIsEnded
 * address:  0x021C90D0
 * packet:   pkt_021C90D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectWork  0x021AC1E0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18344.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FIELD_EFFECT_GetObjectWork(u32 a);

int FLDEFF_D06DENKI_FollowIsEnded(u32 a, u32 b, u32 c, u32 d)
{
if (a != 0) {
    return ((struct Obj18344 *)((u8 *)(FIELD_EFFECT_GetObjectWork(a))))->f16;
}
return 1;
}

