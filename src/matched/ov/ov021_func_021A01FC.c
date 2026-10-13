/*
 * function: FIELD_FOG_FADE_Init
 * address:  0x021A01FC
 * packet:   pkt_ov021_021A01FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_FOG_FadeStart  0x021A0260  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12696.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void FIELD_FOG_FadeStart(u8 *p, u32 a, u32 b, u16 c, u16 d, u16 e);

void FIELD_FOG_FADE_Init(u8 *p, u32 a, u32 b, u32 c)
{
    FIELD_FOG_FadeStart(p + 0x2c, ((struct Obj12696 *)p)->f4, a, p[2], b, c);
}
