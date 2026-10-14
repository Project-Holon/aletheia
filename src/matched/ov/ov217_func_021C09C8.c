/*
 * function: RESEARCH_COMMON_GetPreviousScreen
 * address:  0x021C09C8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x30.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25980.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 RESEARCH_COMMON_GetPreviousScreen(void *p)
{
    return ((struct Obj25980 *)p)->f30;
}
