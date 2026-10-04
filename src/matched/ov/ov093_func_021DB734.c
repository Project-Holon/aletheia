/*
 * function: func_021DB734
 * address:  0x021DB734
 * packet:   pkt_ov093_021DB734
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
#include "../include/Obj13478.h"

extern int func_021D775C(int);
typedef unsigned int   u32;
extern int func_021D76BC(int key, u32 val);

void func_021DB734(int a, int b, int c, int d)
{
    if (c == func_021D775C(2)) {
        unsigned short t = (unsigned short)func_021D775C(0x12);
        ((struct Obj13478 *)d)->f8 = 0;
        if (t == 0x16b && c == func_021D775C(2))
            ((struct Obj13478 *)d)->f8 = func_021D76BC(0x22, 0x13);
    }
}
