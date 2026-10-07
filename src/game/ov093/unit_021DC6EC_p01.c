/*
 * file:     unit_021DC6EC_p01.c
 * unit:     yes
 * function: func_021DC6EC, func_021DC6F8, func_021DC738, func_021DC7BC
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
 */
#include "../../matched/include/Obj00041.h"

struct QF;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

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
void *func_021DC6EC(int *p);
void func_021DC6F8(int a, void *p, int v);
void func_021DC738(int a, void *b, int c);
void func_021DC7BC(int a, void *b, int c);
extern unsigned char d_021F0990[];

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
