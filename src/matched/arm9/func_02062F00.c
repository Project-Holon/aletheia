/*
 * function: NNSi_G2dSetCellAnimationCurrentFrame
 * address:  0x02062F00
 * packet:   pkt_02062D4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_G2dSetCellAnimationFrame    0x02062D08  arm
 */
#include "../include/Obj07015.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int NNSi_G2dSetCellAnimationFrame(void *p, u32 i);

int NNSi_G2dSetCellAnimationCurrentFrame(void *s, u32 i)
{
    u32 r = NNSi_G2dSetCellAnimationFrame(s, i);

    if (r != 0) {
        ((struct Obj07015 *)s)->f10 = 0;
    }
    return r;
}
