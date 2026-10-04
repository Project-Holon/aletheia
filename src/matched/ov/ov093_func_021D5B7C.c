/*
 * function: func_021D5B7C
 * address: 0x021D5B7C
 * packet: pkt_ov093_021D5B7C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: follower 021D5BA4 is already filed in pkt_021D5BA4.
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_021D5B68 0x021D5B68 thumb ov093
 */
#include "../include/Obj00041.h"
typedef unsigned int   u32;
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern int func_021D5B68(void *);
int func_021D5B7C(void *m)
{
    int ok;
    ok = 0;
    if (func_02017E1C(((struct Obj00041 *)m)->f0, 0x4c, 0)) return ok;
    if (func_021D5B68(m) == 0) ok = 1;
    return ok;
}
