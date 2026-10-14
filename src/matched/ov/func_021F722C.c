/*
 * function: BTLV_CAMERA_IsMoving
 * address:  0x021F722C
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_CAMERA_IsMoving   0x021F722C  thumb
 *
 * lane O10 candidate
 */
#include "../include/Obj18557.h"

int BTLV_CAMERA_IsMoving(char *p)
{
    return ((struct Obj18557 *)p)->f14 != 0;
}

