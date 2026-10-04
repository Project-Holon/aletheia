/*
 * function: func_021C0E98
 * address:  0x021C0E98
 * packet:   pkt_ov021_021C0E98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A5408  0x021A5408  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D8E0  0x0216D8E0  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_0216E57C  0x0216E57C  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00235.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

extern int func_0216D3CC(int a0);
extern int func_021A5408(u32 a);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(u32 o, u32 a);
extern void func_020061E4(u32 se);
extern int func_0216D454(u32 o);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *o, struct VecFx32 *v);
extern int func_02163E58(u32 o, Vec3 *v, int *out);
extern u16 func_0216D598(void *p);
extern void func_0216DB4C(u32 o, u32 b);
extern void func_0216DAE0(unsigned int *p, unsigned int v);
extern void func_0216D89C(u32 o, Vec3 *v);
extern void func_0216D8E0(u32 o, void *p);
extern void func_0216E014(void *a, int *p, int b);
extern void func_0216E57C(void *a);

int func_021C0E98(u32 unused, int *st, u8 *p)
{
    Vec3 a;
    Vec3 b;
    Vec3 c;

    switch (*st) {
    case 0:
        if (func_0216D3CC(((struct Obj00235 *)p)->f1C) == 0)
            break;
        if (func_0216D3CC(((struct Obj00235 *)p)->f20) == 0 && func_021A5408(((struct Obj00235 *)p)->f0) == 0)
            break;
        func_0216D410(((struct Obj00235 *)p)->f1C, func_02197E7C(((struct Obj00235 *)p)->f4, 8));
        func_0216D410(((struct Obj00235 *)p)->f20, func_02197E7C(((struct Obj00235 *)p)->f4, 0x20));
        func_020061E4(0x674);
        (*st)++;
        break;
    case 1:
        if (func_0216D454(((struct Obj00235 *)p)->f1C) == 0)
            break;
        if (func_0216D454(((struct Obj00235 *)p)->f20) == 0)
            break;
        if (((struct Obj00235 *)p)->f6 == 0) {
            *st = 4;
            break;
        }
        func_0216D88C((const struct Actor *)((struct Obj00235 *)p)->f1C, (struct VecFx32 *)&a);
        func_02163E58(((struct Obj00235 *)p)->f1C, &a, (int *)(p + 0xc));
        if (func_0216D598((void *)(((struct Obj00235 *)p)->f1C)) == 0x6d)
            ((struct Obj00235 *)p)->fC -= 14 << 12;
        else
            ((struct Obj00235 *)p)->fC -= 26 << 12;
        func_0216DB4C(((struct Obj00235 *)p)->f1C, 1);
        func_0216DAE0((unsigned int *)(((struct Obj00235 *)p)->f1C), 0);
        func_020061E4(0x675);
        (*st)++;
        break;
    case 2:
        func_0216D88C((const struct Actor *)((struct Obj00235 *)p)->f1C, (struct VecFx32 *)&b);
        if (((struct Obj00235 *)p)->fC < b.y) {
            b.y -= 0x4000;
            if (((struct Obj00235 *)p)->fC > b.y)
                b.y = ((struct Obj00235 *)p)->fC;
        } else if (((struct Obj00235 *)p)->fC > b.y) {
            b.y += 0x4000;
            if (((struct Obj00235 *)p)->fC < b.y)
                b.y = ((struct Obj00235 *)p)->fC;
        }
        func_0216D89C(((struct Obj00235 *)p)->f1C, &b);
        if (((struct Obj00235 *)p)->fC == b.y) {
            ((struct Obj00235 *)p)->f14 = 0x2000;
            (*st)++;
        }
        break;
    case 3:
        func_0216D8E0(((struct Obj00235 *)p)->f1C, p + 0x10);
        ((struct Obj00235 *)p)->f14 = -((struct Obj00235 *)p)->f14;
        ((struct Obj00235 *)p)->f8 = ((struct Obj00235 *)p)->f8 + 1;
        if (((struct Obj00235 *)p)->f8 & 4) {
            if (((struct Obj00235 *)p)->f14 < 0)
                ((struct Obj00235 *)p)->f14 += 0x1000;
            else if (((struct Obj00235 *)p)->f14 > 0)
                ((struct Obj00235 *)p)->f14 -= 0x1000;
        }
        if (((struct Obj00235 *)p)->f14 == 0) {
            func_0216D88C((const struct Actor *)((struct Obj00235 *)p)->f1C, (struct VecFx32 *)&c);
            func_0216E014((void *)(((struct Obj00235 *)p)->f1C), (int *)(&c), ((struct Obj00235 *)p)->f4);
            func_0216D8E0(((struct Obj00235 *)p)->f1C, p + 0x10);
            func_0216E57C((void *)(((struct Obj00235 *)p)->f1C));
            (*st)++;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}
