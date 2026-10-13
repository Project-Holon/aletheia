/*
 * function: COLOSSEUM_SendChoiceRequest
 * address: 0x02174CE4
 * packet: pkt_ov012_02174CE4
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COLOSSEUM_GetMyChoice 0x021750C0 thumb ov012
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 COLOSSEUM_GetMyChoice(char *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendData(u32,u32,u32,u32,u32,u32,u32,u32);
u32 COLOSSEUM_SendChoiceRequest(char *p)
{
    u8 v = COLOSSEUM_GetMyChoice(p);
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(),0,0x1504,1,(u32)&v,1,0,0);
}
