/*
 * unit:     yes
 * function: func_021E56E0, func_021E5714
 * address:  0x021E56E0
 * packet:   pkt_ov093_021E56E0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F29D8     0x021F29D8  data   ov093  a4
 */
#include "../include/Obj13527.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021C8010(u8 *p, unsigned int v);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern int d_021F29D8[];

void func_021E56E0(int a, void *b, int c)
{
    u8 *m;

    if (c == func_021D775C(3)) {
        m = (u8 *)func_021C88A4(b, 0x1e, c);
        ((struct Obj13527 *)m)->f4 = 0;
        m[8] = func_021C8010(b, c);
        func_021C88C8(b, m);
    }
}

int *func_021E5714(int *p)
{
    *p = 2;
    return d_021F29D8;
}
