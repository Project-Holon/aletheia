/*
 * function: POKETRADE_NEGO_StepSendReply
 * address: 0x021DDCF0
 * packet: pkt_ov119_021DDCF0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D94D4 0x021D94D4 thumb ov119
 *   POKETRADE_PROC_IsHostSideAlt 0x021D95D0 thumb ov119
 *   POKETRADE_PROC_IsGuestSide 0x021D95F0 thumb ov119
 *   func_021D9610 0x021D9610 thumb ov119
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_021DD080 0x021DD080 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepResolveReplies 0x021DDBF0 thumb ov119
 */
typedef unsigned short u16;
extern int func_021D94D4(char *p);
extern int POKETRADE_PROC_IsHostSideAlt(void *);
typedef unsigned int   u32;
struct Entry;
extern u32 POKETRADE_PROC_IsGuestSide(void *p);
extern int func_021D9610(unsigned char *p);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void func_021DD080(void *a, void *b, void *c);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepResolveReplies(char *p);
void POKETRADE_NEGO_StepSendReply(unsigned char *p)
{
    unsigned char b=13;if(func_021D94D4((char *)p))b=5;else if(POKETRADE_PROC_IsHostSideAlt(p))b=7;else if(POKETRADE_PROC_IsGuestSide(p))b=8;else if(func_021D9610(p))b=6;if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc00,1,(u32)(&b))){func_021DD080(GFL_NET_HANDLE_GetCurrentHandle(),(void *)29,p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepResolveReplies);}
}
