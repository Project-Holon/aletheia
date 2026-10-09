/*
 * file:     unit_021DC6EC.c
 * unit:     yes
 * function: func_021DC6EC, func_021DC6F8, func_021DC738, func_021DC7BC, func_021DC814, func_021DC820, func_021DC844, func_021DC864, func_021DC87C, func_021DC888, func_021DC894, func_021DC8FC, func_021DC908, func_021DC954
 * address:  0x021DC6EC
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
 *   d_021F0990 0x021F0990 data a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7B60  0x021D7B60  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70AC 0x021D70AC thumb ov093
 *   func_021B9A40 0x021B9A40 thumb ov093
 *   func_021D7320 0x021D7320 thumb ov093
 *   func_021D7324   0x021D7324  thumb
 *   d_021F0B48     0x021F0B48  data   ov093  a4
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   d_021F0A00     0x021F0A00  data   ov093  a4
 *   d_021F0770     0x021F0770  data   ov093  a4
 *   d_021F05D0     0x021F05D0  data   ov093  a4
 *   d_021F05B0     0x021F05B0  data   ov093  a4
 */
#include "../../matched/include/Obj00041.h"
#include "../../matched/include/Obj06261.h"
#include "../../matched/include/Obj06262.h"

struct QF;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct QS { u8 pad[12]; u32 v; };

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021C8288(u8 *p);
extern void func_021D7704(int a, int b);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021D7B60(void *p, u32 b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8860(struct S *p, u32 v);
extern u8 func_021D70AC(u8 *);
extern u8 func_021B9A40(unsigned int);
extern void func_021D7320(struct QS *, u32);
extern int func_021D5B68(void *p);
void *func_021DC6EC(int *p);
void func_021DC6F8(int a, void *p, int v);
void func_021DC738(int a, void *b, int c);
void func_021DC7BC(int a, void *b, int c);
int *func_021DC814(int *p);
int func_021DC820(u8 *a, int b, int c, int d, u16 e, u8 f);
void func_021DC844(struct QS *a, int b, int c);
void func_021DC864(int a, int b, int c);
int *func_021DC87C(int *p);
int *func_021DC888(int *p);
void func_021DC894(int a, void *b, u8 c);
int *func_021DC8FC(int *p);
void func_021DC908(int a, void *b, int c);
int *func_021DC954(int *p);
extern unsigned char d_021F0990[];
/*
 * lever: scalar u16/u8 stack inputs; named result preserves cmp operand order.
 */
extern int d_021F0B48[];
extern int d_021F0A00[];
extern int d_021F0770[];
extern int d_021F05D0[];
extern int d_021F05B0[];




/*
 * extent: 12-byte store/return follower after non-C veneer 021DC6DC.
 */
void *func_021DC6EC(int *p) { *p = 2; return d_021F0990; }





void func_021DC6F8(int a, void *p, int v)
{
    u8 k;

    if (v == func_021D775C(3) && func_021C8288(p) == 4) {
        k = func_021D775C(0x16);
        if (k == 4 || k == 5 || k == 8)
            func_021D7704(0x31, 0x14cd);
    }
}





void func_021DC738(int a, void *b, int c)
{
    u8 *m;
    u8 f;

    m = (u8 *)func_021C7CF4(b, c);
    if (func_021D5444((struct QF *)m) == 0x22b) {
        f = (func_021D59B4(m, 13) <= func_021D7B60(m, 2));
        if (f != func_021D59B4(m, 0x13)) {
            m = (u8 *)func_021C88A4(b, 0x39, c);
            *(u32 *)&((struct Obj00041 *)m)->f0 |= 2 << 22;
            m[4] = c;
            m[5] = f;
            func_021C8838(m + 8, 1, (u16)(f == 1 ? 0xb9 : 0xba));
            func_021C88C8(b, m);
        }
    }
}





void func_021DC7BC(int a, void *b, int c)
{
    u8 *m;

    if (c == func_021D775C(2)) {
        if (func_021D5444(func_021C7CF4(b, c)) == 0x22b) {
            m = (u8 *)func_021C88A4(b, 0x39, c);
            m[4] = c;
            m[5] = 0;
            func_021C8838(m + 8, 1, 0xba);
            func_021C8860((struct S *)(m + 8), c);
            func_021C88C8(b, m);
        }
    }
}




int *func_021DC814(int *p)
{
    *p = 3;
    return d_021F0B48;
}




int func_021DC820(u8 *a, int b, int c, int d, u16 e, u8 f) { u8 result; if (c == 2) { result = func_021B9A40(func_021D70AC(a)); if (result != f && e <= 3) return 1; } return 0; }





/*
 * interface: second payload of func_021D7320 is the unchanged callback word.
 */
void func_021DC844(struct QS *a, int b, int c) { if (c == func_021D775C(3)) func_021D7320(a, (u32)func_021DC820); }





/* 021DC864  shape F3: gate on func_021D775C(2) then func_021D7324 */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r3, r4, r5, lr}; adds r5, r0, #0; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DC87A; adds r0, r5, #0; bl func_021D7324; pop {r3, r4, r5, pc}.
 */
void func_021DC864(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D7324(a);
}



int *func_021DC87C(int *p)
{
    *p = 2;
    return d_021F0A00;
}



int *func_021DC888(int *p)
{
    *p = 1;
    return d_021F0770;
}



void func_021DC894(int a, void *b, u8 c)
{
    u32 n;
    u32 i;
    u8 *m;

    if (c == func_021D775C(3)) {
        n = func_021D775C(5);
        for (i = 0; i < n; i++) {
            if (func_021D5B68(func_021C7CF4(b, (u8)func_021D775C(i + 6))) != 0) {
                m = (u8 *)func_021C88A4(b, 0xe, c);
                ((struct Obj06261 *)m)->f0 |= 2 << 22;
                m[0xf] = 1;
                m[0x10] = c;
                ((struct Obj06261 *)m)->f4 = 1;
                m[0xc] = 1;
                func_021C88C8(b, m);
            }
        }
    }
}


int *func_021DC8FC(int *p)
{
    *p = 1;
    return d_021F05D0;
}


void func_021DC908(int a, void *b, int c)
{
    u8 *m;

    if (c == func_021D775C(4) && func_021D775C(0x46) == 0 && func_021D775C(0x16) == 0x10) {
        m = (u8 *)func_021C88A4(b, 0xe, c);
        ((struct Obj06262 *)m)->f0 |= 4 << 21;
        m[0xf] = 1;
        m[0x10] = c;
        ((struct Obj06262 *)m)->f4 = 1;
        m[0xc] = 1;
        func_021C88C8(b, m);
    }
}


int *func_021DC954(int *p)
{
    *p = 1;
    return d_021F05B0;
}
