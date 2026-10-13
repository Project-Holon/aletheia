/*
 * function: FIELD_FOG_Reflect
 * address:  0x021A0170
 * packet:   pkt_ov021_021A0170
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3X_SetFog  0x0207DC44  arm
 *   G3X_SetFogTable  0x0207DD10  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03581.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void G3X_SetFog(int enable, int fogMode, int fogSlope, int fogOffset);
extern void G3X_SetFogTable(u8 *);

static inline void SetFogColor(u16 color, int alpha)
{
    *(volatile u32 *)0x04000358 = (u32)(color | (alpha << 16));
}

void FIELD_FOG_Reflect(u8 *p, u32 a1, u32 a2, u32 a3)
{
    if (((struct Obj03581 *)p)->f40) {
        G3X_SetFog(p[0], p[1], p[2], ((struct Obj03581 *)p)->f4);
        SetFogColor(((struct Obj03581 *)p)->f8, p[3]);
        G3X_SetFogTable(p + 0xc);
        ((struct Obj03581 *)p)->f40 = 0;
    }
}
