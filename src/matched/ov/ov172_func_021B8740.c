/*
 * function: func_021B8740
 * address: 0x021B8740
 * packet: pkt_ov172_021B8740
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendData(u32, u32, u32, u32, u32, u32, u32, u32);
u32 func_021B8740(int a, int b, u8 c, u32 d)
{
    struct { u32 w; u8 b; } buf;
    u32 entry;
    entry = (u32)GFL_NET_HANDLE_GetCurrentHandle();
    buf.b = c;
    buf.w = d;
    return GFL_NET_SendData(entry, 255, 0x2000, 8, (u32)&buf, 1, 0, 0);
}
