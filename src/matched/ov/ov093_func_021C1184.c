/*
 * function: func_021C1184
 * address: 0x021C1184
 * packet: pkt_ov093_021C1184
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Zero predicate on byte offset 1; extent ends in two zero padding bytes.
 */
typedef unsigned char u8;
int func_021C1184(const u8 *p)
{
    return p[1] == 0;
}
