/*
 * function: COLOSSEUM_SendTrainerCard
 * address: 0x02174C34
 * packet: pkt_ov012_02174C34
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
int COLOSSEUM_SendTrainerCard(u32 a)
{
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(),255,0x1502,0x678,a,1,0,1);
}
