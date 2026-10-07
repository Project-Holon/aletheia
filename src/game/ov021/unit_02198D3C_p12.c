/*
 * file:     unit_02198D3C_p12.c
 * unit:     yes
 * function: func_02199DB4, func_02199EAC, func_02199EC0, func_02199ED4, func_02199F30, func_02199F50
 * address:  0x02199DB4
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
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0219FC68  0x0219FC68  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_020508EC  0x020508EC  arm
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   d_021D4ACC     0x021D4ACC  data  a4
 */
#include "../../matched/include/Obj12643.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec;

typedef struct {
    int pos;
    int vel;
    u16 timer;
    u8  last;
} State;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_0216D6D4(void *p);
extern int func_0219FC68(u32, u16 *, u16 *);
extern u16 func_0216D598(void *p);
extern void func_020061E4(u32);
extern void func_0216D8C0(u32, Vec *);
extern void func_0216D674(void *p, u16 v);
extern void func_0216D7CC(u32);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D520(void *p);
extern u32 func_0219C9DC(u8 *p);
extern int func_0216D7A8(void *p, unsigned int v);
extern u32 func_020508EC(u8 *p, int i, u16 *out);
extern void func_0216D5E0(int a0, int a1);
extern u16 *func_0216D6BC(u32, u32);
int func_02199DB4(u32 a);
int func_02199EAC(u32 a, u32 b, u32 c, u32 d);
int func_02199EC0(u32 a, u32 b, u32 c, u32 d);
int func_02199ED4(u32 a);
int func_02199F30(u32 a);
int func_02199F50(u32 a);
extern const Vec d_021D4ACC;


/*
 * Addresses are Black-image addresses.
 */
int func_02199DB4(u32 a)
{
    State *p;
    u16 v[2];

    p = func_0216D6D4((void *)a);
    if (func_0219FC68(a, &v[1], &v[0]) != 1)
        return 0;
    p->timer = p->timer + 1;
    v[0] = v[0] - 1;
    if (func_0216D598((void *)a) == 0xD3) {
        if (v[1] == 2 && p->last != v[0]) {
            p->last = v[0];
            switch (v[0]) {
            case 7:
            case 12:
            case 17:
                func_020061E4(0x7E5);
                break;
            case 10:
            case 15:
            case 20:
                func_020061E4(0x7E6);
                break;
            }
        }
    } else if (p->timer == 0x5F) {
        func_020061E4(0x7E7);
    }
    if (p->timer < 0x5F)
        return 0;
    p->pos += p->vel;
    {
        Vec w = { 0, 0, 0 };
        w.y = p->pos;
        func_0216D8C0(a, &w);
    }
    if (p->pos / 0x8000 < 16)
        return 0;
    func_0216D674((void *)a, 0);
    func_0216D7CC(a);
    return 1;
}


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02199EAC(u32 a, u32 b, u32 c, u32 d)
{
func_0216D674((void *)a, 10);
func_0216D7CC(a);
return 1;
}


int func_02199EC0(u32 a, u32 b, u32 c, u32 d)
{
func_0216D674((void *)a, 11);
func_0216D7CC(a);
return 0;
}


/*
 * Former blocker (now filed in src/matched/arm9): func_020508EC (0x020508EC, arm9, unlabelled leaf, Ilias's).
 * Verified EXACT from a scratch file (region arm9, --arm, dsi/1.1p1 -O4,p):
 *
 *   u32 func_020508EC(u8 *p, int i, u16 *out)
 *   {
 *       u16 v = *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0x1c);
 *       *out = v;
 *       return (u16)(v + 4 + 0xC000) <= 3;
 *   }
 *
 * Addresses are Black-image addresses.
 */
int func_02199ED4(u32 a)
{
    u32 s;
    u32 r;
    u16 out;

    s = func_0219C9DC((u8 *)func_0216D520(func_0216D67C((void *)a)));
    r = func_0216D7A8((void *)a, 0);
    if (r != 0xFFFF) {
        if (func_020508EC((u8 *)s, (u16)r, &out) == 0) {
            return 0;
        }
    }
    func_0216D5E0(a, 1);
    func_0216D674((void *)a, 0);
    func_0216D7CC(a);
    return 1;
}


int func_02199F30(u32 a)
{
    Vec t = {0, 0, 0};
    func_0216D8C0(a, &t);
    func_0216D7CC(a);
    return 1;
}


int func_02199F50(u32 a)
{
    u16 *p;
    Vec t = d_021D4ACC;
    p = func_0216D6BC(a, 6);
    *p = 0;
    ((struct Obj12643 *)p)->f2 = 0;
    func_0216D8C0(a, &t);
    func_0216D674((void *)a, 10);
    func_0216D7CC(a);
    return 1;
}
