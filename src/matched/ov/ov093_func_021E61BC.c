/*
 * function: func_021E61BC
 * address:  0x021E61BC
 * packet:   pkt_ov093_021E61BC
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
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13530.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *l, int a, int b);
struct S;
extern void func_021C8860(struct S *l, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021E61BC(u8 *p, void *a, int b)
{
    u8 *q;
    u8 *r;
    if (b != func_021D775C(3))
        return;
    q = func_021C88A4(a, 0x17, b);
    q[8] = b;
    ((struct Obj13530 *)q)->f4 = 3;
    func_021C88C8(a, q);
    r = func_021C88A4(a, 4, b);
    func_021C8838(r + 4, 2, 0x211);
    func_021C8860((struct S *)(r + 4), b);
    func_021C88C8(a, r);
}
