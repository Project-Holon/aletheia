/*
 * function: func_021D6E70
 * address: 0x021D6E70
 * packet: pkt_ov120_021D6E70
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: follower inside handed 0x021D6E50 extent.
 */
typedef unsigned int u32;
void func_021D6E70(void *unused, int *p, int n)
{
    if(n<(u32)p[0])p[1]=n;
    if(p[1]>2)p[1]=2;
}
