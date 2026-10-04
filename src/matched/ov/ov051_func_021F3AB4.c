/*
 * function: func_021F3AB4
 * address:  0x021F3AB4
 * packet:   pkt_ov051_021F3AB4
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D3CC  0x0216D3CC  thumb
 *   func_02197E7C  0x02197E7C  thumb
 *   func_0216D410  0x0216D410  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D454  0x0216D454  thumb
 *   func_0216D480  0x0216D480  thumb
 *   func_021C90AC  0x021C90AC  thumb
 *   func_021C90D0  0x021C90D0  thumb
 */
#include "../include/Obj07660.h"

extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D3CC(void *a);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *a, int b);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern int func_0216D454(void *a);
extern void func_0216D480(void *a);
extern void func_021C90AC(int a);
extern int func_021C90D0(int a);

int func_021F3AB4(int a, int *s, int *t)
{
    void *r6;

    r6 = func_021A3074(func_02188CB4(*(void **)(t[3] + 8)));
    switch (*s) {
    case 0:
        if (func_0216D3CC(r6) == 1) {
            func_0216D410(r6, func_02197E7C(((struct Obj07660 *)t)->f0, 0x1c));
            func_020061E4(0x55a);
            *s = *s + 1;
        }
    case 1:
        func_021C90AC(((int *)t[2])[1]);
        *s = *s + 1;
        break;
    case 2:
        if (func_021C90D0(((int *)t[2])[1]) == 0)
            break;
        *s = *s + 1;
    case 3:
        if (func_0216D454(r6) == 1) {
            func_0216D480(r6);
            return 1;
        }
        break;
    }
    return 0;
}
