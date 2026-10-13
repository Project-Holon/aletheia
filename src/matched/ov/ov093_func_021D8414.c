/*
 * unit: yes
 * function: BTL_ACTION_SetEscape, BTL_ACTION_SetSkip
 * address: 0x021D8414
 * packet: pkt_ov093_021D8414
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 0x021D8424 is a 14-byte read-modify-write and return leaf with two padding bytes.
 */
typedef unsigned int u32;
void BTL_ACTION_SetEscape(u32 *p)
{
    *p = (*p & ~15) | 4;
}
void BTL_ACTION_SetSkip(u32 *p)
{
    *p = (*p & ~15) | 5;
}
