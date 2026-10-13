/*
 * function: CRYPTOi__BN_clear_free
 * address:  0x021CABC0
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CRYPTOi__BN_free  0x021CABDC  arm  ov114
 *   CRYPTOi__BN_clear  0x021CAE94  arm  ov114
 *
 *
 * Null-guarded flush: seals the pending batch, then drains `a`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void CRYPTOi__BN_clear(u8 *p);
extern void CRYPTOi__BN_free(u8 *p);

void CRYPTOi__BN_clear_free(int a)
{
    if (a == 0)
        return;
    CRYPTOi__BN_clear((u8 *)a);
    CRYPTOi__BN_free((u8 *)a);
}
