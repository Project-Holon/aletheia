/*
 * function: FIELD_CAMERA_SetG3dUp
 * address:  0x0218ED14
 * packet:   pkt_ov021_0218ED14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call leaf: forwards field 0xc and the second argument.
 *
 * symbols:
 *   G3D_CAMERA_SetTarget  0x02048B20  arm
 */
#include "../include/Obj19564.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void G3D_CAMERA_SetTarget(u32 a, u32 b);

void FIELD_CAMERA_SetG3dUp(u8 *p, u32 q)
{
    G3D_CAMERA_SetTarget(((struct Obj19564 *)p)->fC, q);
}
