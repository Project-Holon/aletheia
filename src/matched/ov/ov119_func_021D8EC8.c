/*
 * function: POKETRADE_PROC_GetNetIdOffset
 * address: 0x021D8EC8
 * packet: pkt_ov119_021D8EC8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
u32 POKETRADE_PROC_GetNetIdOffset(u32 a, u32 b)
{
    if (a == GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()))
        return b + 0x10;
    return b + 0x2e6;
}
