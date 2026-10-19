/*
 * function: CDEMO_SCENE_CmdSetLayerVisible
 * address:  0x021B67F4
 * packet:   pkt_021B67F4
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_SetPriority  0x0204047C  arm
 */
#include "../include/Obj14396.h"

extern void BG_SYS_SetPriority(int idx, unsigned short val);

int CDEMO_SCENE_CmdSetLayerVisible(int a, int *q)
{
    BG_SYS_SetPriority((unsigned char)((struct Obj14396 *)q)->f4,
                  (unsigned char)((struct Obj14396 *)q)->f8);
    return 1;
}
