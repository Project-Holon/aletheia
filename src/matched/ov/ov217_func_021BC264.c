/*
 * function: RESEARCH_LIST_IsMomentumActive
 * address:  0x021BC264
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Flag test: nonzero u32 at +0x4c as 1/0.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25855.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

int RESEARCH_LIST_IsMomentumActive(void *p)
{
    if (((struct Obj25855 *)p)->f4C != 0) {
        return 1;
    }
    return 0;
}
