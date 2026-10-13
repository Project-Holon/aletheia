/*
 * function: BTL_NET_IsPerapVoiceReceived
 * address:  0x021D45FC
 * packet:   pkt_ov093_021D45FC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlNet     0x021F3B88  data  ov093
 *   BTL_NET_HasEntry  0x021D4330  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 pad00[0x3af4];
    void *tblB[4];
};

extern struct S *gBtlNet;
extern u8 BTL_NET_HasEntry(int i);

int BTL_NET_IsPerapVoiceReceived(void)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (BTL_NET_HasEntry(i) != 0 && *(u16 *)((u8 *)gBtlNet + i * 0xbbc + 0x17ae) != 0 && gBtlNet->tblB[i] == 0)
            return 0;
    }
    return 1;
}
