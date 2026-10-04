/*
 * function: func_021E5EB8
 * address:  0x021E5EB8
 * packet:   pkt_ov093_021E5EB8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13529.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(void *a, int k, int b);
typedef struct Word { u32 v; } Word;
extern Word func_021E8940(u8 v);
extern void func_021C8838(void *l, int a, int b);
struct S;
extern void func_021C8860(struct S *, unsigned int);
extern void func_021C88C8(void *a, void *b);

void func_021E5EB8(u8 *p, void *a, int b)
{
    u8 *q;
    if (b != func_021D775C(3))
        return;
    q = func_021C88A4(a, 0xc, b);
    q[0xf] = b;
    ((struct Obj13529 *)q)->f4 = 0x1e;
    *(Word *)(q + 8) = func_021E8940(5);
    func_021C8838(q + 0x14, 2, 0x292);
    func_021C8860((struct S *)(q + 0x14), b);
    func_021C88C8(a, q);
}
