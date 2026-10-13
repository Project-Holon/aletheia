/*
 * function: FLDMMDL_GetObjCodeParamBlActRes
 * address:  0x0216E3C8
 * packet:   pkt_ov010_0216E3C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: adds r0, #0x10; bx lr.
 */

void *FLDMMDL_GetObjCodeParamBlActRes(void *p)
{
    return (char *)p + 0x10;
}
