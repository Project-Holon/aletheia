/*
 * file:     unit_0689A84C.c
 * function: func_0689A84C
 * address: 0x0689A84C
 * packet: pkt_ov095_0689A84C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Callee result remains live on return; extent ends with two-byte alignment padding.
 * symbols:
 *   func_02203040  0x02203040  thumb
 */
#include "../../matched/include/Obj13635.h"
typedef unsigned int u32;
extern int func_02203040(u32);

int func_0689A84C(u32 unused, u32 p)
{
    int result;
    result = func_02203040(((struct Obj13635 *)p)->fB0);
    if (result == 1) {
        ((struct Obj13635 *)p)->f98 = 1;
    }
    return result;
}
