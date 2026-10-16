/*
 * function: BTL_CALC_CalcDefeatMoneyLoss
 * address:  0x021D7FF8
 * packet:   pkt_ov093_021D7FF8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   gBtlCalcDefeatMoneyScales     0x021F042D  data  ov093  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

struct Q1;
struct S2;
u8 BTL_SLOT_GetCount(struct Q1 *p);
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern u8 gBtlCalcDefeatMoneyScales[];

u32 BTL_CALC_CalcDefeatMoneyLoss(u32 a, void *b)
{
    u32 n = BTL_SLOT_GetCount(b);
    u32 m = 1;
    u32 i;
    u32 v;

    for (i = 0; i < n; i++) {
        v = BTL_POKEPARAM_GetValue(BTL_SLOT_GetPokeParam(b, (u8)i), 0xf);
        if (v > m)
            m = v;
    }
    if (a >= 9)
        a = 8;
    return gBtlCalcDefeatMoneyScales[a] * (m << 2);
}
