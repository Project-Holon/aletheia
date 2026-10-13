/*
 * unit:     yes
 * function: BTL_NET_AllocPartyBuf, BTL_NET_RecvPartyDone
 * address:  0x021D446C
 * packet:   pkt_ov093_021D446C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   gBtlNet     0x021F3B88  data  ov093
 *   gBtlNetSourceName     0x021F3A98  data  ov093  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 f00;
    u16 f04;
    u8 pad06[0x3ade];
    void *tblA[4];
    void *tblB[4];
};

extern struct S *gBtlNet;
extern const char gBtlNetSourceName[];
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void *BTL_NET_AllocPartyBuf(int idx, int unused, u32 size)
{
    gBtlNet->tblA[idx] = sub_02030734((u16)((gBtlNet->f04 & 0x7fff) | 0x8000), size, 1, gBtlNetSourceName, 0x1ce);
    return gBtlNet->tblA[idx];
}

void BTL_NET_RecvPartyDone(int idx, void *p)
{
    gBtlNet->tblB[idx] = p;
}
