/*
 * function: RESEARCH_LIST_ClearKeyRepeatTimer
 * address:  0x021BC608
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clear the u32 at +0x54.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25864.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_LIST_ClearKeyRepeatTimer(void *p)
{
    ((struct Obj25864 *)p)->f54 = 0;
}
