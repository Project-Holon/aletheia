/*
 * function: func_021D90E8
 * address: 0x021D90E8
 * packet: pkt_ov119_021D90E8
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
void func_021D90E8(u32 a, u32 b, u32 c, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (c == GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()))
            *(u32 *)(base + b * 4 + 0xff0) = a;
        else
            *(u32 *)(base + b * 4 + 0xffc) = a;
    }
}
