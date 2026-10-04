/*
 * function: func_021EC9D8
 * address: 0x021EC9D8
 * packet: pkt_ov170_021EC9D8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _fadd 0x0209C95C arm
 *   _ffix 0x0209C494 arm
 *   func_0204B5AC 0x0204B5AC arm
 */
#include "../include/Obj04547.h"
extern void func_0204B5AC(void *, int *);
int func_021EC9D8(char *p)
{
    int pair[2];
    ((struct Obj04547 *)p)->f7 -= 2;
    *(float *)(p + 8) += 102.0f;
    *(float *)(p + 8) += 102.0f;
    if ((unsigned char)p[7] == 0)
        return 0;
    pair[0] = (int)*(float *)(p + 8);
    pair[1] = (int)*(float *)(p + 8);
    func_0204B5AC(((struct Obj04547 *)p)->f0, pair);
    return 1;
}
