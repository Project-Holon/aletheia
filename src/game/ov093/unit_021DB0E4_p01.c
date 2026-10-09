/*
 * file:     unit_021DB0E4_p01.c
 * unit:     yes
 * function: func_021DB0E4, func_021DB128, func_021DB134, func_021DB1A8
 * address:  0x021DB0E4
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
 *   func_021E889C  0x021E889C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C888C  0x021C888C  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021DB1C4 0x021DB1C4 thumb ov093
 *   d_021F08B0     0x021F08B0  data   ov093  a4
 */
#include "../../matched/include/Obj21319.h"

struct QQ;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021E889C(int a, int b, int c);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C888C(u8 *p, u32 v);
extern int func_021D775C(int key);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021C88B4(void *a, int k, int b);
extern void func_021C8860(struct S *p, u32 v);
extern int func_021DB1C4(unsigned short);
void func_021DB0E4(int unused, void *a, int id);
int *func_021DB128(int *p);
void func_021DB134(void *p, void *a, int id);
int func_021DB1A8(int a, int b, int c, int d, unsigned short k);
extern int d_021F08B0[];


void func_021DB0E4(int unused, void *a, int id)
{
    u8 *r;

    if (func_021E889C(unused, (int)a, id) != 0) {
        r = (u8 *)func_021C88A4(a, 4, id);
        ((struct Obj21319 *)r)->f0 |= 0x800000;
        func_021C8838(r + 4, 1, 0x48);
        func_021C888C(r + 4, 0x56a);
        func_021C88C8(a, r);
    }
}


int *func_021DB128(int *p)
{
    *p = 2;
    return d_021F08B0;
}


void func_021DB134(void *p, void *a, int id)
{
    u8 *r;
    int k;

    if (id == func_021D775C(2)) {
        switch (func_021D70A8(p)) {
        case 0xa3:
            k = 0x1f9;
            break;
        case 0xa4:
            k = 0x1f6;
            break;
        default:
            k = 0x1ba;
            break;
        }
        func_021C88B4(a, 2, id);
        r = (u8 *)func_021C88A4(a, 4, id);
        func_021C8838(r + 4, 2, k);
        func_021C8860((struct S *)(r + 4), id);
        func_021C88C8(a, r);
        func_021C88B4(a, 3, id);
    }
}


int func_021DB1A8(int a, int b, int c, int d, unsigned short k) { if (c == 4 && func_021DB1C4(k)) return 1; return 0; }
