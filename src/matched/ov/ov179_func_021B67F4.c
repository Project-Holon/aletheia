/*
 * function: CDEMO_SCENE_CmdSetBg
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
 *   BG_SYS_SetVisibleLayer  0x0204047C  arm
 */
#include "../include/Obj14396.h"

extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);

int CDEMO_SCENE_CmdSetBg(int a, int *q)
{
    BG_SYS_SetVisibleLayer((unsigned char)((struct Obj14396 *)q)->f4,
                  (unsigned char)((struct Obj14396 *)q)->f8);
    return 1;
}
