/*
 * function: func_0220D8B0
 * address:  0x0220D8B0
 * packet:   pkt_0220D8B0
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
#include "../include/Obj25120.h"

typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void func_0220D8B0(char **a, int b)
{
    if (((struct Obj25120 *)(*a))->f40 == 1)
        GFL_USE_PlaySeDefaultVolume(b);
}