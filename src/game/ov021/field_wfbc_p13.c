/*
 * file:     field_wfbc_p13.c
 * unit:     yes
 * function: func_021944C8, func_021944D8, func_02194588
 * address:  0x021944C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_021945A0  0x021945A0  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 */
#include "../../matched/include/Obj19627.h"
#include "../../matched/include/Obj19628.h"

struct Actor;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_0216D69C(void *p);
extern int func_021945A0(int x);
extern void func_0216D5E0(int a0, int a1);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern u16 func_0216D5F8(void *p);
extern void func_0216E014(void *a, int *p, int b);
extern u16 func_0216D598(void *p);
extern void func_0216D674(void *a, int v);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
void func_021944C8(u32 a);
void func_021944D8(void *a);
void func_02194588(u32 a, u32 b, u32 c, u32 d, u32 e);


/*
 * Addresses are Black-image addresses.
 */
void func_021944C8(u32 a)
{
    ((struct Obj19628 *)(*(u8 * *)&((struct Obj19627 *)((u8 *)func_0216D69C((void *)a)))->fC))->f4 = 1;
}


void func_021944D8(void *a)
{
    int v[3];
    int *r4;
    int r6;
    int *p;
    int s;
    int t;

    r4 = func_0216D69C(a);
    func_0216D5E0((int)a, func_021945A0(*(u16 *)r4[0]));
    r6 = 0;
    func_0216D88C(a, (struct VecFx32 *)v);
    p = (int *)r4[1];
    if (v[0] != p[0] || v[1] != p[1] || v[2] != p[2]) {
        func_0216E014(a, (int *)r4[1], func_0216D5F8(a));
        r6 = 3;
        if (*(u16 *)(r4[3] + 6) != 0) {
            s = func_0216D598(a);
            if (s == 1 || s == 4) {
                int sum = 0;
                p = (int *)r4[1];
                t = v[0] - p[0];
                if (t < 0)
                    t = -t;
                sum += t;
                t = v[2] - p[2];
                if (t < 0)
                    t = -t;
                sum += t;
                if (sum >= 0x4000)
                    r6 = 10;
            }
        }
    }
    func_0216D674(a, r6);
    if (r4[2] != 0)
    {
        int f = 0;

        if (*(int *)r4[2] == 1)
            f = 1;
        func_0216DAC8(a, f);
    }
}


void func_02194588(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    u32 *p;

    p = func_0216D69C((void *)a);
    p[0] = b;
    p[1] = c;
    p[2] = d;
    p[3] = e;
}
