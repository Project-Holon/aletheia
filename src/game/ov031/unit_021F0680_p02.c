/*
 * file:     unit_021F0680_p02.c
 * unit:     yes
 * function: func_021F0D40, func_021F0D58, func_021F0D64, func_021F0DB0
 * address:  0x021F0D40
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0209C2B0 0x0209C2B0 arm
 *   func_02035D20  0x02035D20  arm
 *   func_0204B404  0x0204B404  arm
 *   func_021F0F68  0x021F0F68  thumb  ov031
 *   func_021F0ED8  0x021F0ED8  thumb  ov031
 *   func_021BBC2C  0x021BBC2C  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 *   func_021F0F40  0x021F0F40  thumb  ov031
 *   func_020061E4  0x020061E4  thumb
 */
#include "../../matched/include/Obj20411.h"

struct Obj;
struct Vec2;
typedef struct {
    char pad[0x43C];
    int a;
} B_021F0D40;

typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef struct {
    char pad[0x43C];
    int a;
    int n;
} B_021F0DB0;

extern u32 func_0209C2B0(u32 a, u32 b);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern int func_021F0F68(void *, int, int);
extern void func_021F0ED8(void *, B_021F0DB0 *, int);
extern u8 *func_021BBC2C(B_021F0DB0 *, int);
extern void func_02082D44(void *dst, void *src, int n);
extern void func_021F0F40(void *, B_021F0DB0 *, int);
extern void func_020061E4(u32 a);
int func_021F0D40(B_021F0D40 *p);
u32 func_021F0D58(void *unused, u32 d);
int func_021F0D64(char *p);
int func_021F0DB0(char *a0, void *a1, B_021F0DB0 *a2);


/*
 * Unlabelled leaf (no lr push) sitting in a word run; filed as a blocker of
 * func_021F0C60 and func_021F0CEC.
 */
int func_021F0D40(B_021F0D40 *p)
{
    int v = p->a;

    if (v >= 0x1E)
        v = 0x1D;
    v -= 2;
    if (v < 0)
        v = 0;
    return v;
}


u32 func_021F0D58(void *unused, u32 d)
{
    return func_0209C2B0(0x8000, d);
}


int func_021F0D64(char *p)
{
    unsigned short t[2];
    u32 x;
    u32 y;

    if (func_02035D20(&x, &y) == 0)
        return 0;
    if (x >= 0xE9 && x <= 0xFF && y >= 0x1C && y <= 0x9C) {
        t[0] = 0xF4;
        t[1] = y;
        func_0204B404((struct Obj *)(((struct Obj20411 *)p)->f2C), (const struct Vec2 *)t, 1);
        return 1;
    }
    return 0;
}


int func_021F0DB0(char *a0, void *a1, B_021F0DB0 *a2)
{
    u32 x;
    u32 y;
    int i;
    int t;
    u8 *e;

    if (func_02035D20(&x, &y) == 0)
        return 0;
    if (x <= 0xE8) {
        for (i = 0; i < 3; i++) {
            if (y >= (u32)(i * 0x38) && y <= (u32)(i * 0x38 + 0x38))
                break;
        }
    }
    if (i >= 3 || i > a2->a)
        return 0;
    if (func_021F0F68(a1, i, 1) == 1) {
        t = i;
        i = a2->n;
        if (i >= 3)
            i = i - 2 + t;
        else
            i = t;
        func_021F0ED8(a1, a2, i);
        e = func_021BBC2C(a2, i);
        if (e != 0)
            func_02082D44(e + 0x1A, a0 + 0x28A4, 6);
        func_021F0F40(a1, a2, i);
        func_020061E4(0x54C);
        return 1;
    }
    return 0;
}
