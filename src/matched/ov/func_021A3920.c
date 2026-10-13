/*
 * function: FIELD_PLAYER_CORE_GetDirDisp
 * address:  0x021A3920
 * packet:   pkt_021A3810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x1c.
 *
 * symbols:
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18033.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 FLDMMDL_GetDirDisp(u32);

u16 FIELD_PLAYER_CORE_GetDirDisp(u8 *p)
{
    return FLDMMDL_GetDirDisp(((struct Obj18033 *)p)->f1C);
}
