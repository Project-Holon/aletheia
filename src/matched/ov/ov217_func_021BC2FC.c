/*
 * function: RESEARCH_LIST_IsScrollAnimDone
 * address:  0x021BC2FC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Compare +0x44 against +0x48, 1 when not greater.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01084.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

int RESEARCH_LIST_IsScrollAnimDone(void *p)
{
    if (((struct Obj01084 *)p)->f44 > ((struct Obj01084 *)p)->f48) {
        return 0;
    }
    return 1;
}
