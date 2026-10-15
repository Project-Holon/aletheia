/*
 * function: RESEARCH_TOP_SetMode
 * address:  0x021BA1CC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Field setter, u32 at +0x8c.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25814.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_TOP_SetMode(void *p, u32 v)
{
    ((struct Obj25814 *)p)->f8C = v;
}
