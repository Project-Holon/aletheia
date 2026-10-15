/*
 * function: DWC_SendReliable
 * address:  0x02176E90
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Passes one and the three arguments on.
 *
 * symbols:
 *   DWCi_SendReliable  0x02176EB0  arm  ov009
 */

extern void DWCi_SendReliable(int a, int b, int c, int d);

void DWC_SendReliable(int a, int b, int c)
{
    DWCi_SendReliable(1, a, b, c);
}

