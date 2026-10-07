/*
 * file:     ircbattlemenu_p05.c
 * unit:     yes
 * function: func_02197C9C, func_02197CCC, func_02197D3C, func_02197DA0, func_02197DAC
 * address:  0x02197C9C
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
 *   func_0216DB10  0x0216DB10  thumb  ov010
 *   func_0216DC4C  0x0216DC4C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_0216D8D0  0x0216D8D0  thumb  ov010
 *   func_0216D8F0  0x0216D8F0  thumb  ov010
 *   func_0216D92C  0x0216D92C  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   func_0216D4F4  0x0216D4F4  thumb  ov010
 *   func_0216D514  0x0216D514  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   d_021DDBE0     0x021DDBE0  data  a4
 *   func_02197DCC  0x02197DCC  thumb  ov021
 *   func_02030EE8  0x02030EE8  arm
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 */
#include "../../matched/include/Obj17950.h"

struct Actor;
struct VecFx32;
struct S02030EE8;
struct Node;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

extern int func_0216D55C(int a0, int a1);
extern int func_0216DB10(void *a0);
extern int func_0216DC4C(void *a0);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void func_0216D8B0(u8 *p, u8 *q);
extern void func_0216D8D0(u8 *p, u8 *q);
extern void func_0216D8F0(u8 *p, u8 *q);
extern void func_0216D92C(u8 *, s32 *);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D4F8(u8 *p);
extern u16 func_0216D4F4(void *p);
extern u32 func_0216D514(void *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02030DA8(u32, void (*)(), u32 *, u32);
extern void func_02197DCC(void *a, int *b);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern int func_0216D480(char *p);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
int func_02197C9C(u32 a);
void func_02197CCC(u8 *p, s32 *out);
void func_02197D3C(u32 p0, u32 p1);
int func_02197DA0(u32 a);
void func_02197DAC(void *a);
extern u8 d_021DDBE0;


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02197C9C(u32 a)
{
if (func_0216DB10((void *)a) != 0) {
    if (func_0216DC4C((void *)a) == 0) {
        return 1;
    }
}
if (func_0216D55C(a, 16) != 0) {
    return 1;
}
return 0;
}


/*
 * Sums five 12-byte records fetched from the actor at p into out.
 *
 * Addresses are Black-image addresses.
 */
void func_02197CCC(u8 *p, s32 *out)
{
    s32 a[3];
    s32 b[3];
    s32 c[3];
    s32 d[3];
    s32 e[3];

    func_0216D88C((const struct Actor *)p, (struct VecFx32 *)a);
    func_0216D8B0(p, (u8 *)b);
    func_0216D8D0(p, (u8 *)c);
    func_0216D8F0(p, (u8 *)d);
    func_0216D92C(p, e);
    out[0] = a[0] + b[0] + c[0] + d[0] + e[0];
    out[1] = a[1] + b[1] + c[1] + d[1] + e[1];
    out[2] = a[2] + b[2] + c[2] + d[2] + e[2];
}


/*
 * Addresses are Black-image addresses.
 */
void func_02197D3C(u32 p0, u32 p1)
{
    u32 h;
    u32 *r;
    u32 n;

    h = (u32)func_0216D67C((void *)p0);
    r = func_02030734((u16)(0x8000 | (func_0216D4F8((u8 *)h) & 0x7fff)), 0x14, 1, (const char *)&d_021DDBE0, 0x115);
    n = func_0216D4F4(func_0216D67C((void *)p0)) - 2;
    func_02030DA8(func_0216D514((void *)h), func_02197DCC, r, n);
    r[3] = p0;
    r[4] = p1;
}


int func_02197DA0(u32 a)
{
return ((struct Obj17950 *)((u8 *)(func_02030EE8((struct S02030EE8 *)a))))->f4;
}


void func_02197DAC(void *a)
{
    u32 *p;

    p = (u32 *)func_02030EE8(a);
    func_0216D480((char *)p[3]);
    func_020307B0(p);
    func_02030EAC(a);
}
