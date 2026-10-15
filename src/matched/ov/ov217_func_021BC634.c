/*
 * function: RESEARCH_LIST_SetHeapId
 * address:  0x021BC634
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter, u16 at +8.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25867.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_LIST_SetHeapId(void *p, u16 v)
{
    ((struct Obj25867 *)p)->f8 = v;
}
