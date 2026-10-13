/*
 * function: BTL_NET_FindNetIdByClient
 * address:  0x021D4394
 * packet:   pkt_ov093_021D4394
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no push), filed as the blocker of BTL_NET_SendServerCmd.
 *
 * symbols:
 *   gBtlNet     0x021F3B88  data  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 pad00[0x11];
    u8 f11[4];
};

extern struct S *gBtlNet;

u8 BTL_NET_FindNetIdByClient(u32 a)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (a == gBtlNet->f11[i]) {
            return (u8)i;
        }
    }
    return 0x28;
}
