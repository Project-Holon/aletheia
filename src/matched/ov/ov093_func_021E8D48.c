/*
 * function: BTL_TYPEPAIR_ShareType
 * address:  0x021E8D48
 * packet:   pkt_ov093_021E8D48
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_TYPEPAIR_GetHigh  0x021E8CFC  thumb  ov093
 *   BTL_TYPEPAIR_GetLow  0x021E8D04  thumb  ov093
 */
typedef unsigned char u8;
extern u8 BTL_TYPEPAIR_GetHigh(int v);
extern int BTL_TYPEPAIR_GetLow(int x);

int BTL_TYPEPAIR_ShareType(int a, int b)
{
    if (BTL_TYPEPAIR_GetHigh(a) == BTL_TYPEPAIR_GetHigh(b)) return 1;
    if (BTL_TYPEPAIR_GetHigh(a) == BTL_TYPEPAIR_GetLow(b)) return 1;
    if (BTL_TYPEPAIR_GetLow(a) == BTL_TYPEPAIR_GetHigh(b)) return 1;
    if (BTL_TYPEPAIR_GetLow(a) == BTL_TYPEPAIR_GetLow(b)) return 1;
    return 0;
}
