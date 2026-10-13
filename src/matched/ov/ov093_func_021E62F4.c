/*
 * unit:     yes
 * function: func_021E62F4, func_021E6348, func_021E634C
 * address:  0x021E62F4
 * packet:   pkt_ov093_021E62F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F2AC8     0x021F2AC8  data   ov093  a4
 */
#include "../include/Obj13533.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern int d_021F2AC8[];

void func_021E62F4(int u, void *a, u32 b)
{
    u8 *e;

    if (b == BTL_EVENT_GetVar(3)) {
        e = func_021C88A4(a, 0x17, b);
        e[8] = b;
        ((struct Obj13533 *)e)->f4 = 3;
        func_021C88C8(a, e);
        e = func_021C88A4(a, 4, b);
        func_021C8838(e + 4, 2, 0x220);
        func_021C8860((struct S *)(e + 4), b);
        func_021C88C8(a, e);
    }
}

void func_021E6348(void)
{
}

int *func_021E634C(int *p)
{
    *p = 2;
    return d_021F2AC8;
}
