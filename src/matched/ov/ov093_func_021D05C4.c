/*
 * function: func_021D05C4
 * address:  0x021D05C4
 * packet:   pkt_ov093_021D05C4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021D7F2C  0x021D7F2C  thumb  ov093
 *   func_021CFBBC  0x021CFBBC  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021D799C  0x021D799C  thumb  ov093
 */
#include "../include/Obj03197.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct Q1;
struct S2;
extern u8 func_021B9B94(struct Q1 *p);
extern u32 func_021B8588(void **p);
extern u8 func_021D7F2C(u32 a, u8 b);
extern int func_021CFBBC(void *g, u8 k);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B7C(void *m);
extern u16 func_021D57FC(void *m);
extern int func_021D799C(int a, int b);

int func_021D05C4(u8 *g, u8 a, int b, u8 *out)
{
    u32 n;
    u32 i;
    u8 *m;

    n = func_021B9B94(((struct Obj03197 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj03197 *)g)->f0), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC(g, i) == 0) {
            m = func_021B9C00(((struct Obj03197 *)g)->f118, (u8)i);
            if (func_021D5B7C(m) != 0 && func_021D799C(a, func_021D57FC(m)) <= b) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}
