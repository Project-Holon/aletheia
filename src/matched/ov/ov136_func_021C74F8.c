/*
 * function: func_021C74F8
 * address:  0x021C74F8
 * packet:   pkt_ov136_021C74F8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0            0x020307B0  arm
 */
#include "../include/Obj23652.h"

typedef unsigned char u8;
extern void func_020307B0(void *);
int func_021C74F8(u8 *p)
{
    func_020307B0(((struct Obj23652 *)p)->f10);
    return 8;
}
