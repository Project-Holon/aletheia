/*
 * function: COLOSSEUM_SendPlayerEntry
 * address: 0x02174BB8
 * packet: pkt_ov012_02174BB8
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendData(u32,u32,u32,u32,u32,u32,u32,u32);
u32 COLOSSEUM_SendPlayerEntry(u32 a, u32 b)
{
    u32 v = 0;
    if (b != 1) v = 255;
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(),(u8)v,0x1501,44,a,1,0,1);
}
