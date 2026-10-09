/*
 * file:     btl_server_p56.c
 * unit:     yes
 * function: func_021C4104, func_021C41C0
 * address:  0x021C4104
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C5D88  0x021C5D88  thumb  ov093
 *   func_021C5840  0x021C5840  thumb  ov093
 *   func_021C59C4  0x021C59C4  thumb  ov093
 *   func_021D6D9C  0x021D6D9C  thumb  ov093
 *   func_021C1DCC  0x021C1DCC  thumb  ov093
 *   func_021C1880  0x021C1880  thumb  ov093
 *   func_021C4218  0x021C4218  thumb  ov093
 *   func_021C4208  0x021C4208  thumb  ov093
 *   func_021D6D70  0x021D6D70  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { int a; u8 b; } S;

extern u8 func_021D5440(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C5D88(u8 *p, u8 *a, int b);
extern void func_021C5840(u8 *p, u32 count, int *v, u8 **a, int flag);
extern void func_021C59C4(u8 *p, u32 n, u8 **a, u8 *b, int flag);
extern int func_021D6D9C(u8 *c, u16 *d);
extern void func_021C1DCC(u8 *p, u8 *q, u32 a, u8 *b, u32 s);
extern void func_021C1880(u8 *p, u8 *q, u8 *a, u8 *b, u32 s0, int s1);
extern void func_021C4218(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3);
extern int func_021C4208(u8 *p, int i);
extern void func_021D6D70(u8 *p);
u16 func_021C4104(u8 *p, u32 q, u8 *c, u16 d, S s, u16 *e);
void func_021C41C0(u8 *p, u8 *a);


/*
 * Opens with `push {r0-r3}`: the address of parameters 3-6 is taken; the
 * fifth and sixth parameters are one 8-byte struct passed by value.
 */
u16 func_021C4104(u8 *p, u32 q, u8 *c, u16 d, S s, u16 *e)
{
    u16 ev = *e;
    u8 sa = s.a;
    int m = func_021D5440(c);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x54, m, sa, ev);
    func_021C5D88(p, c, 0x317);
    func_021C5840(p, 1, (int *)(&s), &c, 0);
    func_021C59C4(p, 1, &c, &s.b, 0);
    if (func_021D6D9C(c, &d))
        func_021C41C0(p, c);
    func_021C1DCC(p, (u8 *)e, q, c, d);
    func_021C1880(p, (u8 *)e, (u8 *)q, c, d, 1);
    func_021C4218(p, (u8 *)q, c, (u8 *)e, s.a, d, s.b, 1);
    return d;
}


void func_021C41C0(u8 *p, u8 *a)
{
    int i = func_021D5440(a);
    int r = func_021C4208(p + 0x1ab8, i);
    func_021C5D88(p, a, 0x31a);
    func_021D6D70(a);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x28, i);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x52, r);
}
