/*
 * function: func_021EC994
 * address: 0x021EC994
 * packet: pkt_ov170_021EC994
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_0204B5AC 0x0204B5AC arm
 */
#include "../include/Obj05439.h"
extern void func_0204B5AC(void *, int *);
int func_021EC994(char *p)
{
    int pair[2];
    (((struct Obj05439 *)p)->f7)++;
    *(float *)(p + 8) -= 102.0f;
    if ((unsigned char)p[7] == 40)
        return 0;
    pair[0] = (int)*(float *)(p + 8);
    pair[1] = (int)*(float *)(p + 8);
    func_0204B5AC(((struct Obj05439 *)p)->f0, pair);
    return 1;
}
