/*
 * function: func_021622AC
 * address: 0x021622AC
 * packet: pkt_ov010_021622AC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082D44 0x02082D44 arm
 */
#include "../include/Obj18955.h"
typedef unsigned short u16;
extern void func_02082D44(void *, void *, unsigned);
int func_021622AC(char *p, int index, void *out)
{
    int result = 0;
    if (((struct Obj18955 *)p)->f2 & (1 << (index + 5))) {
        func_02082D44(p + 0x30 + index * 8, out, 8);
        result = 1;
    }
    return result;
}
