/*
 * function: FIELD_FOG_Main
 * address:  0x021A0140
 * packet:   pkt_ov021_021A0140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_FOG_FadeIsRunning  0x021A0250  thumb  ov021
 *   FIELD_FOG_FadeStep  0x021A0280  thumb  ov021
 *   FIELD_FOG_FadeGetOffset  0x021A0290  thumb  ov021
 *   FIELD_FOG_FadeGetSlope  0x021A02A8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09536.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern int FIELD_FOG_FadeIsRunning(u8 *);
extern int FIELD_FOG_FadeStep(u32 a);
extern u32 FIELD_FOG_FadeGetOffset(u8 *);
extern u16 FIELD_FOG_FadeGetSlope(u8 *);

void FIELD_FOG_Main(u8 *p)
{
    if (FIELD_FOG_FadeIsRunning(p + 0x2c)) {
        FIELD_FOG_FadeStep((u32)(p + 0x2c));
        ((struct Obj09536 *)p)->f4 = FIELD_FOG_FadeGetOffset(p + 0x2c);
        p[2] = FIELD_FOG_FadeGetSlope(p + 0x2c);
        ((struct Obj09536 *)p)->f40 = 1;
    }
}
