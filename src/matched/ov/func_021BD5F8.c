/*
 * function: PLACE_NAME_LETTER_SetVisibleRaw
 * address:  0x021BD5F8
 * packet:   pkt_021BD5F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0xc.
 *
 * symbols:
 *   BMP_OAM_SetEnabled  0x02025774  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18235.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BMP_OAM_SetEnabled(u8 *g, unsigned int a);

void PLACE_NAME_LETTER_SetVisibleRaw(void *p, unsigned int a)
{
BMP_OAM_SetEnabled((u8 *)((struct Obj18235 *)p)->fC, a);
}
