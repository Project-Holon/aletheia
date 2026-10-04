/*
 * function: func_021F5748
 * address:  0x021F5748
 * packet:   pkt_ov082_021F5748
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_021917C0  0x021917C0  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 *   func_021F5840  0x021F5840  thumb  ov082
 *   d_021F58D0     0x021F58D0  data  a4
 *   d_021F58E0     0x021F58E0  data  a4
 */
#include "../include/Obj02425.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern int  func_02159190(int a);
extern int  func_0215A61C(int a);
extern int func_021917C0(int *p);
extern u32 func_020056EC(u32 range);
extern void func_021F5840(void *tbl, u32 a, u32 b, u32 c, u32 d, void *e);
extern char d_021F58D0[];
extern char d_021F58E0[];

void func_021F5748(int a0, char *p)
{
    int t;
    int r;

    if (((struct Obj02425 *)p)->f1C == 0 && func_02159190(3) != 0) {
        t = func_0215A61C(((struct Obj02425 *)p)->f10);
        if (t != 0) {
            r = func_021917C0((int *)t);
            if (r == 0) {
                ((struct Obj02425 *)p)->f4C = 0;
                ((struct Obj02425 *)p)->f74 = 0;
            } else if (r == 2 && ((struct Obj02425 *)p)->f74 == 0) {
                ((struct Obj02425 *)p)->f1C = 1;
            }
        }
    }
    func_021F5840(d_021F58D0, 4, 0x184, 8, 4, p + 0x4C);
    if (((struct Obj02425 *)p)->f26 == 0) {
        ((struct Obj02425 *)p)->f28 = 0;
        ((struct Obj02425 *)p)->f26 = func_020056EC(0x14) + 0x50;
    } else {
        ((struct Obj02425 *)p)->f26 = ((struct Obj02425 *)p)->f26 - 1;
    }
    func_021F5840(d_021F58E0, 5, 0x160, 0xC, 6, p + 0x28);
}
