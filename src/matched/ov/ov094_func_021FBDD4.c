/*
 * function: func_021FBDD4
 * address:  0x021FBDD4
 * packet:   pkt_ov094_021FBDD4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_Jump  0x020113B0  thumb
 */
#include "../include/Obj21678.h"
typedef unsigned int   u32;
struct Cur;
extern void VM_Jump(struct Cur *c, u32 v);

void func_021FBDD4(int a, int b, int c, int op, int e)
{
    int t = 0;

    switch (op) {
    case 0:
        if (b == c)
            t = 1;
        break;
    case 1:
        if (b != c)
            t = 1;
        break;
    case 2:
        if (b < c)
            t = 1;
        break;
    case 3:
        if (b > c)
            t = 1;
        break;
    case 4:
        if (b <= c)
            t = 1;
        break;
    case 5:
        if (b >= c)
            t = 1;
        break;
    }
    if (t == 1)
        VM_Jump((struct Cur *)a, ((struct Obj21678 *)a)->f14 + e);
}
