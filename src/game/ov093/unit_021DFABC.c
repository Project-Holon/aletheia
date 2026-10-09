/*
 * file:     unit_021DFABC.c
 * unit:     yes
 * function: func_021DFABC, func_021DFB40, func_021DFB4C, func_021DFB94, func_021DFBAC, func_021DFBF4, func_021DFC00, func_021DFCAC
 * address:  0x021DFABC
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021D76BC   0x021D76BC  thumb
 *   d_021F1934     0x021F1934  data   ov093  a4
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C7F24  0x021C7F24  thumb  ov093
 *   func_021C83D4  0x021C83D4  thumb  ov093
 *   d_021F14CC     0x021F14CC  data   ov093  a4
 *   d_021F14BC     0x021F14BC  data   ov093  a4
 */
#include "../../matched/include/Obj13501.h"
#include "../../matched/include/Obj07822.h"

struct S;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct Rec {
    int pad00;
    u16 f04;
    u8 f06;
    u8 pad07[5];
    u8 f0c[1];
} Rec;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern u32 func_0201BEB8(u16 id, u32 bit);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void *func_021C7CF4(int *p, int i);
extern int func_021DCFF8(int a, int b);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern int func_021EF948(int k);
extern int func_021E85F8(int id);
extern int func_021C7D00(u8 *p, int b);
extern int func_021C7F24(u8 *p, int i);
extern int func_021C83D4(u8 *p);
void func_021DFABC(int a, int q, int id);
int *func_021DFB40(int *p);
void func_021DFB4C(void *self, void *q, int id);
void func_021DFB94(int a, int b, int c);
void func_021DFBAC(void *self, void *q, int id);
int *func_021DFBF4(int *p);
void func_021DFC00(int self, void *q, int id);
int *func_021DFCAC(int *p);
extern int d_021F1934[];
extern int d_021F14CC[];
extern int d_021F14BC[];



void func_021DFABC(int a, int q, int id)
{
    Rec *r;
    void *m;
    int n;

    if (id != func_021D775C(4))
        return;
    if (func_021D775C(70) != 0)
        return;
    if (!func_0201BEB8(func_021D775C(18), 0))
        return;
    r = (Rec *)func_021C88A4((void *)q, 7, id);
    r->f06 = func_021D775C(3);
    m = func_021C7CF4((int *)q, r->f06);
    n = (u8)func_021DCFF8(a, 2);
    r->f04 = func_021D7B74(m, n);
    func_021C8838(r->f0c, 2, 424);
    func_021C8860((struct S *)r->f0c, r->f06);
    func_021C88C8((void *)q, r);
}



int *func_021DFB40(int *p)
{
    *p = 3;
    return d_021F1934;
}



void func_021DFB4C(void *self, void *q, int id)
{
    u8 *r;

    if (id != func_021D775C(2))
        return;
    if (func_021EF948(2) != 0)
        return;
    r = (u8 *)func_021C88A4(q, 4, id);
    func_021C8838(r + 4, 2, 0x198);
    func_021C8860((struct S *)(r + 4), id);
    func_021C88C8(q, r);
}





/* 021DFB94  shape F1: gate on func_021D775C(2) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DFBAA; movs r0, #0x51; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021DFB94(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D76BC(0x51, 1);
}




void func_021DFBAC(void *self, void *q, int id)
{
    u8 *r;

    if (id != func_021D775C(4))
        return;
    r = (u8 *)func_021C88A4(q, 0x20, id);
    r[6] = id;
    ((struct Obj13501 *)r)->f4 = 0;
    func_021C8838(r + 0xc, 2, 0x19b);
    func_021C8860((struct S *)(r + 0xc), id);
    func_021C88C8(q, r);
}


int *func_021DFBF4(int *p)
{
    *p = 1;
    return d_021F14CC;
}


void func_021DFC00(int self, void *q, int id)
{
    u8 t;
    u8 *r;

    if (func_021E85F8(id) == 0)
        return;
    t = func_021D775C(3);
    if (func_021C7D00(q, t) == 6)
        return;
    if (func_021D775C(0x4d) != 0)
        return;
    if (func_021C7F24(q, t) == 0)
        return;
    if (func_021C83D4(q) != 0)
        return;
    r = (u8 *)func_021C88A4(q, 0x23, id);
    func_021C8838(r + 8, 2, 0x1a1);
    func_021C8860((struct S *)(r + 8), id);
    func_021C8860((struct S *)(r + 8), t);
    func_021C88C8(q, r);
    r = (u8 *)func_021C88A4(q, 0x2e, id);
    r[6] = func_021D775C(3);
    r[7] = (r[7] & ~0xf0) | 0x10;
    ((struct Obj07822 *)r)->f4 = 0x28c;
    func_021C88C8(q, r);
}


int *func_021DFCAC(int *p)
{
    *p = 1;
    return d_021F14BC;
}
