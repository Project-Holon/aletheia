/*
 * function: BTL_NET_GetPlayerInfo
 * address: 0x021D48CC
 * packet: pkt_ov093_021D48CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   BTL_NET_FindNetIdByClient 0x021D4394 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *gBtlNet;
extern u8 BTL_NET_FindNetIdByClient(u32);
void *BTL_NET_GetPlayerInfo(u8 a)
{
    int i = BTL_NET_FindNetIdByClient(a);
    void *p;
    if (i != 0x28) return *(void **)(gBtlNet + i * 4 + 0x3ae4);
    p = *(void **)(gBtlNet + 0x3b14);
    if (p != 0 && *(void **)(gBtlNet + 0x3b18) != 0) return p;
    return 0;
}
