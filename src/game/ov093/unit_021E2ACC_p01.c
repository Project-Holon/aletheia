/*
 * file:     unit_021E2ACC_p01.c
 * unit:     yes
 * function: func_021E2ACC, func_021E2B18, func_021E2B5C, func_021E2BB4, func_021E2BF4, func_021E2C4C
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
 */
struct Unk021D62A8;
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
void func_021E2ACC(int u, void *p, int k);
u8 *func_021E2B0C(int *p);
void func_021E2B18(int u, void *p, int k);
void func_021E2B5C(int u, void *p, int k);
u8 *func_021E2BA8(int *p);
void func_021E2BB4(int u, void *p, int k);
void func_021E2BF4(int u, void *p, int k);
u8 *func_021E2C40(int *p);
void func_021E2C4C(int u, void *a, int b, int *p);
extern u8 d_021F29F8[];
extern u8 d_021F2A08[];
extern u8 d_021F2CC0[];


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
