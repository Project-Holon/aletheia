/*
 * file:     field_gimmick_d06_p02.c
 * unit:     yes
 * function: func_021F3AB4, func_021F3B44
 * address:  0x021F3AB4
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_021F3D38  0x021F3D38  thumb  ov051
 *   func_021F3C98  0x021F3C98  thumb  ov051
 *   func_0216D88C  0x0216D88C  thumb
 *   func_02188CD0  0x02188CD0  thumb
 *   func_021C9064  0x021C9064  thumb
 *   func_021C909C  0x021C909C  thumb
 */
#include "../../matched/include/Obj07660.h"

struct Actor;
struct VecFx32;
typedef unsigned int   u32;

extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D3CC(void *a);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *a, int b);
extern void func_020061E4(u32 a);
extern int func_0216D454(void *a);
extern void func_0216D480(void *a);
extern void func_021C90AC(int a);
extern int func_021C90D0(int a);
extern void *func_021F3D38(int a, int x, int y);
extern int func_021F3C98(int *a, int *b);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *b);
extern int func_02188CD0(int a);
extern int func_021C9064(int a, int *b, int c);
extern void func_021C909C(int a);
int func_021F3AB4(int a, int *s, int *t);
void func_021F3B44(int *a, int *out, int x, int y);


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


void func_021F3B44(int *a, int *out, int x, int y)
{
    int buf[3];

    out[0] = (int)func_021F3D38(a[2], x, y);
    func_0216D88C((const struct Actor *)out[0], (struct VecFx32 *)buf);
    out[1] = func_021C9064(func_02188CD0(a[2]), buf, out[0]);
    if (func_021F3C98(a, out) == 1)
        func_021C909C(out[1]);
}
