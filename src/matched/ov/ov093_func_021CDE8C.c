/*
 * function: func_021CDE8C
 * address:  0x021CDE8C
 * packet:   pkt_ov093_021CDE8C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CDDDC  0x021CDDDC  thumb  ov093
 *   func_021EE688  0x021EE688  thumb  ov093
 *   func_021D3F54  0x021D3F54  thumb  ov093
 */
#include "../include/Obj06232.h"

typedef unsigned char  u8;
extern int func_021CDDDC(u8 *p, int *st);
extern int func_021EE688(int, int);
extern void func_021D3F54(u8 *p);

int func_021CDE8C(int a, int b)
{
    int r4;
    if (((struct Obj06232 *)a)->f54 != 0) {
        r4 = func_021CDDDC((u8 *)a, (int *)b);
        if (r4 != 0) {
            if (func_021EE688(((struct Obj06232 *)a)->f14, ((struct Obj06232 *)a)->f1A6) != 0)
                func_021D3F54((u8 *)(a + 0x18));
        }
        return r4;
    }
    func_021EE688(((struct Obj06232 *)a)->f14, ((struct Obj06232 *)a)->f1A6);
    return 1;
}
