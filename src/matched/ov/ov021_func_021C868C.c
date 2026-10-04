/*
 * function: func_021C868C
 * address:  0x021C868C
 * packet:   pkt_ov021_021C868C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C87E0  0x021C87E0  thumb  ov021
 *   func_02158768  0x02158768  thumb  ov010
 */
#include "../include/Obj07575.h"

extern int func_021C87E0(char *p);
struct Desc;
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);

int func_021C868C(int a, char *b)
{
    int r4;
    int flag;
    int v;

    if (b == 0) {
        return 0;
    }
    if (((struct Obj07575 *)b)->f1B4 != 0) {
        return 0;
    }
    ((struct Obj07575 *)b)->f4 = ((struct Obj07575 *)b)->f4 + 1;
    v = func_021C87E0(b);
    switch (v) {
    case 1:
        ((struct Obj07575 *)b)->f0 = 1;
        flag = 0;
        break;
    case 2:
        r4 = (int)func_02158768(a, 1, 0, 0x8015);
        flag = 1;
        break;
    default:
        flag = 0;
        break;
    }
    if (flag == 0) {
        r4 = 0;
    }
    return r4;
}
