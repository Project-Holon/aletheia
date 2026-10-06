/*
 * function: func_021C76D0
 * address:  0x021C76D0
 * packet:   pkt_ov136_021C76D0
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202616C  0x0202616C  thumb
 *   func_021C66A0 0x021C66A0 thumb
 *   func_021C66CC 0x021C66CC thumb
 */
#include "../include/Obj01066.h"
#include "../include/Obj23663.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_0202616C(void **obj, u32 idx);
extern void func_021C66CC(u8 *, int, int, int);
extern void func_021C66A0(u8 *p, int i, u32 v);
void func_021C76D0(u8 *p, u32 v)
{
    u8 *q = func_0202616C(((struct Obj23663 *)(*(u8 * *)&((struct Obj01066 *)p)->f8))->f294, v);
    func_021C66CC(*(u8 * *)&((struct Obj01066 *)p)->f8, 2, q[0], q[1]);
    if (v == 10) {
        func_021C66A0(*(u8 * *)&((struct Obj01066 *)p)->f8, 2, 4);
    } else {
        func_021C66A0(*(u8 * *)&((struct Obj01066 *)p)->f8, 2, 5);
    }
}
