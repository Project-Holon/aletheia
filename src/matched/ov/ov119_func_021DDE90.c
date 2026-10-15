/*
 * function: POKETRADE_NEGO_StepShowWaitMessageB
 * address: 0x021DDE90
 * packet: pkt_ov119_021DDE90
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_SetSyncRange 0x021DD080 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepWaitCancelSync 0x021DDDF4 thumb ov119
 */
#include "../include/Obj10360.h"

typedef unsigned int   u32;
struct MsgBank;
extern void POKETRADE_PROC_SetSyncRange(void *a, void *b, void *c);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_SAVE_ShowTimeIcon(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepWaitCancelSync(unsigned char *p);

void POKETRADE_NEGO_StepShowWaitMessageB(unsigned char *p)
{
    POKETRADE_PROC_SetSyncRange((void *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()),(void *)30,p); MSGDATA_ReadString((struct MsgBank *)(((struct Obj10360 *)p)->f720),0x88,(void *)(((struct Obj10360 *)p)->f738)); POKETRADE_SAVE_OpenMessageWindowTop(p); POKETRADE_SAVE_ShowTimeIcon((char *)p); p[0x11f1]=120; POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitCancelSync);
}
