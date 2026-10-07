/*
 * file:     unit_02198D3C_p16.c
 * unit:     yes
 * function: func_0219A4CC, func_0219A528, func_0219A54C
 * address:  0x0219A4CC
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
 *   func_0219A3D8  0x0219A3D8  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 */
#include "../../matched/include/Obj17954.h"

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u32 v; int n; } St;

extern void func_0219A3D8(u32, int *);
extern int func_0216D83C(void *p);
extern int func_021641E8(int a);
extern int func_0216D86C(void *p);
extern int func_021641F8(u16);
extern int func_02163F10(int a0);
extern void func_0216D674(void *p, u16 v);
extern void *func_0216D684(int a0, int a1, u32 a2, u32 a3);
extern u32 func_0216DA50(u32);
extern void *func_0216D69C(void *p);
extern void func_0216D5E0(int a0, int a1);
int func_0219A4CC(u32 a, u32 b);
int func_0219A528(u32 a, u32 b, u32 c, u32 d);
void func_0219A54C(u32 a);


int func_0219A4CC(u32 a, u32 b)
{
    int r[4];
    int x;
    int y;
    func_0219A3D8(a, r);
    x = func_0216D83C((void *)a) + func_021641E8((u16)b);
    y = func_0216D86C((void *)a) + func_021641F8(b);
    if (r[0] > x || r[2] < x)
        return 0;
    if (r[1] > y || r[3] < y)
        return 0;
    return 1;
}


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216DA50 (0x0216DA50) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219A528(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj17954 *)((u8 *)(func_0216D684(a, 8, c, d))))->f0 = b;
func_0216D674((void *)a, 0);
func_0216DA50(a);
return func_02163F10(a);
}


void func_0219A54C(u32 a)
{
    St *p = func_0216D69C((void *)a);
    switch (p->n) {
    case 0:
        func_0216D5E0(a, (unsigned short)p->v);
        p->n = p->n + 1;
        break;
    case 1:
        break;
    }
}
