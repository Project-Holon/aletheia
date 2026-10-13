/*
 * function: func_02206AF8
 * address:  0x02206AF8
 * packet:   pkt_ov094_02206AF8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj13619.h"

typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void func_02206AF8(char *p)
{
    if (((struct Obj13619 *)p)->f54 != 3 || ((struct Obj13619 *)p)->f58 == 6)
        GFL_USE_PlaySeDefaultVolume(0x555);
}
