/*
 * function: func_021DB5C0
 * address:  0x021DB5C0
 * packet:   pkt_ov093_021DB5C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj07814.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021DB5C0(void *a, void *p, int id)
{
    u16 v;
    u8 *r;

    if (id == func_021D775C(4)) {
        v = func_021D775C(0x20);
        func_021D76BC(0x20, 0);
        if (v != 0) {
            r = (u8 *)func_021C88A4(p, 7, id);
            ((struct Obj07814 *)r)->f0 |= 0x800000;
            r[6] = func_021D775C(3);
            ((struct Obj07814 *)r)->f4 = v;
            func_021C8838(r + 0xc, 2, 0x1c9);
            func_021C8860((struct S *)(r + 0xc), r[6]);
            func_021C88C8(p, r);
        }
    }
}
