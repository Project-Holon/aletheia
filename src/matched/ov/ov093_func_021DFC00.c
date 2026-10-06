/*
 * function: func_021DFC00
 * address:  0x021DFC00
 * packet:   pkt_ov093_021DFC00
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C7F24  0x021C7F24  thumb  ov093
 *   func_021C83D4  0x021C83D4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */
#include "../include/Obj07822.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern int func_021D775C(int key);
extern int func_021E85F8(int id);
extern int func_021C7D00(u8 *p, int b);
extern int func_021C7F24(u8 *p, int i);
extern int func_021C83D4(u8 *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);

void func_021DFC00(int self, void *q, int id)
{
    u8 t;
    u8 *r;

    if (func_021E85F8(id) == 0)
        return;
    t = func_021D775C(3);
    if (func_021C7D00(q, t) == 6)
        return;
    if (func_021D775C(0x4d) != 0)
        return;
    if (func_021C7F24(q, t) == 0)
        return;
    if (func_021C83D4(q) != 0)
        return;
    r = (u8 *)func_021C88A4(q, 0x23, id);
    func_021C8838(r + 8, 2, 0x1a1);
    func_021C8860((struct S *)(r + 8), id);
    func_021C8860((struct S *)(r + 8), t);
    func_021C88C8(q, r);
    r = (u8 *)func_021C88A4(q, 0x2e, id);
    r[6] = func_021D775C(3);
    r[7] = (r[7] & ~0xf0) | 0x10;
    ((struct Obj07822 *)r)->f4 = 0x28c;
    func_021C88C8(q, r);
}
