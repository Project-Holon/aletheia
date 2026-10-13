/*
 * function: UNION_COMM_RequestShutdown
 * address:  0x02172D38
 * packet:   pkt_ov012_02172D38
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 */

typedef unsigned char u8;

void UNION_COMM_RequestShutdown(u8 *p)
{
    if (p[0x3561] == 0) {
        p[0x3561] = 1;
        p[0x3562] = 1;
    }
}
