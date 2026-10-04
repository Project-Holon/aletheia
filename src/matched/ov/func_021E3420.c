/*
 * function: func_021E3420
 * address:  0x021E3420
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E3420   0x021E3420  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021E86E8   0x021E86E8  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D5B40   0x021D5B40  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *
 * Gate on func_021D775C(3), then func_021E86E8(b,c,(u8)func_021D775C(6))
 * must be zero and the (u16) of func_021D5B40(func_021C7CF4(b,k)) non-zero.
 * Record #0x20 carries k, a zero halfword and a three-string tail (c, k and
 * that halfword).
 */
#include "../include/Obj12158.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
int func_021E86E8(void *a, int b, int c);
void *func_021C7CF4(int *p, int i);
int func_021D5B40(void *p);
void *func_021C88A4(int a, int k, int b);
void func_021C8838(void *p, int a, int b);
struct S;
void func_021C8860(struct S *p, unsigned int a);
void func_021C88C8(void *a, void *b);

void func_021E3420(void *a, int b, int c)
{
    u8 k;
    u16 v;
    u8 *p;

    if (c != func_021D775C(3))
        return;
    k = (u8)func_021D775C(6);
    if (func_021E86E8((void *)b, c, k) != 0)
        return;
    v = (u16)func_021D5B40(func_021C7CF4((int *)b, k));
    if (v == 0)
        return;
    p = func_021C88A4(b, 0x20, c);
    ((struct Obj12158 *)p)->f6 = k;
    ((struct Obj12158 *)p)->f4 = 0;
    func_021C8838(p + 0xc, 2, 0x41a);
    func_021C8860((struct S *)(p + 0xc), c);
    func_021C8860((struct S *)(p + 0xc), k);
    func_021C8860((struct S *)(p + 0xc), v);
    func_021C88C8((void *)b, p);
}
