/*
 * function: DWCi_GdbGetRequestResultErrorCode
 * address:  0x021E20B8
 * packet:   pkt_021E20B8
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
 * Leaf: -40000 - (a * 100 + b + 50); the 100-stride and the 50-byte
 *  *  header are the record layout of the table the caller indexes.
 */

int DWCi_GdbGetRequestResultErrorCode(int a, int b)
{
    return -40000 - (a * 100 + b + 50);
}

