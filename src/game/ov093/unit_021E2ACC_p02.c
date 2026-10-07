/*
 * file:     unit_021E2ACC_p02.c
 * unit:     yes
 * function: func_021E2DC0, func_021E2E28, func_021E2E90
 * address:  0x021E2DC0
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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F2D3C     0x021F2D3C  data  ov093  a4
 *   d_021F24C4     0x021F24C4  data  ov093  a4
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021D679C  0x021D679C  thumb  ov093
 *   d_021F25AC     0x021F25AC  data  ov093  a4
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021E8860  0x021E8860  thumb  ov093
 *   d_021F24CC     0x021F24CC  data  ov093  a4
 */
struct QL;
struct QQ;
struct UtilWork;
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
extern u16 func_021D67A8(struct QL *p);
extern u16 func_021D70A8(struct QQ *p);
extern u16 func_021D679C(u8 *p);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern void func_021E8860(int n);
void func_021E2DC0(int u, void *p, int k);
u8 *func_021E2E1C(int *p);
void func_021E2E28(int u, void *p, int k);
u8 *func_021E2E84(int *p);
void func_021E2E90(int u, void *p, int k);
u8 *func_021E2EC8(int *p);
extern u32 d_021F2D3C[];
extern u8 d_021F24C4[];
extern u8 d_021F25AC[];
extern u8 d_021F24CC[];


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
