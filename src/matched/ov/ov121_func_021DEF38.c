/*
 * function: MYSTERY_NET_IsZeroBlock
 * address: 0x021DEF38
 * packet: pkt_ov121_021DEF38
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: Next follower 021DEF54 has its own file.
 */
int MYSTERY_NET_IsZeroBlock(const unsigned *p, unsigned size)
{
    unsigned i;
    for (i = 0; i < size / 4; i++) {
        if (p[i] != 0) return 0;
    }
    return 1;
}
