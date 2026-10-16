/*
 * function: HAND_ITEM_IsHpAtOrBelowFraction
 * address:  0x021DDEA4
 * packet:   pkt_ov093_021DDEA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_CALC_DivideMaxHp  0x021D7B60  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern u32 BTL_CALC_DivideMaxHp(void *p, u32 b);

int HAND_ITEM_IsHpAtOrBelowFraction(void *a, int b, u32 n)
{
    void *m;
    u32 v;

    m = BTL_SERVER_FLOW_GetPokeParam(a, b);
    if (BTL_POKEPARAM_GetValue(m, 0x11) == 0x52 && n > 2)
        n >>= 1;
    if (n == 0)
        n = 1;
    if ((u32)BTL_POKEPARAM_GetValue(m, 0xe) > 1) {
        v = BTL_POKEPARAM_GetValue(m, 0xd);
        if (v <= BTL_CALC_DivideMaxHp(m, n))
            return 1;
    }
    return 0;
}
