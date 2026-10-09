/*
 * file:     fldmmdl_blact_p06.c
 * unit:     yes
 * function: func_0219D584, func_0219D604, func_0219D634, func_0219D680, func_0219D6B8, func_0219D6CC, func_0219D724, func_0219D738, func_0219D780, func_0219D7AC, func_0219D7D0, func_0219D7F0, func_0219D824
 * address:  0x0219D584
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
 *   func_0216D518  0x0216D518  thumb  ov010
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_0219D524  0x0219D524  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D528  0x0216D528  thumb  ov010
 *   func_0219D558  0x0219D558  thumb  ov021
 *   func_0216E3CC  0x0216E3CC  thumb  ov010
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_021C6628  0x021C6628  thumb  ov021
 *   func_0216DFC4  0x0216DFC4  thumb  ov010
 *   func_0216D6F4  0x0216D6F4  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216DA20  0x0216DA20  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_02197EB4  0x02197EB4  thumb  ov021
 *   func_0216DB10  0x0216DB10  thumb  ov010
 *   func_0216D708  0x0216D708  thumb  ov010
 *   func_0216D530  0x0216D530  thumb
 *   func_021BB3C4  0x021BB3C4  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_0207CDB8  0x0207CDB8  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   d_021D80E4     0x021D80E4  data   ov021  a1
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0219D85C  0x0219D85C  thumb  ov021
 *   func_0216DA70  0x0216DA70  thumb  ov010
 *   func_0219D8DC  0x0219D8DC  thumb  ov021
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0219D990  0x0219D990  thumb  ov021
 *   func_0219D930  0x0219D930  thumb  ov021
 *   func_0219DA20  0x0219DA20  thumb  ov021
 *   func_0219D9D8  0x0219D9D8  thumb  ov021
 */
#include "../../matched/include/Obj07479.h"

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u16 a; u16 b; } E4;

extern u32 func_0216D518(u8 *p);
extern void func_021C6AE0(u32 a);
extern void func_021C6AF0(u32 *, u32, u16);
extern void func_021C6AF8(u32 *p, u32 v);
extern void func_021C6AFC(u32 *, u16);
extern u32 func_021C6574(u32, u32 *, u32);
extern u16 func_0219D524(u32 *s, u32 b, u32 a);
extern void func_021C6580(u8 *p, int i);
extern void *func_0216E3C4(void *p);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D528(u8 *p);
extern u16 func_0219D558(u8 *s, u16 k);
extern u8 *func_0216E3CC(u8 *p);
extern u32 func_021C6590(u32, u32, u32, u32);
extern u16 func_0216D598(void *p);
extern void func_021C6628(u32, u32);
extern int func_0216DFC4(void *a, u32 id);
extern u32 *func_0216D548(u32 *p, u32 v);
extern void func_0216D6F4(void *a0);
extern int func_0216DA20(void *p, unsigned int v);
extern u32 func_0216D57C(void *p, u32 v);
extern void func_02197EB4(u32);
extern int func_0216DB10(void *a0);
extern void func_0216D708(void *a0);
extern u32 func_0216D530(u32);
extern u32 func_021BB3C4(u8 *p, char *a1);
extern u16 func_0216D5F8(void *p);
extern void func_0219E784(u32, u32, s16 *);
extern void func_0207CDB8(s16 *, s16 *);
extern int func_0207CFB8(int, int);
extern int func_0216DA5C(void *a0);
extern u16 func_0216D5A0(void *p);
extern u32 func_0219D85C(u32 a);
extern void func_0216DA70(void *a0);
extern void func_0219D8DC(u32);
extern char *func_0216D570(char *p, u32 v);
extern void func_0219D990(u32);
extern void func_0219D930(u32);
extern void func_0219DA20(u32);
extern void func_0219D9D8(u32);
u32 func_0219D584(u32 a, u32 *b, u32 c, u16 *d);
void func_0219D604(u8 *s, u16 k);
u32 func_0219D634(u32 a);
void func_0219D680(u32 a, u32 b);
int func_0219D6B8(u32 *a, u32 b, u32 c, u32 d);
void func_0219D6CC(u32 a);
int func_0219D724(u32 a, char *b);
u32 func_0219D738(u32 a, int b);
int func_0219D780(u32 a);
void func_0219D7AC(u32 a);
void func_0219D7D0(u32 a);
void func_0219D7F0(u32 a);
void func_0219D824(u32 a);
extern u8 d_021D80E4[];


/*
 * Addresses are Black-image addresses.
 */
u32 func_0219D584(u32 a, u32 *b, u32 c, u16 *d)
{
    u32 buf[9];
    u32 t;
    u32 r;
    int i;
    t = func_0216D518((u8 *)a);
    func_021C6AE0((u32)buf);
    if (d[0] != 0xFFFF) {
        func_021C6AF0(buf, t, d[0]);
    }
    if (d[1] != 0xFFFF) {
        func_021C6AF0(buf, t, d[1]);
    }
    func_021C6AF8((u32 *)buf, t);
    for (i = 0; i < 3; i++) {
        if (d[i + 2] != 0xFFFF) {
            func_021C6AFC(buf, d[i + 2]);
        }
    }
    r = func_021C6574(b[1], buf, 0);
    func_0219D524(b, c, r);
    return r;
}


void func_0219D604(u8 *s, u16 k)
{
    int i;
    int n = ((struct Obj07479 *)s)->f8;
    E4 *e = *(E4 * *)&((struct Obj07479 *)s)->fC;
    for (i = 0; i < n; i++, e++) {
        if (e->b == k) {
            func_021C6580((u8 *)(((struct Obj07479 *)s)->f4), e->a);
            e->b = 0xFFFF;
            return;
        }
    }
}


u32 func_0219D634(u32 a)
{
    u16 *p;
    u32 b;
    u32 *s;
    u32 r;
    p = func_0216E3C4((void *)a);
    b = (u32)func_0216D67C((void *)a);
    s = (u32 *)func_0216D528((u8 *)b);
    r = func_0219D558((u8 *)s, *p);
    if (r == 0xFFFF) {
        r = func_0219D584(b, s, *p, (u16 *)func_0216E3CC((u8 *)p));
    }
    return func_021C6590(s[1], r, 0, 0);
}


void func_0219D680(u32 a, u32 b)
{
    u8 *s = (u8 *)func_0216D528(func_0216D67C((void *)a));
    u16 v = func_0216D598((void *)a);
    func_021C6628(((struct Obj07479 *)s)->f4, b);
    if (func_0216DFC4((void *)a, v) == 0) {
        func_0219D604(s, v);
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219D6B8(u32 *a, u32 b, u32 c, u32 d)
{
func_0216D6F4((void *)a);
return (int)func_0216D548(a, 2);
}


void func_0219D6CC(u32 a)
{
    u32 k = 2;
    if (func_0216DA20((void *)a, 2) == 0) {
        func_0219D7AC(a);
        func_0219D7D0(a);
        if (func_0216D57C((void *)a, k << 8) != 0) {
            func_02197EB4(a);
        } else if (func_0216DB10((void *)a) == 0 && func_0219D780(a) == 1) {
            func_0216D708((void *)a);
        }
        func_0219D7F0(a);
        func_0219D824(a);
    }
}


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D530 (0x0216D530) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219D724(u32 a, char *b)
{
return func_021BB3C4((u8 *)func_0216D530((u32)func_0216D67C((void *)a)), b);
}


u32 func_0219D738(u32 a, int b)
{
    s16 v[4];
    int r;
    func_0219E784(a, func_0216D5F8((void *)a), v);
    v[1] = 0;
    func_0207CDB8(v, v);
    r = func_0207CFB8(v[0], v[2]) - b;
    if (r < 0) {
        r += 0x10000;
    }
    return d_021D80E4[r >> 12];
}


int func_0219D780(u32 a)
{
    if (func_0216DA5C((void *)a) == 1) {
        return 1;
    }
    if (func_0216D57C((void *)a, 0x800) == 0) {
        return 1;
    }
    func_0216D5A0((void *)a);
    return 1;
}


void func_0219D7AC(u32 a)
{
    if (func_0216D57C((void *)a, 0x800) != 0 && func_0219D85C(a) == 1) {
        func_0216DA70((void *)a);
    }
}


void func_0219D7D0(u32 a)
{
    if (func_0216D57C((void *)a, 0x20) != 0) {
        func_0219D8DC(a);
    }
    func_0216D570((char *)a, 0xA0);
}


void func_0219D7F0(u32 a)
{
    if (func_0216D57C((void *)a, 0x80) != 0) {
        func_0219D990(a);
    } else if (func_0216D57C((void *)a, 0x20) != 0) {
        func_0219D930(a);
    }
    func_0216D570((char *)a, 0xA0);
}


void func_0219D824(u32 a)
{
    if (func_0216D57C((void *)a, 0x100) != 0) {
        func_0219DA20(a);
    } else if (func_0216D57C((void *)a, 0x40) != 0) {
        func_0219D9D8(a);
    }
    func_0216D570((char *)a, 0x140);
}
