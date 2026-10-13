/*
 * function: func_021BA9D0
 * address:  0x021BA9D0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021BA9D0  0x021BA9D0  thumb  ov217
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10955.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern u32 CLACT_ReleaseCellAnim();
u32 func_021BA9D0(u32 a0)
{
    CLACT_ReleaseCharacter(((struct Obj10955 *)(((u8*)a0)))->f5C);
    CLACT_ReleasePalette(((struct Obj10955 *)(((u8*)a0)))->f60);
    return CLACT_ReleaseCellAnim(((struct Obj10955 *)(((u8*)a0)))->f64);
}

