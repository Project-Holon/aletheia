/*
 * function: BTL_ADAPTER_Cancel
 * address:  0x021EEB70
 * packet:   pkt_ov093_021EEB70
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_NET_ExpectReplies  0x021D4C58  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[4];
    u32 w4;
    u32 w8;
    u8 st : 4;
    u8 hi : 4;
    u8 f0d;
    u8 mode;
    u8 f0f;
    u16 h10;
    u16 h12;
    u8 d[1];
} W;

extern void BTL_NET_ExpectReplies(u32 a);

void BTL_ADAPTER_Cancel(W *p)
{
    p->mode = 0;
    if (p->hi != 0)
        BTL_NET_ExpectReplies(p->hi);
}
