/*
 * function: CDEMO_SCENE_CmdSetDone
 * address:  0x021B6780
 * packet:   pkt_021B6780
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj14393.h"

int CDEMO_SCENE_CmdSetDone(char *p)
{
    ((struct Obj14393 *)p)->f6050 = 2;
    ((struct Obj14393 *)p)->f6054 = 5;
    return 2;
}
