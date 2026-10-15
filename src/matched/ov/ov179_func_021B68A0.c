/*
 * function: CDEMO_SCENE_CmdReset
 * address:  0x021B68A0
 * packet:   pkt_ov179_021B68A0
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B68A1 at 0x021B6A88).
 */
#include "../include/Obj03875.h"
int CDEMO_SCENE_CmdReset(char *p)
{
    ((struct Obj03875 *)p)->f603C = 0;
    ((struct Obj03875 *)p)->f603E = 0;
    ((struct Obj03875 *)p)->f603F = 0;
    ((struct Obj03875 *)p)->f6040 = 0;
    ((struct Obj03875 *)p)->f6044 = 0;
    ((struct Obj03875 *)p)->f6048 = 0;
    ((struct Obj03875 *)p)->f604C = 0;
    ((struct Obj03875 *)p)->f6050 = 4;
    return 2;
}
