/*
 * function: BTL_NET_SendRelayedPlayerInfo
 * address:  0x021D4908
 * packet:   pkt_ov093_021D4908
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlNet     0x021F3B88  data  ov093
 *   BTL_NET_BuildPlayerInfoPacket  0x021D4A0C  thumb ov093
 *   BTL_NET_FreePlayerInfoPacket  0x021D4A64  thumb ov093
 *   GFL_NET_SendData  0x0203D3F8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 f00;
    u16 f04;
};

extern struct S *gBtlNet;
extern void *BTL_NET_BuildPlayerInfoPacket(void *a, u32 heap);
extern void BTL_NET_FreePlayerInfoPacket(void *p);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

u32 BTL_NET_SendRelayedPlayerInfo(void *a)
{
    void *o;
    u32 r;

    o = BTL_NET_BuildPlayerInfoPacket(a, (u16)((gBtlNet->f04 & 0x7fff) | 0x8000));
    r = GFL_NET_SendData(gBtlNet->f00, 0xff, 0x106, 0x6c, (u32)o, 0, 1, 0);
    BTL_NET_FreePlayerInfoPacket(o);
    return r;
}
