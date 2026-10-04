/*
 * function: func_021DC738
 * address:  0x021DC738
 * packet:   pkt_ov093_021DC738
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7B60  0x021D7B60  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj00041.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(void *p);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021D7B60(void *p, u32 b);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, u16 b);
extern void func_021C88C8(void *a, void *b);

void func_021DC738(int a, void *b, int c)
{
    u8 *m;
    u8 f;

    m = (u8 *)func_021C7CF4(b, c);
    if (func_021D5444(m) == 0x22b) {
        f = (func_021D59B4(m, 13) <= func_021D7B60(m, 2));
        if (f != func_021D59B4(m, 0x13)) {
            m = (u8 *)func_021C88A4(b, 0x39, c);
            *(u32 *)&((struct Obj00041 *)m)->f0 |= 2 << 22;
            m[4] = c;
            m[5] = f;
            func_021C8838(m + 8, 1, f == 1 ? 0xb9 : 0xba);
            func_021C88C8(b, m);
        }
    }
}
