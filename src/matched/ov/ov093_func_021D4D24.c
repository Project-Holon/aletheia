/*
 * function: BTL_NET_AllocRelayPacket
 * address:  0x021D4D24
 * packet:   pkt_ov093_021D4D24
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   gBtlNetSourceName     0x021F3A98  data  ov093  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 type : 8;
    u32 size : 24;
} Hdr;

extern const char gBtlNetSourceName[];
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void *BTL_NET_AllocRelayPacket(u32 a, u16 b)
{
    Hdr *h = sub_02030734(b, a + 4, 1, gBtlNetSourceName, 0x477);

    h->size = a;
    h->type = 4;
    return h;
}
