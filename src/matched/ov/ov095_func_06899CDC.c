/*
 * function: func_06899CDC
 * address: 0x06899CDC
 * packet: pkt_ov095_06899CDC
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: const source parameter allows pointee load before final byte store;
 *       veneer extent follower, function_starts seed 06899CDC.
 * symbols:
 *   func_0220266C 0x0220266C thumb ov094
 */
#include "../include/Obj07908.h"
typedef signed char s8;
typedef unsigned int u32;
struct Obj;
extern void func_0220266C(struct Obj *p);
void func_06899CDC(const s8 *p)
{
    ((struct Obj07908 *)p)->f8C = -16;
    ((struct Obj07908 *)p)->f8D = 0;
    ((struct Obj07908 *)p)->f8E = 1;
    func_0220266C((struct Obj *)(*(const u32 *)&((struct Obj07908 *)p)->fB0));
}
