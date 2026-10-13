/*
 * function: UNION_COMMAND_SendConnectSync
 * address: 0x021739CC
 * packet: pkt_ov012_021739CC
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 * Caller reads live r0 after 020399A8 and return from send wrapper.
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
int UNION_COMMAND_SendConnectSync(void)
{
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x1400, 0, 0);
}
