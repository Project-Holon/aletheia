/*
 * function: func_021BDCC0
 * address:  0x021BDCC0
 * packet:   pkt_ov091_021BDCC0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017F90  0x02017F90  thumb
 *   func_02011400  0x02011400  thumb
 *   func_0203F4CC  0x0203F4CC  arm
 */
#include "../include/Obj00009.h"
#include "../include/Obj20929.h"
#include "../include/Obj20930.h"

typedef unsigned int u32;
typedef unsigned char u8;

extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017F90(void *p);
extern u8 func_02011400(int row, int col);
struct RtcTime;
extern void func_0203F4CC(struct RtcTime *time);

int func_021BDCC0(char *p, u32 a1)
{
    u32 t[3];
    u32 lo, hi;
    int r = 0;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 5, 0) != 0x1EC)
        return r;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 0x6F, r) != 0)
        return r;
    if (func_02017E1C(((struct Obj00009 *)p)->f38, 0x6D, r) != 1)
        return r;
    if (func_02017F90(((struct Obj00009 *)p)->f38) & 0x20)
        return r;
    lo = func_02011400(((struct Obj20929 *)(*(char * *)&((struct Obj00009 *)p)->f280))->f5F, r);
    hi = func_02011400(((struct Obj20930 *)(*(char * *)&((struct Obj00009 *)p)->f280))->f5F, 3);
    func_0203F4CC((struct RtcTime *)t);
    if (t[0] < lo || t[0] >= hi)
        return 0;
    return 1;
}
