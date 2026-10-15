/*
 * function: TALKMSGWIN_ProjectToWorld
 * address:  0x02194E74
 * packet:   pkt_02194E74
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
 *   NNS_G3dWorldPosToScrPos  0x0206DF3C  arm
 *   NNS_G3dScrPosToWorldLine  0x0206E0C4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17945.h"
#include "../include/Obj17946.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 NNS_G3dWorldPosToScrPos(u32, u32, u32, u32);
extern u32 NNS_G3dScrPosToWorldLine(u32, u32, u32, u32);

int TALKMSGWIN_ProjectToWorld(u32 a, u32 b, u32 c, u32 d)
{
NNS_G3dWorldPosToScrPos(a, b, c, d);
return NNS_G3dScrPosToWorldLine(((struct Obj17945 *)((u8 *)(b)))->f0, ((struct Obj17946 *)((u8 *)(c)))->f0, d, 0);
}

