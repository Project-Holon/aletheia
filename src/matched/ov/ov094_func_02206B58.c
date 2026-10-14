/*
 * function: BTLV_INPUT_PlayCursorSe
 * address:  0x02206B58
 * packet:   pkt_ov094_02206B58
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
 * lane S13 leaf of BTLV_INPUT_UpdateButtonActors-area callers (BTLV_INPUT_ProcessKeyRepeat)
 */
#include "../include/Obj00823.h"

typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void BTLV_INPUT_PlayCursorSe(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        GFL_USE_PlaySeDefaultVolume(0x552);
}
