/*
 * file:     unit_021E2ACC.c
 * unit:     yes
 * function: func_021E2ACC, func_021E2B18, func_021E2B5C, func_021E2BB4, func_021E2BF4, func_021E2C4C, func_021E2C88, func_021E2D20, func_021E2D50, func_021E2D5C, func_021E2DB4, func_021E2DC0, func_021E2E28, func_021E2E90
 * address:  0x021E2ACC
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
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   d_021F29F8     0x021F29F8  data  ov093  a4
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021E8860  0x021E8860  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2A08     0x021F2A08  data  ov093  a4
 *   d_021F2CC0     0x021F2CC0  data  a4
 *   func_021D7AF0  0x021D7AF0  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021D5778  0x021D5778  thumb  ov093
 *   func_021D5584  0x021D5584  thumb  ov093
 *   d_021F2860     0x021F2860  data  ov093  a4
 *   d_021F24BC     0x021F24BC  data  a4
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   d_021F2D3C     0x021F2D3C  data  ov093  a4
 *   d_021F24C4     0x021F24C4  data  ov093  a4
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021D679C  0x021D679C  thumb  ov093
 *   d_021F25AC     0x021F25AC  data  ov093  a4
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   d_021F24CC     0x021F24CC  data  ov093  a4
 *   d_021F272C     0x021F272C  data   ov093  a4
 */
#include "../../matched/include/Obj13512.h"

struct Unk021D62A8;
struct S;
struct QQ;
struct UtilWork;
struct QL;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Msg {
    u8 f0[4];
    u32 f4;
    u8 f8;
    u8 f9[11];
    u8 f14;
} Msg;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern void *func_021D5844(void *m);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern int func_021D76BC(int key, u32 val);
extern u32 func_021D6D7C(u8 *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021E8860(int n);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021D7AF0(u32 pct);
extern void func_021C83DC(char *p, int x);
extern int func_021D5B48(u8 *p);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 val);
extern u32 func_021D78AC(u32 range);
extern u16 func_021D70A8(struct QQ *p);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern int func_021D59B4(u8 *p, int k);
extern u16 func_021D67A8(struct QL *p);
extern u16 func_021D679C(u8 *p);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
void func_021E2ACC(int u, void *p, int k);
u8 *func_021E2B0C(int *p);
void func_021E2B18(int u, void *p, int k);
void func_021E2B5C(int u, void *p, int k);
u8 *func_021E2BA8(int *p);
void func_021E2BB4(int u, void *p, int k);
void func_021E2BF4(int u, void *p, int k);
u8 *func_021E2C40(int *p);
void func_021E2C4C(int u, void *a, int b, int *p);
void func_021E2C88(int u, void *p, int k, int *out);
void func_021E2D20(int u, int a, int b);
int *func_021E2D50(int *p);
void func_021E2D5C(int u, void *p, int k);
u8 *func_021E2DB4(int *p);
void func_021E2DC0(int u, void *p, int k);
u8 *func_021E2E1C(int *p);
void func_021E2E28(int u, void *p, int k);
u8 *func_021E2E84(int *p);
void func_021E2E90(int u, void *p, int k);
u8 *func_021E2EC8(int *p);
extern u8 d_021F29F8[];
extern u8 d_021F2A08[];
extern u8 d_021F2CC0[];
extern u16 d_021F2860[];
extern u8 d_021F24BC[];
extern u32 d_021F2D3C[];
extern u8 d_021F24C4[];
extern u8 d_021F25AC[];
extern u8 d_021F24CC[];
extern int d_021F272C[];





void func_021E2ACC(int u, void *p, int k)
{
    u32 v;
    if (k == func_021D775C(3)) {
        v = (u32)((0xff - func_02017E1C(func_021D5844(func_021C7CF4(p, k)), 9, 0)) * 10) / 25;
        if (v == 0)
            v = 1;
        func_021D76BC(0x30, v);
    }
}





u8 *func_021E2B0C(int *p)
{
    *p = 2;
    return d_021F29F8;
}





void func_021E2B18(int u, void *p, int k)
{
    void *q;
    if (k == func_021D775C(3)) {
        q = func_021C7CF4(p, (u8)func_021D775C(4));
        if (func_021D6D7C((u8 *)((int)q)) == 0) {
            if (func_021D62C4(q, 2) != 0)
                func_021E8860(2);
        }
    }
}





void func_021E2B5C(int u, void *p, int k)
{
    u8 t;
    Msg *m;
    if (k == func_021D775C(3)) {
        t = func_021D775C(6);
        if (func_021D62C4(func_021C7CF4(p, t), 2) != 0) {
            m = func_021C88A4(p, 0xb, k);
            m->f8 = t;
            m->f14 = 1;
            m->f4 = 2;
            func_021C88C8(p, m);
        }
    }
}





u8 *func_021E2BA8(int *p)
{
    *p = 2;
    return d_021F2A08;
}





void func_021E2BB4(int u, void *p, int k)
{
    void *q;
    if (k == func_021D775C(3)) {
        q = func_021C7CF4(p, (u8)func_021D775C(4));
        if (func_021D6D7C((u8 *)((int)q)) == 0) {
            if (func_021D62C4(q, 1) != 0)
                func_021E8860(2);
        }
    }
}





void func_021E2BF4(int u, void *p, int k)
{
    u8 t;
    Msg *m;
    if (k == func_021D775C(3)) {
        t = func_021D775C(6);
        if (t != 0x1f) {
            if (func_021D62C4(func_021C7CF4(p, t), 1) != 0) {
                m = func_021C88A4(p, 0xb, k);
                m->f8 = t;
                m->f14 = 1;
                m->f4 = 1;
                func_021C88C8(p, m);
            }
        }
    }
}





u8 *func_021E2C40(int *p)
{
    *p = 3;
    return d_021F2CC0;
}





void func_021E2C4C(int u, void *a, int b, int *p)
{
    if (b == func_021D775C(3)) {
        if (func_021D7AF0(0x14) != 0)
            *p = func_021D76BC(0x51, 1);
        func_021C83DC(a, (u8)(*p != 0));
    }
}




void func_021E2C88(int u, void *p, int k, int *out)
{
    u8 b;
    u8 *m;
    void *q;
    if (k == func_021D775C(3) && *out != 0) {
        b = func_021D775C(4);
        q = func_021C7CF4(p, b);
        if (func_021D5B48(q) == 0) {
            m = func_021C88A4(p, 5, k);
            m[6] = b;
            ((struct Obj13512 *)m)->f4 = func_021D7B74(q, 4);
            func_021C8838(m + 8, 2, 0x183);
            func_021C8860((struct S *)(m + 8), b);
            func_021C88C8(p, m);
        } else {
            m = func_021C88A4(p, 4, k);
            func_021C8838(m + 4, 2, 0xd2);
            func_021C8860((struct S *)(m + 4), b);
            func_021C88C8(p, m);
        }
    }
}



void func_021E2D20(int u, int a, int b)
{
    int x;
    u32 r;

    if (b == func_021D775C(3)) {
        x = 0x50;
        r = func_021D78AC(0x50);
        if (r < 0x28)
            x = 0x28;
        else if (r >= 0x46)
            x = 0x78;
        func_021D76BC(0x30, x);
    }
}


int *func_021E2D50(int *p)
{
    *p = 1;
    return d_021F272C;
}


void func_021E2D5C(int u, void *p, int k)
{
    void *q;
    u32 n;
    int r;
    int v;
    if (k == func_021D775C(3)) {
        q = func_021C7CF4(p, k);
        r = func_021D5778(q, func_021D70A8((void *)u));
        if (r != 4) {
            n = (u8)(int)func_021D5584(q, (int)r);
            if (n >= 5)
                n = 4;
            v = d_021F2860[n];
        } else {
            v = 0x28;
        }
        func_021D76BC(0x30, v);
    }
}



u8 *func_021E2DB4(int *p)
{
    *p = 1;
    return d_021F24BC;
}




void func_021E2DC0(int u, void *p, int k)
{
    void *q;
    u32 i;
    int x;
    int sum;
    u32 v;
    if (k == func_021D775C(3)) {
        q = func_021C7CF4(p, (u8)func_021D775C(4));
        sum = 0;
        for (i = 0; i < 7; i++) {
            x = func_021D59B4(q, d_021F2D3C[i]);
            if (x > 6)
                sum += x - 6;
        }
        v = sum * 20 + 0x3c;
        if (v > 200)
            v = 200;
        func_021D76BC(0x30, v);
    }
}




u8 *func_021E2E1C(int *p)
{
    *p = 1;
    return d_021F24C4;
}




void func_021E2E28(int u, void *p, int k)
{
    void *q;
    u32 t;
    u32 n;
    u32 i;
    if (k == func_021D775C(3)) {
        q = func_021C7CF4(p, k);
        if (func_021D67A8(q) == func_021D70A8((void *)u)) {
            t = func_021D775C(0x30);
            n = func_021D679C(q);
            for (i = 0; i < n; i++) {
                t <<= 1;
                if (t > 0xa0) {
                    t = 0xa0;
                    break;
                }
            }
            func_021D76BC(0x30, t);
        }
    }
}




u8 *func_021E2E84(int *p)
{
    *p = 1;
    return d_021F25AC;
}




void func_021E2E90(int u, void *p, int k)
{
    if (k == func_021D775C(3)) {
        if (func_021D5BB0(func_021C7CF4(p, (u8)func_021D775C(4)), 2) != 0)
            func_021E8860(2);
    }
}




u8 *func_021E2EC8(int *p)
{
    *p = 1;
    return d_021F24CC;
}
