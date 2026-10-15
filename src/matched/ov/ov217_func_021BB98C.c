/*
 * function: RESEARCH_LIST_GetSubState
 * address:  0x021BB98C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x20.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25850.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 RESEARCH_LIST_GetSubState(void *p)
{
    return ((struct Obj25850 *)p)->f20;
}
