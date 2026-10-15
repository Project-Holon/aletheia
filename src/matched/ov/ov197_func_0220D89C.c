/*
 * function: B_BAG_MAIN_PlaySe
 * address:  0x0220D89C
 * packet:   pkt_0220D89C
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj25118.h"

typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void B_BAG_MAIN_PlaySe(char **a, int b)
{
    if (((struct Obj25118 *)(*a))->f40 == 1)
        GFL_USE_PlaySeDefaultVolume(b);
}