/*
 * function: RESEARCH_LIST_GetEntryCount
 * address:  0x021BC6DC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Field getter, u8 at +0x30.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25871.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 RESEARCH_LIST_GetEntryCount(void *p)
{
    return ((struct Obj25871 *)p)->f30;
}
