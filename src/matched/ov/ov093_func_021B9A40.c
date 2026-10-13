/*
 * function: BTL_MAIN_IsPokeIdInSecondPair
 * address: 0x021B9A40
 * packet: pkt_ov093_021B9A40
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enum result preserves zero-first arms before u8 return narrowing.
 */
typedef enum { FALSE = 0, TRUE = 1 } BOOL;
unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int x)
{
    BOOL result;
    if (x < 12) result = FALSE;
    else result = TRUE;
    return result;
}
