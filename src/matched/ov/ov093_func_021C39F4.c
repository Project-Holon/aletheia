/*
 * function: BTL_SERVER_FLOW_PickRandomBenchPoke
 * address:  0x021C39F4
 * packet:   pkt_ov093_021C39F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B99C0  0x021B99C0  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   BTL_POKEPARAM_IsAbleToBattle  0x021D5B7C  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 */
#include "../include/Obj09971.h"
#include "../include/Obj21091.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Q1;
struct S;
struct S2;
extern u8 func_021B9B94(struct Q1 *p);
extern int func_021B99C0(struct S **p, u32 b);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsAbleToBattle(void *m);
extern u32 BTL_CALC_Random(u32 range);

int BTL_SERVER_FLOW_PickRandomBenchPoke(u8 *a, u8 *b)
{
    u8 buf[8];
    u32 n;
    u32 i;
    int c;

    n = func_021B9B94(((struct Obj09971 *)b)->f4);
    i = func_021B99C0(((struct Obj21091 *)a)->f4, b[0xb]);
    c = 0;
    for (; i < n; i++) {
        if (BTL_POKEPARAM_IsAbleToBattle(func_021B9C00(((struct Obj09971 *)b)->f4, (u8)i))) {
            buf[c] = i;
            c++;
        }
    }
    if (c != 0) {
        return buf[BTL_CALC_Random(c)];
    }
    return -1;
}
