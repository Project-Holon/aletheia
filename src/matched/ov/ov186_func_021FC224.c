/*
 * function: BR_RES_GetCurrentSetParam
 * address:  0x021FC224
 * packet:   pkt_021FC224
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Extent runs long: 0x021FC230 is an unlabelled follower leaf (a plain
 * `p[0x3e] = v` setter), so this is EXACT*.
 *
 * symbols:
 *   BR_RES_GetSetParam  0x021FC394  thumb  ov186
 */
#include "../include/Obj24832.h"

typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 BR_RES_GetSetParam(u32 n);

int BR_RES_GetCurrentSetParam(char *p)
{
    return BR_RES_GetSetParam(((struct Obj24832 *)p)->fF8);
}
