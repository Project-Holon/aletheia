/*
 * file:     unit_021E4154.c
 * unit:     yes
 * function: func_021E4154, func_021E4220, func_021E4238, func_021E42B0, func_021E4334
 * address:  0x021E4154
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
 *   d_021F27A4     0x021F27A4  data   ov093  a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_CALC_DivideMaxHpMin1 0x021D7B74 thumb ov093
 *   func_021D5D50 0x021D5D50 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   d_021F2B10 0x021F2B10 data a4
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021B9A5C  0x021B9A5C  thumb  ov093
 *   func_021C82C4  0x021C82C4  thumb  ov093
 */
#include "../../matched/include/Obj02138.h"
#include "../../matched/include/Obj13518.h"

struct S;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed char    s8;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int);
extern void *func_021C7CF4(int *p, int i);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern int func_021D5D50(s8 *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *p, u32 val);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern unsigned char func_021B9A40(unsigned int x);
extern u8 func_021B9A5C(u32 x);
extern int func_021C82C4(int a, int b, int c);
void func_021E4154(int unused, void *s, int k);
int *func_021E4214(int *p);
/* 021E4220 shape F1: gate on BTL_EVENT_GetVar(3) */ void func_021E4220(int a, int b, int c);
void func_021E4238(int a0, u8 *s, int k, int *pf);
void func_021E42B0(int a0, u8 *s, int k, int *pf);
extern int d_021F2B10[];


void func_021E4154(int unused, void *s, int k)
{
    void *q;
    int n;
    int t;
    u8 *p;
    if (k == BTL_EVENT_GetVar(3)) {
        q = func_021C7CF4(s, k);
        n = BTL_CALC_DivideMaxHpMin1(q, 2);
        t = func_021D5D50(q, 1);
        if (func_021D59B4(q, 13) > (u32)n && t != 0) {
            p = func_021C88A4(s, 8, k);
            p[4] = 1;
            p[6] = 1;
            p[7] = k;
            ((struct Obj02138 *)p)->f10 = -n;
            func_021C88C8(s, p);
            p = func_021C88A4(s, 14, k);
            *(int *)(p + 4) = 1;
            p[12] = t;
            p[15] = 1;
            p[16] = k;
            p[13] = 1;
            p[14] = 1;
            func_021C88C8(s, p);
            p = func_021C88A4(s, 4, k);
            func_021C8838(p + 4, 2, 613);
            func_021C8860((struct S *)(p + 4), k);
            func_021C88C8(s, p);
            p = func_021C88A4(s, 33, k);
            p[4] = k;
            ((struct Obj02138 *)p)->f8 = 1;
            func_021C88C8(s, p);
        }
    }
}


int *func_021E4214(int *p)
{
    *p = 3;
    return d_021F2B10;
}


/* 021E4220  shape F1: gate on BTL_EVENT_GetVar(3) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021E4236; movs r0, #0x51; movs r1, #1; bl BTL_EVENT_OverwriteVar; pop {r4, pc}.
 */
void func_021E4220(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3))
        BTL_EVENT_OverwriteVar(0x51, 1);
}


void func_021E4238(int a0, u8 *s, int k, int *pf)
{
    u8 v;
    u8 *e;
    u8 *e2;

    if (k == BTL_EVENT_GetVar(3)) {
        v = BTL_EVENT_GetVar(4);
        if (BTL_POKEPARAM_TestTurnFlag(func_021C7CF4((int *)s, v), 7) != 0 || *pf != 0) {
            e = func_021C88A4((char *)s, 0x16, k);
            e[8] = v;
            ((struct Obj13518 *)e)->f4 = 7;
            func_021C88C8(s, e);
            e2 = func_021C88A4((char *)s, 4, k);
            func_021C8838(e2 + 4, 2, 526);
            func_021C8860((struct S *)(e2 + 4), v);
            func_021C88C8(s, e2);
        }
    }
}


void func_021E42B0(int a0, u8 *s, int k, int *pf)
{
    int v;
    u32 i;
    u8 *e;

    if (k == BTL_EVENT_GetVar(3)) {
        v = func_021B9A5C(func_021B9A40(k));
        if (func_021C82C4((int)s, v, 9) != 0 || func_021C82C4((int)s, v, 10) != 0) {
            e = func_021C88A4((char *)s, 0x1a, k);
            e[7] = v;
            e[4] = 3;
            for (i = 1; i < 3; i++)
                e[4 + i] = 0;
            if (e[4] > 2)
                e[6] |= 2;
            if (e[4] > 2)
                e[6] |= 4;
            func_021C88C8(s, e);
            *pf = 1;
        }
    }
}


extern int d_021F27A4[];
int *func_021E4334(int *p);

int *func_021E4334(int *p)
{
    *p = 1;
    return d_021F27A4;
}
