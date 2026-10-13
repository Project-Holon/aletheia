/*
 * unit:     yes
 * function: BTL_NET_HasEntry, BTL_NET_IsLeaderKnown, BTL_NET_IsLeader, BTL_NET_GetLeaderValue
 * address:  0x021D4330
 * packet:   pkt_ov093_021D4330
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlNet  0x021F3B88  data  ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *gBtlNet;

u8 BTL_NET_HasEntry(int i)
{
    return (gBtlNet + i * 2)[0x3b21];
}

int BTL_NET_IsLeaderKnown(void)
{
    if (gBtlNet[7] != 0x28)
        return 1;
    return 0;
}

int BTL_NET_IsLeader(void)
{
    if (gBtlNet[7] == gBtlNet[6])
        return 1;
    return 0;
}

u8 BTL_NET_GetLeaderValue(void)
{
    u8 *p = gBtlNet;

    if (p != 0)
        return p[0x3b29];
    return 100;
}
