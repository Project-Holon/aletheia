/*
 * function: func_021C85B8
 * address: 0x021C85B8
 * packet: pkt_ov093_021C85B8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C85D4 0x021C85D4 thumb ov093
 */
#include "../include/Obj00294.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C85D4(u8 *, int, int);
void func_021C85B8(u8 *p)
{
    if (((struct Obj00294 *)p)->f1A64 != 0) {
        --((struct Obj00294 *)p)->f1A64;
        func_021C85D4(p, ((struct Obj00294 *)p)->f1A64, 0);
    }
}
