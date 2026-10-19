/*
 * function: BTL_TYPEPAIR_IsSingleType
 * address:  0x021E8DA8
 * packet:   pkt_ov093_021E8DA8
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
extern unsigned char BTL_TYPEPAIR_GetHigh(int x);
extern int BTL_TYPEPAIR_GetLow(int x);

int BTL_TYPEPAIR_IsSingleType(int x)
{
    if (BTL_TYPEPAIR_GetHigh(x) == BTL_TYPEPAIR_GetLow(x)) {
        return 1;
    }
    return 0;
}
