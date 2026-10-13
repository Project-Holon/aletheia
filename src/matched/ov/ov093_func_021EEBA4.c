/*
 * function: BTL_ADAPTER_PollSend
 * address:  0x021EEBA4
 * packet:   pkt_ov093_021EEBA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_NET_AreAllRepliesReceived  0x021D4B98  thumb  ov093
 *   BTL_NET_GetClientReply  0x021D4BD4  thumb  ov093
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

extern int BTL_NET_AreAllRepliesReceived(void);
extern u16 BTL_NET_GetClientReply(int a, u8 **q);

u32 BTL_ADAPTER_PollSend(W *p)
{
    if (p->hi != 0) {
        if (BTL_NET_AreAllRepliesReceived() != 0) {
            p->w8 = BTL_NET_GetClientReply(p->f0d, (u8 **)(&p->w4));
            p->st = 1;
            return 1;
        }
        return 0;
    }
    return p->st;
}
