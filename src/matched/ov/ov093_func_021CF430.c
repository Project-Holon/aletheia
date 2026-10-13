/*
 * unit: yes
 * function: BTL_CLIENT_SetSlotFlag, BTL_CLIENT_GetSlotFlag
 * address: 0x021CF430
 * packet: pkt_ov093_021CF430
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * follower: unlabelled byte accessor at 0x021CF43C.
 */
typedef unsigned char u8;
typedef unsigned int u32;
void BTL_CLIENT_SetSlotFlag(u8 *p, u32 i, u32 v)
{
    (p + i)[0x130] = v;
}
u8 BTL_CLIENT_GetSlotFlag(u8 *p, u32 i)
{
    return (p + i)[0x130];
}
