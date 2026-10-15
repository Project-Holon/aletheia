/*
 * function: POKETRADE_NEGO_StoreRemoteOffer
 * address: 0x021DD380
 * packet: pkt_ov119_021DD380
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   gOfferSlotInitTable 0x021E80E0 data a4
 */
#include "../include/Obj22739.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void MI_CpuCopy8(void *,const void *,int);
extern const char gOfferSlotInitTable[];
void POKETRADE_NEGO_StoreRemoteOffer(char *p,int i,void *src)
{
    *(int *)(p+0xfb0+i*4)=i; *(int *)(p+0xfc8+i*4)=i; if(*(void **)(p+0xfe4+i*4)==0) *(void **)(p+0xfe4+i*4)=func_02030734(((struct Obj22739 *)p)->f5F4,POKE_TOOL_GetPartyParamSize(),1,(void *)gOfferSlotInitTable,0x122);MI_CpuCopy8(src,*(void **)(p+0xfe4+i*4),POKE_TOOL_GetPartyParamSize());
}
