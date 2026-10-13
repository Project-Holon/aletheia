/*
 * function: FLDEFF_NAMIPOKE_SPLASH_IsFinished
 * address:  0x021AD5CC
 * packet:   pkt_021AD5CC
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
#include "../include/Obj18088.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FIELD_EFFECT_GetObjectWork(u32 a);

int FLDEFF_NAMIPOKE_SPLASH_IsFinished(u32 a)
{
if (a != 0) {
    return ((struct Obj18088 *)((u8 *)(FIELD_EFFECT_GetObjectWork(a))))->fC;
}
return 1;
}

