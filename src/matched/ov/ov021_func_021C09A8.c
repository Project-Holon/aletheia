/*
 * function: EVENT_RECOVERY_SetBallsStep
 * address:  0x021C09A8
 * packet:   pkt_ov021_021C09A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: stores the next state and clears the halfword counter at +0x16.
 *
 * symbols:
 */
#include "../include/Obj20159.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void EVENT_RECOVERY_SetBallsStep(u8 *p, int *st, int v)
{
    *st = v;
    ((struct Obj20159 *)p)->f16 = 0;
}
