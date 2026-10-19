/*
 * function: BTL_TYPEPAIR_Split
 * address:  0x021E8D0C
 * packet:   pkt_ov093_021E8D0C
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

void BTL_TYPEPAIR_Split(int x, unsigned char *a, unsigned char *b)
{
    *a = BTL_TYPEPAIR_GetHigh(x);
    *b = BTL_TYPEPAIR_GetLow(x);
}
