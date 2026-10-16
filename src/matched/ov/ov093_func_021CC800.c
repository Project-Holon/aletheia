/*
 * function: BTL_SERVER_FLOW_SumSideHp
 * address:  0x021CC800
 * packet:   pkt_ov093_021CC800
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_IsClientUsed  0x021B8B9C  thumb  ov093
 *   BTL_MAIN_GetClientSide  0x021B8BC4  thumb  ov093
 *   BTL_SIDE_GetSlotOfClient  0x021B9AEC  thumb  ov093
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 */
#include "../include/Obj09984.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_MAIN_IsClientUsed(unsigned char *p, unsigned char k);
struct S2;
extern unsigned char BTL_MAIN_GetClientSide(int unused, unsigned int b);
extern char *BTL_SIDE_GetSlotOfClient(char *p, int i);
struct Q1;
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern u32 _u32_div_f(u32, u32);

void BTL_SERVER_FLOW_SumSideHp(u8 *a, u32 *out1, u32 *out2, u8 want)
{
    u32 sum;
    u32 j;
    u32 i;
    char *p;
    u32 n;
    u8 *t;

    sum = 0;
    *out1 = 0;
    *out2 = 0;
    for (j = 0; j < 4; j++) {
        if (BTL_MAIN_IsClientUsed(((struct Obj09984 *)a)->f4, j) != 0 &&
            want == BTL_MAIN_GetClientSide((int)(((struct Obj09984 *)a)->f4), (u8)j)) {
            p = BTL_SIDE_GetSlotOfClient(((struct Obj09984 *)a)->f8, j);
            n = BTL_SLOT_GetCount((struct Q1 *)p);
            for (i = 0; i < n; i++) {
                t = BTL_SLOT_GetPokeParam((struct S2 *)p, (u8)i);
                sum += BTL_POKEPARAM_GetValue(t, 14);
                *out1 += BTL_POKEPARAM_GetValue(t, 13);
            }
        }
    }
    *out2 = _u32_div_f(*out1 * 100, sum);
}
