/*
 * file:     unit_021E6358.c
 * unit:     yes
 * function: func_021E6358, func_021E63AC, func_021E63B0
 * address:  0x021E6358
 * packet:   pkt_ov093_021E6358
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F2AD8     0x021F2AD8  data   ov093  a4
 */
#include "../../matched/include/Obj13534.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern int d_021F2AD8[];

void func_021E6358(int u, void *a, u32 b)
{
    u8 *e;

    if (b == func_021D775C(3)) {
        e = func_021C88A4(a, 0x17, b);
        e[8] = b;
        ((struct Obj13534 *)e)->f4 = 4;
        func_021C88C8(a, e);
        e = func_021C88A4(a, 4, b);
        func_021C8838(e + 4, 2, 0x217);
        func_021C8860((struct S *)(e + 4), b);
        func_021C88C8(a, e);
    }
}

void func_021E63AC(void)
{
}

int *func_021E63B0(int *p)
{
    *p = 2;
    return d_021F2AD8;
}
