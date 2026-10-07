/*
 * file:     field_gimmick_d06_p01.c
 * unit:     yes
 * function: func_021F38A4, func_021F3958, func_021F39F8
 * address:  0x021F38A4
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
 *   func_021F3D6C  0x021F3D6C  thumb  ov051
 *   func_021F3724  0x021F3724  thumb  ov051
 *   func_021F3718  0x021F3718  thumb  ov051
 *   func_021F3D04  0x021F3D04  thumb  ov051
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3038  0x021A3038  thumb
 *   func_02164208  0x02164208  thumb
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216DDC0  0x0216DDC0  thumb
 *   func_0216D588  0x0216D588  thumb
 *   func_021F3C98  0x021F3C98  thumb  ov051
 *   func_021F3C84  0x021F3C84  thumb  ov051
 *   func_021F3AB4  0x021F3AB4  thumb  ov051
 *   func_02188C80  0x02188C80  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082C60  0x02082C60  arm
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D3CC  0x0216D3CC  thumb
 *   func_02197E7C  0x02197E7C  thumb
 *   func_0216D410  0x0216D410  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D454  0x0216D454  thumb
 *   func_0216D480  0x0216D480  thumb
 *   func_021C909C  0x021C909C  thumb
 */
#include "../../matched/include/Obj06158.h"
#include "../../matched/include/Obj01876.h"

struct VecFx32;
struct Desc;
struct Obj;
typedef unsigned int   u32;

extern void *func_021F3D6C(int a);
extern int func_021F3724(int a);
extern int func_021F3718(int a);
extern void func_021F3D04(int a, int b);
extern void *func_02188CB4(unsigned char *p);
extern void func_021A3038(unsigned char *a, struct VecFx32 *b);
extern void func_02164208(int a, int *b, int c);
extern void *func_02188C7C(unsigned char *p);
extern int func_0216DDC0(void *a, int b, int c, int d);
extern int func_0216D588(int a);
extern int func_021F3C98(int *a, int *b);
extern int func_021F3C84(int *a, int *b, int c);
extern int func_021F3AB4(int a, int *s, int *t);
extern int func_02188C80(int a);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082C60(void *a, int b, int c);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D3CC(void *a);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *a, int b);
extern void func_020061E4(u32 a);
extern int func_0216D454(void *a);
extern void func_0216D480(void *a);
extern void func_021C909C(int a);
int func_021F38A4(int a, int b);
int func_021F3958(int a, int id, int arg);
int func_021F39F8(int a, int *s, int *t);


int func_021F38A4(int a, int b)
{
    int v[3];
    int res;
    int x;
    int y;
    int h;
    unsigned int i;
    int *p;
    unsigned int n;
    int *r4;

    res = 0;
    r4 = func_021F3D6C(a);
    func_021A3038(func_02188CB4((void *)a), (struct VecFx32 *)v);
    func_02164208(b, v, 1 << 16);
    x = (short)(((v[0] >> 4) / 4096));
    y = (short)(((v[2] >> 4) / 4096));
    n = func_021F3724(*r4);
    p = (int *)func_021F3718(*r4);
    i = 0;
    if (i < n)
        for (; i < n; i++) {
            if (p[0] == x && p[2] == y)
                func_021F3D04(a, i);
            p += 3;
        }
    h = func_0216DDC0(func_02188C7C((void *)a), x, y, 0);
    if (h != 0 && func_0216D588(h) == 0xfd)
        res = func_021F3958(a, h, b);
    return res;
}


int func_021F3958(int a, int id, int arg)
{
    int sp3;
    int sp8;
    int sp1;
    unsigned short i;
    int v;
    char *r5;
    char *r7;
    unsigned short *r6;

    r5 = func_021F3D6C(a);
    sp8 = func_02188C80(a);
    for (i = 0; i < 12; i++) {
        v = *(int *)(r5 + 12 + i * 8);
        if (v == id)
            break;
    }
    if (i >= 12)
        i = 0;
    r7 = r5 + 12 + i * 8;
    if (func_021F3C98((int *)r5, (int *)r7) == 1)
        return 0;
    sp3 = func_021F3C84((int *)r5, (int *)r7, arg);
    if (sp3 == 0)
        sp1 = (int)func_020122C0((void *)sp8, 0, func_021F3AB4, 0x10);
    else
        sp1 = (int)func_020122C0((void *)sp8, 0, func_021F39F8, 0x10);
    r6 = func_020124E8((struct Obj *)sp1);
    func_02082C60(r6, 0, 0x10);
    r6[0] = arg;
    *(char * *)&((struct Obj06158 *)r6)->fC = r5;
    r6[1] = i;
    *(char * *)&((struct Obj06158 *)r6)->f8 = r7;
    ((struct Obj06158 *)r6)->f4 = sp3;
    return sp1;
}


int func_021F39F8(int a, int *s, int *t)
{
    void *r6;

    r6 = func_021A3074(func_02188CB4(*(void **)(t[3] + 8)));
    switch (*s) {
    case 0:
        if (func_0216D3CC(r6) == 1) {
            func_0216D410(r6, func_02197E7C(((struct Obj01876 *)t)->f0, 0x1c));
            func_020061E4(0x6ce);
            *s = *s + 1;
        }
        break;
    case 1:
        if (func_0216D3CC(*(void **)t[2]) == 1) {
            if (t[1] > 0) {
                int v = 8;
                if (t[1] <= 1)
                    v = 0x10;
                else if (t[1] <= 2)
                    v = 0x10;
                else if (t[1] <= 4)
                    v = 0xc;
                func_0216D410(*(void **)t[2], func_02197E7C(((struct Obj01876 *)t)->f0, v));
                t[1] = t[1] - 1;
            } else {
                func_020061E4(0x6a3);
                *s = *s + 1;
            }
        }
        break;
    case 2:
        if (func_0216D454(r6) == 1) {
            func_0216D480(*(void **)t[2]);
            func_0216D480(r6);
            func_021C909C(((int *)t[2])[1]);
            return 1;
        }
        break;
    }
    return 0;
}
