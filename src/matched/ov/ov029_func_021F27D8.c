/*
 * function: func_021F27D8
 * address:  0x021F27D8
 * packet:   pkt_ov029_021F27D8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F279C  0x021F279C  thumb  ov029
 *   func_021EFEF8  0x021EFEF8  thumb  ov029
 *   func_021F21F8  0x021F21F8  thumb  ov029
 *   func_020056EC  0x020056EC  thumb
 *   func_021F3190  0x021F3190  thumb  ov029
 *   func_021F20AC  0x021F20AC  thumb  ov029
 */
#include "../include/Obj03633.h"

typedef unsigned int   u32;
extern void *func_021F279C(int a, int b, int c, int d);
extern void func_021EFEF8(char *p, void (*f)(void), int a);
extern void func_021F21F8(char *p);
extern u32 func_020056EC(u32 range);
extern void func_021F3190(int a, int b, int c, int d);
extern void func_021F20AC(char *p);

char *func_021F27D8(int a0, int a1, int a2, void (*cb)(int), int arg, int flag)
{
    char *p = func_021F279C(a0, a1, a2, flag);

    *(void (**)(int))(p + 0x1fc) = cb;
    ((struct Obj03633 *)p)->f200 = arg;
    if (flag != 0) {
        func_021EFEF8(p, (void (*)(void))func_021F21F8, 0x1160);
        ((struct Obj03633 *)p)->f45B = 0;
    } else {
        if (*(void (**)(int))(p + 0x1fc) != 0)
            (*(void (**)(int))(p + 0x1fc))(((struct Obj03633 *)p)->f200);
        *(int *)&((struct Obj03633 *)p)->f1FC = 0;
        ((struct Obj03633 *)p)->f200 = 0;
    }
    func_021F3190(a0, ((struct Obj03633 *)p)->f24, func_020056EC(10), 0x70);
    func_021F20AC(p);
    return p;
}
