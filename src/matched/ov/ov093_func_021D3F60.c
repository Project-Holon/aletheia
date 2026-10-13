/*
 * function: BTL_CLIENT_GetCounterMode
 * address: 0x021D3F60
 * packet: pkt_ov093_021D3F60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: Parent approved only the bounded four-byte accessor. Unapproved
 * followers 021D3F64 and 021D3F88, matched 021D3F98 and code 021D3FA8 follow;
 * no follower is included in this source.
 */
typedef unsigned char u8;
u8 BTL_CLIENT_GetCounterMode(u8 *p)
{
    return p[1];
}
