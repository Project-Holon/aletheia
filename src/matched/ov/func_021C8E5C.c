/*
 * function: FIELD_TILE_MOVE_SlideStopLoopSe
 * address:  0x021C8E5C
 * packet:   pkt_021C8E5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x24.
 *
 * symbols:
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18343.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void GFL_USE_StopSeSlot(int i);

void FIELD_TILE_MOVE_SlideStopLoopSe(int *p)
{
    GFL_USE_StopSeSlot(((struct Obj18343 *)p)->f24);
}
