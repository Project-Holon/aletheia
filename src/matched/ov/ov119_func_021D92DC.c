/*
 * function: func_021D92DC
 * address: 0x021D92DC
 * packet: pkt_ov119_021D92DC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
void func_021D92DC(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle())
        (base + a)[0x11e0] = *src;
}
