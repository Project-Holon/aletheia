/*
 * function: func_021D89B8
 * address:  0x021D89B8
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D89B8   0x021D89B8  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C804C   0x021C804C  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *
 * Gate on func_021D775C(2); the counter at +4 of d must reach 5 -- the
 * func_021C804C(b,c,&v) block bumps it once (rejecting a low nibble of 3) --
 * then record #4 is published as a two-string record and d's flag pair is set
 * to (0, 1).
 */
#include "../include/Obj04900.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
int func_021C804C(int a, int b, void *v);
void *func_021C88A4(int a, int k, int b);
void func_021C8838(void *p, int a, int b);
struct S;
void func_021C8860(struct S *p, unsigned int a);
void func_021C88C8(void *a, void *b);

void func_021D89B8(void *a, int b, int c, void *d)
{
    struct { unsigned int kind : 4; } v;
    u8 *p;

    if (c != func_021D775C(2))
        return;
    if (((struct Obj04900 *)d)->f8 != 0)
        return;
    if (((struct Obj04900 *)d)->f4 < 5) {
        if (func_021C804C(b, c, &v) == 0)
            return;
        if (v.kind == 3)
            return;
        ((struct Obj04900 *)d)->f4 += 1;
    }
    if (((struct Obj04900 *)d)->f4 < 5)
        return;
    p = func_021C88A4(b, 4, c);
    func_021C8838(p + 4, 2, 0x1f3);
    func_021C8860((struct S *)(p + 4), c);
    func_021C88C8((void *)b, p);
    ((struct Obj04900 *)d)->fC = 0;
    ((struct Obj04900 *)d)->f8 = 1;
}
