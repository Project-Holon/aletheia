/*
 * function: BTLV_INPUT_PlayCancelSe
 * address:  0x02206B14
 * packet:   pkt_ov094_02206B14
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
#include "../include/Obj00823.h"

typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void BTLV_INPUT_PlayCancelSe(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        GFL_USE_PlaySeDefaultVolume(0x548);
}
