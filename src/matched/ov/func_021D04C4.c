/*
 * function: FLDEFF_HIDE_IsFinished
 * address:  0x021D04C4
 * packet:   pkt_021D04C4
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
#include "../include/Obj18369.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FIELD_EFFECT_GetObjectWork(u32 a);

int FLDEFF_HIDE_IsFinished(u32 a)
{
if (a != 0) {
    return ((struct Obj18369 *)((u8 *)(FIELD_EFFECT_GetObjectWork(a))))->f1C;
}
return 1;
}

