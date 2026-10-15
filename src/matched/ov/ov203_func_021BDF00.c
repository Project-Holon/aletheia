/*
 * function: DEMO3D_GRAPHIC_Draw
 * address:  0x021BDF00
 * packet:   pkt_021BDF00
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DEMO3D_GRAPHIC_DrawClact  0x021BE0E0  thumb  ov203
 *   DEMO3D_GRAPHIC_Noop  0x021BE078  thumb  ov203
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25309.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void DEMO3D_GRAPHIC_DrawClact(void *a0);
extern void DEMO3D_GRAPHIC_Noop(void *a0);

void DEMO3D_GRAPHIC_Draw(u8 *p)
{
    if (((struct Obj25309 *)p)->f14 == 0) {
        DEMO3D_GRAPHIC_DrawClact(p + 4);
        DEMO3D_GRAPHIC_Noop(p);
    }
}

