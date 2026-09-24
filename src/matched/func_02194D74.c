/*
 * function: func_02194D74
 * address:  0x02194D74
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Compares 0x20 bytes, skipping the first and the 0xdth: 0 at the first
 * difference, 1 when the rest agree.
 *
 * symbols:
 *

 */

int func_02194D74(unsigned char *p, unsigned char *q)
{
    int i;

    for (i = 0; i < 0x20; i++) {
        if (i != 0 && i != 0xd && p[i] != q[i]) return 0;
    }
    return 1;
}


