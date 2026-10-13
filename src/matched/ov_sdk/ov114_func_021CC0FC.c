/*
 * function: CRYPTOi__BN_mod
 * address:  0x021CC0FC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CRYPTOi__BN_div  0x021CBB80  arm  ov114
 *
 *
 * Forwards four arguments behind a leading zero to CRYPTOi__BN_div.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void CRYPTOi__BN_div(int, int, int, int, int);

void CRYPTOi__BN_mod(int a, int b, int c, int d)
{
    CRYPTOi__BN_div(0, a, b, c, d);
}
