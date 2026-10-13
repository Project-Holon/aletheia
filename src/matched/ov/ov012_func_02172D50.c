/*
 * function: UNION_COMM_RequestStart
 * address:  0x02172D50
 * packet:   pkt_ov012_02172D50
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

void UNION_COMM_RequestStart(u8 *p)
{
    if (p[0x3561] == 0) {
        p[0x3561] = 1;
        p[0x3562] = 2;
    }
}
