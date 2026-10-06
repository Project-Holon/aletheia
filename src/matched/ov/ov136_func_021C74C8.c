/*
 * function: func_021C74C8
 * address:  0x021C74C8
 * packet:   pkt_ov136_021C74C8
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
#include "../include/Obj14197.h"
#include "../include/Obj14198.h"

typedef unsigned char u8;
typedef unsigned int u32;
struct Bf7 {
    u8 v : 7;
    u8 w : 1;
};
extern u32 func_020307B0(void *p);
int func_021C74C8(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj14197 *)p)->f10;
    ((struct Bf7 *)(p + 0x21))->v = ((struct Obj14198 *)q)->f3C;
    p[0x20] = ((struct Obj14198 *)q)->f40;
    func_020307B0(q);
    return 0;
}
