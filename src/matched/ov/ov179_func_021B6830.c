/*
 * function: CDEMO_SCENE_CmdSetBlend2
 * address:  0x021B6830
 * packet:   pkt_ov179_021B6830
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B6831 at 0x021B6A68).
 */
#include "../include/Obj08295.h"
int CDEMO_SCENE_CmdSetBlend2(char *p, int *q)
{
    ((struct Obj08295 *)p)->f6034 = q[1];
    ((struct Obj08295 *)p)->f6038 = q[2];
    ((struct Obj08295 *)p)->f6050 = 3;
    ((struct Obj08295 *)p)->f6054 = 5;
    return 2;
}
