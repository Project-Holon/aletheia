/*
 * function: WORLDTRADE_ADAPTER_CanProceed
 * address:  0x0220252C
 * packet:   pkt_0220252C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *

 * 1 only when the query is clear and the u16 at +0x32 is set.
 */
#include "../include/Obj12247.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct Rec0200AD8C;
extern u16 func_0200AD8C(const struct Rec0200AD8C *p);

u32 WORLDTRADE_ADAPTER_CanProceed(u8 *p)
{
    if (func_0200AD8C((const struct Rec0200AD8C *)(*(u32 *)(((struct Obj12247 *)p)->f0))) == 0) {
        if (((struct Obj12247 *)p)->f32 != 0) {
            return 1;
        }
    }
    return 0;
}
