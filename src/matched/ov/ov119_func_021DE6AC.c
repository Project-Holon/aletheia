/*
 * function: POKETRADE_NEGO_StepSendOfferMon
 * address: 0x021DE6AC
 * packet: pkt_ov119_021DE6AC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepOpenOfferActionMenu 0x021DE66C thumb ov119
 */
#include "../include/Obj10361.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0x11fb]; u8 state:4; u8 other:4; } Flags;
extern int POKETRADE_PROC_IsNetSession(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepOpenOfferActionMenu(char *p);
void POKETRADE_NEGO_StepSendOfferMon(char *p)
{
    unsigned id;
    if(((Flags *)p)->state==1) return;
    if(POKETRADE_PROC_IsNetSession(p)!=0) {
        id=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
        if(!GFL_NET_SendToHandle((void *)id,(u16)0xc01,(u16)POKE_TOOL_GetPartyParamSize(),(u32)(((struct Obj10361 *)p)->f106C))) return;
    }
    p[0x11fb]=((u8)p[0x11fb]&~15)|1;
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepOpenOfferActionMenu);
}
