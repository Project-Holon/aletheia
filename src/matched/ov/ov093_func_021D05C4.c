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
 *   BTL_MAIN_GetRule  0x021B8588  thumb  ov093
 *   BTL_CALC_GetScanStartIndex  0x021D7F2C  thumb  ov093
 *   BTL_CLIENT_HasSlotInOrder  0x021CFBBC  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   BTL_POKEPARAM_IsAbleToBattle  0x021D5B7C  thumb  ov093
 *   BTL_POKEPARAM_GetTypePair  0x021D57FC  thumb  ov093
 *   BTL_CALC_GetTypeAffinityVsPair  0x021D799C  thumb  ov093
 */
#include "../include/Obj03197.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct Q1;
struct S2;
extern u8 func_021B9B94(struct Q1 *p);
extern u32 BTL_MAIN_GetRule(void **p);
extern u8 BTL_CALC_GetScanStartIndex(u32 a, u8 b);
typedef signed char    s8;
extern int BTL_CLIENT_HasSlotInOrder(s8 *p, int v);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsAbleToBattle(void *m);
extern u16 BTL_POKEPARAM_GetTypePair(void *m);
extern int BTL_CALC_GetTypeAffinityVsPair(int a, int b);

int func_021D05C4(u8 *g, u8 a, int b, u8 *out)
{
    u32 n;
    u32 i;
    u8 *m;

    n = func_021B9B94(((struct Obj03197 *)g)->f118);
    i = BTL_CALC_GetScanStartIndex(BTL_MAIN_GetRule(((struct Obj03197 *)g)->f0), g[0x11c]);
    for (; i < n; i++) {
        if (BTL_CLIENT_HasSlotInOrder((s8 *)g, (u8)i) == 0) {
            m = func_021B9C00(((struct Obj03197 *)g)->f118, (u8)i);
            if (BTL_POKEPARAM_IsAbleToBattle(m) != 0 && BTL_CALC_GetTypeAffinityVsPair(a, BTL_POKEPARAM_GetTypePair(m)) <= b) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}
