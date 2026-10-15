/*
 * function: RESEARCH_TOP_SetStateTimer
 * address:  0x021BA380
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter, u32 at +0x24.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25819.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_TOP_SetStateTimer(void *p, u32 v)
{
    ((struct Obj25819 *)p)->f24 = v;
}
