/*
 * function: DWCi_GdbGetStartRequestErrorCode
 * address:  0x021E1EAC
 * packet:   pkt_021E1EAC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Leaf: -40000 - (a * 100 + b), the plain two-term member of the
 *  *  DWCi_GdbGetRequestResultErrorCode family (that one adds the 50-byte header).
 */

int DWCi_GdbGetStartRequestErrorCode(int a, int b)
{
    return -40000 - (a * 100 + b);
}

