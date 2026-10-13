/*
 * function: func_02206B30
 * address:  0x02206B30
 * packet:   pkt_ov094_02206B30
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *
 * lane S13 leaf of func_0220648C
 */
#include "../include/Obj00823.h"

typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void func_02206B30(char *p)
{
    if (((struct Obj00823 *)p)->f58 != 6) {
        if (((struct Obj00823 *)p)->f54 != 3) {
            GFL_USE_PlaySeDefaultVolume(0x54d);
        }
    } else {
        GFL_USE_PlaySeDefaultVolume(0x54c);
    }
}
