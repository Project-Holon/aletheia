/*
 * function: func_021D0980
 * address:  0x021D0980
 * packet:   pkt_ov093_021D0980
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   BTL_MAIN_GetRule  0x021B8588  thumb  ov093
 *   BTL_CALC_GetScanStartIndex  0x021D7F2C  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   BTL_POKEPARAM_IsAbleToBattle  0x021D5B7C  thumb  ov093
 */
#include "../include/Obj00489.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct Q1;
struct S2;
extern u8 func_021B9B94(struct Q1 *p);
extern u32 BTL_MAIN_GetRule(void **p);
extern u8 BTL_CALC_GetScanStartIndex(u32 a, u8 b);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsAbleToBattle(void *m);

u8 func_021D0980(u8 *g, u8 *out)
{
    u32 n;
    u8 c;
    u32 i;

    n = func_021B9B94(((struct Obj00489 *)g)->f118);
    i = BTL_CALC_GetScanStartIndex(BTL_MAIN_GetRule(((struct Obj00489 *)g)->f0), g[0x11c]);
    c = 0;
    for (; i < n; i = (u8)(i + 1)) {
        if (BTL_POKEPARAM_IsAbleToBattle(func_021B9C00(((struct Obj00489 *)g)->f118, i))) {
            if (out)
                out[c] = i;
            c = (u8)(c + 1);
        }
    }
    return c;
}
