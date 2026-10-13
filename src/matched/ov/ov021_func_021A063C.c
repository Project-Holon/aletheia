/*
 * function: FIELD_LIGHT_StartColorFadeHold
 * address:  0x021A063C
 * packet:   pkt_ov021_021A063C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_LIGHT_FADE_InitHold  0x021A0C60  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19695.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void FIELD_LIGHT_FADE_InitHold(u16 *p, u16 a, u16 b);

void FIELD_LIGHT_StartColorFadeHold(u8 *p, u16 a, u32 b)
{
    FIELD_LIGHT_FADE_InitHold((u16 *)(p + 0x484), b, a);
    ((struct Obj19695 *)p)->f0 = 1;
}
