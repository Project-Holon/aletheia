/*
 * function: PMS_WORDLIST_GetScrollDelta
 * address:  0x021BEDE0
 * packet:   pkt_ov110_021BEDE0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Word accessor: p + 8.
 */
#include "../include/Obj22381.h"

typedef unsigned char u8;
typedef unsigned int u32;

u32 PMS_WORDLIST_GetScrollDelta(u8 *p)
{
    return ((struct Obj22381 *)p)->f8;
}
