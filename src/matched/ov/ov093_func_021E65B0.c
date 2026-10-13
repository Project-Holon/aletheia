/*
 * unit:     yes
 * function: func_021E65B0, func_021E6648
 * address:  0x021E65B0
 * packet:   pkt_ov093_021E65B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   PALANM_IsColorCodeKnown  0x020213C0  thumb
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F2B28     0x021F2B28  data   ov093  a4
 */
#include "../include/Obj06277.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int PALANM_IsColorCodeKnown(u32 a);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern int d_021F2B28[];

void func_021E65B0(int u, void *a, u32 b)
{
    u8 *e;
    u8 k;
    u16 t;

    if (b == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        t = (int)BTL_POKEPARAM_GetItem(func_021C7CF4(a, k));
        if (PALANM_IsColorCodeKnown(t) != 0) {
            e = func_021C88A4(a, 0x20, b);
            e[6] = k;
            ((struct Obj06277 *)e)->f4 = 0;
            func_021C8838(e + 0xc, 2, 0x308);
            func_021C8860((struct S *)(e + 0xc), b);
            func_021C8860((struct S *)(e + 0xc), t);
            func_021C88C8(a, e);
            e = func_021C88A4(a, 0x22, b);
            ((struct Obj06277 *)e)->f0 |= 2 << 23;
            ((struct Obj06277 *)e)->f6 = t;
            e[4] = b;
            func_021C88C8(a, e);
        }
    }
}

int *func_021E6648(int *p)
{
    *p = 3;
    return d_021F2B28;
}
