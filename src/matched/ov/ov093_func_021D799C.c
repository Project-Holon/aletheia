/*
 * function: BTL_CALC_GetTypeAffinityVsPair
 * address:  0x021D799C
 * packet:   pkt_ov093_021D799C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_SplitBytes  0x021E8D0C  thumb  ov093
 *   BTLV_CORE_BytesEqual  0x021E8DA8  thumb  ov093
 *   BTL_CALC_GetTypeAffinity  0x021D794C  thumb  ov093
 *   BTL_CALC_CombineTypeAffinity  0x021D79E8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTLV_CORE_SplitBytes(int v, u8 *a, u8 *b);
extern int BTLV_CORE_BytesEqual(int v);
extern int BTL_CALC_GetTypeAffinity(int a, int b);
extern int BTL_CALC_CombineTypeAffinity(int a, int b);

int BTL_CALC_GetTypeAffinityVsPair(int a, int v)
{
    u8 t[2];
    int x;

    BTLV_CORE_SplitBytes(v, &t[1], &t[0]);
    if (BTLV_CORE_BytesEqual(v))
        return BTL_CALC_GetTypeAffinity(a, t[1]);
    x = BTL_CALC_GetTypeAffinity(a, t[1]);
    return BTL_CALC_CombineTypeAffinity(x, BTL_CALC_GetTypeAffinity(a, t[0]));
}
