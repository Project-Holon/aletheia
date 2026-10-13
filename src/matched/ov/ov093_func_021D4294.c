/*
 * function: BTL_NET_SendEntry
 * address:  0x021D4294
 * packet:   pkt_ov093_021D4294
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gBtlNet     0x021F3B88  data  ov093
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 */

typedef unsigned char u8; typedef unsigned short u16;
struct S { void *link; u8 pad[0x3b1c - 4]; u16 buf[2]; };
extern struct S *gBtlNet;
typedef unsigned int   u32;
struct Entry;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
int BTL_NET_SendEntry(u16 v)
{
    u16 *b = gBtlNet->buf;
    b[0] = 0x64;
    b[1] = v;
    return GFL_NET_SendToHandle(gBtlNet->link, 0x100, 4, (u32)((void *)b));
}
