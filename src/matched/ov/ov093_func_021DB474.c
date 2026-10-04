/*
 * function: func_021DB474
 * address:  0x021DB474
 * packet:   pkt_ov093_021DB474
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */
#include "../include/Obj21327.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021E85F8(int id);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);

void func_021DB474(int unused, void *a, int id, int *f)
{
    u8 *r;

    if (*f != 0) {
        if (func_021E85F8(id) != 0) {
            r = (u8 *)func_021C88A4(a, 4, id);
            ((struct Obj21327 *)r)->f0 |= 0x800000;
            func_021C8838(r + 4, 2, 0x1c0);
            func_021C8860((struct S *)(r + 4), id);
            func_021C88C8(a, r);
        }
        *f = 0;
    }
}
