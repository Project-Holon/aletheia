/*
 * function: func_021BACF4
 * address:  0x021BACF4
 * packet:   pkt_021BACF4
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_SetStereoOutput  0x02005C28  thumb
 */
#include "../include/Obj20645.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void GFL_USE_SetStereoOutput(u32 a);

void func_021BACF4(u8 *p, u32 a, u32 b)
{
    if (((struct Obj20645 *)p)->f4 == 3 || b == 1) {
        if (a == 0) {
            GFL_USE_SetStereoOutput(1);
        } else {
            GFL_USE_SetStereoOutput(0);
        }
    }
}
