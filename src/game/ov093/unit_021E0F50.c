/*
 * file:     unit_021E0F50.c
 * unit:     yes
 * function: func_021E0F50, func_021E0F68, func_021E0F74, func_021E0FB8, func_021E1010, func_021E101C, func_021E1050, func_021E1068, func_021E1074, func_021E10CC
 * address:  0x021E0F50
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
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2A48     0x021F2A48  data   ov093  a4
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   d_021F28E8     0x021F28E8  data   ov093  a4
 *   d_021F266C     0x021F266C  data   ov093  a4
 *   d_021F263C     0x021F263C  data   ov093  a4
 */
#include "../../matched/include/Obj07826.h"

struct S;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
void func_021E0F50(int a, int b, int c);
int *func_021E0F68(int *p);
void func_021E0F74(int unused, void *q, int id);
void func_021E0FB8(int unused, void *q, int id);
int *func_021E1010(int *p);
void func_021E101C(int a, int b, int c);
void func_021E1050(int a, int b, int c);
int *func_021E1068(int *p);
void func_021E1074(int unused, void *q, int id);
int *func_021E10CC(int *p);
extern int d_021F2A48[];
extern int d_021F28E8[];
extern int d_021F266C[];
extern int d_021F263C[];




/* 021E0F50  shape F1: gate on func_021D775C(3) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021E0F66; movs r0, #0x51; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021E0F50(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x51, 1);
}




int *func_021E0F68(int *p)
{
    *p = 2;
    return d_021F2A48;
}




void func_021E0F74(int unused, void *q, int id)
{
    void *m;
    int k;
    u8 t;

    if (id == func_021D775C(3)) {
        t = func_021D775C(4);
        m = func_021C7CF4(q, t);
        k = 0x11;
        if (func_021D59B4(m, 0x11) == 0x36 || func_021D59B4(m, k) == 0xf)
            func_021D76BC(0x40, 1);
    }
}





void func_021E0FB8(int unused, void *q, int id)
{
    u8 *r;
    int t;

    if (id == func_021D775C(3)) {
        t = func_021D775C(6);
        r = (u8 *)func_021C88A4(q, 0x1f, id);
        r[6] = t;
        ((struct Obj07826 *)r)->f4 = 0xf;
        func_021C8838(r + 0xc, 2, 0x195);
        func_021C8860((struct S *)(r + 0xc), r[6]);
        func_021C8860((struct S *)(r + 0xc), ((struct Obj07826 *)r)->f4);
        func_021C88C8(q, r);
    }
}



int *func_021E1010(int *p)
{
    *p = 2;
    return d_021F28E8;
}



void func_021E101C(int a, int b, int c)
{
    int n;

    if (c != func_021D775C(3))
        return;
    n = (unsigned char)func_021D775C(4);
    if (func_021D62C4(func_021C7CF4((int *)b, n), 2) == 0)
        func_021D76BC(64, 1);
}




/* 021E1050  shape F1: gate on func_021D775C(3) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021E1066; movs r0, #0x40; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021E1050(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x40, 1);
}


int *func_021E1068(int *p)
{
    *p = 1;
    return d_021F266C;
}


void func_021E1074(int unused, void *q, int id)
{
    void *a;
    void *b;
    u8 t;
    u8 x;
    u8 y;

    if (id == func_021D775C(3)) {
        t = func_021D775C(4);
        a = func_021C7CF4(q, t);
        b = func_021C7CF4(q, id);
        x = func_021D59B4(b, 0x12);
        y = func_021D59B4(a, 0x12);
        if (x == 2 || y == 2 || x == y)
            func_021D76BC(0x40, 1);
    }
}


/*
 * sdk:      DWC_GdbInitialize (libdwcgdb.TWL.HYB.a(dwc_gdb.o))
 */
int *func_021E10CC(int *p)
{
    *p = 1;
    return d_021F263C;
}
