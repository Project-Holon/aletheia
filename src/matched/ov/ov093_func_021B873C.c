/*
 * function: BTL_MAIN_GetZukanSeenCount
 * address:  0x021B873C
 * packet:   pkt_021B873C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_SAVE_CountCaughtNational  0x0200CF28  thumb
 */
#include "../include/Obj20961.h"

typedef unsigned short u16;
struct Blk37;
u16 ZUKAN_SAVE_CountCaughtNational(struct Blk37 *p);

typedef unsigned int   u32;
u32 BTL_MAIN_GetZukanSeenCount(char **p)
{
    return ZUKAN_SAVE_CountCaughtNational((struct Blk37 *)(((struct Obj20961 *)(*p))->f68));
}
