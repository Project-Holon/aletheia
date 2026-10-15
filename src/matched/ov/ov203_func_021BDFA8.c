/*
 * function: DEMO3D_GRAPHIC_VBlank
 * address:  0x021BDFA8
 * packet:   pkt_ov203_021BDFA8
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DEMO3D_GRAPHIC_UpdateBg  0x021BE07C  thumb  ov203
 *   DEMO3D_GRAPHIC_VBlankClact  0x021BE0E8  thumb  ov203
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25311.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void DEMO3D_GRAPHIC_UpdateBg(void *a0);
extern void DEMO3D_GRAPHIC_VBlankClact(u8 *);

void DEMO3D_GRAPHIC_VBlank(u32 a, u8 *p)
{
    if (((struct Obj25311 *)p)->f14 == 0) {
        DEMO3D_GRAPHIC_UpdateBg(p);
        DEMO3D_GRAPHIC_VBlankClact(p + 4);
    }
}
