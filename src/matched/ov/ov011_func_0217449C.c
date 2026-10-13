/*
 * function: INTRUDE_COMM_RecvPeerFlags
 * address: 0x0217449C
 * packet: pkt_ov011_0217449C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: existing follower ov011_func_021744D0.c stays separate.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 low : 4; u8 flags : 2; u8 high : 2; } F93F;
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
u32 GFL_NET_GetHandleNetID(struct Link *p);
void INTRUDE_COMM_RecvPeerFlags(int a, int b, u8 *c, u8 *p)
{
    if (a != GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()))) {
        ((F93F *)(p + 0x93f))->flags |= *c;
    }
}
