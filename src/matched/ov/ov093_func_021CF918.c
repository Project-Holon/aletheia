/*
 * function: func_021CF918
 * address:  0x021CF918
 * packet:   pkt_ov093_021CF918
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021CF89C  0x021CF89C  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021CF9B4  0x021CF9B4  thumb  ov093
 */
#include "../include/Obj07774.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct S2;
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *m);
extern int func_021CF89C(u8 *p, void *q);
struct QI;
extern u16 func_021D5B40(struct QI *p);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021CF9B4(u8 *g, void *m, u8 *a, u16 *b);

u32 func_021CF918(u8 *g, u8 *a, u16 *b)
{
    u32 i;
    u8 *m;
    u32 r;

    for (i = 0; i < g[0x11c]; i++) {
        m = func_021B9C00(((struct Obj07774 *)g)->f118, (u8)i);
        if (func_021D5B68(m) == 0) {
            if (func_021CF89C(g, m) != 0 && func_021D5B40((struct QI *)m) == 0xe4)
                return 4;
            if (func_021D59B4(m, 0x11) == 0x32)
                return 4;
        }
    }
    for (i = 0; i < g[0x11c]; i++) {
        r = func_021CF9B4(g, func_021B9C00(((struct Obj07774 *)g)->f118, (u8)i), a, b);
        if (r != 4)
            return r;
    }
    return 4;
}
