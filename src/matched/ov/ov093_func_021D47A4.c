/*
 * function: BTL_NET_GetParty
 * address:  0x021D47A4
 * packet:   pkt_ov093_021D47A4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlNet     0x021F3B88  data  ov093
 *   BTL_NET_FindNetIdByClient  0x021D4394  thumb ov093
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 pad00[0x3ae4];
    void *tblA[4];
    void *tblB[4];
    void *tblC[4];
};

extern struct S *gBtlNet;
extern u8 BTL_NET_FindNetIdByClient(u32 a);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);

void *BTL_NET_GetParty(u8 a)
{
    u32 idx = BTL_NET_FindNetIdByClient(a);
    void *p;
    u32 n;
    u32 i;

    if (idx != 0x28) {
        return gBtlNet->tblA[idx];
    }
    p = gBtlNet->tblC[a];
    if (p != 0) {
        n = POKEPARTY_GetCount(p);
        for (i = 0; i < n; i++) {
            POKEPARTY_GetMember(p, i);
        }
        return p;
    }
    return 0;
}
