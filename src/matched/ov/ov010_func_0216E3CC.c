/*
 * function: FLDMMDL_GetObjCodeParamMdlRes
 * address:  0x0216E3CC
 * packet:   pkt_ov010_0216E3CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: returns its argument plus 0x10.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

u8 *FLDMMDL_GetObjCodeParamMdlRes(u8 *p)
{
    return p + 0x10;
}
