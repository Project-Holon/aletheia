/*
 * function: func_021DAE38
 * address:  0x021DAE38
 * packet:   pkt_ov093_021DAE38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */
#include "../include/Obj21317.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);

void func_021DAE38(int unused, void *a, int id, int *f)
{
    u8 *r;
    u32 k;

    if (*f != 0) {
        k = (u8)func_021D775C(2);
        r = (u8 *)func_021C88A4(a, 4, id);
        ((struct Obj21317 *)r)->f0 |= 0x800000;
        func_021C8838(r + 4, 2, 0x389);
        func_021C8860((struct S *)(r + 4), k);
        func_021C8860((struct S *)(r + 4), f[1]);
        func_021C88C8(a, r);
        *f = 0;
    }
}
