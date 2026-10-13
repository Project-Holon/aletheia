/*
 * function: DWCi_ScGetRequestErrorCode
 * address:  0x021DF644
 * packet:   pkt_021DF644
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
 * Leaf: -43000 - (a * 100 + b); same 100-byte record stride as the
 *  *  DWCi_GdbGetRequestResultErrorCode family but a different table base.
 */

int DWCi_ScGetRequestErrorCode(int a, int b)
{
    return -43000 - (a * 100 + b);
}

