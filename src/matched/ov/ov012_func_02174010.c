/*
 * function: UNION_COMMAND_SendAppData
 * address: 0x02174010
 * packet: pkt_ov012_02174010
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendDataMask 0x0203D4D0 arm
 */
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendDataMask(u32, u32, u32, u32, u32, u32, u32, u32);
u32 UNION_COMMAND_SendAppData(u32 a, void *p)
{
    return GFL_NET_SendDataMask((u32)GFL_NET_HANDLE_GetCurrentHandle(), a, 0x1412, 0x28, (u32)p, 1, 0, 0);
}
