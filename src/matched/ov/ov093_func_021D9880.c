/*
 * function: func_021D9880
 * address:  0x021D9880
 * packet:   pkt_ov093_021D9880
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 */
#include "../include/Obj10057.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C7CF4(int *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021D7B74(u8 *p, u32 k);

void func_021D9880(void *a, int b, int c)
{
    void *q;
    u8 *p;

    if (c == func_021D775C(0x39) && b == func_021D775C(2)) {
        q = func_021C7CF4(a, b);
        p = func_021C88A4(a, 5, b);
        ((struct Obj10057 *)p)->f0 |= 0x800000;
        p[6] = b;
        ((struct Obj10057 *)p)->f4 = func_021D7B74(q, 0x10);
        func_021C88C8(a, p);
        func_021D76BC(0x41, 1);
    }
}
