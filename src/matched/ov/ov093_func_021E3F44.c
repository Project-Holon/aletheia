/*
 * unit:     yes
 * function: func_021E3F44, func_021E3FB4
 * address:  0x021E3F44
 * packet:   pkt_ov093_021E3F44
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
 *   BTL_POKEPARAM_GetConsumedItem  0x021D6740  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F27C4     0x021F27C4  data   a4
 */
#include "../include/Obj10088.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern int BTL_EVENT_GetVar(int);
struct QI;
struct QK;
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u16 BTL_POKEPARAM_GetConsumedItem(struct QK *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, unsigned int val);
extern void func_021C88C8(void *a, void *p);
extern int d_021F27C4[];

void func_021E3F44(int u, void *a, int c)
{
    void *q;
    int h;
    char *p;

    if (c == BTL_EVENT_GetVar(3)) {
        q = func_021C7CF4(a, c);
        if (BTL_POKEPARAM_GetItem(q) == 0) {
            h = BTL_POKEPARAM_GetConsumedItem(q);
            if (h != 0) {
                p = func_021C88A4(a, 0x20, c);
                ((struct Obj10088 *)p)->f4 = h;
                p[6] = c;
                p[7] = 1;
                func_021C8838(p + 0xc, 2, 0x2dd);
                func_021C8860((struct S *)(p + 0xc), c);
                func_021C8860((struct S *)(p + 0xc), h);
                func_021C88C8(a, p);
            }
        }
    }
}

int *func_021E3FB4(int *p)
{
    *p = 1;
    return d_021F27C4;
}
