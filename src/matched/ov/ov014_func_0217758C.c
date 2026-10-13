/*
 * function: NET_WHPIPE_ResetState
 * address: 0x0217758C
 * packet: pkt_ov014_0217758C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
void NET_WHPIPE_ResetState(u8 *p)
{
    p[0xCEA] = 0;
    p[0xCEF] = 0;
    p[0xCEB] = 0;
    p[0xCEC] = 0;
    p[0xCE9] = 0;
    p[0xCE8] = 0;
}
