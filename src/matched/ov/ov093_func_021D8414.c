/*
 * unit: yes
 * function: func_021D8414, func_021D8424
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
void func_021D8414(u32 *p)
{
    *p = (*p & ~15) | 4;
}
void func_021D8424(u32 *p)
{
    *p = (*p & ~15) | 5;
}
