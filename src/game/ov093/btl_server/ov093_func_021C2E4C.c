/*
 * function: func_021C2E4C
 * address: 0x021C2E4C
 * packet: pkt_ov093_021C2E4C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../../../matched/include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
u32 func_021C2E4C(u8 *p)
{
    if (++((struct Obj00003 *)p)->f778 == 0)
        ((struct Obj00003 *)p)->f778 = 1;
    return ((struct Obj00003 *)p)->f778;
}
