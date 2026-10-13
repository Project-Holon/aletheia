/*
 * function: BTL_MAIN_IsPokeIdInFirstPair
 * address:  0x021B9A50
 * packet:   pkt_021B9A50
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_IsPokeIdInSecondPair  0x021B9A40  thumb  ov093
 *   BTL_MAIN_IsZero  0x021B9A5C  thumb  ov093
 */

unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int x);
unsigned char BTL_MAIN_IsZero(unsigned int x);

unsigned char BTL_MAIN_IsPokeIdInFirstPair(unsigned int x)
{
    return BTL_MAIN_IsZero(BTL_MAIN_IsPokeIdInSecondPair(x));
}
