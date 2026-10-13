/*
 * function: func_021D916C
 * address: 0x021D916C
 * packet: pkt_ov119_021D916C
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
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
void func_021D916C(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle())
        *(u32 *)(base + a * 4 + 0x5e4) = *src;
}
