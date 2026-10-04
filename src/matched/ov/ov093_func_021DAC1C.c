/*
 * function: func_021DAC1C
 * address:  0x021DAC1C
 * packet:   pkt_ov093_021DAC1C
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
#include "../include/Obj21310.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);

void func_021DAC1C(int unused, void *a, int id, int *f)
{
    u8 *r;

    if (id == func_021D775C(2) && *f != 0) {
        r = (u8 *)func_021C88A4(a, 4, id);
        ((struct Obj21310 *)r)->f0 |= 0x800000;
        func_021C8838(r + 4, 2, 0xd2);
        func_021C8860((struct S *)(r + 4), id);
        func_021C88C8(a, r);
        *f = 0;
    }
}
