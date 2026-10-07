/*
 * file:     unit_021DC32C.c
 * unit:     yes
 * function: func_021DC32C, func_021DC4A4, func_021DC4D4, func_021DC564
 * address:  0x021DC32C
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
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C88B4 0x021C88B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F0658 0x021F0658 data a4
 *   d_021F05F8 0x021F05F8 data a4
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021D85C0  0x021D85C0  thumb  ov093
 *   func_021D7D18  0x021D7D18  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D84F0 0x021D84F0 thumb ov093
 *   d_021F0600 0x021F0600 data a4
 */
#include "../../matched/include/Obj03701.h"
#include "../../matched/include/Obj06260.h"

struct S;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern u8 *func_021C8120(u8 *p, int b);
extern int func_021D5D14(s8 *p, int i, int sign);
extern u32 func_021D78AC(u32 k);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021D76BC(int,unsigned int);
extern u32 func_0201BEB8(u16 id, u32 bit);
extern int func_021D85C0(int a, u32 b);
extern u32 func_021D7D18(int x);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern unsigned int func_021D84F0(unsigned int, unsigned int);
void func_021DC32C(int a, void *b, u8 c);
void *func_021DC498(int *p);
void func_021DC4A4(int a, int b, int c);
void *func_021DC4C8(int *p);
void func_021DC4D4(int u, void *a, int b);
void *func_021DC564(unsigned int *p);
extern u8 d_021F0658[];
extern unsigned char d_021F05F8[];
extern unsigned char d_021F0600[];

/*
 * Pointer-sum grouping preserves both candidate-list load sequences.
 * Signed byte storage of -1 preserves the subtraction from the live one.
 */
void func_021DC32C(int a, void *b, u8 c)
{
    u8 *buf;
    void *m;
    u8 n1;
    u8 n2;
    u32 i;
    u8 n;
    u32 j;
    u8 first;
    u8 second;
    u16 pair;
    u8 *r;
    if (c == func_021D775C(2)) {
        buf = func_021C8120(b, 0xb6);
        m = func_021C7CF4(b, c);
        n2 = 0;
        n1 = 0;
        for (i = 0; i < 7; i++) {
            if (func_021D5D14(m, i + 1, 1)) buf[0xa8 + n1++] = i + 1;
            if (func_021D5D14(m, i + 1, -1)) buf[0xaf + n2++] = i + 1;
        }
        second = 0;
        first = 0;
        if (n1 == 0 && n2 != 0) {
            second = (buf + func_021D78AC(n2))[0xaf];
        } else if (n1 != 0 && n2 == 0) {
            first = (buf + func_021D78AC(n1))[0xa8];
        } else if (n1 != 0 && n2 != 0) {
            n = 0;
            for (i = 0; i < n1; i++) {
                for (j = 0; j < n2; j++) {
                    if (buf[0xa8 + i] != buf[0xaf + j]) {
                        ((u16 *)buf)[n++] = (buf[0xa8 + i] << 8) | buf[0xaf + j];
                        if (n >= 0x54) break;
                    }
                }
            }
            pair = ((u16 *)buf)[func_021D78AC(n)];
            first = pair >> 8;
            second = pair;
        }
        func_021C88B4(b, 2, c);
        if (first) {
            r = (u8 *)func_021C88A4(b, 14, c);
            r[15] = 1;
            r[16] = c;
            ((struct Obj03701 *)r)->f4 = first;
            r[12] = 2;
            func_021C88C8(b, r);
        }
        if (second) {
            r = (u8 *)func_021C88A4(b, 14, c);
            r[15] = 1;
            r[16] = c;
            ((struct Obj03701 *)r)->f4 = second;
            *(s8 *)&((struct Obj03701 *)r)->fC = -1;
            func_021C88C8(b, r);
        }
        func_021C88B4(b, 3, c);
    }
}

void *func_021DC498(int *p) { *p = 1; return d_021F0658; }

void func_021DC4A4(int a, int b, int c) { if (c == func_021D775C(2) && func_021D775C(50) > 0) func_021D76BC(65,1); }

void *func_021DC4C8(int *p) { *p = 1; return d_021F05F8; }


void func_021DC4D4(int u, void *a, int b)
{
    u8 *e;
    if (b == func_021D775C(3)
        && func_021D775C(0x46) == 0
        && func_021D775C(0x47) == 0
        && func_0201BEB8(func_021D775C(0x12), 0) != 0
        && func_021D85C0((int)a, 0x1e) != 0) {
        e = func_021C88A4(a, 0xc, b);
        ((struct Obj06260 *)e)->f0 |= 2 << 22;
        e[0xf] = func_021D775C(4);
        ((struct Obj06260 *)e)->f4 = 5;
        ((struct Obj06260 *)e)->f8 = func_021D7D18(5);
        func_021C8838(e + 0x14, 2, 0x1d8);
        func_021C8860((struct S *)(e + 0x14), e[0xf]);
        func_021C88C8(a, e);
    }
}

void *func_021DC564(unsigned int *p)
{
    *p = func_021D84F0(4, 1);
    return d_021F0600;
}
