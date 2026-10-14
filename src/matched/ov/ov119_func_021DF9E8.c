/*
 * function: POKETRADE_NEGO_SendOfferMon
 * address: 0x021DF9E8
 * packet: pkt_ov119_021DF9E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
#include "../include/Obj00001.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 low:4;u8 high:4; } Flags;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void MI_CpuCopy8(const void *,void *,unsigned);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
int POKETRADE_NEGO_SendOfferMon(char *p,void *src,int kind)
{
    unsigned id;
    int one;
    id=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
    if(((Flags *)(p+0x11fb))->low) return 0;
    MI_CpuCopy8(src,((struct Obj00001 *)p)->f106C,POKE_TOOL_GetPartyParamSize());
    one=1;
    if(!(int)GFL_NET_SendData(id,255,(u16)kind,POKE_TOOL_GetPartyParamSize(),(u32)(((struct Obj00001 *)p)->f106C),(int)0,(int)0,(int)one)) return 0;
    ((Flags *)(p+0x11fb))->low=one;
    return one;
}
