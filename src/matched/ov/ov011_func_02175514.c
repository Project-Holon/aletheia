/*
 * function: func_02175514
 * address:  0x02175514
 * packet:   pkt_ov011_02175514
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     unlabelled leaf (push {r3,r4}, no lr); callers func_0218123C and
 *           func_02181584 in ov018. Its follower 0x0217553C is also an
 *           unlabelled leaf.
 */

typedef unsigned char u8;

int func_02175514(u8 *p)
{
    int r;

    if (p[0x155] != 4) {
        r = p[0x157];
        if (r != 0) {
            p[0x157] = 0;
            return r;
        }
    }
    return 0;
}
