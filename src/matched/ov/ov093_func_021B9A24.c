/*
 * function: BTL_MAIN_IsPokeSamePair
 * address: 0x021B9A24
 * packet: pkt_ov093_021B9A24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_IsPokeIdInSecondPair 0x021B9A40 thumb ov093
 */
extern unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int);
int BTL_MAIN_IsPokeSamePair(unsigned int a, unsigned int b)
{
    unsigned char v = BTL_MAIN_IsPokeIdInSecondPair(a);
    if (v == BTL_MAIN_IsPokeIdInSecondPair(b)) return 1;
    return 0;
}
